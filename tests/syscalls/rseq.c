#include <liblinux/start.h>
#include <liblinux/linux.h>

#include "memset.h"

enum TestResult
{
	TEST_SUCCESS,
	TEST_FAILURE,
	TEST_EXPECTED_FAILURE,
	TEST_OTHER_FAILURE,
};

enum TestResult test_correct_usage(void)
{
	enum linux_error_t err = linux_error_none;

	struct linux_rseq rseq;
	memset(&rseq, 0, sizeof rseq);
	uint32_t const sig = 0x12341234;

	err = linux_rseq(&rseq, sizeof rseq, 0, sig);
	if (err)
		return TEST_FAILURE;

	err = linux_rseq(&rseq, sizeof rseq, linux_RSEQ_FLAG_UNREGISTER, sig);
	if (err)
		return TEST_FAILURE;

	return TEST_SUCCESS;
}

enum TestResult test_faulty_unregister(void)
{
	enum linux_error_t err = linux_error_none;

	struct linux_rseq rseq;
	memset(&rseq, 0, sizeof rseq);
	uint32_t const sig = 0x12341234;

	err = linux_rseq(&rseq, sizeof rseq, linux_RSEQ_FLAG_UNREGISTER, sig);
	if (err != linux_EINVAL)
		return TEST_FAILURE;

	return TEST_SUCCESS;
}

enum TestResult test_double_register(void)
{
	enum linux_error_t err = linux_error_none;

	struct linux_rseq rseq;
	memset(&rseq, 0, sizeof rseq);
	uint32_t const sig = 0x12341234;

	err = linux_rseq(&rseq, sizeof rseq, 0, sig);
	if (err)
		return TEST_OTHER_FAILURE;

	err = linux_rseq(&rseq, sizeof rseq, 0, sig);
	if (err != linux_EBUSY)
		return TEST_FAILURE;

	err = linux_rseq(&rseq, sizeof rseq, linux_RSEQ_FLAG_UNREGISTER, sig);
	if (err)
		return TEST_OTHER_FAILURE;

	return TEST_SUCCESS;
}

noreturn void linux_start(uintptr_t argc, char* argv[], char* envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;

	if (test_correct_usage() != TEST_SUCCESS)
		linux_exit_group(1);
	if (test_faulty_unregister() != TEST_SUCCESS)
		linux_exit_group(2);
	if (test_double_register() != TEST_SUCCESS)
		linux_exit_group(3);

	linux_exit_group(0);
}
