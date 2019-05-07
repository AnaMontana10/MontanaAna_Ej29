#include <iostream>
#include <fstream>
#include <cmath>

/* Problema de ecuacion de onda  para una cuerda con Laplace*/
//usare tres arreglos para calcular las posiciones finales

//defino constantes para la longitud maxima de la cuerda y el tiempo.
         
#define maxt  6     	//maximo para el tiempo	   

using namespace std; 

int main()
{
	double L = 1;	//longitud cuerda	
	int max = 101; 	

    double now[max];
    double old[max];
    double neww[max];
	double dt = 0.01; //delta de tiempo
	double rho = 0.01; //densidad
	double T = 400; //tension
	double dx = 0.01;
	double c = 1/2;
	double constante = c*c /((dx*dx)/(dt*dt)); 
	
	ofstream outfile;
	

/* inicializar now y old para t =0 con las condiciones dadas*/
	

	for(int i=0; i<max; i++){	
		
		if(i == 0 && i == 100){

			now[i]=0; 
			old[i]=now[i];
		}
		else{

			now[i]= sin(M_PI * i/max); 
			old[i]=now[i];
		}
		

		
	}
//calculo new primero

	for (int i = 0; i<max; i++){

		neww[i]= 2 * now[i] - old[i] + constante *(now[i+1] + now[i-1] -2* now[i]);
	}	
	for (int i = 0; i<max; i++){	/* actualizo los otros dos arreglos*/
		
		now[i] =neww[i]; 
		old[i]= now[i];
		}	
	
 // hallar new otra vez
	outfile.open("datosonda.dat");
	for (double t = 2*dt ; t<maxt; t = t + dt){

		for (int i = 0; i<max; i++){

		neww[i]= 2* now[i]- old[i]+ constante *(now[i+1] + now[i-1] -2* now[i]);

		}	

		for (int i=0; i<max; i++){
		 
		outfile << neww[i] << " ";
	      
	    }
	    outfile << "\n";


		for (int i = 0; i<max; i++){		
			
			now[i] =neww[i]; 
			old[i]= now[i]; }

		
	}
	
	
	
	
	outfile.close();

	return 0;
	      
}
 
