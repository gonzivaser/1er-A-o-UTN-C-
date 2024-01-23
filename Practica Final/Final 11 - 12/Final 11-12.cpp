#include<iostream>
#include<cstring>
using namespace std; 


/*--------------------------------EJERCICIO 1:---------------------------------*/
// A: Una funcion que retorne una lista ordenada a partir de la union de una pila y una cola 
/*
NOTAS: 
- DESENCOLAR ELEMENTOS DE LA COLA Y METERLOS EN UNA PILA 
- CARGAR LA PILA EN LA LISTA INSERTANDO DE MANERA ORDENADA 
- RETORNAR LA LISTA
*/

void Union (nodo*& fte, nodo*& fin, nodo*& pila, nodo*& lista) {
    // DESENCOLO LA COLA 
    while (fte != NULL) {
        int aux; 
        aux = unqueue(fte, fin);
        
        // CARGO LA PILA CON EL AUXILIAR DONDE GUARDE LOS DATOS DE LA COLA 
        push(pila, aux); 
    }

    // CARGO LOS DATOS DE LA PILA EN LA LISTA INSERTANDOLOS DE MANERA ORDENADA 
    while ()
    InsertarOrdenado (lista, pop(pila));   


    // RETORNO LA LISTA 
    cout << "Lista Ordenada De Union De Pila y Cola: " << pop(lista) << endl; 
}

// B: UN PROCEDIEMIENTO QUE GENERE UNA LISTA SIN ORDEN A PARTIR DE LA INTERSECCION DE 2 LISTAS
/*
NOTAS: 
- INTERSECCION --> QUE AMBOS ELEMENTOS SE ENCUENTREN EN LAS DOS LISTAS
- SI SE ENCUENTRAN, AGREGARLO A LA NUEVA LISTA 
- BASICAMENTE HACER UN APAREO 
*/

void Interseccion (nodo*& lista1, int tam1, nodo*& lista2, int tam2, nodo*& lista_nueva) {
    int i = 0;
    int j = 0; 
    int k = 0; 

    while (i < tam1 && j < tam2) {
        
    }
}


/*--------------------------------EJERCICIO 2:---------------------------------*/
struct Reservas {
    int codigo_hotel; 
    int cantidad_reservas; 
    int cantidad_dias_disponibles; 
};

struct InfoLista {
    int codigo_hotel;
    int cantidad_dias_reservados; 
};

struct NodoLista {
    InfoLista info; 
    NodoLista* sgte;
};

void ActulizacionVector (NodoLista*& lista, Reservas vector[], int N) {
    NodoLista* aux = lista; 

    // RECORRO LISTA
    while (aux != NULL) {
        // RECORRO VECTOR
        for (int i = 0; i < N; i++) {

            // SI MIS CODIGOS DE HOTEL SON IGUALES ACTUALIZO
            if (vector[i].codigo_hotel == aux->info.codigo_hotel) {
                vector[i].cantidad_dias_disponibles = vector[i].cantidad_dias_disponibles - aux->info.cantidad_dias_reservados; 
            }
        }

        aux = aux->sgte;
    }
}


/*--------------------------------EJERCICIO 3:---------------------------------*/
struct InfoArch {
    int codigo_producto; 
    int peso; 
    char tipo[1]; 
    int cantidad_stock; 
};

// A: ORDENAR EL ARCHIVO POR CODIGO DE PRODUCTO 
void OrdenarArchivoPorCodigo (FILE* f) {
    f = fopen("STOCK.DAT", "rb"); 

    // PASO ARCHIVO A VECTOR 
    fseek(f, 0, SEEK_SET); 
    int D = ftell(f); 
    int cantreg = D / sizeof(InfoArch); 
    fseek(f, 0, SEEK_END); 

    InfoArch al; 
    InfoArch vector[cantreg]; 

    int i = 0; 
    while(fread(&al, sizeof(InfoArch), 1, f)) {
        vector[i] = al; 
        i++; 
    }

    // COMO YA TENGO EL ARCHIVO EN UN VECTOR, LO ORDENO CON ORDENAMIENTO BURBUJA 
    Burbuja(vector, cantreg); // ORDENADO POR CODIGO DE PRODUCTO
}

void Burbuja (InfoArch vector [], int cantreg) {
    int i, j; 
    int aux; 

    for (i = 1; i < cantreg; i++) {
        for (j = 1; j <= (cantreg - 1); j++) {  
            if (vector.codigo_producto[j - 1] > vector.codigo_producto[j]) {
                aux = vector[j - 1]; 
                vector[j - 1] = vector[j]; 
                vector[j] = aux; 
            }
        }
    }
}


// B: GENERAR DOS LISTAS Y MOSTRARLAS POR PANTALLA 
// A: LA PRIMERA LISTA CON LOS PRODUCTOS QUE NO TIENEN UNIDADES DE STOCK 
struct InfoLista {
    int codigo_producto; 
};

struct NodoLista {
    InfoLista info;
    NodoLista* sgte; 
};

void GenerarListaProductosSinStock (NodoLista*& lista, InfoArch vector []) {
    // RECORRO VECTOR Y VEO QUE PRODUCTOS NO TIENEN STOCK ASI LOS CARGO EN LA LISTA
    int cantreg; 
    for (int i = 0; i < cantreg; i++) {
        if (vector[i].cantidad_stock == 0) {
            InsertarOrdenado(lista, vector[i].codigo_producto); 
        }
    }

    // MUESTRO LA LISTA
    NodoLista* aux = lista; 
    while (aux != NULL) {
        cout << "Productos Sin Stock: " << aux->info.codigo_producto << endl;

        aux = aux->sgte;
    }
}


// B: LA SEGUNDA LISTA CON PRODUCTOS PESADOS (PESO MAYOR A 100 KG) Y BEBIDAS('B')
struct InfoLista {
    int codigo_producto; 
};

struct NodoLista {
    InfoLista info;
    NodoLista* sgte; 
};

void GenerarListaProductosSinStock (NodoLista*& lista, InfoArch vector []) {
    // RECORRO VECTOR Y VEO QUE PRODUCTOS CUYO PESO > 100 KG Y BEBIDAS
    int cantreg;     

    for (int i = 0; i < cantreg; i++) {
        if (vector[i].peso > 100 || strcmp(vector[i].tipo, 'B') == 0) {
            InsertarOrdenado(lista, vector[i].codigo_producto); 
        }
        else {
            i++; 
        }
    }

    // MUESTRO LA LISTA
    NodoLista* aux = lista; 
    while (aux != NULL) {
        cout << "Productos Pesados o Bebidas: " << aux->info.codigo_producto << endl;

        aux = aux->sgte;
    }
}

