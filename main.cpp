///DIEGO DAYAN GUERRA 20152020024
///BRAYAN STEVEN ALDANA 20152020042

#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

struct Nodo{
	int dato;
	Nodo *ant;
	Nodo *sig;
};

class ListaDoble{
	Nodo *cab,*fin;
	//Métodos
	public:
		ListaDoble();
		void agregar(int);
		bool agregarIzquierda(int,int);
		bool agregarDerecha(int,int);
		int eliminarCabeza();
		void eliminarFin();
		bool eliminar(int);//elemento dado
		void ordenar();
		void mostrar();
		Nodo *buscar(int);
		bool vacia();
	
};

ListaDoble::ListaDoble(){
	cab=fin=NULL;
}

void ListaDoble::agregar(int dato){
	Nodo *p= new Nodo;
	p->dato=dato;
	p->sig=cab;
	if(cab){//si cab es diferente de nulo
		cab->ant=p;
	}else{
		fin=p;
	}
	p->ant=NULL;
	cab=p;
	
	
}


void ListaDoble::ordenar(){
	int aux,operaciones=0;
	Nodo *q = cab;		
	
	while(q!=NULL){
		Nodo *r = q->sig;
		while(r!=NULL){
			if((q->dato) > (r->dato)){
				aux=q->dato;
				(*q).dato = (*r).dato;
				(*r).dato = aux;
			}
			r=r->sig;
		}
		q=q->sig;		
	}
}



bool ListaDoble::agregarIzquierda(int dato, int elemento){
	Nodo *q=buscar(elemento);
	//Encontro el elemento
	if(q!=NULL){
		Nodo *r = new Nodo;
		(*r).dato=dato;
		(*r).sig=q;
		
		if((*q).ant==NULL){				
			(*r).ant=NULL;
			(*q).ant=r;
			cab=r;
		}
		else{
			Nodo *s=(*q).ant;
			(*s).sig=r;
			
		}
		return true;
	}
	return false;
}

bool ListaDoble::agregarDerecha(int dato, int elemento){
	Nodo *q=buscar(elemento);
	//Encontro el elemento
	if(q!=NULL){
		Nodo *r = new Nodo;
		(*r).dato=dato;
		(*r).ant=q;		
		if((*q).sig==NULL){				
			(*r).sig=NULL;			
			fin=r;
		}
		else{
			Nodo *s=(*q).sig;
			(*s).ant=r;
			(*r).sig=s;
					
		}
		(*q).sig=r;			
		return true;
	}
	return false;
}
	
void ListaDoble::mostrar(){
	Nodo *p=cab;
	while(p!=NULL){ //while(p)
		cout<<p->dato<<" ";
		p=p->sig;
	
	}
}

Nodo *ListaDoble::buscar(int elemento){
	int k=0;
	Nodo *q = cab;	
	while(q!=NULL){				
		if((*q).dato == elemento){
			return q;			
		}
		k++;
		q=(*q).sig;
	}
	return q;
}
	
bool ListaDoble::vacia(){
	return cab==NULL;
}

int ListaDoble::eliminarCabeza(){//
	int num;
	Nodo *p=cab;
	Nodo *r;
	if(p==NULL){
		return -1;
	}else{
		r=p->sig;
		num=p->dato;
		cab=r;
		delete p;
		return num;
	}
}

void ListaDoble::eliminarFin(){
	Nodo *q = fin;
	if(q!=NULL){
		if((*q).ant!=NULL){
			Nodo *r = (*q).ant;		
			(*r).sig=NULL;
			fin=r;
		}
		else{
			fin=NULL;
			cab=NULL;
			delete q;
		}		
	}
	
}

bool ListaDoble::eliminar(int dato){//elimina elemento dado
	Nodo *p;	
	Nodo *r;
	Nodo *q=buscar(dato);
	if(q!=NULL){
		if((*q).ant==NULL && (*q).sig==NULL){
			cab=NULL;			
		}
		else if((*q).ant==NULL){
			p=(*q).sig;
			(*p).ant=NULL;
			cab=p;			
		}
		else if((*q).sig==NULL){			
			p=(*q).ant;			
			(*p).sig=NULL;			
		}		
		else{
			r=(*q).ant;
			p=(*q).sig;
			(*r).sig=p;
			(*q).ant=r;							
		}
		delete q;
		return true;
	}	
	return false;
}

	
char menuLista();
char menuAgregar();
char menuEliminar();

int main(int argc, char** argv) {
	ListaDoble lista;
	char opcion;
	int dato,posicion, elemento;
	do{
		opcion= menuLista();
		switch(opcion){
			case 'a':
			case 'A':{
				do{
					opcion= menuAgregar();
					if(opcion=='c' || opcion=='C'){
						cout<<"Digite el elemento a agregar: ";						
						cin>>dato;
						lista.agregar(dato);
						lista.mostrar();
					}else if(opcion=='i' || opcion=='I'){
						cout<<"Digite el dato a agregar: ";						
						cin>>dato;
						cout<<"Digite el elemento a agregar a la izquierda: ";						
						cin>>elemento;
						if(lista.agregarIzquierda(dato,elemento) == true){
							cout<<"Se agrego el elemeto correctamente\n";
						}
						else{
							cout<<"No se encontro el elemento referencia\n";
						}
						lista.mostrar();
					}else if(opcion=='d' || opcion=='D'){
						cout<<"Digite el dato a agregar: ";						
						cin>>dato;
						cout<<"Digite el elemento a agregar a la derecha: ";						
						cin>>elemento;
						if(lista.agregarDerecha(dato,elemento) == true){
							cout<<"Se agrego el elemeto correctamente\n";
						}
						else{
							cout<<"No se encontro el elemento\n";
						}
					}
				}while(opcion != 'r' && opcion != 'R');
				
				break;
			}
			case 'e':
			case 'E':{
				do{
					opcion= menuEliminar();
					if(opcion=='f' || opcion=='F'){
						cout<<"Se elimino el elemento final "<<endl;
						lista.eliminarFin();
		
						
					}else if(opcion=='c' || opcion=='C'){
						int resultado;
						resultado=lista.eliminarCabeza();
						if(resultado!=(-1)){
							cout<<"Se elimino el elemento: "<<resultado<<endl;
						}else{
							cout<<"No hay elementos a eliminar"<<endl;
						}
					}else if(opcion=='e' || opcion=='E'){
						cout<<"Ingrese dato a eliminar: ";
						cin>>dato;
						if(lista.eliminar(dato)){
							cout<<"El elemento se ha eliminado"<<endl;
						}else{
							cout<<"El elemento a eliminar no se encuentra en la lista."<<endl;
						}
					}
				}while(opcion != 'r' && opcion != 'R');
				break;
			}
			case 'b':
			case 'B':{
				cout<<"Digite el elemento a buscar: ";
				cin>>dato;
				if(lista.buscar(dato)!=NULL){
					cout<<"Se encontro el elemento"<<endl;
				}else{
					cout<<"No se encontro el elemento"<<endl;
				}
				break;
			}
			case 'o':
			case 'O':{
				cout<<"Se ordenara la lista"<<endl;
				lista.ordenar();
				break;
				
			}
			case 'm':
			case 'M':{
				cout<<"Los elementos almacenados son: \n ";										
				lista.mostrar();
				break;
			}
			case 't':
			case 'T':{
				break;
			}
		}
	}while(opcion != 't' && opcion != 'T');
	return 0;
}

char menuLista(){
	char opcion;
	cout<<"\n\tMENU LISTA\n";
	cout<<"(A)gregar\n";
	cout<<"(E)liminar\n";
	cout<<"(B)uscar\n";
	cout<<"(O)rdenar\n";
	cout<<"(M)ostrar\n";
	cout<<"(T)erminar\n";
	
	cin>>opcion;
	return opcion;
}

char menuAgregar(){
	char opcion;
	cout<<"\n\tMENU AGREGAR\n";
	cout<<"Agregar por la (c)abeza\n";
	cout<<"A la (i)zquierda de\n";
	cout<<"A la (d)erecha de\n";
	cout<<"(R)egresar\n";
	
	cin>>opcion;
	return opcion;
}

char menuEliminar(){
	char opcion;
	cout<<"\n\tMENU Eliminar\n";
	cout<<"El del (f)inal\n";
	cout<<"El de la (c)abeza\n";
	cout<<"(E)lemento dado.\n";
	cout<<"(R)egresar\n";
	
	cin>>opcion;
	return opcion;
}

