/*Dada una pila desarrollar un procedimiento que ordene la misma de acuerdo al valor de
sus nodos y la retorne. Solo se deben usar pilas. (Definir parámetros y codificar).*/

#include<iostream>
using namespace std; 

/*--------------STRUCTS----------------*/
struct nodo {
    int info; 
    nodo* sgte; 
};

void push (nodo*&, int); 
int pop(nodo*&); 
void CargarPila(nodo*&); 
void MostrarPila(nodo*&);

void OrdenarPila(nodo*&);

/*--------------INT MAIN----------------*/
int main () {
    nodo* pila = NULL; 

    // CARGO LA PILA 
    CargarPila(pila); 

    // ORDENO LA PILA 
    OrdenarPila(pila);

    // MUESTRO LA PILA
    MostrarPila(pila); 
   
}


/*--------------DECLARADAS----------------*/
void OrdenarPila (nodo*& pila) {

    // CREO PILA AUXILIAR 
    nodo* aux = NULL;

    // ORDENO LA PILA 
    while (pila != NULL) {
        int valor_actual = pop(pila); 

        while (aux != NULL  && valor_actual < aux -> info) {
            push(pila, pop(aux)); 
        }

        push(aux, valor_actual); 
    }

    // CAMBIO A LA PILA ORIGINAL 
    while (aux != NULL) {
        push(pila, pop(aux)); 
    }

}


void MostrarPila (nodo*& pila) {
    while (pila != NULL) {
        cout << pop(pila) << endl; 
    }
}


void CargarPila (nodo*& pila) {

    int input; 
    cout << "Ingrese el valor a cargar en la pila: "; 
    cin >> input; 

    while (input > -1) {
        push(pila, input); 

        cout << "Ingrese el valor a cargar en la pila (-1 para terminar): "; 
        cin >> input; 
    }

    cout << endl; 
}


void push (nodo*& pila, int x) {
    nodo*p = new nodo(); 

    p -> info = x; 
    p -> sgte = pila; 
    pila = p; 

    return; 
}


int pop (nodo*& pila) {
    int x; 
    nodo* p = pila; 

    x = pila -> info; 
    pila = p -> sgte; 
    
    delete p; 
    return x; 
}
