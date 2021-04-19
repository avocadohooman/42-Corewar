#!/bin/bash

source colors.sh

if [ -z "$1" ]
then
	echo "usage: $0 /path/to/corewar/folder"
	exit 1
fi
if [ ! -d "$1" ]
then
	printerr "$1 is not a directory."
	exit 1
fi

echo "Making corewar..."
make -C $1 corewar > /dev/null
if [ $? != 0 ]
then
	printerr "Failed to make corewar executable."
	echo "Make sure that a Makefile exists in $1 and that it has the \"corewar\" rule."
	exit 1
elif [ ! -f $1/corewar ]
then
	printerr "Makefile ran but no corewar file was created."
	exit 1
fi
corewar=$1/corewar

echo "Extracting information..."
# Extract victory message
sh makeChampion.sh "" __NAME__ > /tmp/empty.cor
if [ ! -f /tmp/empty.cor ]
then
	printerr "makeChampion.sh failed to create champion."
	exit 1
fi
output=$($corewar /tmp/empty.cor)
status=$?
if [ $status != 0 ]
then
	printf "${c_lred}Failed to run ${c_yellow}$corewar /tmp/empty.cor${c_off}\n"
	printerr "corewar returned exit status $status."
	exit 1
fi
victory_message=$(echo "$output" | grep __NAME__ | tail -1)
if [ -z "$victory_message" ]
then
	printerr "Could not locate victory message."
	echo "Make sure corewar outputs something like \"My Awesome Champion (player 3) won!\""
	exit 1
fi
victory_format=$(echo "$victory_message" | sed 's/1/__NUM__/1')

# Extract dump format
sh makeChampion.sh "11 22 33 44 55 66 77 88 99 AA BB CC DD EE FF" > /tmp/alphabet.cor
output=$($corewar -dump 1 /tmp/alphabet.cor)
status=$?
if [ $status != 0 ]
then
	printf "${c_lred}Failed to run ${c_yellow}$corewar -dump 1 /tmp/alphabet.cor${c_off}\n"
	printerr "corewar returned exit status $status."
	exit 1
fi
match=$(echo "$output" | awk 'match(toupper($0), /11.*22.*33.*44.*55.*66.*77.*88.*99.*AA.*BB.*CC.*DD.*EE.*FF/) {print NR, RSTART, RLENGTH}' | tail -1)
if [ -z "$match" ]
then
	printerr "Failed to identify dump in output."
	exit 1
fi
read dump_start dump_line_start match_size <<< $match
let "match_end = dump_line_start + match_size - 1"
match=$(echo "$output" | sed -n "${dump_start}p" | cut -c $dump_line_start-$match_end)
capture_regex="11(.*)22(.*)33(.*)44(.*)55(.*)66(.*)77(.*)88(.*)99(.*)(AA|aa)(.*)(BB|bb)(.*)(CC|cc)(.*)(DD|dd)(.*)(EE|ee)(.*)(FF|ff)"
if [[ ! $match =~ $capture_regex ]]
then
	printerr "An unknown error occured."
	echo "Note: this error is most likely caused by inconsistent uppercase/lowercase in the dump output."
	exit 1
else
	dump_delimiter="${BASH_REMATCH[1]}"
	for i in 2 3 4 5 6 7 8 9 11 13 15 17 19
	do
		if [ "${BASH_REMATCH[$i]}" != "$dump_delimiter" ]
		then
			printerr "Multiple delimiters found in corewar dump (\"$dump_delimiter\" != \"${BASH_REMATCH[$i]}\")."
			echo "Make sure separators between octets in the dump are consistent."
			exit 1
		fi
	done
fi
full_line_regex=$(printf "/11.*22.*33.*44.*55.*66.*77.*88.*99.*AA.*BB.*CC.*DD.*EE.*FF(${dump_delimiter}[0-9|A-F]{2})*/" | tr a-z A-Z)
dump_line_size=$(echo "$output" | awk "match(toupper(\$0), ${full_line_regex}) {print RLENGTH}")
let "dump_line_end = dump_line_start + dump_line_size - 1"
output_end=$(echo "$output" | wc -l)
dump_end=$output_end
while [ $dump_end -ge $dump_start ]
do
	dump=$(echo "$output" | sed -n "${dump_start},${dump_end}p" | cut -c $dump_line_start-$dump_line_end)
	if [ -z "$dump_delimiter" ] ; then
		dump_raw=$(echo "$dump" | tr -d '\n')
	else
		dump_raw=$(echo "$dump" | sed "s/$dump_delimiter//g" | tr -d '\n')
	fi
	byte_count=$(printf "$dump_raw" | wc -c)
	if [ $byte_count -le 8192 ] ; then
		break
	fi
	let "dump_end = dump_end - 1"
done
if [ $byte_count -ne 8192 ]
then
	printerr "Could not match dump in output."
	echo "Make sure that MEM_SIZE is 4096 in op.h, that the dump is on contiguous lines, and that all the format of dump lines is consistent."
	exit 1
fi
if [[ ! "$dump_raw" =~ ^112233445566778899(AABBCCDDEEFF|aabbccddeeff)0*$ ]]
then
	printerr "Dump did not match expected output."
	exit 1
fi
let "dump_size = dump_end - dump_start + 1"
let "lines_after_dump = output_end - dump_end"

# Create corewar information file
rm -rf user.info
if [ $? -ne 0 ]
then
	printerr "Unable to modify user.info"
	exit 1
fi
echo "$1path to corewar folder
__CHAMPS__command line args (regular usage)
-dump __CYCLE__ __CHAMPS__command line args (dump after cycles)
$dump_sizenumber of lines in dump
$lines_after_dumpnumber of extra lines following dump (if any)
$dump_line_startindex in a dump line at which the hex starts
$dump_line_endindex in a dump line at which the hex ends
$dump_delimiterdelimiter between octets (if any)
$victory_formatformat of victory message" | column -t -s '' > user.info
if [ ! -f user.info ]
then
	printerr "Failed to write to user.info"
	exit 1
fi

# Output results
printf "${c_green}Setup ran successfully.${c_off}\n"
echo "The following information was obtained about your corewar program."
echo "If anything is incorrect, modify user.info accordingly."
cat user.info | sed -e 's/^/	/'
