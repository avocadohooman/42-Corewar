.name "Batman"
.comment "This city needs me"

loop:   
        sti r1, %14, %1
        ld %4294902016, r4
live:   
        live %0
        ld %0, r2
        zjmp %-26
