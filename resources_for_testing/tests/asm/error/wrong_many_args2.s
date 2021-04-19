.name "wrong"
.comment "error"

l2:		sti r1, %:live, %1
		and r1, %0, r1, r3			#too many args for any op

live:	live %1
		zjmp %:live
