.name "heatdeath.png"
.comment "I'll make all existence reach thermodynamic equilibrium."

reproduce:	fork %:expansion

expansion:	sti r1, %:enthropy, %1
			ld %0, r2

enthropy:	live %1
			zjmp %:expansion
