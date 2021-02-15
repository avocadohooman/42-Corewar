if [ $# -eq 0 ]
  then
    echo "No arguments supplied"
	exit
fi
TEST_DIR=$1

for f in $TEST_DIR/*.s ; do
	../asm "$f"
done
