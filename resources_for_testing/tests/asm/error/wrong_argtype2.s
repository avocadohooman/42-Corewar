.name "wrong"
.comment "error"

l2:		sti r1, %:live, %1
		and r1, %0, %5			#wrong arg type

live:	live %1
		zjmp %:live
