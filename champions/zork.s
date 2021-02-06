.name "Batman"
.comment "This city needs me"

loop:   
        st r7, r11
live:   
        live %0
        ld %0, r2
        zjmp %-19