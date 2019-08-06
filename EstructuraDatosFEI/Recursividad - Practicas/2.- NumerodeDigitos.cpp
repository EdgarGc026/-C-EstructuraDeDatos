//Realizar una funcion que calcule los digitos que contiene un numero

#include <iostream>
#include <conio.h>

using namespace std;



int nDig(int n){
	
	if(n<10){
		return 1;
		
	}else{
		
		return 1 + nDig(n/10);
	}
	
	
	
}


int main(){
	int numero;
	cout<<"Ingresa tu numero para contar sus digitos: ";
	cin>>numero;
	
	cout<<nDig(numero);
	
	
	getch();
	return 0;
}
