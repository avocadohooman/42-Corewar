if [ $# -eq 0 ]
  then
    echo "No arguments supplied"
	exit
fi
TEST_DIR=$1

./ASM_mass.sh "$TEST_DIR"
./CW_mass.sh "$TEST_DIR" 2
