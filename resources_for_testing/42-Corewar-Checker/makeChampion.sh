#!/bin/bash

source colors.sh

function zero_pad {
	to_pad=$1
	new_size=$2
	let "pad_size = new_size - ${#to_pad}"
	for (( i=0; i < $pad_size; i++ ))
	do
		to_pad+="0"
	done
	echo $to_pad
}

magic="00ea83f3"
name="Auto-made champion"
comment="This champion was made using makeChampion.sh"

# Verify existence of first argument
if [ $# -eq 0 ] ;
then
	echo "usage: $0 bytecode [name [comment]]"
	exit 1
fi

# If second or third arguments exist, use as name and comment respectively
if [ ! -z "$2" ] ;
then
	name=$2
fi
if [ ! -z "$3" ] ;
then
	comment=$3
fi

# Validate first argument as bytecode and trim space
if ! [[ "$1" =~ ^[[:space:]0-9a-fA-F]*$ ]]
then
	printerr "Argument 1 not well formatted. Expected hexadecimal string of the format \"XX XX ...\""
	exit 1
fi
bytecode=$(echo "$1" | tr -d "[:space:]")

# Calculate size and convert from integer to hex
if (( ${#bytecode} % 2 ))
then
	printerr "Bytecode should be in full octets. (Expected an even number of hex; got ${#bytecode})."
	exit 1
fi
let "size = ${#bytecode} / 2"
size_hex=$(printf "%.8x\n" $size)

# Convert name and comment from ASCII to hex
name_hex=$(printf "$name" | xxd -p | tr -d "[:space:]")
comment_hex=$(printf "$comment" | xxd -p | tr -d "[:space:]")

# Pad name and comment to the correct lengths
name_hex="$(zero_pad "$name_hex" 264)"			# 128 * 2 (xx = 1 byte) + 8 (round to longword boundary)
comment_hex="$(zero_pad "$comment_hex" 4104)"	# 2048 * 2 + 8

# Combine and reverse hexdump
echo $magic$name_hex$size_hex$comment_hex$bytecode | xxd -r -p
