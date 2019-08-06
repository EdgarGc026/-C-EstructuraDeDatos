//Realizar una funcion que regrese un 1 si el arreglo esta ordenado de menor a mayor o un 0 si no

#include <iostream>
#include <conio.h>

using namespace std;

int posX(int a[], int n, int x){
	
	if(n>=0){
		if(a[n-1]==x){
			return n;
		}else{
		return posX(a,n-1,x);
		}
		

		
	}else{
		return -1; 	
}
}

int main(){
	
	int arr[]= {1,4,6,8,2};
	
	cout<<"La posicion de x es: " ;
	cout<<posX(arr,5,4);
	
	getch();
	return 0;
}
