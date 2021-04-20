#!/bin/bash

source colors.sh

function load_corewar_info_file
{
	if [ -z "$1" ]
	then
		printerr "Must specify a file"
		return 1
	fi
	if [ ! -f "$1" ]
	then
		printerr "$1 is not a file."
		return 1
	fi
	if [ "$1" = "$corewar_info_file" ]
	then
		# the info file hasn't changed since the last time info was ran
		return 0
	fi
	_corewar_info_file=$1

	# Read variables
	vars=$(cat $_corewar_info_file | cut -d '' -f 1)
	_corewar_folder=$(echo "$vars" | sed -n 1p)
	_args_regular=$(echo "$vars" | sed -n 2p)
	_args_dump=$(echo "$vars" | sed -n 3p)
	_dump_size=$(echo "$vars" | sed -n 4p)
	_lines_after_dump=$(echo "$vars" | sed -n 5p)
	_dump_line_start=$(echo "$vars" | sed -n 6p)
	_dump_line_end=$(echo "$vars" | sed -n 7p)
	_dump_delimiter=$(echo "$vars" | sed -n 8p)
	_victory_format=$(echo "$vars" | sed -n 9p)
	if	[ -z "$_corewar_folder" ] || \
		[ -z "$_dump_line_start" ] || \
		[ -z "$_dump_line_end" ] || \
		[ -z "$_victory_format" ] || \
		! [[ $_args_regular == *"__CHAMPS__"* ]] || \
		! [[ $_args_dump == *"__CHAMPS__"* ]] || \
		! [[ $_args_dump == *"__CYCLE__"* ]]
	then
		printerr "Unable to parse $_corewar_info_file"
		return 1
	fi
	num_regex="^[0-9]+"
	if	[[ ! $_dump_size =~ $num_regex ]] || \
		[[ ! $_lines_after_dump =~ $num_regex ]]
	then
		printerr "Unable to parse $_corewar_info_file"
		return 1
	fi
	let "_dump_tail = _dump_size + _lines_after_dump"

	# Make corewar
	make -C $_corewar_folder corewar > /dev/null
	if [ $? != 0 ]
	then
		printerr "Failed to make corewar executable."
		echoerr "Make sure that a Makefile exists in $_corewar_folder and that it has the \"corewar\" rule."
		return 1
	elif [ ! -f $_corewar_folder/corewar ]
	then
		printerr "Makefile ran but no corewar file was created."
		return 1
	fi

	# Once we're sure there are no errors, update the shell variables
	corewar_info_file=$_corewar_info_file
	corewar_folder=$_corewar_folder
	args_regular=$_args_regular
	args_dump=$_args_dump
	dump_size=$_dump_size
	lines_after_dump=$_lines_after_dump
	dump_line_start=$_dump_line_start
	dump_line_end=$_dump_line_end
	dump_delimiter=$_dump_delimiter
	victory_format=$_victory_format
	dump_tail=$_dump_tail
	corewar=$corewar_folder/corewar
	return 0
}
