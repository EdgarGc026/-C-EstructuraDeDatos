

#include <iostream>
#include <conio.h>

using namespace std;

int busqBin(int a[],int pi,int pd,int x){
	if(pi<=pd){
		int pm= (pi + pd)/2;
		
		if(x== a[pm])
			
			return pm;
		
		if(x<a[pm])
			
			return busqBin(a,pi,pm-1,x);
		
	else
	
		return busqBin(a,pm+1,pd,x);
		
	}
		
	
	return -1;
	
}


int main(){
	int arr[]={1,3,7,11,12,40,50,55,72,78,83,95,101,112};
	
	cout<<"Tu Dato se encontro en la posicion: ";
	
	cout<<busqBin(arr,0,14,12);
	
	
	getch();
	return 0;
}
