.name "wrong"
.comment "error"

l2:		sti r1, %:live, %1 - r3			#erronous argmath
		and r1, %0, r1

live:	live %1	
		zjmp %:live
