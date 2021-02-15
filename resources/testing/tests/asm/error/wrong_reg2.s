.name "wrong"
.comment "error"

l2:		sti r1, %:live, %1
		and r1000, %0, r1			#wrong register

live:	live %1
		zjmp %:live
