#include <iostream>
using namespace std;

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

int main(){
	
	int a[]={1,4,2,3};
	for(int i=0;i<4;i++){
		cout<<a[i];
	}
	ordSeleccion(a,4);
	return 0;
}
