//Regrese el mayor de un arreglo

#include <iostream>
#include <conio.h>

using namespace std;


int mayor(int a[], int n){
	int m;
	
	int *p;
	p=a;
	while(p<=a+n-1){
	
		if(m>*p){
	
		}else{
				m=*p;
			
		}
			p++;
		}
		
	return m;
		}
		
	//_________________________________________________________	
		
int mayor2(int a[], int n){
	int *p;
	
	p=a;
	int m = *p;
	p++;
	while(p<a+n){
	
		if(*p>m)
			m=*p;
			p++;
		
		}
		
	return m;
				
	
}

int main(){
	
	int arreglo[]= {2,500,5,89};
	
	
	cout<<"El elemento mayor es: "<<mayor(arreglo,4);
	cout<<endl;
	
	cout<<"El elemento mayor que dio el profe es: "<<mayor2(arreglo,4);
	
	getch();
	return 0;
}
