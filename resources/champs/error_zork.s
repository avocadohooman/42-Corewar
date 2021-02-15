.name "B_atman"
.comment "I will f***ing destroy your VM with my invalid sti 1st arg registry value!"

loop:   
        sti r0, %7, %1
live:   
        live %0
        ld %0, r2
        zjmp %-19
