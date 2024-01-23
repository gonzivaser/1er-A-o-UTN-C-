#include<iostream>
using namespace std; 

/*--------------STRUCTS----------------*/
// ARRANCO CON STRUCT DE INFO SECUNDARIA
// LS = LISTA SECUNDARIA, LP = LISTA PRINCIPAL
struct vendedor {
    int mes; 
    int total_vendido; 
    int id_vendedor; 
    int id_localidad; 
}; 

struct infoLS {  
    int idvendedor; 
    int cantidad; 
};

struct nodoLS {
    infoLS info; 
    nodoLS* sgte; 
};

struct infoLP {
    int mes; 
    int cant_vendidos; 
    nodoLS* ptr; 
};

struct nodoLP {
    infoLP info; 
    nodoLP* sgte; 
}; 


/*--------------INT MAIN----------------*/
int main () {
    // ARCHIVO 
    FILE* f = fopen("ARCHIVOS.DAT", "rb"); 
    vendedor al; 


    // DECLARO LISTAS 
    nodoLP* listaP = NULL; 


    // CARGO LA LISTA LEYENDO EL ARCHIVO 
    while(fread(&al, sizeof(vendedor), 1, f)) {
        nodoLP* nodoIns = InsertarSinRepetir(listaP, );
    }

    return 0; 
}


/*--------------DECLARADAS----------------*/
nodoLP* InsertarOrdenado (nodoLP*& lista, infoLP info) {
    nodoLP* p = new nodo(); 
    p -> info = info; 
    p -> sgte = NULL; 

    if (lista == NULL || info.mes < lista -> info.mes) {
        p -> sgte = lista; 
        lista = p; 
    }
    else {
        nodoLP* q = lista; 
        while (q -> sgte != NULL && q -> sgte -> info.mes < info.mes) {
            q = q -> sgte; 
        }
        p -> sgte = q -> sgte; 
        q -> sgte = p; 
    }

    return p;
}


nodoLP* InsertarSinRepetir (nodoLP*& lista, infoLP info) {
    // QUE SI EXISTE EL MES ME DEVUELVA EL PUNTERO 
    // PARA QUE AGREGUE EL NODO DE LS Y SI NO EXISTE, QUE LO CREE ORDENADO
    // Y YAMBIEN ME DEVUELVA EL PUNTERO AL NODO PARA QUE AGREGUE EL NODO DE LS 
    nodoLP* encontro = Buscar(lista, info); 

    if (encontro == NULL) {
        encontro = InsertarOrdenado(lista, info);
    }

    return encontro; 
}


nodoLP* Buscar (nodoLP* lista, int mesbuscado) {
    nodoLP* aux = lista; 

    while (aux != NULL && aux -> info.mes != mesbuscado) {
        aux = aux -> sgte; 
    }

    return aux; 
}