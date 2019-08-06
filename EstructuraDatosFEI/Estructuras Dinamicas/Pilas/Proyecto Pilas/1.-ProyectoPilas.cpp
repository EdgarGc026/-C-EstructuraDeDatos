#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <cstring>
#include <string.h>

using namespace std;

class Nodo{
	
    char operador;
    Nodo *sig;
    
	public:
    		void setDato(char operador);
			void setSig(Nodo *p);
			int getDato();
			Nodo *getSig();
};


	void Nodo::setDato(char operador){
		operador = operador;
		
	}
	
	void Nodo::setSig(Nodo *p){
		sig = p;
		
	}
	
	int Nodo::getDato(){
		return operador;
		
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
			void push(char operador);
			void pop();
			void mostrar();
			
			//complementarias
			
					
			
			
			int determinarPrioridad(char digito);
			char obtenerOperador();
			
	};
    
    Pila::Pila(){
    	tope=NULL;
	}
    
    int Pila::estaVacia(){
        return tope == NULL;
    }
    
    int Pila::getDato(){
		if(estaVacia()){
			cout<<"Error en getDato()";
			return -1;
		}
		return tope->getDato();
	}
    
    void Pila::push(char operador){
			Nodo *p;
			p= new Nodo();
			
			p->setDato(operador);
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
    
    
    
    char Pila::obtenerOperador(){
        if(!estaVacia()){
            return tope->getDato();
        }
    }
    
    int Pila::determinarPrioridad(char digito) {
        char operador [6]={'+','-','/','*','(',')'};
        int prioridad [6]={1,1,2,2,-1,0};
        for(int i=0; i<6; i++){
            if(digito == operador[i]){
                return prioridad[i];
            }
        }
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
		int mayor();
		
		int estaOrd();
		int getUltimo();
		int tamano();
		
		int posicion(int x);
		void insertarAlFinal(int x);
		void invertir();
		int menor();
		void eliminarFinal();
		int eliminax(int x);
		int buscar(int x);
		
		
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
		
			void Lista::insertarAlFinal(int x){
			Nodo *p;
			Nodo *q;
			
			p=cab;
			q=new Nodo;
			q->setDato(x);
			q->setSig(NULL);
			
				if(cab!=NULL){
					while(p->getSig()!=NULL)
					p=p->getSig();
					p->setSig(q);
				}else
				cab=q;
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






int main() {
      
    Pila pila;
    Pila paux; 
	Lista lista;  
	
	string ecuacion;
	string aperturas = "({[";
	string cierres = ")}]";
	
	
	
	char op[] = {"4+5(9*10)"} ;
	for (int i=0; i<8; i++){
		pila.push(op[i]);
		
	}
	cout<<"pila";
	pila.mostrar();
		
		    
    bool sw = 1; //La ecuacion es correcta;
  
   	cout<<"Ingresa tu ecuación: ";
	   getline(cin,ecuacion);
					
		
		cout<<"La ecuacion es: "<<ecuacion<<endl;
		
		for(int i=0; i<ecuacion.size();i++){
			
			 if(ecuacion[ecuacion.size()] != '+' && ecuacion[ecuacion.size()] != '-' && ecuacion[ecuacion.size()] != '*' && ecuacion[ecuacion.size()] != '/' && ecuacion[ecuacion.size()] != '(' && ecuacion[ecuacion.size()] != ')'){
			//	op = ecuacion[ecuacion.size()];
			//	lista.insertarAlFinal(op);
					lista.mostrar();
					
			
			}
		
    	}   
    	

   
   	getch();
    return 0;
}



