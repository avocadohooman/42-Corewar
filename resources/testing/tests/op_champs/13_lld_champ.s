.comment "Champion de test de l'instruction LLD."
.name "Test LLD"

live:	live %1
		lld %55, r1
		st r1,256		#12,5
		lld -4,r2		#17,5
		st r2,256		#22,5
		lld 6,r3			#27,5
		st r3,256		#32,5
		lld 1030,r4		#37,5
		st r4,256		#42,5
		lld -1028,r5		#47,5
		st r5,256		#52,5
		lld %40,r8		#57,7
		zjmp %:carry	#64,3
		lld %0,r9		#67,7
		zjmp %:live		#74,3
carry:	st r1,256		#77,5
		zjmp %:carry	#82,3
