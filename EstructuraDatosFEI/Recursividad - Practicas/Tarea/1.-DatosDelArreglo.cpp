//1.- Imprima todos los datos de un arreglo

#include<iostream>
#include<conio.h>

using namespace std;


void imprimir(int a[], int n){
	if(n>=1){
		
		imprimir(a,n-1);
		cout<<a[n-1]<<" , ";
	
	}
	
	
	
}

int main(){
	
	int numeros[]={4,2,3,4,8,9};
	
	imprimir(numeros,6);
	getch();
	return 0;
}
