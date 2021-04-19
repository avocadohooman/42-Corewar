.name "wrong"
.comment "error"

l2:		sti r1, %:live, %1
		and r1, %0, r1

live:	live %1
		zjmp r4				#wrong argtype
