.name "wrong"
.comment "error"

l2:		sti %:live, %1, r1		#correct args in wrong order
		and r1, %0, r1

live:	live %1
		zjmp %:live
