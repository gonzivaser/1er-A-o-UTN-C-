#include<iostream>
using namespace std; 

/*--------------STRUCTS----------------*/
// ARRANCO CON STRUCT DE INFO SECUNDARIA
// LS = LISTA SECUNDARIA, LP = LISTA PRINCIPAL
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
    nodoLS* ptr; 
};

struct nodoLP {
    infoLP info; 
    nodoLP* sgte; 
}; 


/*--------------INT MAIN----------------*/
int main () {
    nodoLP* lista; 


    nodoLP* nodoIns = InsertarSinRepetir(lista, info); 
    insertarOrdenadoLS (nodoIns -> info.ptr, infoLS); 

    return 0; 
}


/*--------------DECLARADAS----------------*/
nodoLP* InsertarOrdenado (nodoLP*& lista, infoLP info) {
    nodoLP* p = new nodoLP(); 
    p -> info = info; 

    return p;
}


nodoLP* InsertarSinRepetir (nodoLP*& lista, int info) {
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