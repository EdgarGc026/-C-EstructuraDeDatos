#include <iostream>
#include <conio.h>

using namespace std;

void imprimir(int a[], int n){
	int *p;
	p=a;
	while(p<a+n-1){
		cout<<*p;
		p++;
	}
	
	
}




int main(){
	int a= 3;
	int b= 5;
	
	intercambio(a,b);
	cout<<a<<" "<<b;
	
	
}
