#include <iostream>
#include <conio.h>

using namespace std;

struct alumno{
	string matricula;
	string nombre;
	float calificacion;
};

typedef alumno tipo;

class Nodo{
	Nodo * izq;
	Nodo * der;
	alumno dato;
	public:
		Nodo();
		Nodo(tipo x);
		friend class Arbol;
};

Nodo::Nodo(){
	izq = NULL;
	der = NULL;
	alumno al;
	al.nombre = " ";
	al.matricula = " ";
	al.calificacion;
	dato=al;
}

Nodo::Nodo(tipo x){
	izq = NULL;
	der = NULL;
	alumno al;
	al.nombre = x.nombre;
	al.matricula = x.matricula;
	al.calificacion = x.calificacion;
	dato=al;
}

typedef Nodo * pNodo;

class Arbol{
	pNodo raiz;
	public:
		Arbol();
		tipo getDato();
		int estaVacia();
		pNodo getRaiz(); 
		void agregarNodo(tipo x, pNodo & p);
		void meter(tipo x);
		
		tipo menor(pNodo p);
		void eliminarNodo(tipo x, pNodo &p);
		void sacar(tipo x);
		
	    //complementarios
		
		tipo mayor(pNodo p);
		void preOrden(pNodo p);
		void inOrden(pNodo p);
		void postOrden(pNodo p);
		int esHoja(tipo x, pNodo p);
		int estaX(tipo x, pNodo p);
		int nivel(tipo x, pNodo p);
		int altura(pNodo p);
		int nNodos(pNodo p); //Contar nodos
		
		tipo estaX2(tipo x, pNodo p);
		
};

Arbol::Arbol(){
	raiz = NULL;
	
}

int Arbol::estaVacia(){
	return raiz==NULL;
}

tipo Arbol::getDato(){
	if(estaVacia()){
		cout<<"Arbol vacio";
	}
	return raiz->dato;
}



pNodo Arbol::getRaiz(){
	return raiz;
}

tipo Arbol::menor(pNodo p){
	if(p==NULL){
		cout << "no hay elementos en el arbol";
		alumno al;
		return al;
	}
	if(p->izq==NULL)
		return p->dato;
	else
		return menor(p -> izq);
}

void Arbol::agregarNodo(tipo x, pNodo & p){
	if(p==NULL)
		p=new Nodo(x);
	else if(x.matricula<p->dato.matricula){
		agregarNodo(x,p->izq);
		}else if(x.matricula>p->dato.matricula){
			agregarNodo(x,p->der);

		}
	}
	
void Arbol::meter(tipo x){
	agregarNodo(x,raiz);
}

int Arbol::estaX(tipo x,pNodo p){
	if (p==NULL)
		return 0;
	else{
		if(x.matricula<p->dato.matricula)
			return estaX(x,p->izq);
		else{
			if(x.matricula>p->dato.matricula)
				return estaX(x,p->der);
			else
				return 1;
		}
	}
}

tipo Arbol::estaX2(tipo x,pNodo p){
	if (p==NULL){
		cout <<"Error en estaX2()"<< endl;
		alumno al;
		return al;
	}else{
		if(x.matricula==p->dato.matricula)
			return p->dato;
		else{
			if(x.matricula<p->dato.matricula)
				return estaX2(x,p->izq);
			else
				return estaX2(x,p->der);
		}
	}
}

void Arbol::eliminarNodo(tipo x, pNodo & p){
	if (p!=NULL){
		if(x.matricula==p->dato.matricula){
			if (p->izq==NULL){
				pNodo q = p;
				p=p->der;
				delete q;
			}else{
				if(p->der==NULL){
					pNodo q=p;
					p=p->izq;
					delete q;
				}else{
					tipo m=menor(p->der);
					p->dato=m;
					eliminarNodo(m,p->der);
				}
			}
		}else{
			if(x.matricula<p->dato.matricula)
				eliminarNodo(x,p->izq);
			else
				eliminarNodo(x,p->der);
		}
	}
}

void Arbol::sacar(tipo x){
	eliminarNodo(x,raiz);
}

void Arbol::preOrden(pNodo p){
	if(p!=NULL){
		cout<<p->dato.matricula<<", "<<p->dato.nombre<<", "<<p->dato.calificacion<<" "<<" | ";
		preOrden(p->izq);
		preOrden(p->der);
	}
}

void Arbol::inOrden(pNodo p){
	if(p!=NULL){
		inOrden(p->izq);
		cout<<p->dato.matricula<<", "<<p->dato.nombre<<", "<<p->dato.calificacion<<" "<<" | ";
		inOrden(p->der);
	}
}

void Arbol::postOrden(pNodo p){
	if(p!=NULL){
		postOrden(p->izq);
		postOrden(p->der);
		cout<<p->dato.matricula<<", "<<p->dato.nombre<<", "<<p->dato.calificacion<<" "<<" | ";
	}
}

int main(){	
	Arbol arbol1;

	int elemento;
	int opcion;
	int respuesta;
	
	do{
		cout<<"-----MENU-----\n";
		cout<<"1.- Registrar Alumno\n";
		cout<<"2.- Eliminar Alumno (Por matricula)\n";
		cout<<"3.- Mostrar en Pre-Orden\n";
		cout<<"4.- Mostrar en In-Orden\n";
		cout<<"5.- Mostrar en Post-Orden\n";
		cout<<"6.- Consultar nombre (Por matricula)\n";
		cout<<"7.- Consultar calificacion (Por matricula)\n";
		cout<<"8.- Salir\n";
		
		cout<<endl;
		cout<<"Que quieres hacer?\n";
		cin>>opcion;
		cout<<endl;
		
		alumno alu;
		
		switch(opcion){
		
			case 1:
			system ("cls");
			
			do{					
					cout<<"Ingresa su matricula: \n";
					cin>>alu.matricula; 
					
					cout<<"Ingresa su nombre: \n";
					cin>>alu.nombre;
					
					cout<<"Ingresa su calificacion: \n";
					cin>>alu.calificacion; 
					
					cout<<"Quieres meter otro alumno:  1.-SI  2.-NO \n";
					cin>>respuesta;
					
					arbol1.meter(alu);				
					
				}while(respuesta!=2);
		
			break;
			
			case 2:
				
				do{
				
				cout<<"Que alumno quieres eliminar?\n  Ingresa matricula  (DEBE DE ESTAR BIEN ESCRITA): ";
				cin>>alu.matricula;
				
				if(!arbol1.estaX(alu,arbol1.getRaiz())){
					cout<<"No existe el alumno que quieres eliminar\n";
				}
				
				cout<<"Quieres eliminar otro alumno:  1.-SI  2.-NO \n";
					cin>>respuesta;
				
				arbol1.sacar(alu);
				
				}while(respuesta!=2);
				
				break;
				
			case 3:
				
				arbol1.preOrden(arbol1.getRaiz());
				break;
				
			case 4:
				arbol1.inOrden(arbol1.getRaiz());
				break;
				
			case 5:
				arbol1.postOrden(arbol1.getRaiz());
				break;
				
			case 6:
				cout<<"Matricula: ";
				cin>>alu.matricula;
				
				if(arbol1.estaX(alu,arbol1.getRaiz())){
					alu=arbol1.estaX2(alu,arbol1.getRaiz());
					cout<<alu.nombre<<endl;
				}else
					cout<<"El alumno no existe\n";
					
					break;
					
			case 7:
			
				cout<<"Matricula: ";
				cin>>alu.matricula;	
				if(arbol1.estaX(alu, arbol1.getRaiz())){
					alu=arbol1.estaX2(alu,arbol1.getRaiz());
					cout<<alu.calificacion<<endl;
				}else
					cout<<"El alumno no existe\n";
					break;	
					
			case 8:
				break;		
						
	}		
		
	}while(opcion!=8);	
	
	getch();
	return 0;
}
