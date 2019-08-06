#include <iostream>
#include <conio.h>

using namespace std;

long factorial(int n){
	if(n==0 || n==1){
		return 1;
		
	}else{
		
		return factorial(n-1) * n;
	}
}

int main(){
	
	cout<<"El resultado es: "<<factorial(5);
	
	
	getch();
	return 0;
}
