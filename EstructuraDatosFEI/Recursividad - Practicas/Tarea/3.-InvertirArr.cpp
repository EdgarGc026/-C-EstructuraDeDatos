//3.- Invertir un arreglo 

#include<iostream>
#include<conio.h>

using namespace std;


/*void invertir(int a[], int pi, int pd){
	
	if( pd==0){

		
	}else{
		cout<<a[pd-1]<<" , ";
		invertir(a,pi,pd-1);
	}
	
	
}
*/

void invertir(int a[], int pi, int pd){
	
	if( pi<pd){
		int aux= a[pi];
		a[pi]= a[pd];
		a[pd]=aux;
		
		
		invertir(a,pi+1,pd-1);
		cout<<aux;
		
	}

	
}

int main(){
	
	int arrInv[] = {5,9,3,7,10,9};
	invertir(arrInv,0,6);
	
	getch();
	return 0;
}
