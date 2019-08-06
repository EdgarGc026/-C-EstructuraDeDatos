#include <iostream>
#include <conio.h>

using namespace std;

void intercambio(int &a, int &b){
	int aux = a;
	a = b;
	b= aux;
	
	
}




int main(){
	int a= 3;
	int b= 5;
	
	intercambio(a,b);
	cout<<a<<" "<<b;
	
	
}
