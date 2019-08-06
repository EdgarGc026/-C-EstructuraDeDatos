#include <iostream>
using namespace std;

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

int main(){
	
	return 0;
}
