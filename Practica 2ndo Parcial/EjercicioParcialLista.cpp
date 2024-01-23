#include<iostream>
using namespace std; 

/*--------------STRUCTS Y PROTOTIPOS----------------*/
struct alumno {
    char nombre[50]; 
    int legajo; 
}; 

struct nodo {
    alumno info; 
    nodo* sgte; 
};

nodo* insertarOrdenado (nodo*, alumno); 
alumno pop (nodo*); 


/*--------------INT MAIN----------------*/
int main () {
    FILE* f = fopen("ARCHIVO.DAT", "rb"); 
    alumno info; 
    nodo* lista = NULL; 

    // CARGO LA LISTA LEYENDO EL ARCHIVO
    while (fread(&info, sizeof(alumno), 1, f)) {
        insertarOrdenado(lista, info); 
    }

    // LIBERO LOS DATOS Y DESECHO LA LISTA
    alumno aux; 
    while (lista != NULL) {
        aux = pop(lista); 
        cout << aux.legajo;
        cout << aux.nombre;  
    }

    return 0; 
}


/*--------------DECLARADAS----------------*/
nodo* insertarOrdenado (nodo* lista, alumno info) {
    nodo* p = new nodo(); 
    p -> info = info; 
    p -> sgte = NULL; 

    // 1 Y 2 SI ESTA VACIA O ES MENOR QUE EL PRIMERO 
    if (lista == NULL || info.legajo < lista -> info.legajo) {
        p -> sgte = lista; 
        lista = p; 
    }
    else {
        // VA EN EL MEDIO O AL FINAL 
        // TENGO QUE BUSCAR DONDE VA 
        nodo* q = lista; 
        while (q -> sgte != NULL && q -> sgte -> info.legajo < info.legajo) {
            q = q -> sgte; 
        }
        p -> sgte = q -> sgte; 
        q -> sgte = p; 
    }

    return p; 
}

alumno pop (nodo*& lista) {
    alumno x; 
    nodo* p = lista; 
    x = lista -> info; 
    lista = p -> sgte; 
    
    delete p; 
    return x; 
}