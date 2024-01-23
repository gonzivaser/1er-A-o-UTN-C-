/*Desarrollar un procedimiento que ingrese por teclado un conjunto de Apellidos y Nombre
de alumnos y los imprima en orden inverso al de ingreso. (Definir parámetros y codificar).*/

#include<iostream>
#include<cstring>
using namespace std; 

/*----------STRUCTS------------*/
struct persona {
    char nombre[50]; 
    char apellido[50]; 
};

struct nodo {
    persona info; 
    nodo* sgte; 
}; 

void push (nodo*&, persona);  // METER 
persona pop (nodo*&); // SACAR 


/*--------------INT MAIN----------------*/
int main () {
    persona al; 
    nodo* pila = NULL; 

    cout << "Ingrese el nombre: "; 
    cin >> al.nombre; 

    while(strcmp(al.nombre, "x") != 0) {
        cout << "Ingrese el apellido: "; 
        cin >> al.apellido; 

        push(pila, al);

        cout << "Ingrese el nombre: "; 
        cin >> al.nombre; 
    }

    while(pila != NULL) {
        persona nom = pop(pila);  

        cout << nom.nombre << endl; 
        cout << nom.apellido << endl; 
    }

    return 0; 
}


/*------------DECLARADAS--------------*/
void push (nodo*& pila, persona x) {
    nodo* p = new nodo(); 

    p -> info = x; 
    p -> sgte = pila; 
    pila = p; 

    return; 
}

persona pop (nodo*& pila) {
    persona x; 
    nodo* p = pila; 

    x = pila -> info; 
    pila = p -> sgte; 
    delete p; 

    return x; 
}