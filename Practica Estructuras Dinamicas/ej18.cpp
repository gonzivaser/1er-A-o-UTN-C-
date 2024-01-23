/*Dadas dos listas LISTA y LISTB (nodo = registro + puntero), desarrollar y codificar un
procedimiento que genere una única lista LISTC a partir de ellas. (Primero los nodos de LISTA
y luego los de LISTB).*/

#include<iostream>
using namespace std; 

/*--------------STRUCTS----------------*/
struct nodo {
    int info; 
    nodo* sgte; 
};

// FUNCIONES DE LISTA
nodo* InsertarOrdenado(nodo*&, int);
int pop(nodo*&);

// FUNCIONES DE CARGAR LISTA
void CargarListaA (nodo*&, nodo*&); 
void CargarListaB (nodo*&, nodo*&); 

// FUNCION DE MOSTRAR LA LISTA
void MostrarLista (nodo*&); 


/*--------------INT MAIN----------------*/
int main () {
    nodo* listaA = NULL; 
    nodo* listaB = NULL; 
    nodo* listaC = NULL; 

    // CARGO LA LISTA C CON LOS VALORES DE LA A 
    CargarListaA(listaA, listaC); 

    // CARGO LA LISTA C CON LOS VALORES DE LA B
    CargarListaB(listaB, listaC); 

    // MUSTRO LA LISTA C
    MostrarLista(listaC); 

    return 0; 
}


/*--------------DECLARADAS----------------*/
void MostrarLista (nodo*& listaC) {
    while (listaC != NULL) {
        cout << pop(listaC) << endl; 
    }
}


void CargarListaB (nodo*& listaB, nodo*& listaC) {
    int input; 
    cout << "Ingrese el valor que quiere ingresar a la lista B (-1 para terminar): "; 
    cin >> input; 

    while (input > -1) {
        InsertarOrdenado(listaC, input); 

        cout << "Ingrese el valor que quiera ingresar a la lista B (-1 para terminar): "; 
        cin >> input; 
    }
    cout << endl; 
}


void CargarListaA (nodo*& listaA, nodo*& listaC) {
    int input; 
    cout << "Ingrese el valor que quiere ingresar a la lista A (-1 para terminar): "; 
    cin >> input; 

    while (input > -1) {
        InsertarOrdenado(listaC, input); 

        cout << "Ingrese el valor que quiera ingresar a la lista A (-1 para terminar): "; 
        cin >> input; 
    }
    cout << endl; 
}


nodo* InsertarOrdenado (nodo*& lista, int info) {
    nodo* aux = new nodo(); 
    aux -> info = info; 
    aux -> sgte = NULL; 

    // 1 Y 2 SI ESTA VACIA O ES MENOR QUE EL PRIMERO 
    if (lista == NULL || info < lista -> info) {
        aux -> sgte = lista; 
        lista = aux; 
    }
    else {
        // VA EN EL MEDIO O AL FINAL 
        // TENGO QUE BUSCAR DONDE VA 
        nodo* q = lista; 
        while (q -> sgte != NULL && q -> sgte -> info < info) {
            q = q -> sgte; 
        }
        aux -> sgte = q -> sgte; 
        q -> sgte = aux; 
    }

    return aux; 
}


int pop (nodo*& pila) {
    int x; 
    nodo* p = pila; 

    x = pila -> info; 
    pila = p -> sgte; 
    
    delete p; 
    return x; 
}