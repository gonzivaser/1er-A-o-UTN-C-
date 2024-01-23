/*Dada una pila y un valor X, desarrollar un procedimiento que inserte el valor X en la última
posición de la pila y la retorne. (Definir parámetros y codificar).*/ 

#include<iostream>
#include<cstring>
using namespace std; 

/*--------------STRUCTS----------------*/
struct nodo {
    int info; 
    nodo* sgte; 
}; 

void push (nodo*&, int); 
int pop(nodo*&); 
void MeterValorX(nodo*&, int); 


/*--------------INT MAIN----------------*/
int main () {
    nodo* pila = NULL; 
    
    // ARMO PILA 
    push(pila, 10);
    push(pila, 20);
    push(pila, 30);
    push(pila, 40);


    // PREGUNTO AL USUARIO EL VALOR X
    int valor_X; 
    cout << "Valor X: "; 
    cin >> valor_X; 

    // APLICO FUNCION PARA METER EL VALOR X
    MeterValorX(pila, valor_X); 

    // MUESTRO LA PILA PARA VER SI FUNCIONA 
    while (pila != NULL) {
        int aux = pop(pila); 
        cout << aux << endl; 
    }



    return 0; 
}


/*--------------DECLARADAS----------------*/
void MeterValorX(nodo*& pila, int x) {

    // SACO LA PILA HASTA LA ULTIMA POSICION Y LOS GUARDO EN PILA TEMPORAL
    nodo* pila_temporal = NULL; 
    while (pila != NULL) {
        push (pila_temporal, pop(pila)); 
    }

    // METO EL VALOR X EN LA PILA PARA QUE QUEDE EN LA ULTIMA POSICION 
    push(pila, x); 

    // PASO DE VUELTA DE PILA TEMPORAL A LA PILA 
    while (pila_temporal != NULL) {
        push (pila, pop(pila_temporal)); 
    }

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
