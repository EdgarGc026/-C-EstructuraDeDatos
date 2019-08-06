/* Función recursiva que imprima si n=90 ... 90,91,92...190*/

#include <iostream>
#include <conio.h>

using namespace std;

void serie2(int n,int num){
	
	if(n<num){
		cout<<n+1<<" , ";
		serie2(n+1,num);
	}else{
		cout<<"Fin de la serie";
	}
	
}

int main(){
	
	serie2(0,6);
	
	
	getch();
	return 0;
}
