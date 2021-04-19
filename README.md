```
 ██████╗ ██████╗ ██████╗ ███████╗██╗    ██╗ █████╗ ██████╗ 
██╔════╝██╔═══██╗██╔══██╗██╔════╝██║    ██║██╔══██╗██╔══██╗
██║     ██║   ██║██████╔╝█████╗  ██║ █╗ ██║███████║██████╔╝
██║     ██║   ██║██╔══██╗██╔══╝  ██║███╗██║██╔══██║██╔══██╗
╚██████╗╚██████╔╝██║  ██║███████╗╚███╔███╔╝██║  ██║██║  ██║
 ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝ 
	––– Executing instructions since 2020 –––
```

### Status: Preparing for evaluations...

This project is a replica of the computer game Core War, launched in 1984.<br>

In this project our assignment was:
* Do a assembler to compile custom assembler code (AKA. Champions) to bytecode.
* Do a VM to execute instructions and oversee the game.
* Do our own Champion.

## The Game
The last player to stay alive wins!
## The VM
Execute instructions :))
## Assembler
Compile custom assembly code (Redcode)
## How to Makefile
Build all<br>
`$ make`<br>
Build asm (Assembler)<br>
`$ make asm`<br>
Build corewar (VM)<br>
`$ make corewar`<br>
Clean .o files and clutter<br>
`$ make clean`<br>
Clean all<br>
`$ make fclean`<br>

### How to run
How to run VM
```
$ ./corewar champion_file.cor ... <champion_file_4.cor>
```
Corewar can handle 1 to 4 champions at a time.<br><br>
Additional options for VM:
* `-lldfix`: Reference corewar's _lld_ only reads 2 bytes, and this flag fixes that bug.
* `-dump <cycle>`: Dump memory to stdout 32 octets / line and exit the game.
* `-prettydump <cycle>`: Dump memory to stdout 64 octets / line fancier and exit the game.
* `-n <nb> champion_file_2.cor`: Override champion execution order by giving a champion a custom number.


How to run ASM
```
$ ./asm champion_file.s
```


