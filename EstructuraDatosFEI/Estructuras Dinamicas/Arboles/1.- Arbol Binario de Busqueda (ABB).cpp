#include <iostream>
#include <conio.h>
typedef int tipo;

using namespace std;

class Nodo{
	Nodo *izq;
	Nodo *der;
	tipo dato;
	friend class Arbol;
	
public:
	Nodo();
	Nodo(tipo x);
		
};

Nodo::Nodo(){
	izq=NULL;
	der=NULL;
	dato=-1;
}

Nodo::Nodo(tipo x){
	izq=NULL;
	der = NULL;
	dato=x;
}
typedef Nodo *pNodo;


class Arbol{
	pNodo raiz;
public:
	Arbol();
	~Arbol();

	tipo getDato();
	int estaVacia();
	pNodo getRaiz();
	
	//complementarias
	void agregaNodo(tipo x,pNodo &p);
	void meter(tipo x);
	void eliminarNodo(tipo x, pNodo &p);
	void sacar(tipo x);
	tipo menor(pNodo p);
	tipo mayor(pNodo p);
	int estaX(tipo x, pNodo p);
	void preOrden(pNodo p);
	void inOrden(pNodo p);
	void postOrden(pNodo p);
	int esHoja(tipo x, pNodo p);
	int nivel(tipo x, pNodo p);
	int altura(pNodo p);
	int nNodos(pNodo p); //Contar nodos
};

Arbol::Arbol(){
	raiz=NULL;
}

int Arbol::estaVacia(){
	return raiz==NULL;
}

tipo Arbol::getDato(){
	if(estaVacia()){
		cout<<"Arbol vacio error en getDato()" << endl;
		return -1;
	}
	return raiz->dato;
}

pNodo Arbol::getRaiz(){
	return raiz;
}

tipo Arbol::menor(pNodo p){
	if(p==NULL){
		cout<<"No hay elementos en arbol";
		return -1;
	}if(p->izq==NULL)
		return p->dato;
	else
		return menor(p->izq);	
}

tipo Arbol::mayor(pNodo p){
	if(p==NULL){
		cout<<"No hay elementos en arbol";
		return -1;
	}
	else if(p->der==NULL)
	
		return p->dato;
		
		else
		return mayor(p->der);
			
}

void Arbol::agregaNodo(tipo x,pNodo &p){
	if(p==NULL)
		p=new Nodo(x);
		
	else if(x<p->dato)
		agregaNodo(x,p->izq);
		
		else if(x>p->dato)
		agregaNodo(x,p->der);
		
		else
		cout<<"El dato ya existe" << endl;
}

void Arbol::meter(tipo x){
	agregaNodo(x,raiz);
}

int Arbol::estaX(tipo x, pNodo p){
	if(p==NULL)
		return 0;
	
	if(p->dato == x)
		return 1;
		
	if(x < p->dato)
		return estaX(x, p->izq);
		
	else //
		return estaX(x, p->der);
}

void Arbol::eliminarNodo(tipo x, pNodo &p){
	if (p == NULL){
		return;
	}
	if (p->dato == x){ //encontre a x
		if (p->der == NULL){
			pNodo q;
			q = p;
			p = p->izq;
			delete q;
		}
		else if (p->izq == NULL){
			pNodo q;
			q = p;
			p = p->der;
			delete p;
		}
		else{
			tipo m = menor(p->der);
			p->dato = m;
			eliminarNodo(m, p->der)
		}
	}
	else if (x < p->dato)
		eliminarNodo(x, p->izq);
	
	else
		eliminarNodo(x, p->der);
}

/* void Arbol::eliminarNodo(tipo x, pNodo &p){
	if(p!=NULL){
		if(x==p->dato){ //Ya lo encontre
			if(p->izq==NULL){ //No tiene hijo izquierda
				pNodo q = p;
				p=p->der;
				delete q;
			}
			else if(p->der==NULL){
				pNodo q = p;
				p=p->izq;
				delete q;
			}
			
			else { //tiene ambos hijos
			tipo m= menor(p->der);
			p->dato=m;
			eliminarNodo(m,p->der);			
			}			
		
		}
			else if(x<p->dato)
				eliminarNodo(x,p->izq);
				
				else
				eliminarNodo(x,p->der);
	}
}
 */
void Arbol::sacar(tipo x){
	eliminarNodo(x,raiz);
}

void Arbol::preOrden(pNodo p){
	if(p!=NULL){
		cout<<p->dato<<", ";
		preOrden(p->izq);
		preOrden(p->der);
		
		
	}
}

void Arbol::inOrden(pNodo p){
	if(p!=NULL){
		
		inOrden(p->izq);
		cout<<p->dato<<", ";
		inOrden(p->der);
		
		
	}
}

void Arbol::postOrden(pNodo p){
	if(p!=NULL){
		
		postOrden(p->izq);
		postOrden(p->der);
		cout<<p->dato<<", ";
		
		
	}
}

int Arbol::nNodos(pNodo p){
	if(p==NULL){
		return 0;	
	}else
	return 1 + nNodos(p->izq) + nNodos(p->der);
	
}

int Arbol::nivel(tipo x, pNodo p){
	if(!estaX(x,p))
		return 0;
	if(p->dato == x)
		return 1;
	if(x < p->dato)
		return 1 + nivel(x,p->izq);
	else
		return 1+nivel(x, p->der);
}
	
	/* if(p==NULL){
		return 0;
		
	}else{
		if(p->dato == x){
			return 1;
		}
		
		else if(x<p->dato)
		return 1 + nivel(x,p->izq);
		
		else
		return 1 + nivel(x,p->der);	
		
	}	 */
}


//_____________________TAREA______________________
int Arbol::esHoja(tipo x, pNodo p){
	if(p==NULL)
		return 0;
	if(p->dato ==x){
		if(p->izq ==NULL && p->der ==NULL)
			return 1;
		else 
			return 0;
		}if(x < p->dato)
			return esHoja(x, p->izq);
		return esHoja(x,p->der);
}
	/* if(p!=NULL){
		while(p->dato!=x){
		
	 if(x<p->dato){
			return esHoja(x,p->izq);
				if(p->dato == x && p->izq == NULL && p->der == NULL){  
				cout<<"Es hoja";
				return 1;	
					
			}else if(x>p->dato)	
			
			return esHoja(x,p->der);			
					if(p->dato == x && p->izq == NULL && p->der == NULL)
						return 1;
						
	}else{
	
	cout<<"El elemento no es hoja\n";
	return 0;
			}
		}
	} */
}

int Arbol::altura(pNodo p){
	int alt1;
	int alt2;
	
	if(p==NULL){
		cout<<"Error en altura()\n";
		return 0;
	}else{
		
	alt1=altura(p->izq);		
	alt2=altura(p->der);
	
		if(alt1>alt2){
			return 1+altura(p->izq);
		}else{
			return 1+altura(p->der);
		}		
		
	}
	
}
 //_______________________________________________


int main(){
	
	Arbol arbol1;
	
	arbol1.meter(50);
	arbol1.meter(40);
	arbol1.meter(45);
	arbol1.meter(20);
	arbol1.meter(70);
	arbol1.meter(80);
	arbol1.meter(75);
	arbol1.meter(90);
	arbol1.meter(60);
	arbol1.meter(55);
	arbol1.meter(100);
	arbol1.meter(10);
	arbol1.meter(5);
	arbol1.meter(8);
	
	
	cout<<"El elemento menor es: "<<arbol1.menor(arbol1.getRaiz())<<endl;
	cout<<"El elemento mayor es: "<<arbol1.mayor(arbol1.getRaiz())<<endl;
	cout<<endl;
	
	cout<<"Pre-Orden\n";
	arbol1.preOrden(arbol1.getRaiz());
	cout<<endl;
	cout<<"In-Orden\n";
	arbol1.inOrden(arbol1.getRaiz());
	cout<<endl;
	cout<<"Post-Orden\n";
	arbol1.postOrden(arbol1.getRaiz());
	cout<<endl;
	cout<<endl;
	
	cout<<"Los nodos totales son: "<<arbol1.nNodos(arbol1.getRaiz())<<endl;
	
	
	cout<<"El nodo x esta en el nivel: "<<arbol1.nivel(45,arbol1.getRaiz())<<endl;

	cout<<"Es hoja? 1= SI  0 = NO"<<arbol1.esHoja(8,arbol1.getRaiz())<<endl;	
	
//	cout<<"Altura del arbol: "<<arbol1.altura(arbol1.getRaiz())<<endl;
	getch();
	return 0;
}


