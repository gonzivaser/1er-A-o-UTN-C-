#include<iostream>
using namespace std; 


struct tp {
    int cp1; 
    int cp2; 
};

struct nodo {
    int info; 
    nodo* sgte; 
}; 

void push (nodo*&, int);  // METER 
int pop (nodo*&); // SACAR 


int main () {
    // INVOCACION DE FUNCIONES 
    nodo* pila = NULL; 
    
    push(pila, 10);
    push(pila, 20);
    push(pila, 30);
    push(pila, 40); 

    while(pila != NULL ) {
        cout << pop(pila) << endl; 
    }


    return 0; 
}


// PUSH SOLO PILA 
void push (nodo*& pila, int x) {
    
    // ARMAR EL NODO
    nodo* p = new nodo(); 

    // GUARDO LA INFO EN LA VARIABLE X
    p -> info = x; 
    p -> sgte = pila;

    // PILA LE PONGO LA DIRECCION DE P 
    pila = p; 

    return; 
}

// POP SOLO  
int pop (nodo*& pila) {

    int x; 
    nodo* p = pila; 

    // TENGO LA INFO 
    x = pila -> info; 

    pila = p -> sgte; 
    delete p; 


    return x; 
}