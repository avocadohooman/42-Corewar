.comment "Champion de test de l'instruction STI."
.name "Test STI"

live:	live %1
		ld %42, r1
		ld %255,r2
		ld %1,r3
		ld %20,r4
		ld %251,r5
		sti r1,r2,r3
		sti r2,r4,%236
		sti r4,2,r5
		sti r1,1,%255
		sti r2,%214,r1
		sti r4,%36,%220
		sti r1,%1000,%280
		zjmp %:carry
		sti r2,%255,%1
		sti r16,%56,%200
		zjmp %:live
carry:	st r1,256
		zjmp %:carry
