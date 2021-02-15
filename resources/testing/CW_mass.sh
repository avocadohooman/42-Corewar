if [ $# -eq 0 ]
  then
    echo "No arguments supplied"
	echo "$0 [TEST DIR] [LEVEL]"
	exit
fi
TEST_DIR=$1
LEVEL=$2

FAILED="FAILED:\n"
for f in $TEST_DIR/*.cor ; do
	echo "Testing: $f"
	./cw_tester_log.sh "$f"
	if [ $? -eq -1 ]
	then
		FAILED+="$f\n"
	fi
	if [ $LEVEL -gt 1 ]
	then
		for g in $TEST_DIR/*.cor ; do
			echo "Testing: $f $g $h"
			./cw_tester_log.sh "$f" "$g"
			if [ $? -eq -1 ]
			then
				FAILED+="$f $g\n"
			fi
			if [ $LEVEL -gt 2 ]
			then
				for h in $TEST_DIR/*.cor ; do
					echo "Testing: $f $g $h"
					./cw_tester_log.sh "$f" "$g" "$h"
					if [ $? -eq -1 ]
					then
						FAILED+="$f $g $h\n"
					fi
					if [ $LEVEL -gt 3 ]
					then
						for j in $TEST_DIR/*.cor ; do
							echo "Testing: $f $g $h $j"
							./cw_tester_log.sh "$f" "$g" "$h" "$j"
							if [ $? -eq -1 ]
							then
								FAILED+="$f $g $h $j\n"
							fi
						done
					fi
				done
			fi
		done
	fi
done
