/*Realizar una estructura con capacidad de un millon de caracteres 
para ver que es lo que ocurre */

#include <iostream>
#include <conio.h>


using namespace std;

struct Escuela{
	char nombre[1000000];
	int edad;
	int calificacion;
	
	
}Escuela1;

int main(){

	char nuevoNombre[1000000];
	char nuevaCalificacion[1000000];
	char nuevaEdad[1000000];
	
	char nombre[20];
	
	cout<<"Nombre: ";
	cin.getline(Escuela1.nombre,20,'\n');
	cout<<"Edad: ";
	cin>>Escuela1.edad;
	cout<<"Calificacion ";
	cin>>Escuela1.calificacion;
	
	cout<<"Los datos del alumno son: "<<endl;
	cout<<"Nombre: "<<Escuela1.nombre<<endl;
	cout<<"Edad: "<<Escuela1.edad<<endl;
	cout<<"Calificacion: "<<Escuela1.calificacion<<endl;
	
	
	getch();
return 0;	
}
