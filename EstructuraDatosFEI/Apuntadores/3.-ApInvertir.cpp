#include <iostream>
#include <conio.h>

using namespace std;

void invertir (int a[], int n){
	int *p;
	int *q;
	
		p=a;
		q=a+n-1;
	while(p<q){
		int aux=*p;
		*p=*q;
		*q=aux;
	p++;
	q--;
		
	}
	
	
}




int main(){
	
	int arr[] = {2,4,1,3,4};
	
	invertir(arr,5);
	
	getch();
	return 0;

}
	
