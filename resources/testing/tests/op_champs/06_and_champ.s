.comment "Champion de test de l'instruction AND."
.name "Test AND"

live:	live %1
		ld %3,r1
		ld %4,r2
		ld %7,r3
		ld %15,r4
		and r1,r3,r9		#33,5
		st r9,256			#38,5
		and -3,r4,r10		#43,6
		st r10,256			#49,5
		and 57341,r1,r11	#54,6
		st r11,256			#60,5
		and -3,6,r12		#65,7
		st r12,256			#72,5
		and r3,%14,r13		#77,8
		st r13,256			#85,5
		and -3,%27,r14		#90,9
		st r14,256			#99,5
		and %91,%110,r15	#104,11
		st r15,256			#115,5
		and %15,%8,r16		#120,11
		zjmp %:live			#131,3
		st r15,256			#134,5
		st r16,256			#139,5
		and r1,r2,r16		#144,5
		zjmp %:live			#149,3
carry:	st r1,256			#152,5
		and r1,r2,r7		#157,5
		zjmp %:carry		#162,3
