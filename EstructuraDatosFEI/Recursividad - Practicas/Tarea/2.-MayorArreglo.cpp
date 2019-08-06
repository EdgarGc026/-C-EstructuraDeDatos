//2.- Calcule el mayor de un arreglo 

#include<iostream>
#include<conio.h>

using namespace std;


/*int maximo=0;
int mayor(int a[],int n){
	
	if(n==0){
		
	return maximo;
	}else{
		if(maximo>a[n-1]){
			
		
		
		}else{
			maximo=a[n-1];
			
		
		}
		mayor(a,n-1);
	}
	
	
}
*/

int mayor(int a[],int n){
	int m;
	if(n==1)
	return a[n-1];
	
	else{
		m=mayor(a,n-1);
		
		if(m>a[n-1])
		return m;
	else
	return a[n-1];	
	}
}



int main(){
	int arrMayor[] = {5,12,3,7,10,11};
	
	cout<<mayor(arrMayor,6);
	
	getch();
	return 0;
}
