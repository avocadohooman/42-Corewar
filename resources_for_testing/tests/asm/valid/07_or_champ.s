.comment "Champion de test de l'instruction OR."
.name "Test OR"

live:	live %1
		ld %3,r1
		ld %4,r2
		ld %7,r3
		ld %15,r4
		or r1,r3,r9			#33,5
		st r9,256			#38,5
		or -3,r4,r10		#43,6
		st r10,256			#49,5
		or 27341,r1,r11		#54,6
		st r11,256			#60,5
		or -3,6,r12			#65,7
		st r12,256			#72,5
		or r3,%14,r13		#77,8
		st r13,256			#85,5
		or -3,%27,r14		#90,9
		st r14,256			#99,5
		or %91,%110,r15		#104,11
		st r15,256			#115,5
		or %15,%8,r16		#120,11
		zjmp %:live			#131,3
		st r15,256			#134,5
		st r16,256			#139,5
		or r7,r8,r16		#144,5
		zjmp %:live			#149,3
carry:	st r1,256			#152,5
		or %0,%0,r7			#157,5
		zjmp %:carry		#162,3
