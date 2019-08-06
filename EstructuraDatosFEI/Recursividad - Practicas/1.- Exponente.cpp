//Realizar una funcion que reciba 2 parametros donde uno sea el numero y el otro el exponente

#include <iostream>
#include <conio.h>

using namespace std;

long exponente(int b, int e){
	
	if(e==0){
		return 1;
	}else{
		return b * exponente(b,e-1);
		 
			
		
	}
	
	
	
}

int main(){
	
	cout<<exponente(3,4);
	
	getch();
	return 0;
}
