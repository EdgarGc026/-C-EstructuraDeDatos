#include <iostream>

using namespace std;


//realizar una funcion en c++ que regrese un 1 si un dato x esta en el arrglo o un 0 si no

//Escribir una funcion en c++ que invierta los datos de un arreglo

//funcion en c++ que regrese el valor mayor de un arrglo

//funcion que elimine un dato de la siguiente manera: [ 2, 5, 6, 3, 4]   [2,6,3,4,4]


int estaX(int arr[],int n,int x){
	
	
	
		for(int i=0;i<n;i++){
			if(arr[i]==x){
				return 1;
			}
		}
			 
		 return 0;
	
}


void invertir(int arr[], int n){
	int j=n-1;
	int i=0;
	
	while(i<j){
		int aux=arr[i];
		arr[i] = arr[j];
		arr[j]=aux;
		i++;
		j--;
		
			for(int i;i<=5;i++){
	
	cout<<arr[i];
}
	}
		
}

int getMayor(int arr[], int n){
	
	int mayor=arr[0];
	
	for(int i=1; i<n;i++){
		
		if(arr[i]>mayor){
			mayor=arr[i];
		}
		
		cout<<"El elemento mayor es: ";
		return mayor;
	}

	
}

void eliminarX(int arr[], int n, int x){
	
	int i=0;
	int band = 0;
	
	while(!band & i<n){
		if(arr[i] == x){
			band = 1;
			i++;
		}
		if(band){  //si encontre x
			for(int j=i;j<n;j++){
				arr[j-1] = arr[j]; 
			}
		}
	}
	
	
}

int main(){
	
	int arr[5] ={3,2,4,1,9};
	
	for(int i;i<=5;i++){
	
	cout<<arr[i];
	
}
	cout<<"Esta o no esta el elemento";
	cout<<estaX(arr,5,4);
	cout<<endl;
	
	cout<<"Invertir arreglo";
	invertir(arr,5);
	

	
	
	cout<<endl;
	
	cout<<getMayor(arr,5);
	cout<<endl;
	
	cout<<"Eliminar";
	eliminarX(arr,5,1);
	cout<<endl;
	
	

	
	return 0;
}
