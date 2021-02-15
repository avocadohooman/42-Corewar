rm -f cw_diff_mem dump_orig dump_us
for (( i=0; i<=24000; i+=100 ))
do
	../corewar $1 $2 $3 $4 -s -d $i > dump_us
	./corewar_orig -d $i $1 $2 $3 $4 > dump_orig
	DIFF=$(diff dump_orig dump_us)
	if [ "$DIFF" != "" ]
	then
		echo "DUMP DIFF $i /n" >> cw_diff_mem
		echo "DUMP DIFF $i"
		echo "$DIFF" >> cw_diff_mem
		echo "" >> cw_diff_mem
	fi
done
# ./corewar $1 $2 $3 $4 -s > dump_us
# ./resources/corewar $1 $2 $3 $4 > dump_orig
# DIFF=$(diff dump_orig dump_us)
# 	if [ "$DIFF" != "" ]
# 	then
# 		echo "DUMP DIFF $i /n" >> cw_diff_mem
# 		echo "$DIFF" >> cw_diff_mem
# 		echo "" >> cw_diff_mem
# 	fi