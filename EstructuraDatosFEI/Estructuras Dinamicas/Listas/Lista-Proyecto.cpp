#include <iostream>
#include <conio.h>

#include <ctype.h> //detectar un digito en el arreglo

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
		sig=p;
	}
	
	int Nodo::getDato(){
		return dato;
	}
	
	Nodo *Nodo::getSig(){
		return sig;
	}
	
	
class Lista{
	
		Nodo *cab;	
		
	public:
		Lista();
		~Lista();
		int estaVacia();
		int getDato();
		void meter(int x);
		void sacar();
		void mostrar();
		int tamano();
};

Lista::Lista(){
			cab=NULL;
		}
		
		int Lista::estaVacia(){
			return cab==NULL;
		}
		
	/*	int Lista::estaVacia(){
			if(cab==NULL){
				return 1;
			}else{
				return 0;
			}
		}
		
		*/
		
		void Lista::meter(int x){
			Nodo *p;
			p= new Nodo();
			p->setDato(x);
			p->setSig(cab);
			cab=p;
		}
		
		void Lista::sacar(){
			Nodo *p;
			p=cab;
				if(p!=NULL){
					cab = p->getSig();
					delete p;
				}
		}
		
		int Lista::getDato(){
			if(estaVacia()){
				cout<<"Error lista vacia en getDato";
				return 1;
			}
			return cab->getDato();
		}
		
				
		//DESTRUCTOR
	
		Lista::~Lista(){
			if(cab!=NULL){
				Nodo *p;
				p=cab;
				while(cab!=NULL){
					cab=p->getSig();
					delete p;
					p=cab;
				}
			}
		}
		
			int Lista::tamano(){
			Nodo *p;
			p=cab;
			
			int contador=0;
			
			while(p!=NULL){
				contador++;
				p=p->getSig();
			}
			return contador;
		}
		
	void Lista::mostrar(){
		cout<<"cab-> ";
		Nodo *p;
		p=cab;
		while(p!=NULL){
			cout<<p->getDato()<<"-> ";
			p= p->getSig();
		}
		cout<<"NULL \n";
	}

int main(){
	int listas[8];
	
	Lista lista1[8];
	
	int elemento;
	char arreglo[50] = "45Lava23la5tina",p;
	
	for (int i=0;i<99;i++) 
		p=arreglo[i];
		cout<<p,isdigit(p);
		
		
	//__________________________________________________
	

	if(elemento==isdigit(p)){
	
	
	lista1.meter(elemento);
	
	}else{
		cout<<"No hay enteros en la lista";
		return -1;
	}
	
	lista1.mostrar();

	
	getch();
	return 0;
}
