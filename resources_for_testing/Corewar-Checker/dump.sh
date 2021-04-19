#!/bin/bash

source colors.sh
source info.sh

# Validate parameters
if [ -z "$1" ] || [ -z "$2" ] || [ -z "$3" ]
then
	echoerr "usage: $0 corewar.info cycles \"champ1 champ2 ...\""
	exit 1
fi

# Extract variables from .info file
load_corewar_info_file $1
if [ $? -ne 0 ] ; then
	exit 1
fi

# Make dump
# Thanks to https://stackoverflow.com/questions/407523/escape-a-string-for-a-sed-replace-pattern for this regex
cycle_escaped=$(echo $2 | sed -e 's/[\/&]/\\&/g')
champs_escaped=$(echo $3 | sed -e 's/[\/&]/\\&/g')
args=$(echo "$args_dump" | sed "s/__CYCLE__/$cycle_escaped/" | sed "s/__CHAMPS__/$champs_escaped/")
output=$($corewar $args)
dump=$(echo "$output" | tail -n $dump_tail | head -n $dump_size | cut -c $dump_line_start-$dump_line_end)
if [ -z "$dump_delimiter" ]
then
	echo "$dump" | tr -d '\n' | tr 'a-f' 'A-F'
else
	echo "$dump" | sed "s/$dump_delimiter//g" | tr -d '\n' | tr 'a-f' 'A-F'
fi
