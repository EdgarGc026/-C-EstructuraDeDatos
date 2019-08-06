#include <iostream>
#include <conio.h>

using namespace std;

int contador=0;
int pos(int a[], int n, int x){
	int *p;
	p=a;
	while(p<a+n-1){
		
		p++;
	
	contador++;	
	
	if(*p==x){
		return contador;
	}

	}
	
		
	
}

int contador1=0;
int mayor(int a[], int n, int x){
	int *p;
	p=a;
	while(p<a+n-1){
		
		p++;
	
	contador++;	
	
	if(*p==x){
		return contador;
	}

	}
	
		
	
}




int main(){
	
	int arreglo[]= {2,4,5,9};
	
	
	cout<<pos(arreglo,4,5);
	
}
