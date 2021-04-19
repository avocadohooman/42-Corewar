.name "wrong"
.comment "error"

l2:		sti r1, %:live			#not enough args
		and r1, %0, r1

live:	live %1
		zjmp %:live
