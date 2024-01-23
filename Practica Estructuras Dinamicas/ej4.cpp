/*Dada una pila y dos valores X e Y, desarrollar un procedimiento que reemplace cada valor
igual a X que se encuentre en la pila por el valor Y retornando la pila modificada. En caso
de no haber ningún valor igual a X retornar la pila sin cambio. (Definir parámetros y
codificar).*/

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
void Remplazar(nodo*&, int, int);


/*--------------INT MAIN----------------*/
int main () {
    nodo* pila = NULL; 

    // PREGUNTO AL USUARIO VALOR X e Y
    int valor_x; 
    cout << "Ingrese valor por el que quiere remplazar: "; 
    cin >> valor_x;

    int valor_y; 
    cout << "Ingrese el valor por el que quiere remplazar al ingresado: "; 
    cin >> valor_y; 

    // ARMO PILA 
    CargarPila(pila); 

    // REMPLAZO POR VALORES 
    Remplazar(pila, valor_x, valor_y); 

    // MUESTRO LA PILA PARA VER SI FUNCIONA
    MostrarPila(pila); 

    return 0; 
}


/*--------------DECLARADAS----------------*/

void Remplazar (nodo*& pila, int valRemplazar, int valFinal) {
    
    // DECLARO PILA AUXILIAR 
    nodo* aux = NULL; 

    // SACO LA PILA Y LA CARGO EN UNA AUXILIAR 
    while (pila != NULL) {
        int valor_actual = pop(pila); 

        // SI ALGUN VALOR ES IGUAL AL X Y LO REMPLAZA POR EL VALOR Y
        // DE NO SER ASI, CARGA CON EL RESTO DE VALORES 
        if(valor_actual == valRemplazar) {
            push(aux, valFinal); 
        } 
        else {
            push(aux, valor_actual); 
        }
    }

    // VUELVO A CARGAR LA PILA ORIGINAL CON LA AUXILIAR 
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
