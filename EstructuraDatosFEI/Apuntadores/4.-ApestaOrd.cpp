#include <iostream>
#include <conio.h>

using namespace std;

int ordenada(int a[], int n){
	int *p;
	p=a;

	while(p<a+n-1){
		
		
		if(*p>*(p+1))
			return 0;
			
		else
		p++;
				 	
	}
		return 1;	
}




int main(){
	
	
	
	int arreglo[]={1,4,8,10};
	
	ordenada(arreglo,4);

	
	return 0;
	
	
}
