#include "test.h"

static enum TestResult test_available(void)
{
	if (linux_access(0, 0) == linux_ENOSYS)
		return TEST_NOT_SUPPORTED;

	return TEST_SUCCESS;
}

static enum TestResult test_file_not_found(void)
{
	if (linux_access("liblinux_nonexistent_test_file", linux_F_OK) != linux_ENOENT)
		return TEST_FAILURE;

	return TEST_SUCCESS;
}

static enum TestResult test_segfault(void)
{
	if (linux_access(0, linux_F_OK) != linux_EFAULT)
		return TEST_FAILURE;

	return TEST_SUCCESS;
}

static enum TestResult test_invalid_mode(void)
{
	if (linux_access("liblinux_test_file", (linux_F_OK | linux_R_OK | linux_W_OK | linux_X_OK) + 1) != linux_EINVAL)
		return TEST_FAILURE;

	return TEST_SUCCESS;
}

static enum TestResult test_no_permission(void)
{
	char const filename[] = "liblinux_test_file";

	linux_fd_t fd = -1;
	if (linux_openat(linux_AT_FDCWD, filename, linux_O_CLOEXEC | linux_O_CREAT, linux_S_IRUSR, &fd))
		return TEST_OTHER_FAILURE;

	if (linux_access(filename, linux_W_OK) != linux_EACCES)
	{
		linux_unlinkat(linux_AT_FDCWD, filename, 0);
		return TEST_FAILURE;
	}

	if (linux_unlinkat(linux_AT_FDCWD, filename, 0))
		return TEST_OTHER_FAILURE;
	return TEST_SUCCESS;
}

static enum TestResult test_correct_usage(void)
{
	char const filename[] = "liblinux_test_file";

	linux_fd_t fd = -1;
	if (linux_openat(linux_AT_FDCWD, filename, linux_O_CLOEXEC | linux_O_CREAT, linux_S_IRUSR | linux_S_IWUSR, &fd))
		return TEST_OTHER_FAILURE;

	if (linux_access(filename, linux_F_OK))
	{
		linux_unlinkat(linux_AT_FDCWD, filename, 0);
		return TEST_FAILURE;
	}

	if (linux_unlinkat(linux_AT_FDCWD, filename, 0))
		return TEST_OTHER_FAILURE;
	return TEST_SUCCESS;
}

BEGIN_TEST()
	DO_TEST(test_available, "Syscall is available");
	DO_TEST(test_file_not_found, "File not found");
	DO_TEST(test_segfault, "Segfault");
	DO_TEST(test_invalid_mode, "Invalid file mode");
	DO_TEST(test_no_permission, "No permission");
	DO_TEST(test_correct_usage, "Correct usage");
END_TEST()
