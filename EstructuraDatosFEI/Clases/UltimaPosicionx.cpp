/*Funcion que regrese la posicion de la ultima
aparicion del elemento x, -1 en el otro caso*/

#include <iostream>
#include <conio.h>

using namespace std;

int pos(int a[],int n, int x){
	if(n==0){
		return -1;
		
		
		
	}else{
		if(a[n-1]==x){
			return n-1;
			
		}else{
			return pos(a,n-1,x);
		}
	}
	
	
	
}


int main(){
	int arr[]={5,4,9,7,8};
	
	cout<<"Tu Dato se encontro en la posicion: ";
	
	cout<<pos(arr,5,8);
	
	
	getch();
	return 0;
}
