/*Idem Ejercicio Nro. 13, pero el listado de alumnos por división debe realizarse ordenado
creciente por división y decreciente por número de legajo*/

#include<iostream>
using namespace std; 

/*--------------STRUCTS----------------*/
struct InfoArch {
    char nombre[35]; 
    int legajo; 
    int division; 
};

// PILA 
struct InfoPila {
    char nombre[35]; 
    int legajo; 
};

struct nodoPila {
    InfoPila info; 
    nodoPila* sgte; 
}; 

// LISTA 
struct InfoLista {
    int division; 
    nodoPila* ptrPILA; 
};

struct nodoLista {
    InfoLista info; 
    nodoLista* sgte; 
}; 


// FUNCIONES DE PILA 
InfoPila pop(nodoPila*&);
void push (nodoPila*&, int);    

// FUNCIONES DE LISTA 
nodoLista* InsertarOrdenado(nodoLista*&, int);
InfoLista pop(nodoLista*&); 

// FUNCION PARA REALIZAR EL EJERCICIO 
void Algoritmo (FILE*, InfoArch al, nodoLista*&, nodoPila*&); 


/*--------------INT MAIN----------------*/
int main () {
    FILE* f = fopen("ALUMNOS.DAT", "rb"); 
    nodoLista* lista = NULL; 
    nodoPila* pila = NULL; 

    return 0; 
}


/*--------------DECLARADAS----------------*/
void Algoritmo (FILE* f, InfoArch al, nodoLista*& lista, nodoPila*& pila) {
    // CREO LA LISTA AUXILIAR 
    nodoLista* aux = NULL; 

    // LEO EL ARCHIVO 
    while(fread(&al, sizeof(InfoArch), 1, f)) {
        aux = InsertarOrdenado(aux, al.division); 

        push(aux->info.ptrPILA, al);
    }

    // MUESTRO EL ARCHIVO 
    while (lista != NULL) {
        cout << "Division: " << pop(lista); 
        cout << "Nombre y legajo: " << pop(aux)
    }
}


nodoLista* InsertarOrdenado (nodoLista*& lista, InfoLista info) {
    nodoLista* aux = new nodo(); 
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
        nodoLista* q = lista; 
        while (q -> sgte != NULL && q -> sgte -> info.division < info.division) {
            q = q -> sgte; 
        }
        aux -> sgte = q -> sgte; 
        q -> sgte = aux; 
    }

    return aux; 
}

InfoPila pop (nodoPila*& pila) {
    InfoPila x; 
    nodoPila* p = pila; 

    x = pila -> info; 
    pila = p -> sgte; 
    
    delete p; 
    return x; 
}

void push (nodoPila*& pila, InfoPila x) {
    nodoPila* p = new nodo(); 
    p -> info = x; 
    p -> sgte = NULL; 
    
    // SI LA PILA ESTA VACIA O EL LEGAJO A INGRESAR ES MAYOR QUE EL LEGAJO SUPERIOR ENTRA EL VALOR
    if (p == NULL || x.legajo > pila->info.legajo) {
        p -> sgte = pila; 
        pila = p; 
    }
    // SI EL LEGAJO A INSERTAR ES MENOR QUE EL LEGAJO EN LA PARTE DE ARRIBA, TIENE QUE ENCONTRAR EL LUGAR
    else {
        nodoPila* aux = pila; 
        while (aux -> sgte != NULL && x.legajo < aux->sgte->info.legajo) {
            aux = aux -> sgte; 
        }
        p -> sgte = aux -> sgte; 
        aux -> sgte = p; 
    }

    return; 
}

InfoLista pop (nodoLista*& lista) {
    InfoLista = x; 
    nodoLista* p = lista; 

    x = lista -> sgte; 
    lista = p -> sgte; 

    delete p; 
    return x; 
}