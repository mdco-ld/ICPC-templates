#!/bin/bash

running() {
	echo "Running $1 tests"
}

compile() {
	g++ "tests/$1.cpp" -o "tests-bin/$1" -I./templates/ -std=c++20
	return $?
}

ce() {
	echo "FAILED $1 tests with COMPILATION ERROR"
	return 0
}

failed() {
	local STATUS="WRONG ANSWER"
	echo "FAILED $1 tests with $STATUS"
}

pass() {
	echo "PASSED $1 tests"
}

run() {
	local NAME="$1"
	local FILENAME="$2"
	running "$NAME"
	compile "$FILENAME"
	if [[ $? -eq 1 ]]; then
		ce "$NAME"
		return 1
	fi
	./tests-bin/"$FILENAME"
	if [[ $? -eq 0 ]]; then
		pass "$NAME"
	else
		failed "$NAME" $?
		return 1
	fi
}

run KMP kmp
