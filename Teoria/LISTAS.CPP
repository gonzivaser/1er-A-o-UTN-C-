#include<iostream>
using namespace std; 


/*--------------STRUCTS----------------*/
struct nodo {
    int info; 
    nodo* sgte; 
};

nodo* InsertarOrdenado(nodo*&, int); 


/*--------------INT MAIN----------------*/
int main () {
    nodo* lista = NULL; 
    // ITERO LEYENDO EL ARCHIVO Y CARGO LA LISTA
    nodo* q = lista; 
    while (q != NULL) {
        cout << q -> info; 
        q = q -> sgte;
    }

    // DESECHE LA LISTA DESPUES DE LIBERAR LOS DATOS 
    while (lista != NULL) {
        cout << pop(lista); 
    }




    return 0; 
}

/*--------------DECLARADAS----------------*/
nodo* insertarOrdenado (nodo*& lista, int info) {
    nodo* p = new nodo(); 
    p -> info = info; 
    p -> sgte = NULL; 

    // 1 Y 2 SI ESTA VACIA O ES MENOR QUE EL PRIMERO 
    if (lista == NULL || info < lista -> info) {
        p -> sgte = lista; 
        lista = p; 
    }
    else {
        // VA EN EL MEDIO O AL FINAL 
        // TENGO QUE BUSCAR DONDE VA 
        nodo* q = lista; 
        while (q -> sgte != NULL && q -> sgte -> info < info) {
            q = q -> sgte; 
        }
        p -> sgte = q -> sgte; 
        q -> sgte = p; 
    }

    return p; 
}