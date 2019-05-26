#include "test.h"

static enum TestResult test_available(void)
{
	if (linux_rseq(0, 0, 0, 0) == linux_ENOSYS)
		return TEST_NOT_SUPPORTED;

	return TEST_SUCCESS;
}

static enum TestResult test_correct_usage(void)
{
	struct linux_rseq rseq;
	memset(&rseq, 0, sizeof rseq);
	uint32_t const sig = 0x12341234;

	if (linux_rseq(&rseq, sizeof rseq, 0, sig))
		return TEST_FAILURE;

	if (linux_rseq(&rseq, sizeof rseq, linux_RSEQ_FLAG_UNREGISTER, sig))
		return TEST_FAILURE;

	return TEST_SUCCESS;
}

static enum TestResult test_faulty_unregister(void)
{
	struct linux_rseq rseq;
	memset(&rseq, 0, sizeof rseq);
	uint32_t const sig = 0x12341234;

	if (linux_rseq(&rseq, sizeof rseq, linux_RSEQ_FLAG_UNREGISTER, sig) != linux_EINVAL)
		return TEST_FAILURE;

	return TEST_SUCCESS;
}

static enum TestResult test_double_register(void)
{
	struct linux_rseq rseq;
	memset(&rseq, 0, sizeof rseq);
	uint32_t const sig = 0x12341234;

	if (linux_rseq(&rseq, sizeof rseq, 0, sig))
		return TEST_FAILURE;

	if (linux_rseq(&rseq, sizeof rseq, 0, sig) != linux_EBUSY)
		return TEST_FAILURE;

	if (linux_rseq(&rseq, sizeof rseq, linux_RSEQ_FLAG_UNREGISTER, sig))
		return TEST_FAILURE;

	return TEST_SUCCESS;
}

BEGIN_TEST()
	DO_TEST(test_available, "Syscall is available");
	DO_TEST(test_correct_usage, "Syscall works");
	DO_TEST(test_faulty_unregister, "Faulty unregistering is error");
	DO_TEST(test_double_register, "Double unregistering is error");
END_TEST()
