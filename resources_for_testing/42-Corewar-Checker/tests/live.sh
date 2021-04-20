./test.sh "01 FF FF FF FF $inf_loop" "$inf_loop"
./test.sh "$inf_loop" "01 FF FF FF FE $inf_loop"
./test.sh "01 FF FF FF FE $inf_loop" "$inf_loop"
./test.sh "$inf_loop" "01 FF FF FF FF $inf_loop"
./test.sh "01 FF FF FF FF 01 FF FF FF FF $inf_loop" \
          "01 FF FF FF FE $inf_loop" \
		  "09 00 03 01 FF FF FF FD $inf_loop" \
		  "04 54 02 02 02 01 FF FF FF FC $inf_loop"
./test.sh "01 FF FF FF FF 01 FF FF FF FE 01 FF FF FF FD 01 FF FF FF FC $inf_loop" "$inf_loop"
./test.sh ""
./test.sh "" ""
./test.sh "" "" ""
./test.sh "" "" "" ""
./test.sh "$inf_loop" "$inf_loop" "$inf_loop" \
          "01 FF FF FF FB 01 7F FF FF FF 01 BF FF FF FF $inf_loop"
./test.sh "01 00 00 00 00 01 00 00 00 01 01 00 00 00 02 01 93 39 D4 CA $inf_loop" \
          "$inf_loop" "$inf_loop" "$inf_loop"
./test.sh -c 1755,1756 "01 FF FF FF FC 02 90 00 00 00 01 02 04 54 02 02 02 06 64 02 80 00 00 00 03 09 00 03 09 FF F0 03 70 01"
./test.sh -c 1755,1756 "01 00 00 00 00 02 90 00 00 00 01 02 04 54 02 02 02 06 64 02 80 00 00 00 03 09 00 03 09 FF F0 03 70 01"
./test.sh -c 1755,1756 "01 65 F9 91 92 02 90 00 00 00 01 02 04 54 02 02 02 06 64 02 80 00 00 00 03 09 00 03 09 FF F0 03 70 01"
./test.sh -c 3016,3017,3022,3023 "02 90 00 00 00 01 02 01 00 00 00 00 01 FF FF FF FB 01 A6 4D 66 4F 04 54 02 02 02 06 64 02 00 80 00 00 03 09 FF E4 02 90 00 00 00 01 02 04 54 02 02 02 06 64 02 00 08 00 00 03 09 00 03 09 00 03 09 FF ED 09 00 03 09 00 03 03 70 01 00 00 00 03 70 01" "02 D0 00 64 10 01 00 00 00 00 09 FF FB"
