//var = 15 ; i = 10 ; D = i-var ; if D > 0 goto 20, else goto 30

//var = 15
@15
D=A
@var
M=D

//i = 10
@10
D=A
@i
M=D

//i - var
@i
D=M
@var
D=D-M

//if (D > 0) goto 20
@20
D;JGT
//else goto 30
@30
0;JMP