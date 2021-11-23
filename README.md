# SSOO-tarea03
### Estudiante: Alexis Loyola
### Correo: alexis.loyola@alumnos.uv.cl

#### Diseño de solución:
Se implementó la solucion para mostrar en pantalla la secuencia Fibonacci y los numeros impares con un maximo de 50 iteraciones del ciclo utilizando un fork() para que el proceso padre muestre el Fibonacci y el proceso hijo muestre los impares, ambos con su respectiva informacion mostrada en pantalla (PPIDE, PID).

Se buscó informacion en internet sobre como identificar las señales de ctrl+C, ctrl+Z y ctrl+\, para que al momento de ingresarlas muestre en pantalla un mensaje diciendo que no se permite la detencion.

Para poder detener la ejecucion se debe abrir la otra terminal y ejecutar las señales mencionadas para detener individualmente los ciclos padre e hijo.
