.name "heatdeath.png"
.comment "I'll make all existence reach thermodynamic equilibrium."

reproduce:
	fork %:infinite_expansion

infinite_expansion:
	sti r1, %7, %1
	ld %0, r2
	ld %70, r4
	aff r4

maximum_enthropy:
	live %1
	zjmp %:infinite_expansion
