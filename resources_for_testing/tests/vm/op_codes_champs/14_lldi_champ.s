.comment "Champion de test de l'instruction LLDI."
.name "Test LLDI"

live:	live %1
		ld %42, r1			#5
		ld %3,r2			#12
		ld %1,r3			#19
		ld %20,r4			#26
		ld %-200,r5			#33
		lldi r2,r3,r8		#40
		st r8,256			#45
		lldi r4,%5,r9		#50
		st r9,256			#56
		lldi 2,r5,r10		#61
		st r10,256			#67
		lldi 1,%2,r11		#72 voir si ca vaut autre chose que 0
		st r11,256			#79
		lldi %-30,r1,r12		#84
		st r12,256			#90
		lldi %-224,%220,r13	#95
		st r13,256			#102
		lldi %1000,%24,r14	#107
		st r14,256			#114
		lldi %1000,%24,r15	#119
		zjmp %:carry		#126
		st r1,256			#129
		lldi %56,%200,r16	#134
		zjmp %:live			#141
carry:	st r1,256			#144
		and %1,%2,r6		#149
		zjmp %:carry		#160
