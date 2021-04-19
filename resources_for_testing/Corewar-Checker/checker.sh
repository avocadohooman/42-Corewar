#!/bin/bash

source colors.sh

function pad_string
{
	str=$1
	if (( ${#str} > $2 ))
	then
		str="${1:0:$(($2 - 3))}..."
	fi
	if (( ($2 - ${#str}) % 2 ))
	then
		str="$str "
	fi
	while (( ${#str} < $2 ))
	do
		str="$str ."
	done
	printf "$str"
}

function test_suite
{
	if [ -z "$1" ] || [ -z "$2" ] ; then
		echo "Skipping badly formatted test suite."
		return 1
	fi

	echo "=== ${t_bold}Test suite \"$1\"${t_off} ================================="
	if [ -z "$num_total" ] ; then
		num_total=0
	fi
	if [ -z "$num_failed" ] ; then
		num_failed=0
	fi
	if [ -z "$num_passed" ] ; then
		num_passed=0
	fi
	suite_num_total=0
	suite_num_failed=0
	suite_num_passed=0

	let "run_str_width = 40 + ${#1}"
	while read test; do
		if [[ $test != "./test.sh "* ]] ; then
			continue
		fi
		run_str=$(pad_string "Running test ${test#./test.sh }" $run_str_width)
		printf "    $run_str "
		eval $test > /dev/null
		if (( ${PIPESTATUS[0]} )) ; then
			printf "${c_red}KO${c_off}\n"
			failed_tests="$failed_tests$test"$'\n'
			let "suite_num_failed++"
			let "num_failed++"
		else
			printf "${c_green}OK${c_off}\n"
			let "num_passed++"
			let "suite_num_passed++"
		fi
		let "num_total++"
		let "suite_num_total++"
	done < <(echo "$2")

	printf "    "
	echo "$1-------------------------------------------" | sed "s/./-/g"

	percent_passed=$(echo "100 * $suite_num_passed / $suite_num_total" | bc)
	echo "    $suite_num_passed tests passed out of $suite_num_total total tests (${percent_passed}%)."

	echo "$1===================================================" | sed "s/./=/g"
	echo
}

export inf_loop="02 D0 00 64 10 09 00 00"

test_suite "Basic instructions" "$(cat tests/basic.sh)"
test_suite "Carry flag" "$(cat tests/carry.sh)"
test_suite "Live" "$(cat tests/live.sh)"
test_suite "CYCLE_TO_DIE" "$(cat tests/cycle_to_die.sh)"
test_suite "Process order" "$(cat tests/order.sh)"
test_suite "Invalid instruction" "$(cat tests/bad_instruction.sh)"
test_suite "Concurrent modification" "$(cat tests/overwrite.sh)"
test_suite "Full programs" "$(cat tests/program.sh)"
# TODO Randomly generated tests
# test_suite "" "$(cat tests/.sh)"
# TODO -n flag tests

echo "$num_failed tests failed out of $num_total total tests."
if (( $num_failed ))
then
	printf "${c_red}${t_bold}Failed tests:${t_off}${c_off}\n"
	printf "$failed_tests" | sed "s/^/    /"
else
	printf "${c_green}All tests passed!${c_off}\n"
fi
