#include <iostream>
using namespace std;

void ordBurbuja(int a[],int n){
	for(int i=0;i<n-2;i++){
		for(int j=n-1;j<i+1;j++){
			if(a[j]<a[j-1]){
				int aux=a[j];
				a[j]=a[j-1];
				a[j-1]=aux;
			}
		}
	}
}

void mostrar(int *vector,int n){
	for(int i=0; i<n; i++){
		cout<<vector[i]<<" | ";
	}
}

int main(){
		int datos[4]={1,3,5,2};
	
	cout<<"Ordenamiento por burbuja\n";
	
	ordBurbuja(datos,4);
	mostrar(datos,4);


	
	return 0;
}
