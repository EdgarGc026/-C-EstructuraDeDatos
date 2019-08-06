#include <iostream>

using namespace std;

void serie(int n){
	
	if(n>0){
		cout<<n<<" ";
	
	
		serie(n-1);
	}
	
}

int main(){
	
	serie(100);
	
	return 0;
}
