#include "test.h"

static enum linux_error fork(linux_pid_t* pid)
{
	linux_word_t result = 0;
	enum linux_error const err = linux_clone(linux_SIGCHLD, 0, 0, 0, 0, &result);
	*pid = (linux_pid_t)result;
	return err;
}

static enum TestResult test_available(void)
{
	if (linux_accept(0, 0, 0, 0) == linux_ENOSYS)
		return TEST_NOT_SUPPORTED;

	return TEST_SUCCESS;
}

static enum TestResult test_invalid_fd(void)
{
	if (linux_accept(3, 0, 0, 0) != linux_EBADF)
		return TEST_FAILURE;

	return TEST_SUCCESS;
}

static enum TestResult test_invalid_fd_type(void)
{
	if (linux_accept(1, 0, 0, 0) != linux_ENOTSOCK)
		return TEST_FAILURE;

	return TEST_SUCCESS;
}

/*
 * This tests fails under qemu because the syscall returns EINVAL instead of EFAULT
 *
static enum TestResult test_segfault(void)
{
	linux_fd_t server;
	if (linux_socket(linux_AF_UNIX, linux_SOCK_STREAM, 0, &server))
		return TEST_OTHER_FAILURE;

	struct linux_sockaddr_un const addr =
	{
		.sun_family = linux_AF_UNIX,
		.sun_path = "\0liblinux test socket",
	};
	if (linux_bind(server, (struct linux_sockaddr const*)&addr, sizeof addr))
	{
		linux_close(server);
		return TEST_OTHER_FAILURE;
	}

	if (linux_listen(server, 1))
	{
		linux_close(server);
		return TEST_OTHER_FAILURE;
	}

	linux_pid_t pid;
	if (fork(&pid))
	{
		linux_close(server);
		return TEST_OTHER_FAILURE;
	}
	if (pid == 0) // child
	{
		if (linux_close(server))
			return TEST_OTHER_FAILURE;

		linux_fd_t fd;
		if (linux_socket(linux_AF_UNIX, linux_SOCK_STREAM, 0, &fd))
			return TEST_OTHER_FAILURE;

		if (linux_connect(fd, (struct linux_sockaddr const*)&addr, sizeof addr))
		{
			linux_close(fd);
			linux_exit_group(TEST_OTHER_FAILURE);
		}

		linux_close(fd);
		linux_exit_group(TEST_SUCCESS);
	}

	linux_fd_t client;
	enum linux_error const err = linux_accept(server, (struct linux_sockaddr*)1, 0, &client);
	if (err != linux_EFAULT)
	{
		if (!err)
			linux_close(client);
		linux_close(server);
		return TEST_FAILURE;
	}

	if (linux_close(server))
		return TEST_OTHER_FAILURE;

	return TEST_SUCCESS;
}*/

static enum TestResult test_non_listening(void)
{
	linux_fd_t server = 0;
	if (linux_socket(linux_AF_UNIX, linux_SOCK_STREAM, 0, &server))
		return TEST_OTHER_FAILURE;

	struct linux_sockaddr_un const addr =
	{
		.sun_family = linux_AF_UNIX,
		.sun_path = "\0liblinux test socket",
	};
	if (linux_bind(server, (struct linux_sockaddr const*)&addr, sizeof addr))
	{
		linux_close(server);
		return TEST_OTHER_FAILURE;
	}

	linux_fd_t client = 0;
	enum linux_error const err = linux_accept(server, 0, 0, &client);
	if (err != linux_EINVAL)
	{
		if (!err)
			linux_close(client);
		linux_close(server);
		return TEST_FAILURE;
	}

	if (linux_close(server))
		return TEST_OTHER_FAILURE;

	return TEST_SUCCESS;
}

static enum TestResult test_correct_usage(void)
{
	linux_fd_t server = 0;
	if (linux_socket(linux_AF_UNIX, linux_SOCK_STREAM, 0, &server))
		return TEST_OTHER_FAILURE;

	struct linux_sockaddr_un const addr =
	{
		.sun_family = linux_AF_UNIX,
		.sun_path = "\0liblinux test socket",
	};
	if (linux_bind(server, (struct linux_sockaddr const*)&addr, sizeof addr))
	{
		linux_close(server);
		return TEST_OTHER_FAILURE;
	}

	if (linux_listen(server, 1))
	{
		linux_close(server);
		return TEST_OTHER_FAILURE;
	}

	linux_pid_t pid = 0;
	if (fork(&pid))
	{
		linux_close(server);
		return TEST_OTHER_FAILURE;
	}
	if (pid == 0) // child
	{
		if (linux_close(server))
			return TEST_OTHER_FAILURE;

		linux_fd_t fd = 0;
		if (linux_socket(linux_AF_UNIX, linux_SOCK_STREAM, 0, &fd))
			return TEST_OTHER_FAILURE;

		if (linux_connect(fd, (struct linux_sockaddr const*)&addr, sizeof addr))
		{
			linux_close(fd);
			linux_exit_group(TEST_OTHER_FAILURE);
		}

		linux_close(fd);
		linux_exit_group(TEST_SUCCESS);
	}

	linux_fd_t client = 0;
	if (linux_accept(server, 0, 0, &client))
	{
		linux_close(server);
		return TEST_FAILURE;
	}

	if (linux_close(client))
		return TEST_OTHER_FAILURE;
	if (linux_close(server))
		return TEST_OTHER_FAILURE;

	if (linux_waitid(linux_P_ALL, 0, 0, linux_WEXITED, 0))
		return TEST_OTHER_FAILURE;

	return TEST_SUCCESS;
}

BEGIN_TEST()
	DO_TEST(test_available, "Syscall is available");
	DO_TEST(test_invalid_fd, "Invalid file descriptor number");
	DO_TEST(test_invalid_fd_type, "Invalid file descriptor type");
	//DO_TEST(test_segfault, "Invalid sockaddr pointer");
	DO_TEST(test_non_listening, "Socket not listening");
	DO_TEST(test_correct_usage, "Syscall works");
END_TEST()
