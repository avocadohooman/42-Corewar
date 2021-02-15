.comment "Champion de test de l'instruction ADD."
.name "Test ADD"

# live:	live %1
# 		ld %1,r1
# 		st r1,256
# 		st r1,-5
# 		ld %8,r2
# 		st r2,r3
# 		st r3,256
# 		st r1,1280
# 		zjmp %:carry
# 		st r16,256
# 		zjmp %:live
# carry:	st r1,256
# 		zjmp %:carry

live: 	live %1
		ld %1, r1
		ld %2, r2
		ld %3, r3
		ld %0, r6
		ld %0, r7
		add r3, r2, r4
		st r4, 256
		add r1, r2, r5
		st r5, 256
		add r6, r7, r8
		st r8, 256
		zjmp %:live
carry:	st r1, 256
		add r6, r7, r8
		st r8, 256
		zjmp %:carry
