/*Dadas dos colas COLA y COLB (nodo = registro + puntero), desarrollar y codificar un
procedimiento que genere una única cola COLAB a partir de ellas. (Primero los nodos de
COLA y luego los de COLB).*/

#include<iostream>
using namespace std; 

/*--------------STRUCTS----------------*/
struct nodo {
    int info; 
    nodo* sgte;
};

// FUNCIONES DE COLA 
void queue(nodo*&, nodo*&, int); 
int unqueue(nodo*&, nodo*&); 

// FUNCIONES DE CARGA
void CargarColaA(nodo*&, nodo*&, nodo*&, nodo*&); 
void CargarColaB(nodo*&, nodo*&, nodo*&, nodo*&); 

// FUNCIONES DE MOSTRAR 
void MostrarCola(nodo*&, nodo*&); 


/*--------------INT MAIN----------------*/
int main () {
    nodo* fteA = NULL; 
    nodo* finA = NULL; 
    nodo* fteB = NULL; 
    nodo* finB = NULL;
    nodo* fteC = NULL; 
    nodo* finC = NULL;

    // CARGO COLA A EN COLA C 
    CargarColaA(fteA, finA, fteC, finC); 

    // CARGO COLA B EN COLA C 
    CargarColaB(fteB, finB, fteC, finC); 

    // MOSTRAR COLA C 
    MostrarCola(fteC, finC); 


    return 0; 
}


/*--------------DECLARADAS----------------*/
void MostrarCola (nodo*& fteC, nodo*& finC) {
    while (fteC != NULL) {
        int aux = unqueue(fteC, finC); 
        cout << "La cola C compuesta primero por la A y luego por la B es: " << aux << endl; 
    }
}


void CargarColaB (nodo*& fteB, nodo*& finB, nodo*& fteC, nodo*& finC) {
    
    int input; 
    cout << "Ingrese el valor que quiere ingresar a la cola B (-1 para terminar): "; 
    cin >> input; 

    while (input > -1) {
        queue(fteC, finC, input); 

        cout << "Ingrese el valor que quiere ingresar a la cola B (-1 para terminar): ";
        cin >> input; 
    }

    cout << endl; 

}


void CargarColaA (nodo*& fteA, nodo*& finA, nodo*& fteC, nodo*& finC) {
    
    int input; 
    cout << "Ingrese el valor que quiere ingresar a la cola A (-1 para terminar): "; 
    cin >> input; 

    while (input > -1) {
        queue(fteC, finC, input); 

        cout << "Ingrese el valor que quiere ingresar a la cola A (-1 para terminar): ";
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