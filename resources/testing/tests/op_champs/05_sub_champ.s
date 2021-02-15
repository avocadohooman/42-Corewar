.comment "Champion de test de l'instruction SUB."
.name "Test SUB"

live: 	live %1
		ld %1, r1
		ld %2, r2
		ld %15, r3
		ld %13, r6
		ld %0, r7
		sub r3, r2, r4
		st r4, 256
		sub r1, r2, r5
		st r5, 256
		add r6, r2, r8
		st r8, 256
        sub r8, r3, r9
        st r9, 256
		zjmp %:live
carry:	st r1, 256
		add r6, r7, r10
		st r10, 256
		zjmp %:carry
