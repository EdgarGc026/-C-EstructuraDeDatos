#include <iostream>
#include <string.h>
using namespace std;

class Pila{
	char a[1000];
	int tope;
	int maximo;
	public:
		Pila();
		Pila(int m);
		char estaVacia();
		char estaLlena();
		char getDato();
		void push(char x);
		void pop();
		void vaciar();
		void mostrar();
};

Pila::Pila(){
	tope=-1;
	maximo=1000;
}

Pila::Pila(int m){
	tope=-1;
	m=maximo;
	
}

char Pila::estaVacia(){
	return tope==-1;
}

char Pila::estaLlena(){
	return tope==maximo-1;
}

char Pila::getDato(){
	if(estaVacia()){
		cout<<"Error en getDato()";
		return -1;
	}else{
		return a[tope];
	}
}

void Pila::push(char x){
	if(!estaLlena()){
		tope++;
		a[tope]=x;
	}
}

void Pila::pop(){
	if(!estaVacia())
		tope--;
}

void Pila::vaciar(){
	tope=-1;
}

void Pila::mostrar(){
	Pila paux;
	bool abreC = false;
	bool abreL = false;
	bool abreP = false;
	int contC = 0;
	int contL = 0;
	int contP = 0;
	
	while(!estaVacia()){		
		paux.push(getDato());
		pop();
	}
	
	while(!paux.estaVacia()){
		push(paux.getDato());
		paux.pop();	
		
		cout<<"\t elemento "<<getDato()<<"\n";
		if(abreP == false && getDato() == '('){
			cout<<"abre parentesis\n";
			contP++;
			abreP = true;
		}else if(abreP == false && getDato() == ')'){
			cout<<"Ecuacion no balanceada falto abrir parentesis\n";
			cout<<"cerro el parentesis\n";
			contP--;		
		}else if(abreP == false && getDato() == ')'){
			
			cout<<"Esta mal la expresion\n";
		}else if(abreP == true && getDato() == ')'){
			
			cout<<"cerro el parentesis\n";
			abreP = false;
			contP--;
		}
		
		if(abreC == false && getDato() == '['){
			cout<<"abre corchete\n";
			abreC = true;
			contC++;
		}else if(abreC == false && getDato() == ']'){
			cout<<"Ecuacion no balanceada falto abrir corchete\n";
			cout<<"cerro el corchete\n";
			abreC = false;
			contC--;
		}else if(abreC == false && getDato() == ']'){			
			cout<<"Esta mal la expresion\n";
		}else if(abreC == true && getDato() == '['){
			cout<<"Estan mal los corchetes\n";
		}else if(abreC == true && getDato() == ']'){
			
			cout<<"cerro el corchete\n";
			abreC = false;
			contC--;
		}
		
		if(abreL == false && getDato() == '{'){
			cout<<"abre llave\n";
			abreL = true;
			contL++;
		}else if(abreL == false && getDato() == '}'){
			cout<<"Ecuacion no balanceada falto abrir llave\n";
			cout<<"cerro el llave\n";
			abreL = false;
			contL--;
		}else if(abreL == false && getDato() == '}'){
			
			cout<<"Esta mal la expresion\n";
		}else if(abreL == true && getDato() == '{'){
			cout<<"Estan mal los corchetes\n";
		}else if(abreL == true && getDato() == '}'){
			
			cout<<"cerro el llave\n";
			abreL = false;
			contL--;
		}
	}
	if (contP != 0 or contL != 0 or contC != 0) 
		cout<<"La expresion esta mal\n";
	else
		cout<<"la expresion esta bien\n";
}


int main(){
	
	Pila pila;
	char letra[]={"(a+b*c*{x+y}+(a+b)"}; 
	
	cout<<endl;
	cout<<"\tComprobando expresion: ";
	for(int i=0;i<strlen(letra);i++){
		cout<<letra[i];
		pila.push(letra[i]);
	}
	cout<<"\n\n";
	pila.mostrar();
	
	return 0;
}
