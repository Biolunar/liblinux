#!/bin/sh

if [ -z $1 ]; then
	echo "Usage: ./run_tests.sh <architecture> [interpreter]"
	exit
fi

ARCH=$1
INTERP=$2

. src/$ARCH/syscalls.sh

echo "Beginning tests."

# Test return values:
# 0 - Success
# 1 - Not supported
# 2 - Failure
# 3 - Other failure

for SYSCALL in $SYSCALLS
do
	FILE="tests/syscalls/${SYSCALL}"
	printf "\tTesting ${SYSCALL}... "
	$INTERP ./$FILE
	RET=$?
	if [ $RET -eq 0 ]; then
		printf "\033[32mSUCCESS\033[0m\n"
	elif [ $RET -eq 1 ]; then
		printf "\033[33mNOT SUPPORTED\033[0m\n"
	elif [ $RET -eq 2 ]; then
		printf "\033[31mFAILURE\033[0m\n"
	elif [ $RET -eq 3 ]; then
		printf "\033[31mOTHER FAILURE\033[0m\n"
	else
		printf "\033[31mUNKNOWN ERROR\033[0m\n"
	fi
done

echo "Finished tests."
