#!/bin/bash

source colors.sh
source info.sh

# Extract cycles (if applicable)
if [ "$1" = "-c" ]
then
	if ! [[ "$2" =~ ^([0-9],?)+$ ]]
	then
		printerr "Expected a comma-separated list of positive numbers following -c."
		exit 1
	fi
	cycles=$(echo $2 | tr "," " ")
	shift 2
else
	cycles=""
fi

# Error checking
if [ $# -eq 0 ]
then
	printf "usage: $0 [-c cycles] champ1 champ2 ...\n  cycles: comma separated list of cycles to check (e.g. 42,43,44)\n  champ: either a .cor file or the raw bytecode in hexadecimal\n"
	exit 0
fi
if ! [ -f zaz.info ]
then
	printerr "Missing file: zaz.info"
	exit 1
fi
if ! [ -f user.info ]
then
	printerr "Missing file: user.info"
	exit 1
fi

# Print test header
printf "Running test"
for champ in "${@:1}"
do
	printf " \"$champ\""
done
printf "\n"

# Creation of test champion(s)
i=1
champs=""
for champ in "${@:1}"
do
	if [ -f "$champ" ]
	then
		# Champion from file
		champs="$champs $champ"
	else
		# Champion from bytecode
		./makeChampion.sh "$champ" "test_champ_$i" > /tmp/champ$i.cor
		if [ $? -ne 0 ]
		then
			printerr "Champion creation failed."
			exit 1
		fi
		champs="$champs /tmp/champ$i.cor"
		let "i++"
	fi
done

# Test the diff at the end of various cycles
function cycle_dump_test
{
	printf "Cycle"
	for cycle in $cycles
	do
		printf " $cycle"

		# Generate dump files
		sh dump.sh zaz.info $cycle "$champs" > /tmp/cor_expected_dump
		if [ $? -ne 0 ]
		then
			printerr "Failed to dump zaz's corewar."
			exit 1
		fi
		sh dump.sh user.info $cycle "$champs" > /tmp/cor_actual_dump
		if [ $? -ne 0 ]
		then
			printerr "Failed to dump user's corewar."
			exit 1
		fi

		# Compare
		diff=$(diff /tmp/cor_expected_dump /tmp/cor_actual_dump)
		if [ -z "$diff" ]
		then
			printf " (${c_green}OK${c_off})"
		else
			printf " (${c_red}KO${c_off})\n"
			return 1
		fi
	done
	echo
	return 0
}

# Test the content of the victory message
function victory_message_test
{
	# escape the champs (for use with sed later)
	champs_escaped=$(echo $champs | sed -e 's/[\/&]/\\&/g')

	# Obtain the expected victory message
	load_corewar_info_file zaz.info
	if [ $? -ne 0 ] ; then
		exit 1
	fi
	args=$(echo "$args_regular" | sed "s/__CHAMPS__/$champs_escaped/")
	output=$($corewar $args | tail -1)
	status=$?
	if [ $status -ne 0 ]
	then
		printerr "zaz's corewar returned exit status $status."
		exit 1
	fi

	# Test against formatted strings until we find the victor
	for i in 1 2 3 4 5
	do
		if [ $i -eq 5 ]
		then
			printerr "Could not parse zaz's victory message."
			exit 1
		fi
		msg=$(echo "$victory_format" | sed "s/__NUM__/$i/g" | sed "s/__NAME__/test_champ_$i/g")
		if [ "$output" = "$msg" ]
		then
			break
		fi
	done

	# Obtain the user's victory message
	load_corewar_info_file user.info
	if [ $? -ne 0 ] ; then
		exit 1
	fi
	args=$(echo "$args_regular" | sed "s/__CHAMPS__/$champs_escaped/")
	output=$($corewar $args | tail -1)
	if [ $status -ne 0 ]
	then
		printerr "corewar returned exit status $status."
		exit 1
	fi

	# Compare
	msg=$(echo "$victory_format" | sed "s/__NUM__/$i/g" | sed "s/__NAME__/test_champ_$i/g")
	if [ "$output" = "$msg" ]
	then
		printf "${c_green}OK${c_off}\n"
		return 0
	fi
	printf "${c_red}KO${c_off}\n"
	return 1
}

# Test
if [ -z "$cycles" ]
then
	victory_message_test
else
	cycle_dump_test
fi
exit $?
