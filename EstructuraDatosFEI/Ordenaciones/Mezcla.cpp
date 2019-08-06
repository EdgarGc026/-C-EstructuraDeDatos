#include <iostream>
using namespace std;


void ordMezcla(int a[],int pi,int pd){
	if(pi<pd){
		int pm=(pi+pd)/2;
		ordMezcla(a,pi,pm);
		ordMezcla(a,pm+1,pd);
		mezclar(a,pi,pm,pd);
	}
}
