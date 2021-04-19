.comment "Champion de test de l'instruction AFF."
.name "Test AFF"

live:	live %1
		ld %65,r1
		ld %321,r2
		st r1,256
		aff r1
		st r2,256
		aff r2
		zjmp %:test
		aff r3
		zjmp %:testo
		and %3,%8,r6
		zjmp %:live
test:	st r2,256
		and %3,%8,r7
		zjmp %:live
testo:	st r2,256
		and %3,%8,r8
		zjmp %:live
