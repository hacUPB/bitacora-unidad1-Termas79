//Copiar una constante al registro D
@1954
D=A
@23
D=D+A

//Apuntar a pos. 100 de RAM y asignar 0
@100
M=0

@17
D=A
@100
M=D

//RAM[100] <-- RAM[200]

@200
D=M
@100
M=D

//RAM[3] <-- RAM[3] - 15

@15
D=A
@3
M=M-D

//RAM[3] <-- RAM[4] + 1

@4
D=M+1
@3
M=D

// if (D = 0) goto 300

@300
D;JEQ

// if (RAM[3] < 100) goto 12

@3
D=M
@100
D=D-A

@12
D;JLT