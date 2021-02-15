rm -f cw_diff_log dump_orig dump_us dump_orig_parsed
echo "\nOur CW"
time ../corewar $1 $2 $3 $4 -s -log 1 > dump_us
echo "\nOriginal CW"
time ./corewar_orig -v 6 $1 $2 $3 $4 > dump_orig
python3 parse_orig.py > dump_orig_parsed
DIFF=$(diff dump_orig_parsed dump_us)
echo ""
if [ "$DIFF" != "" ]
then
	echo "$DIFF" >> cw_diff_log
	echo "\033[31mDifference found and saved in cw_diff_log\033[0m"
	exit -1
fi
echo "\033[32mDone\033[0m"
exit 0