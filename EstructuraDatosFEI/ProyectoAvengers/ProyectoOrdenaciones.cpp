#include <iostream>
#include <string.h>
using namespace std;

//BubleSort

struct avengers{
	string nombre;
	int inteligencia;
	int fuerza;
	int velocidad;
	
	
};



void ordBurbuja(int a[],int n){
	for(int i=0; i<n; i++){	
		for(int j=0; j<n-1; j++){
			if(a[j] > a[j+1]){
				int aux=a[j];
				a[j]=a[j+1];
				a[j+1]= aux;
			}
		}
	}
}

//Inserrtion

void ordInsercion(int a[],int n){
	for(int i=0;i<n-1;i++){
		int aux=a[i];
		int j=i-1;
		bool finj=false;
		while(j>=0 and !finj){
			if(a[j]>aux){
				a[j+1]=a[j];
				j=j-1;
			}else{
				finj=true;
			}
		}
		a[j+1]=aux;
	}
}




//Selection Sort
void ordSeleccion(int a[],int n){
	for(int i=0;i<n-2;i++){
		int pm=i;
		for(int j=i+1;j<n-1;j++){
			if(a[j]<a[pm]){
				pm=j;
			}
		}
		int aux=a[pm];
		a[pm]=a[i];
	}
}

//Quick Sort 
int partir(int a[],int pi,int pd){
	int piv=a[pi];
	int i=pi;
	int j=pd;
	while(i<j){
		while(a[i]<=piv){
			i=j+1;
		}
		while(a[j]>piv){
			j=j-1;
		}
		if(i<j){
			int aux = a[i];
			a[i] = a[j];
			a[j] = aux;
		}
	}
	int aux = a[j];
	a[j] = piv;
	a[pi] =aux;
	
	return j;
}

void ordRapido(int a[],int pi,int pd){
	if(pi<pd){
		int p=partir(a,pi,pd);
		ordRapido(a,pi,p-1);
		ordRapido(a,p+1,pd);
	}
}




//MergeSort

void mezclar(int a[], int pi, int pm, int pd){
	int arreglo[];
	
	
	for(int i=pi; i<pd; i++){
		int ax[i] = a[i];
	}
	
	i=pi;
	int j=pm+1;
	int k=pi;
	
	while(i<=pm && j<= pd){
		if(ax[i]<ax[j]){
			a[k] = ax[i];
			i= i+1;
			
		}else{
			a[k] = ax[j];
			j = j+1;
			
		}
		k = k+1;
		
	}
	while( i<=pm ){
		a[k] = ax[i];
		i = i+1;
		k = k+1;
		
	}
	
	while( j<= pd){
		a[k] = ax[j];
		j = j+1;
		k = k+1;
	}
	
	
}

void ordMezcla(int a[],int pi,int pd){
	if(pi<pd){
		int pm=(pi+pd)/2;
		ordMezcla(a,pi,pm);
		ordMezcla(a,pm+1,pd);
		mezclar(a,pi,pm,pd);
	}
}



// HeapSort

void consHeap(int a[],int n){
	//int k;
	for(int k=2;k<n;k++){
		int i;
		k=i;
		int p=k/2;
		bool fink=false;
		while(k>1 and !fink){
			if(a[k]>a[p]){
				int aux=a[k];
				a[k]=a[p];
				a[p]=aux;
				k=p;
				p=k/2;
			}else{
				fink=true;
			}
		}
	}
}



void reconsHeap(int a[],int n){
	int aux=a[1];
	a[1]=a[n];
	a[n]=aux;
	n=n-1;
	int k=1;
	int izq=2;
	int der=3;
	bool fink=false;
	while(!fink and k<=n/2){
		if(izq==n){
			if(a[izq]>a[k]){
				aux=a[izq];
				a[izq]=a[k];
				a[k]=aux;
			}else{
				fink=true;
			}
		}else if(a[izq]>a[k] and a[izq]>=a[der]){
			aux=a[izq];
			a[izq]=a[k];
			a[k]=aux;
			k=izq;
		}else{
			if(a[der]>a[k] and a[der]>=a[izq]){
				aux=a[der];
				a[der]=a[k];
				a[k]=aux;
				k=der;
			}else{
				fink=true;
			}
		}
		izq=k*2;
		der=k*2+1;
	}
}

void ordHeap(int a[],int n){
	consHeap(a,n);
	int nElementos=n-1;
	while(nElementos>1){
		reconsHeap(a,nElementos);
		nElementos=nElementos-1;
	}
}


void mostrar(int *vector,int n){
	for(int i=0; i<n; i++){
		cout<<vector[i]<<" | ";
	}
}

int main(){
	cout<<"Proyecto5: Ordenamientos  (Estructura de Datos)\n";
	cout<<"Integrantes: \n";
	cout<<"\tLuis Daniel Carmona Villa\n ";
	cout<<"\tArturo Nermi Landa Jimenez\n";
	cout<<"Profesor:  Angel Juan\n";
	cout<<endl;
	
	
	avengers avenger1;
	avenger1.nombre = "Iron Man";
	avenger1.inteligencia = 95;
	avenger1.fuerza= 80;
	avenger1.velocidad = 75;
	
	avengers avenger2;
	avenger2.nombre = "Thor";
	avenger2.inteligencia = 85;
	avenger2.fuerza= 100;
	avenger2.velocidad = 95;
	
	avengers avenger3;
	avenger3.nombre = "Hulk";
	avenger3.inteligencia = 70;
	avenger3.fuerza= 100;
	avenger3.velocidad = 80;
	
	avengers avenger4;
	avenger4.nombre = "Capitan";
	avenger4.inteligencia = 100;
	avenger4.fuerza= 90;
	avenger4.velocidad = 75;
	
	avengers avenger5;
	avenger5.nombre = "Thanos";
	avenger5.inteligencia = 80;
	avenger5.fuerza= 100;
	avenger5.velocidad = 85;
	
	
	
	
	
	int datos[4]={1,3,5,2};
	int tamano = 4; //para quicksort
	
	cout<<"Ordenamiento por burbuja\n";
	
	ordBurbuja(datos,4);
	mostrar(datos,4);
	cout<<endl;
	
	cout<<"Ordenamiento por Insercion\n";
	
	ordInsercion(datos,4);
	mostrar(datos,4);
	cout<<endl;
	
	cout<<"Ordenamiento por Seleccion\n";
	
	ordSeleccion(datos,4);
	mostrar(datos,4);
	cout<<endl;
	
	cout<<"Ordenamiento por QuickSort\n";
	
	ordRapido(datos,0,tamano-1);
	mostrar(datos,4);
	cout<<endl;
	
	cout<<"Ordenamiento por MergeSort\n";
	
	
	mostrar(datos,4);
	cout<<endl;
	
	cout<<"Ordenamiento por HeapSort\n";
	
	ordHeap(datos,4);
	mostrar(datos,4);
	cout<<endl;
	
	


	
	return 0;
}



