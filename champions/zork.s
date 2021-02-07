.name "Batman"
.comment "This city needs me"

loop:   
        zjmp %-19
live:   
        live %0
        ld %0, r2
        zjmp %-19