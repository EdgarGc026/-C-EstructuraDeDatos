#include <iostream>
#include <conio.h>

using namespace std;
 //En una cola statica no es necesario poner el destructor por que no esta reservando espacio en memoria cada vez que se insertan datos
 
 class Cola{
 	int a[100];
 	int frente;
 	int final;
 	int max; // controlar cual es el maximo que permito en una cola estatica
 	int cd; //contador de datos
 	
 	public:
 		Cola();
 		Cola(int m);
 		int estaVacia();
 		int estaLlena();
 		int getDato();
 		void meter(int x);
 		void sacar();
 		
 		
 		//complementarios
 		
 		void mostrar();
 };
 
 Cola::Cola(){ //Un constructor sirve para inicializar valores de atributo
 	frente=-1;
 	final=-1;
 	max=100;
 	cd=0;
 }
 
 Cola::Cola(int m){
 	frente=0;
 	final=-1;
 	cd=0;
 	max=m;

}


int Cola::estaVacia(){
	return cd==0;
}

int Cola::estaLlena(){
	return cd==max;
}

int Cola::getDato(){
	if(estaVacia()){
		cout<<"No hay datos en la cola estatica\n";
		return -1;
	}
	return a[frente];
}

void Cola::meter(int x){
	
	
	if(estaLlena()){
		cout<<"Error cola llena";
		return;		
	}
	final ++;
	if(final==max)
		final =0;
		
		//(final ++) % max;
		
		
		a[final]=x;
		cd++;
}

void Cola::sacar(){
	if(estaVacia()){
		cout<<"Error cola vacia";
		return;
	}
	
	frente++;
	if(frente==max)
	frente=0;
	
	//(final ++) % max;
	
	cd--;
}

	void Cola::mostrar(){
		Cola caux;
		cout<<"Frente -> ";
		
		while(!estaVacia()){
			cout<<getDato()<<"-> ";
			caux.meter(getDato());
			sacar();
		}
		while(!caux.estaVacia()){
			meter(caux.getDato());
			caux.sacar();
		}
		cout<<"<- Final\n";
	}



int main(){
	Cola cola1;
	
	cola1.meter(7);
	
	cola1.mostrar();
	
	
}
