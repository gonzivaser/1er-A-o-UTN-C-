/*Dada una cola (nodo = registro + puntero), desarrollar y codificar una función que devuelva
la cantidad de nodos que tiene. */

#include<iostream>
#include<cstring>
using namespace std; 

/*--------------STRUCTS----------------*/
struct nodo {
    int info; 
    nodo* sgte; 
};

void queue(nodo*&, nodo*&, int); 
int unqueue(nodo*&, nodo*&); 

void CargarCola(nodo*&, nodo*&); 
void MostrarCola(nodo*&, nodo*&); 

/*--------------INT MAIN----------------*/
int main () {
    nodo* fte = NULL; 
    nodo* fin = NULL; 

    // CARGO LA COLA 
    CargarCola(fte, fin); 


    // MUESTRO LA COLA CON LAS CONDICIONES
    MostrarCola(fte, fin); 

    return 0; 
}

/*--------------DECLARADAS----------------*/
void MostrarCola (nodo*& fte, nodo*& fin) {
    
    // INICIALIZO CONTADOR PARA VER CUANTOS NODOS HAY
    // CREO COLA AUXILIAR PARA RECORRER  
    int i = 0; 
    nodo* aux = fte; 

    while (aux != NULL) {
        i++; 
        aux = aux -> sgte;
    }

    // MUESTRO LA CANTIDAD DE NODOS QUE TIENE LA COLA CON EL CONTADOR  
    cout << "La cantidad de nodos que tiene la cola es: " << i << endl; 
}


void CargarCola (nodo*& fte, nodo*& fin) {
    
    int input; 
    cout << "Ingrese el valor que quiere ingresar a la cola (-1 para terminar): "; 
    cin >> input; 

    while (input > -1) {
        queue(fte, fin, input); 

        cout << "Ingrese el valor que quiere ingresar a la cola (-1 para terminar): ";
        cin >> input; 
    }

    cout << endl; 

}


void queue (nodo*& fte, nodo*& fin, int info) {
	
    nodo* p = new nodo();
	p->info = info;
	p->sgte = NULL; 
	
    if (fte == NULL) { 
		fte = p;
	} else {
		fin->sgte = p;
	}
	
    fin = p;	
	
    return;
}


int unqueue (nodo*& fte, nodo*& fin) {

    int x; 
    nodo* p = fte; 
    x = fte->info; 
    fte = p->sgte; 

    if (fte == NULL) {
        fin = NULL; 
    }

    delete p; 
    return x; 
}