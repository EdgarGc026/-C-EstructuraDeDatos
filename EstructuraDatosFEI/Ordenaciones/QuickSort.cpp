#include <iostream>
using namespace std;

void ordRapido(int a[],int pi,int pd){
	if(pi<pd){
		int p=partir(a,pi,pd);
		ordRapido(a,pi,p-1);
		ordRapido(a,p+1,pd)
	}
}

int partir(int a[],int pi,int pd){
	int piv=a[pi];
	int i=pi;
	int j=pd;
	while(i<j){
		while(a[i]=<piv){
			
		}
	}
}
