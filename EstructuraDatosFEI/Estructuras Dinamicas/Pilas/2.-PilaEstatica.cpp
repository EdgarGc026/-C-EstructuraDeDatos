#include <iostream>;
#include <conio.h>;

using namespace std;

class Pila{
	int a[1000];
	int tope;
	int maximo;
	
		public:
			Pila();
			Pila(int m);
			int estaVacia();
			int estaLlena();
			int getDato();
			void push(int x);
			void pop();
			
			//complemetarios
			void mostrar();
			void vaciar();
};

	Pila::Pila(){
		tope=-1;
		maximo = 1000;
	}
	
	Pila::Pila(int m){
		tope=-1;
		
		maximo = m;
		
	}
	
	int Pila::estaVacia(){
		return tope==-1;
		
	}
	
	
	int Pila::estaLlena(){
		return tope==maximo-1;
		
	}
	
	int Pila::getDato(){
		if(estaVacia()){
			cout<<"Error en getDato()\n";
			return -1;
			
		}
		return a[tope];
		
	}
	
	void Pila::push(int x){
		if(estaLlena()){
			cout<<"Error en la pila Push\n";
			return;
		}
		tope++;
		
		a[tope] = x;
		
		//a[++tope] = x
	}
	
	void Pila::pop(){
		if(estaVacia()){
			cout<<"Error en pop, no hay elementos";
			return;
		}
		
		tope--;
	
	}
	
	
	//Complementarios
	
	void Pila::mostrar(){
		Pila paux;
		cout<<"Tope -> ";
		
		while(!estaVacia()){
			cout<<getDato()<<"-> ";
			paux.push(getDato());
			pop();
		}
		while(!paux.estaVacia()){
			push(paux.getDato());
			paux.pop();
		}
		
		
	}
	
	void Pila::vaciar(){
		tope=-1;
	}
	
	
int main(){
	
	
	


	Pila pila1;
	
	char op[] = {"4+5(9*10)"} ;
	for (int i=0; i<8; i++){
		pila1.push(op[i]);
		
	}
	pila1.mostrar();
	
	
	
	
	pila1.push(4);
	pila1.push(5);
	pila1.push(6);
	
	cout<<"Pila Original\n";
	pila1.mostrar();
	
	cout<<endl;
	
	cout<<"Pila despues de ejecutar metodo vaciar()\n";
	pila1.vaciar();	
	pila1.mostrar();
	
	getch();
	return 0;
}	
