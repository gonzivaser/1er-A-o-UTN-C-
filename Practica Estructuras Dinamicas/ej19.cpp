/*Dada una LISTA (nodo = registro + puntero), imprimirla en orden natural si tiene más de 10
nodos, caso contrario imprimiría en orden inverso.*/

#include<iostream>
using namespace std; 

/*--------------STRUCTS----------------*/
struct nodo {
    int info; 
    nodo* sgte;
};

// FUNCIONES DE LISTA
nodo* InsertarOrdenado(nodo*&, int);
int pop(nodo*&);
void push (nodo*&, int);    

// FUNCIONES DE CARGAR LISTA
void CargarLista (nodo*&); 

// FUNCION DE MOSTRAR LA LISTA
void MostrarLista (nodo*&); 

// ORDEN INVERSO 
void Inverso (nodo*&, nodo*&); 


/*--------------INT MAIN----------------*/
int main () {
    nodo* lista = NULL; 
    nodo* pila = NULL; 

    // CARGO LA LISTA 
    CargarLista(lista); 

    // MUESTRO LISTA INVERSA O NORMAL 
    Inverso(lista, pila); 

    return 0; 
}


/*--------------DECLARADAS----------------*/
void Inverso (nodo*& lista, nodo*& pila) {
    // ME FIJO SI LA PILA TIENE MAS DE 10 NODOS LLAMANDO A "MOSTRAR LISTA"
    // SI TIENE MAS DE 10, LA MUESTRO
    // SI TIENE MENOS DE 10, LA PASO A UNA PILA Y MUSTRO LA PILA YA QUE ASI SE IMPRIME INVERSAMENTE

    nodo* listaAux = lista; 
    int i = 0;
    
    // RECORRO LA LISTA CON EL CONTADOR
    while (listaAux != NULL) {
        listaAux = listaAux -> sgte; 
        i++; 
    }

    if (i < 10) {
        while (lista != NULL) {
            push(pila, pop(lista)); 
        }

        while (pila != NULL) {
            cout << "Orden Inverso: " << pop(pila) << endl;
        }
    } 
    else {
        MostrarLista(lista); 
    }

}


void MostrarLista(nodo*& lista) {
    while (lista != NULL) {
        cout << "Lista Normal: " << pop(lista) << endl; 
    }
    cout << endl; 
}


void CargarLista (nodo*& lista) {
    int input; 
    cout << "Ingrese el valor que quiere ingresar a la lista (-1 para terminar): "; 
    cin >> input; 

    while (input > -1) {
        InsertarOrdenado(lista, input); 

        cout << "Ingrese el valor que quiera ingresar a la lista (-1 para terminar): "; 
        cin >> input; 
    }
    cout << endl; 
}


nodo* InsertarOrdenado (nodo*& lista, int info) {
    nodo* aux = new nodo(); 
    aux -> info = info; 
    aux -> sgte = NULL; 

    // 1 Y 2 SI ESTA VACIA O ES MENOR QUE EL PRIMERO 
    if (lista == NULL || info < lista -> info) {
        aux -> sgte = lista; 
        lista = aux; 
    }
    else {
        // VA EN EL MEDIO O AL FINAL 
        // TENGO QUE BUSCAR DONDE VA 
        nodo* q = lista; 
        while (q -> sgte != NULL && q -> sgte -> info < info) {
            q = q -> sgte; 
        }
        aux -> sgte = q -> sgte; 
        q -> sgte = aux; 
    }

    return aux; 
}


int pop (nodo*& pila) {
    int x; 
    nodo* p = pila; 

    x = pila -> info; 
    pila = p -> sgte; 
    
    delete p; 
    return x; 
}

void push (nodo*& pila, int x) {
    nodo*p = new nodo(); 

    p -> info = x; 
    p -> sgte = pila; 
    pila = p; 

    return; 
}