/*Dada una lista (nodo = registro + puntero), desarrollar y codificar una función que devuelva
la cantidad de nodos que tiene. */

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

// FUNCIONES DE CARGA Y MOSTRAR
void CargarLista(nodo*&); 
void MostrarLista(nodo*&); 

/*--------------INT MAIN----------------*/
int main () {
    nodo* lista = NULL; 

    // CARGO LISTA
    CargarLista(lista); 

    // MUESTRO LA LISTA
    MostrarLista(lista); 
    

    return 0; 
}


/*--------------DECLARADAS----------------*/
void MostrarLista (nodo*& lista) {

    int i = 0; 
    while (lista != NULL) {
        cout << pop(lista) << endl; 
        i++; 
    }

    cout << "Cantidad de nodos que tiene es : " << i << endl; 

}


void CargarLista (nodo*& lista) {
    int input; 
    cout << "Ingrese el valor que quiere ingresar a la lista (-1 para terminar): "; 
    cin >> input; 

    while (input > -1) {
        InsertarOrdenado(lista, input); 

        cout << "Ingrese el valor que quiera ingresar a la lista (-1 para terminar): "; 
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
