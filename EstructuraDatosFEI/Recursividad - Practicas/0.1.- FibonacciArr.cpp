#include <iostream>
#include <conio.h>

using namespace std;

int fibo(int n){	
int a[100];
if(a[n]!=0){
	return a[n];
}else{
	a[n]= fibo(n-2) + fibo (n-1);
	return a[n];
}
}

int main(){
	
	fibo(6);
	
	getch();
	return 0;
}
