.name "Train stopper"
.comment "This is the last stop"

init:
	sti r1, %:uploop, %1
init2:
	sti r1, %:downloop, %1
	sti r1, %:gener1, %1
	sti r1, %:gener2, %1
	sti r1, %:gener3, %1
	sti r1, %:gener4, %1
	sti r1, %:liveloop, %1
	ld %0, r2
	ld %0, r3
	fork %:livespam
	ld %107217152, r5
	ld %1, r6
	ld %655352, r7
	st r7, :init + 7
	st r6, :init + 4
	st r5, :init
	st r5, :init
	st r5, :init  

init_g:
	and r1, %0, r4
gener1:
	live %1
	fork %:updef

gener2:
	live %1
	fork %:downdef

gener3:
	live %1
	fork %:init_g
gener4:
	live %1
	fork %:livespam
	zjmp %:gener1

updef:
	and r1, %0, r4
uploop:
	live %1
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	st r2, -400
	zjmp %:uploop

livespam:
	and r1, %0, r4
liveloop:
	live %1
	zjmp %:liveloop

downdef:
	and r1, %0, r4
downloop:
	live %1
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	st r3, 236
	zjmp %:downloop
