/* Función recursiva que imprima si n=90 ... 90,91,92...190*/

#include <iostream>
#include <conio.h>

using namespace std;

void serie3(int n){
	if(n<=100){
		cout<<n<<" ";
		serie3(n+1);
	}else{
		
		cout<<" Fin de la serie3";
	}
	
}

int main(){
	
	serie3(90);
	
	
	getch();
	return 0;
}
