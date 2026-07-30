//Modifica el programa de la actividad anterior de tal manera que puedas mover la línea horizontal de derecha 
//a izquierda usando las teclas d e i respectivamente. Tu programa no tiene que verificar si la línea se sale 
//de la pantalla.
    @SCREEN
    D=A
    @cont
    M=D
    A=M
    M=-1
(LOOP)
    @KBD
    D=M
    @100 //d
    D=D-A
    @ET1
    D;JEQ
    @KBD
    D=M
    @105 //i
    D=D-A
    @ET2
    D;JEQ
    @LOOP
    0;JMP
(ET1)
    
(END)
    @END
    0;JMP