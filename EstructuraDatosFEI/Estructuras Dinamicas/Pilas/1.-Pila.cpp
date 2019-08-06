#include <iostream>
#include <conio.h>

using namespace std;

class Nodo{
	
	int dato;
	Nodo *sig;
	
		public:
			
			void setDato(int x);
			void setSig(Nodo *p);
			int getDato();
			Nodo *getSig();
			
};

	void Nodo::setDato(int x){
		dato = x;
		
	}
	
	void Nodo::setSig(Nodo *p){
		sig = p;
		
	}
	
	int Nodo::getDato(){
		return dato;
		
	}
	
	Nodo *Nodo::getSig(){
		return sig;
	}
	
	class Pila{
		Nodo *tope;
		
		public:
			Pila();
			~Pila();
			int estaVacia();
			int getDato();
			void push(int x);
			void pop();
			void mostrar();
			
			//complementarias
			
			void invertir();
			int getFondo();
			int mayor();
			int posicion(int x);
	};
	
	Pila::Pila(){
		tope=NULL;
	}
	
	int Pila::estaVacia(){
		return tope==NULL;
	}
	
	int Pila::getDato(){
		if(estaVacia()){
			cout<<"Error en getDato()";
			return -1;
		}
		return tope->getDato();
	}
	
	
	void Pila::push(int x){
			Nodo *p;
			p= new Nodo();
			
			p->setDato(x);
			p->setSig(tope);
			
			tope =p;
		
	}
	
	void Pila::pop(){
		if(!estaVacia()){
		
		Nodo *p;
		p=tope;
		
			tope =p->getSig();
			delete p;
		}
		
	}
	

	
	void Pila::invertir(){
		Pila p2, p3;
		while(!estaVacia()){
			p2.push(getDato());
			pop();
		}
		while(!p2.estaVacia()){
			p3.push(p2.getDato());
			p2.pop();
		}
		while(!p3.estaVacia()){
			push(p3.getDato());
			p3.pop();
		}
	}
	
	int Pila::mayor(){
		Pila paux;
		int m;	
		
		if(estaVacia()){
			cout<<"No hay elementos en la pila\n";
			return -1;
		}else{
			while(!estaVacia()){
				
			paux.push(getDato());
			pop();
			
			if(getDato() > m){
				m=getDato();
			}
		}
		while(!paux.estaVacia()){
			push(paux.getDato());
			paux.pop();
			}
			return m;
		}
		
	}
	
	int Pila::getFondo(){
		Pila paux;
		int fondo;
		
		if(estaVacia()){
			cout<<"Error en el getFondo()\n";
			return -1;
		}else{
			
			while(!estaVacia()){
				fondo = getDato();
				paux.push(getDato());
				pop();
				
				
			}
			while(!paux.estaVacia()){
				push(paux.getDato());
				paux.pop();
			}
			return fondo;
		}
		
	}
	
	int Pila::posicion(int x){
		Pila paux;
		
		int contador=0;
		int band = 0;
		
		if(estaVacia()){
			cout<<"Error en posicion()\n";
			return -1;
		}else{
			
			while(!estaVacia() && !band){
				if(getDato()==x)
					band =1;
					
					else
						contador++;
				paux.push(getDato());
				pop();
				
				
				
							
			}
			
			while(!paux.estaVacia()){
				push(paux.getDato());
				paux.pop();
			}
			if(band)
			return contador;
			else
			return -1;
		}
		
	}
	
		
	//Destructor
	
Pila::~Pila(){		
	Nodo *p;
	p=tope;
			while(tope != NULL){
	tope=p->getSig();
	delete p;
	p=tope;
}

}

	void Pila::mostrar(){
		Pila paux;
		cout<<"tope -> ";
		while(!estaVacia()){
			cout<<getDato()<<"-> ";
			paux.push(getDato());
			pop();
		}
		cout<<"NULL";
		while(!paux.estaVacia()){
			push(paux.getDato());
			paux.pop();
		}
	}



int main(){
	
	Pila pila1;
	

	pila1.push(8);
	pila1.push(1000);
	pila1.push(356);
	pila1.push(987);
	pila1.push(52);

	pila1.push(987);
	

	
	cout<<"Pila Original\n";
	pila1.mostrar();
	cout<<endl;
	
	cout<<"Pila Invetida\n";
	
	cout<<endl;
	
	
	cout<<"El elemento mayor es: "<<pila1.mayor();
	cout<<endl;
	
	cout<<"El elemento que buscas esta en la posicion : "<<pila1.posicion(987);
	cout<<endl;
	
	cout<<"El fondo es: "<<pila1.getFondo();
	cout<<endl;
	
	
	
	
	
	
	getch();
	return 0;
}
	
