/*Dada una pila y dos valores X e I, desarrollar un procedimiento que inserte el valor X en la
posición I de la pila si es posible. (Definir parámetros y codificar).*/

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


/*--------------INT MAIN----------------*/
int main () {
    nodo* pila = NULL; 
    
    // ARMO PILA 
    push(pila, 10);
    push(pila, 20);
    push(pila, 30);
    push(pila, 40);


    // PREGUNTO AL USUARIO QUE VALOR QUIERE Y EN QUE POSICION 
    int valor_X; 
    cout << "Que valor quiere ingresar: ";
    cin >> valor_X;  

    int valor_I; 
    cout << "En que posicion lo quiere (1 a 4): "; 
    cin >> valor_I; 


    // SACO LA PILA HASTA QUE SE IGUALE AL VALOR I Y LOS GUARDO EN PILA TEMPORAL
    nodo* pila_temporal = NULL; 
    int i = 0; 
    while (pila != NULL && i != valor_I) {
        push(pila_temporal, pop(pila)); 
        i++; 
    }

    // METO EL VALOR X 
    push(pila, valor_X); 


    // METO LOS VALORES RESTANTES QUE SAQUE POR EL VALOR X
    while (pila_temporal != NULL) {
        push (pila, pop(pila_temporal)); 
    }


    // SACO LA PILA A VER SI FUNCIONA 
    while (pila != NULL) {
        int aux = pop(pila); 
        cout << aux << endl; 
    }

    return 0; 
}


/*--------------DECLARADAS----------------*/
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
