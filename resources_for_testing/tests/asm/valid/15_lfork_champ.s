.comment "Champion de test de l'instruction LFORK."
.name "Test LFORK"

start:	st r2,256
		ld %33, r2
live:	live %1
		ld %42, r1
		st r1,256
		lfork %4067
		lfork %25
		zjmp %:live
		st r1,256
		and %3,%4,r5
		zjmp %:live
fork:	st r1,256
		and %3,%4,r6
		zjmp %:fork
