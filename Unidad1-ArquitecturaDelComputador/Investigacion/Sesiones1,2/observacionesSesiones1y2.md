Experimento #1

- Se almacena el valor 3 en RAM[16] porque almacena el valor guardado en el registro D que era 3 por las operaciones anteriores.

Ciclos fetch-decode-execute
--> ROM[0] = Apunta a RAM[1] 
--> ROM[1] = Almacena A (1) en D
--> ROM[2] = Apunta a RAM[2]
--> ROM[3] = Suma D con A y lo almacena en el nuevo D
--> ROM[4] = Apunta a RAM[16]
--> ROM[5] = Almacena valor de D en M de RAM[16]
--> ROM[6] = Apunta a RAM[6]
--> ROM[7] = Salta a ejecutar la instrucción almacenada en ROM[A] (ROM[6])
Se genera un loop que mantiene saltando de ROM[7] a ROM[6]

![alt text](ej1sesion1.png)
----------------------------------------------------------------------------------------------------------------
Expeerimento #2

--> ROM[0] = Apunta RAM[5]
--> ROM[1] = Almacena A (5) en D
--> ROM[2] = Apunta RAM[10]
--> ROM[3] = Almacena D (5) mas A (10) en el nuevo D
--> ROM[4] = Apunta RAM[20]
--> ROM[5] = Almacena D (15) en M de RAM[20]
----------------------------------------------------------------------------------------------------------------
ROM
- Memoria de lectura que almacena instrucciones para leerlas y ejectutarlas para luego ser almacenadas en la memoria RAM.

RAM
- Memoria de lectura y escritura que almacena información de datos asignados por instrucciones ejecutadas en el ciclo fetch-decode-execute.