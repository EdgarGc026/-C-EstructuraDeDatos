#include <iostream>

using namespace std;

void saluda(){
	cout<<"Hola ";
	saluda();
}

void saluda2(int n){
	if(n==1){
		cout<<"Hola";
		saluda2(n);
	}
}

void saluda3(int n){
	if(n>0){
		cout<<"Hola";
		saluda3(n-1);
	}
}

int main(){
	
//	cout<<"Funcion 1: "<<endl;  // La primera no es por que no tiene condicion de salida
//	saluda();
//	cout<<"Funcion 2: "<<endl; // No lo es por que igual no tiene condicion de salida
//	saluda2(2);
	cout<<"Funcion 3: "<<endl; // Si lo es por que cumple con que sea diferente de cero el caso da salida
	saluda3(1);
	
	
	
	
	return 0;	
}
