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
	
	
	//_________________________________________________________________________________________________________________________________
	
	
class Cola{
	Nodo *frente;
	Nodo *final;
	
	public:
		Cola();
		~Cola();
		int estaVacia();
		int getDato();
		void meter(int x);
		void sacar();
		void mostrar();
		void invertir();
		int mayor();
		int menor();
		int estaOrdenada();
		int estaOrdenada2();
		int posicion(int x);
		int posicion2(int x);
		void eliminarX(int x);
		void eliminary(int y);
		
		int getUltimo();
		void mezclarColas(Cola c2);
			
};	


	Cola::Cola(){
		frente=NULL;
		final=NULL;
	}
	
	int Cola::estaVacia(){  //CON QUE UN APUNTADOR APUNTE A NULO LA COLA ESTA VACIA
		return frente==NULL;
	}
	
	void Cola::meter(int x){
		Nodo *p;
		p= new Nodo();
		p->setDato(x);
		p->setSig(NULL);
		
		
		if (estaVacia()){
			frente = p;
			
			
		}else{
			final->setSig(p);
			
		}
		final =p;
		
		
	}
	
	void Cola::sacar(){
		Nodo *p;
		p=frente;
		
		frente=p->getSig();
		
		if(frente!=NULL)		
			
			frente=p->getSig();
			delete p;
		
			if(frente==NULL){
			
				final=NULL;
			}
	}
	
	int Cola::getDato(){
		if(estaVacia()){
			cout<<"Error en la cola getDato()\n";
			return -1;
			
		}else{
			return frente->getDato();
		}
	}
	
	//Destructor_____
	Cola::~Cola(){
			Nodo *p;
			p=frente;
			while(frente!=NULL){
				frente=p->getSig();
				delete p;
				p=frente;
			}
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
	
	
	
	int Cola::mayor(){
		Cola caux;
		int m;		
		if(estaVacia()){			
			cout<<"No hay elementos en mayor";
			return -1;
		
		}else{
			while(!estaVacia()){			
			caux.meter(getDato());
			sacar();
			
			if(getDato()>m){
				m=getDato();
				cout<<"m="<<m<<endl;
			}
		}
		while(!caux.estaVacia()){
			meter(caux.getDato());
			caux.sacar();
			}
		}
		return m;
	}
	
	
	int Cola::menor(){
		Cola caux;
		int minimo;		
		if(estaVacia()){			
			cout<<"No hay elementos en menor";
			return -1;
		
		}else{
			while(!estaVacia()){			
			caux.meter(getDato());
			sacar();
			
			if(getDato()<minimo){
				minimo=getDato();
				cout<<"minimo="<<minimo<<endl;
			}
		}
		while(!caux.estaVacia()){
			meter(caux.getDato());
			caux.sacar();
			}
		}
		return minimo;
	}
	
	

	
		
	int Cola::estaOrdenada(){
	
		if(estaVacia()){
			cout<<"No hay elementos";
			return -1;
		}else{
				Cola caux;
			int valor=getDato();
			while(!estaVacia()){
				caux.meter(getDato());
				sacar();
			
				if(getDato()<=valor){
					cout<<"Esta ordenada: "<<endl;
					return 1;
					
				}else{
					cout<<"No lo esta\n";
					return -1;
				}
			}
			while(!caux.estaVacia()){
				meter(caux.getDato());
				caux.sacar();
			}
		}
		
		
	}
	
	/*	int Cola::estaOrdenada2(){
	
		if(estaVacia())
			cout<<"No hay elementos";
			return -1;
				Cola caux;
				int band = 1;
			int valor=getDato();
			caux.meter(getDato());
				sacar();
			
			
			while(!estaVacia() && band){
				if(getDato()<=valor)
					band = 0;			
				
				valor=getDato();
				caux.meter(getDato());
				sacar();		
					if(estaVacia())
					return 1;
					
				}
				
				while(!estaVacia()){
					caux.meter(getDato());
					sacar();
				}
			
			while(!caux.estaVacia()){
				meter(caux.getDato());
				caux.sacar();
			}
			return band;
		
	}
	
		
		*/
	
	
	
	int Cola::posicion(int x){
		
		Cola caux;
		int contador=1;
		if(estaVacia()){
			cout<<"No existen elementos\n";
			return -1;
		}
			while(!estaVacia()){
				
				caux.meter(getDato());
				sacar();
		 	
				if(getDato()==x){
				
				contador++;
			}
				}
				while(!caux.estaVacia()){
				meter(caux.getDato());
				caux.sacar();
			}
			return contador;
		}
		
		
		int Cola::posicion2(int x){
		
		
		if(estaVacia()){
			cout<<"No existen elementos\n";
			return -1;
		}
		Cola caux;
		int contador=0;
		int band=0;
			while(!estaVacia() && !band){
				
				if(getDato()==x)
				
				band = 1;
			
				else
					contador ++;
				
				caux.meter(getDato());
				sacar();
		 	
				
				}
				while(!estaVacia()){
					caux.meter(getDato());
					sacar();
				}
				
				while(!caux.estaVacia()){
				meter(caux.getDato());
				caux.sacar();
			}
			if (band)
			return contador;
			else
			return -1;
		}
		

	
	void Cola::eliminarX(int x){
		Cola caux;
		if(estaVacia()){
			cout<<"No existen valores a sacar\n";
		}else{		
		
		while(!estaVacia()){
			if(getDato()==x){
				sacar();
				
				cout<<"El elemento Se ha eliminado"<<endl;
				}else{
					caux.meter(getDato());
					sacar();
				}
			}
			while(!caux.estaVacia()){
				meter(caux.getDato());
				caux.sacar();
			}
		}
	}
	
	//______________________________ eliminar y
	void Cola::eliminary(int y){
		if(estaVacia()){
			return;
			
			
		}
		Cola caux;
		int band=0;
		while(!estaVacia() && !band){
			if(y==getDato())
				band=1;
			else
				caux.meter(getDato());
				sacar();
		}
		while(!estaVacia()){
			caux.meter(getDato());
			sacar();
		}
		while(!caux.estaVacia()){
			meter(caux.getDato());
			caux.sacar();
		}		
	}
	
	
	void Cola::invertir(){
		if(!estaVacia()){
			int x = getDato();
			sacar();
			invertir();
			meter(x);
			
			mostrar();
		}
	}
	
	
	//_________________ 21/03/2018
	
	
	int Cola::getUltimo(){
		if(estaVacia()){
			cout<<" error en get Ultimo()";
			return -1;
		}
		Cola caux;
		int ultimo;
		
		while(!estaVacia()){
			caux.meter(getDato());
			ultimo=getDato();
			sacar();
			
		}
			while(!caux.estaVacia()){
				meter(caux.getDato());
				caux.sacar();
		}
		return ultimo;
		
	}
	
	
	
	void Cola::mezclarColas(Cola c2){
		Cola caux;
		while(!estaVacia()){   // Copiar cola original en auxiliar
			caux.meter(getDato());
			sacar();
		}
		
		while(!caux.estaVacia()  && !c2.estaVacia()){ // Mezcla siempre y cuando ambas colas tengan al menos un dato
			meter(caux.getDato());
			meter(c2.getDato());
			caux.sacar();
			c2.sacar();
		}
		while(!c2.estaVacia()){ 	//	Si se acaba la cola 1 terminas de bajar la c2
			meter(c2.getDato());
			c2.sacar();
		}
		while(!caux.estaVacia()){		// Si se acabo la cola 2 terminas de bajar la cola 1
			meter(caux.getDato());
			caux.sacar();
			
		}
			
	}
	
int main(){
	Cola cola1;
	Cola cola2;
	
	cola2.meter(100);
	cola2.meter(200);
	cola2.meter(300);
	
	int opcion;
	int elemento;
	int respuesta;
	
	do{
		cout<<"----Menu-----\n";
		cout<<"1.-Meter Elementos\n";
		cout<<"2.-Sacar\n";
		cout<<"3.-Mostrar Elementos\n";
		cout<<"4.-Invertir cola\n";
		cout<<"5.-Obtener mayor\n";
		cout<<"6.-Obtener menor\n";
		cout<<"7.-Esta ordenanda?\n";
		cout<<"8.-Devuelve posicion\n";
		cout<<"9.-Eliminar x\n";
		cout<<"10.- Eliminar Y\n";
		
		cout<<"11.- Invertir Cola\n";
		cout<<"12.- getUltimo\n";
		cout<<"13.- Mezclar colas\n";
	
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
					
					cola1.meter(elemento);
					
				
					
					
				}while(respuesta!=2);
				
					break;
				
				
				case 2:
					
				system("cls");
				
				cola1.sacar();
			
				break;	
				
				case 3:
				system("cls");
				
				cola1.mostrar();
				
					break;
					
				case 4:
					system("cls");
					
					
					
					break;
					
					case 5:
						system("cls");
						
						cout<<"El elemento mayor es: "<<cola1.mayor();
				
						break;
						
					case 6:
						system("cls");
						
						cout<<"El elemento menor es: "<<cola1.menor();
						
						break;
						
					case 7:
						system("cls");
						
						cout<<"Esta ordenadada? 1=SI,   -1=NO\n" <<cola1.estaOrdenada()<<endl;
						
						
						break;
						
					case 8:
						system("cls");
						cout<<"Que elemento quieres buscar su posicion? ";
						cin>>elemento;
						cout<<"Tu elemento x esta en la posición: "<<cola1.posicion2(elemento);
					
						break;
						
					case 9:
						system("cls");
						
					
						cout<<"Que elemento quieres eliminar?";
						cin>>elemento;
						
						cola1.eliminarX(elemento);
						
						break;
						
					case 10:
						system("cls");
					
						cout<<"Que elemento quieres eliminar?";
						cin>>elemento;
						
						cola1.eliminary(elemento);
						
						break;
						
					case 11:
						system("cls");
					
						cola1.invertir();
						
						break;
						
					case 12:
						system("cls");
					
						cout<<"El ultimo elemento de la cola es: "<<cola1.getUltimo();
						
						break;	
						
					case 13:
						system("cls");
					
						cout<<"Mezclar colas";
						
						cola1.mezclarColas(cola2);
						
						
						cola1.mostrar();
						
						
						break;				
						
					
					
				
	
				}
			
		}while(opcion!=14);
		
		getch();
		return 0;
		
	
	
	
}	
