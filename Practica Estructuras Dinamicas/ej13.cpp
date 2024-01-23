/*Dado un archivo de registros de alumnos, donde cada registro contiene:
a) Apellido y Nombre del alumno (35 caracteres) 
b) Número de legajo (7 dígitos)
c) División asignada (1 a 100)
Ordenado por número de legajo
Desarrollar el algoritmo y codificación del programa que imprima el listado de alumnos 
por división, ordenado por división y número de legajo crecientes, a razón de 55 alumnos por hoja.
*/

#include<iostream>
using namespace std; 

/*--------------STRUCTS----------------*/
struct InfoArch {
    char nombre[35]; 
    int legajo; 
    int division; 
};

// LISTA SECUNDARIA 
struct InfoListaSecu {
    char nombre[35]; 
    int legajo; 
};

struct nodoListaSecu {
    InfoListaSecu info; 
    nodoListaSecu* sgte; 
}; 

// LISTA PRINCIPAL 
struct InfoListaPrinci {
    int division; 
    nodoListaSecu* ptrLS; 
};

struct nodoListaPrinci {
    InfoListaPrinci info; 
    nodoListaPrinci* sgte; 
}; 


// FUNCION PARA REALIZAR EL EJERCICIO 
void Algoritmos (FILE*, nodoListaPrinci*&); 



/*--------------INT MAIN----------------*/
int main () {
    FILE* f = fopen("ALUMNOS.DAT", "rb"); 
    nodoListaPrinci* listaPrinci = NULL; 
    nodoListaSecu* listaSecu = NULL; 

    // MUSTRO LA FUNCION ALGORITMO 
    Algoritmos(f, listaPrinci);

    return 0; 
}


/*--------------DECLARADAS----------------*/
void Algoritmos (FILE* f, nodoListaPrinci*& lista) {
    nodoListaPrinci* aux = NULL; 

    while (lista != NULL) {
        cout << "La division es: " << pop(lista) << endl;
        cout << "Legajo: " << pop(lista->info.ptrLS) << endl;   
        lista = lista -> sgte; 
    }

}


// INSERTO ORDENADO LA LISTA SECUNDARIA POR LEGAJO
nodoListaSecu* InsertarOrdenado (nodoListaSecu*& lista, InfoListaSecu info) {
    nodoListaSecu* aux = new nodo(); 
    aux -> info = info; 
    aux -> sgte = NULL; 

    // 1 Y 2 SI ESTA VACIA O ES MENOR QUE EL PRIMERO 
    if (lista == NULL || info.legajo < lista -> info.legajo) {
        aux -> sgte = lista; 
        lista = aux; 
    }
    else {
        // VA EN EL MEDIO O AL FINAL 
        // TENGO QUE BUSCAR DONDE VA 
        nodoListaSecu* q = lista; 
        while (q -> sgte != NULL && q -> sgte -> info.legajo < info.legajo) {
            q = q -> sgte; 
        }
        aux -> sgte = q -> sgte; 
        q -> sgte = aux; 
    }
    return aux; 
}


nodoListaPrinci* InsertarOrdenado (nodoListaPrinci*& lista, InfoListaPrinci info) {
    nodoListaPrinci* aux = new nodo(); 
    aux -> info = info; 
    aux -> sgte = NULL; 

    // 1 Y 2 SI ESTA VACIA O ES MENOR QUE EL PRIMERO 
    if (lista == NULL || info.division < lista -> info.division) {
        aux -> sgte = lista; 
        lista = aux; 
    }
    else {
        // VA EN EL MEDIO O AL FINAL 
        // TENGO QUE BUSCAR DONDE VA 
        nodoListaPrinci* q = lista; 
        while (q -> sgte != NULL && q -> sgte -> info.division < info.division) {
            q = q -> sgte; 
        }
        aux -> sgte = q -> sgte; 
        q -> sgte = aux; 
    }
    return aux; 
}

