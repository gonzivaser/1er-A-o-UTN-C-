/*Definir una función INVERSA que evalúe dos conjuntos de caracteres separados por un
punto y retorne True si los conjuntos son inversos (ej: ABcDe.eDcBA) o False si no lo son. Los
conjuntos deben ingresarse por teclado. (Definir parámetros y codificar).*/

#include<iostream>
using namespace std; 

/*--------------STRUCTS----------------*/
struct nodo {
    char dato[50]; 
    nodo* sgte; 
};

void push (nodo*&, char); 
char pop(nodo*&); 


/*--------------INT MAIN----------------*/
int main () {
    nodo* pila = NULL; 

    
    return 0; 
}


/*--------------DECLARADAS----------------*/
void push (nodo*& pila, char letra) {
    nodo*p = new nodo(); 

    p -> dato = letra; 
    p -> sgte = pila; 
    pila = p; 

    return; 
}

char pop (nodo*& pila) {
    char letra; 
    nodo* p = pila; 

    letra = pila -> dato; 
    pila = p -> sgte; 
    
    delete p; 
    return letra; 
}
