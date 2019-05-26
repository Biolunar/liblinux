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
	echo -n "	Testing ${SYSCALL}... "
	$INTERP ./$FILE
	RET=$?
	if [ $RET -eq 0 ]; then
		echo -e "\e[32mSUCCESS\e[0m"
	elif [ $RET -eq 1 ]; then
		echo -e "\e[33mNOT SUPPORTED\e[0m"
	elif [ $RET -eq 2 ]; then
		echo -e "\e[31mFAILURE\e[0m"
	elif [ $RET -eq 3 ]; then
		echo -e "\e[31mOTHER FAILURE\e[0m"
	else
		echo -e "\e[31mUNKNOWN ERROR\e[0m"
	fi
	#echo "$FILE"
done

echo "Finished tests."
