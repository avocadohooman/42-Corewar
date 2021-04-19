.name "wrong"
.comment "error"

l2:		sti r1, fake, %1		#fake argument
		and r1, %0, r1

live:	live %1
		zjmp %:live
