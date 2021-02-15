## DIRECTORY TO RUN TEST ON ##
if [ $# -eq 0 ]
  then
    echo "No Folder supplied"
	exit
fi
TEST_DIR=$1

## DIFF LOG FILE NAME ##

DIFF_LOG="asm_diff_log"

## COLORS ##
GREEN="\033[0;32m"
RED="\033[0;31m"
EOC="\033[0m"

## SCRIPT ##
rm $TEST_DIR/*.cor
rm $DIFF_LOG
for f in $TEST_DIR/*.s ; do
	echo "Testing: $f"
	[ -f original_temp ] && rm original_temp
	[ -f our_temp ] && rm our_temp
	[[ -f "$f" ]] || continue
	STATUS=$(./asm_orig "$f")
	COR="${f%.s}.cor"
	if [ ! -f "$COR" ]
	then
		echo "Original ASM failed to create $COR\n$STATUS\n" >> $DIFF_LOG
		echo "Fake" > original_temp
		echo "$RED Original FAIL$EOC"
	else
		echo "$GREEN Original OK$EOC"
		hexdump $COR > original_temp
	fi
	rm -f $COR
	STATUS=$(../asm "$f")
	if [ ! -f "$COR" ]
	then
		echo "Our ASM failed to create $COR\n$STATUS\n" >> $DIFF_LOG
		echo "$RED Our ASM FAIL$EOC"
		echo ""
		continue
	fi
	echo "$GREEN Our ASM OK$EOC"
	hexdump $COR > our_temp
	DIFF=$(diff original_temp our_temp)
	if [ "$DIFF" != "" ]
	then
		echo "Difference for $f /n" >> $DIFF_LOG
		echo "$DIFF" >> $DIFF_LOG
		echo "" >> $DIFF_LOG
		echo "$RED Diff in hexdump$EOC"
	fi
	echo ""
done
[ -f original_temp ] && rm original_temp
[ -f our_temp ] && rm our_temp
rm $TEST_DIR/*.cor