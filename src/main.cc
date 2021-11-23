#include <iostream> //Librerias necesarias
#include <thread>
#include <chrono>
#include <csignal>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void invalid(int sig) {
	std::cout << "Detencion no permitida \n" << std::endl; //Mostrar mensaje de Detencion no permitida
}

int main(){

	long int a = 0, b = 0, c = 1, c_hijo = 1, c_padre = 1, d = 1; //Definir variables
	int child = fork(); //Fork

	signal(SIGTSTP, invalid); //Detecta ctrl+Z
	signal(SIGINT, invalid); //Detecta ctrl+C
	signal(SIGQUIT, invalid); //Detecta ctrl+\

	while (c_hijo<=50){ //Realiza el ciclo 50 veces.
		if (child == 0){
			if (d % 2 != 0){
				std::cout << "Valor impar: " << d << " - PID = " << getpid() << "\n"; //Muestra el valor impar y el PID
				std::this_thread::sleep_for(std::chrono::seconds(1)); //Sentencia para controlar tiempo de salida de numeros
				c_hijo++; //Se le suma 1 al contador de ciclos hijo
				}
			d++; //Se suma 1 al contador para sacar impares
		}else{
			while (c_padre<=50){ //Realiza el ciclo 50 veces
				a = b + c;
				b = c;
				c = a;
				std::cout << "Valor Fibonacci: " << a << " - PPIDE = " << getpid() << "\n"; //Muestra el valor Fibonacci y el PPIDE
				std::this_thread::sleep_for(std::chrono::seconds(1)); //Sentencia para controlar tiempo de salida de numeros
				c_padre++; //Se le suma 1 al contador de ciclos padre
				if(c_padre==51){ //Termina la ejecucion al completar 50 iteraciones del ciclo
					return EXIT_SUCCESS;
				}
			}
		}
	}
}
