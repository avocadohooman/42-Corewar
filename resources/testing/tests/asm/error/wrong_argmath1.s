.name "wrong"
.comment "error"

l2:		sti r1, %:live, %1+s			#erronous argmath
		and r1, %0, r1

live:	live %1	
		zjmp %:live
