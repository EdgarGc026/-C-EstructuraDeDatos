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
		
		void unidades();
		void decenas();
		void centenas();
		
		void ordenarUni();
		
		
			
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
   
   //OBTENER CIFRAS
   
   
   
	void Cola::unidades(){
		if(estaVacia()){
			cout<<"No hay datos en la cola\n";
		}
		
		Cola caux;	
		
		
	/*	int aux;
		int uni = getDato() %10; //unidades
		
		aux = getDato() - uni;
		
		aux = aux % 100; //decenas
		
		int decenas = aux/10;
		
		aux = getDato() -decenas*10 -uni;
		
		int centenas = aux/100; //centenas
			*/
		
		while(!estaVacia()){
			caux.meter(getDato() %10);
				
			sacar();
			
			
			
		
		}
		
		
	}
	
	

		
	
	
	void Cola::decenas(){
			if(estaVacia()){
			cout<<"No hay datos en la cola\n";
		}
		
		Cola caux;	
		
		int valor = getDato();
		int aux;
		int uni = getDato() %10; //unidades
		
		aux = getDato() - uni;
		
		aux = aux % 100; //decenas
		
		int dec = aux/10;
		
		aux = getDato() -dec*10 -uni;
		
		int centenas = aux/100; //centenas
			
		
		while(!estaVacia()){
			caux.meter(getDato());
				
			sacar();
			
			dec;
		
		}
		
		while(!caux.estaVacia()){
			meter(caux.getDato());
			caux.sacar();
			
			}
	}
	
	void Cola::centenas(){
			if(estaVacia()){
			cout<<"No hay datos en la cola\n";
		}
		
		Cola caux;	
		
		int valor = getDato();
		int aux;
		int uni = getDato() %10; //unidades
		
		aux = getDato() - uni;
		
		aux = aux % 100; //decenas
		
		int dec = aux/10;
		
		aux = getDato() -dec*10 -uni;
		
		int cen = aux/100; //centenas
			
		
		while(!estaVacia()){
			caux.meter(getDato());
				
			sacar();
			
			cen;
		
		}
		
		while(!caux.estaVacia()){
			meter(caux.getDato());
			caux.sacar();
			
			}
	}

	

	
int main(){
	//Cola original
	Cola colaOriginal;
	//Colas Auxiliares
	Cola cola0;
	Cola cola1;
	Cola cola2;
	Cola cola3;
	Cola cola4;
	Cola cola5;
	Cola cola6;
	Cola cola7;
	Cola cola8;
	Cola cola9;
	
	int uni;
	int dec;
	int cen;
	
	int arr[1000];
	int cantidad;
	
	cout<<"Cuantos numeros metera en la cola?\n";
	cin>>cantidad;
	
	for(int i=0;i<cantidad;i++){
		cout<<"ingrese un numero: ";
		cin>>arr[i];
	}	

	cout<<endl;
	
	for(int i=0;i<cantidad;i++){
		cout<<arr[i]<<" ";
	}
	
	
	
	//Calcular unidades, decenas y centenas
	for(int i=0;i<cantidad;i++){
		int aux;
		uni = arr[i] %10; //unidades
		
		aux = arr[i] - uni;
		
		aux = aux % 100; //decenas
		
		dec = aux/10;
		
		aux = arr[i] -dec*10 -uni;
		
		cen = aux/100; //centenas
	}
	//__________________________________
	
	
	
	

	colaOriginal.mostrar();
	
	
	
	
	 //Mandamos a llamar unidades y hacemos comparaciones;
	 
	
	colaOriginal.unidades();
			 for(int i=0;i<cantidad;i++){
					
					if(uni==0){
						cola0.meter(arr[i]);							
						
					}else if(uni==1){
						cola1.meter(arr[i]);
						
							}else if(uni==2){
							cola2.meter(arr[i]);
							
								}else if(uni==3){
								cola3.meter(arr[i]);
								
									}else if(uni==4){
									cola4.meter(arr[i]);
									
										}else if(uni==5){
										cola5.meter(arr[i]);
										
											}else if(uni==6){
											cola6.meter(arr[i]);
											
												}else if(uni==7){
												cola7.meter(arr[i]);
												
													}else if(uni==8){
													cola8.meter(arr[i]);
													
														}else if(uni==9){
														cola9.meter(arr[i]);
														}
					}
						cout<<"Cola1: ";
						cola1.mostrar();
						cout<<endl;
						
						cout<<"Cola2: ";
						cola2.mostrar();
						cout<<endl;
						
						cout<<"Cola3: ";
						cola3.mostrar();
						cout<<endl;
						
						cout<<"Cola4: ";
						cola4.mostrar();
						cout<<endl;
						
						cout<<"Cola5: ";
						cola5.mostrar();
						cout<<endl;
						
						cout<<"Cola6: ";
						cola6.mostrar();
						cout<<endl;
						
						cout<<"Cola7: ";
						cola7.mostrar();
						cout<<endl;
						
						cout<<"Cola8: ";
						cola8.mostrar();
						cout<<endl;
						
						cout<<"Cola9: ";
						cola9.mostrar();
						cout<<endl;
				
	
		
		getch();
		return 0;
		
	
	
	
}	
