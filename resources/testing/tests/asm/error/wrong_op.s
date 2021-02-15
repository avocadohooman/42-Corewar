.name "wrong"
.comment "error"

l2:		sti r1, %:live, %1
		sd r1, %0, r1			#nonexistent operation

live:	live %1
		zjmp %:live
