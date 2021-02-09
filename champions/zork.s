.name "Batman"
.comment "This city needs me"

loop:   
<<<<<<< HEAD
        sti r1, %7,%1
=======
        sti r1, %7, %1
>>>>>>> master
live:   
        live %0
        ld %0, r2
        zjmp %-19
