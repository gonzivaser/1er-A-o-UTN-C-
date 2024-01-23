/*Dada una pila y un valor X colocar el valor x en la tercera posicion de la pila, retornando
un parámetro con valor 'S' o 'N' según haya sido exitoso o no el requerimiento. (Definir
parámetros y codificar).*/

#include<iostream>
#include<cstring>
using namespace std; 

/*----------STRUCTS------------*/
struct nodo {
    int info; 
    nodo* sgte; 
}; 

void push (nodo*&, int); 
int pop (nodo*&); 


/*--------------INT MAIN----------------*/
int main () {
    nodo* pila = NULL; 

    push(pila, 10);
    push(pila, 20);
    push(pila, 30);
    push(pila, 40);

    int valor_x; 
    cout << "Ingrese el valor X: "; 
    cin >> valor_x; 

    // SACO VALORES DE PILA HASTA QUE EL CONTADOR ESTE EN 3
    int i = 0; 
    while (pila != NULL && i != 3) {
        pop(pila); 
        i++; 
    }

    // METO EL VALOR "X" A LA PILA EN LA POSICION 3
    push(pila, valor_x); 

    // VUELVO A METER LOS VALORES 
    push(pila, 20); 
    push(pila, 30); 
    push(pila, 40); 

    // SACO LA PILA A VER SI FUNCIONA
    while(pila != NULL) {
        int aux = pop(pila); 
        cout << aux << endl; 
    }



    return 0; 
}


/*------------DECLARADAS--------------*/
void push (nodo*& pila, int x) {
    nodo* p = new nodo(); 

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