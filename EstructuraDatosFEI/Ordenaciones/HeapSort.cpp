#include <iostream>
using namespace std;



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

int main(){
	
	int a[]={4,2,1,5};
	ordHeap(a,4);
	
	return 0;
}
