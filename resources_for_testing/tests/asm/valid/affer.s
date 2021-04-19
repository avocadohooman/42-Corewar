.name "affer"
.comment "affing"

ld %65, r2
ld %70, r3
ld %70, r4
ld %73, r5
ld %78, r6
ld %71, r7
ld %32, r8

loop:
live %1
aff r2
aff r3
aff r4
aff r5
aff r6
aff r7
aff r8
and r16, r15, r14
zjmp %:loop
