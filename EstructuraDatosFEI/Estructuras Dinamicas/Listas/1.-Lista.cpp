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
		sig=p;
	}
	
	int Nodo::getDato(){
		return dato;
	}
	
	Nodo *Nodo::getSig(){
		return sig;
	}
	
	
	
	
/*________________________________________________________________________________________________________*/

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
		
		int Lista::estaOrd(){
			
			Nodo *p;
			p=cab;
			
			if(cab==NULL || p->getSig()==NULL)
				return 1;
				
			Nodo *q;
			q=p->getSig();
			while (q!=NULL){
				if(p->getDato() > q->getDato())
					return 0;
					
				p=q;
				
				q=q->getSig();
			}	
			return 1;
		}
		
	
		int Lista::mayor(){
			
			Nodo *p;
			p=cab;
			int m;
			if(estaVacia()){
				cout<<"No hay mayores que buscar\n";
				return -1;
		}else{
		
					
					m= p->getDato();
					p=p->getSig();
					
					while( p!=NULL){
						if(p->getDato() > m)
						m = p->getDato();
						p=p->getSig();
						
					}
					return m;
				}
			}
		//Insertar al final
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
			
		int Lista::menor(){
			
			Nodo *p;
			p=cab;
			int minimo;
			if(estaVacia()){
				cout<<"No hay mayores que buscar\n";
				return -1;
		}else{
		
					
					minimo= p->getDato();
					p=p->getSig();
					
					while( p!=NULL){
						if(p->getDato() < minimo)
						minimo= p->getDato();
						p=p->getSig();
						
					}
					return minimo;
				}
			}	
			
		int Lista::eliminax(int x){
			Nodo *p;
			Nodo *q;
			
			p=cab;
			q=NULL;
			
			int band=0;	
			
			while(p->getSig()==NULL && !band){
				if(p->getDato()==x){
				
				
					band=1;
					if(q==NULL){
					
					
					cab=p->getSig();
		
				}else
				q->setSig(p->getSig());
				delete p;
			}else
			p=p->getSig();
			
			}	
    	}
	
	
	
	
	
		
		void Lista::invertir(){
			Lista l2,l3;
			while(!estaVacia()){
				l2.meter(getDato());
				sacar();
			}
			while(!l2.estaVacia()){
				l3.meter(l2.getDato());
				l2.sacar();
			}
			while(!l3.estaVacia()){
				meter(l3.getDato());
				l3.sacar();
			}
					
	}
	
	
	
	int contador=1;
		
		int Lista::posicion(int x){
			Nodo *p;
			p=cab;
			
			int contador=1;
			while(p!=NULL){
			
				if(p->getDato()==x)
				return contador;
				p=p->getSig();
				contador++;
			}
				return -1;
		}
		
		int Lista::getUltimo(){
			Nodo *p;
			p=cab;
			
				if(cab==NULL){
					cout<<"Error en el getUltimo()";
					return -1;
				}
				while(p->getSig()!=NULL){	
					p=p->getSig();
				}
				return p->getDato();
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
				
		
		int Lista::buscar(int x){
			Nodo *p;
			p=cab;
			
			int band=0;
			
			if(p->getDato()==x && !band){
				cout<<"encontrado";
				band = 1;
				return 1;
			
			}else{
				p=p->getSig();
					cout<<"No se encontro";
					return 0;
				
				
				
			}
			
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




int main(){
	Lista lista1;
	
	int opcion;
	int elemento;
	int respuesta;
	
	do{
		cout<<"----Menu-----\n";
		cout<<"1.-Meter Elementos\n";
		cout<<"2.-Sacar\n";
		cout<<"3.-Mostrar Elementos\n";
		cout<<"4.-Obtener mayor\n";
		cout<<"5.-Esta ordenanda?\n";
		cout<<"6.-Regresar ultimo elemento\n";
		cout<<"7.-Contar los elementos\n";
		cout<<"8.-Eliminar x\n";
		cout<<"9.-Devuelve posicion\n";
		cout<<"10.-Menor\n";
		cout<<"11.-Insertar al final\n";
		cout<<"12.-Invertir lista\n";
		
		cout<<endl;
		
		cout<<"Que quieres hacer? ";
		cin>>opcion;
		
		switch(opcion){
			
			case 1:
				system("cls");
				
				do{
					cout<<"Ingresa el elemento a meter: \n";
					cin>>elemento; 
					
					cout<<"Quieres meter otro elemento:  1.-SI  2.-NO \n";
					cin>>respuesta;
					
					lista1.meter(elemento);
					
					
				}while(respuesta!=2);
				
					break;
				
				
				case 2:
					
				system("cls");
				
				cout<<"El elemento sacado es : ";
				lista1.sacar();	
			
				break;	
				
				case 3:
				system("cls");
				
				cout<<"Los elementos son: "<<endl;
				
				lista1.mostrar();
				
					break;
					
				case 4:
					system("cls");
					
					cout<<"El elemento mayor es: "<<lista1.mayor()<<endl;
					
					break;
					
					case 5:
						system("cls");
						
						cout<<"Esta Ordenada? 0 = NO     1= SI "<<endl;
						cout<<lista1.estaOrd()<<endl;
						
						break;
						
					case 6:
						system("cls");
						
						cout<<"getUltimo()"<<endl;
						cout<<lista1.getUltimo()<<endl;
						
						break;
						
					case 7:
						system("cls");
						
						cout<<"Tamano de la lista"<<endl;
						cout<<lista1.tamano()<<endl;
						
						break;
						
					case 8:
						system("cls");
						
						cout<<"Eliminar x"<<endl;
						cout<<lista1.eliminax(3);
						
						break;
						
					case 9:
						system("cls");
						
						cout<<"La posicion del elemento x es: "<<lista1.posicion(3)<<endl;
						
						break;
					
					case 10:
						system("cls");
						
						cout<<"El elemento minimo es: "<<lista1.menor()<<endl;
						
						break;
						
					case 11:
						system("cls");
						
						cout<<"Insertar al final\n";
						
						lista1.insertarAlFinal(500);
						
						break;
						
					case 12:
						system("cls");
						
						cout<<"Invertir lista\n";
						
						lista1.invertir();
						
						break;
					
					case 13:
						system("cls");
						
						cout<<"Buscar: "<<lista1.buscar(10);
	
				}
			
		}while(opcion!=14);
		
		getch();
		return 0;
		
	}
	
	


