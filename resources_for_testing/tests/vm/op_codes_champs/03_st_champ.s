.comment "Champion de test de l'instruction ST."
.name "Test ST"

live:	live %1
		ld %1,r1		#5,7
		st r1,256		#12,5
		st r1,-5		#17,5
		ld %8,r2		#22,7
		st r2,r3		#29,4
		st r3,256		#33,5
		st r1,1280		#38,5
		zjmp %:carry	#43,3
		st r16,256		#46,5
		zjmp %:live		#51,3
		st r1,256		#54,5
		and %1,%2,r9	#59,11
		zjmp %:live		#70,3
carry:	st r1,256		#73,5
		zjmp %:carry	#78,3
