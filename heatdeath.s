.name "heatdeath.png"
.comment "I'll make all existence reach thermodynamic equilibrium."

reproduce:	fork %:expansion
			and %0, %0, r3
			and %0, %0, r3

expansion:	sti r1, %:enthropy, %1
			ld %0, r2

enthropy:	live %1
			zjmp %:enthropy
