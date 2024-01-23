#include<iostream>
#include<cstring>
using namespace std; 

/*
NOTAS: 
- 
*/

/*--------------------------------EJERCICIO 1:---------------------------------*/
// A: Una funcion que retorne una lista ordenada a partir de la union de una pila y una cola 
struct NodoC {
    int info; 
    NodoC* sgte; 
};

struct NodoP {
    int info; 
    NodoP* sgte; 
};

struct NodoL {
    int info; 
    NodoL* sgte; 
};

void Union (NodoC*& cola, NodoP*& pila, NodoL* lista) {
    NodoC* fte = NULL; 
    NodoC* fin = NULL; 

    // DESENCOLO LA COLA Y LA PUSHEO EN LA PILA Y AHI OBTENGO LA UNION 
    while (fte != NULL) {
        int aux = unqueue(fte, fin); 

        // METO ELEMENTOS DE LA COLA DENTRO DE LA PILA 
        push (pila, aux); 
    }
   
    // POPEO LA PILA 
    while (pila != NULL) {
        int auxiliar = pop(pila); 

        // INSERTO ORDENADAMENTE LOS ELEMENTOS DE LA PILA EN LA LISTA
        InsertarOrdenado(lista, auxiliar); 
    }
}

// B: Una funcion que retorne una lista sin orden a partir de la interseccion de 2 listas
struct NodoL1 {
    int info; 
    NodoL1* sgte; 
};

struct NodoL2 {
    int info; 
    NodoL2* sgte; 
};

struct NodoL3 {
    int info; 
    NodoL3* sgte; 
};


void Interseccion (NodoL1*& lista1, NodoL2*& lista2, NodoL3*& lista3) {
    NodoL1* aux1 = lista1; 
    NodoL2* aux2 = lista2; 

    // RECORRO AMBAS LISTAS
    while (aux1 != NULL) {
        while (aux2 != NULL) {
            if (aux1->info == aux2->info) {
                InsertarOrdenado(lista3, aux1->info); 
            }

            aux2 = aux2->sgte;
        }

        aux1 = aux1->sgte; 
    }
}




/*--------------------------------EJERCICIO 2:---------------------------------*/
struct InfoVector {
    int codigo_hotel; 
    int cant_reservas; 
    int cant_dias_disponibles; 
};

struct InfoReservas {
    int codigo_hotel; 
    int cant_dias_reservados; 
};

struct NodoReservas {
    InfoReservas info; 
    NodoReservas* sgte; 
};

void Actualizar (InfoVector vector [], NodoReservas*& lista) {
    NodoReservas* aux = lista; 
    
    // RECORRO PRIMERO LA LISTA
    while (aux != NULL) {

        // EMPIEZO A RECORRER EL VECTOR PARA PODER IR ACTUALIZANDOLO
        for (int i = 0; i < 50; i++) {
            // SI EL CODIGO DE HOTEL COINCIDE ACTUALIZO
            if (vector[i].codigo_hotel == aux->info.codigo_hotel) {
                // RESERVAS
                vector[i].cant_reservas = vector[i].cant_reservas + aux->info.cant_dias_reservados; 

                // CANTIDAD DIAS DISPONIBLES 
                vector[i].cant_dias_disponibles = vector[i].cant_dias_disponibles - aux->info.cant_dias_reservados;
            }
        }

        aux = aux->sgte; 
    }
}




/*--------------------------------EJERCICIO 3:---------------------------------*/
struct InfoArch {
    int codigo_producto; 
    int peso; 
    char tipo[2]; 
    int cant_stock; 
};

struct InfoSinStock {
    int codigo_producto; 
    int peso; 
    char tipo[2]; 
    int cant_stock; 
};

struct NodoSinStock {
    InfoSinStock info; 
    NodoSinStock* sgte; 
};

NodoSinStock* GenerarListaSinStock (NodoSinStock*& lista, InfoArch vector []) {
    int N;
    vector[N]; 

    for (int i = 0; i < N; i++) {
        if (vector[i].cant_stock == 0) {
            InsertarOrdenado(lista, vector[i]); 
        }
    }

    // MUESTRO LA LISTA
    NodoSinStock* aux = lista; 
    while (aux != NULL) {
        cout << "Lista Productos Sin Stock " << endl; 
        cout << "Codigo Producto: " << aux->info.codigo_producto << endl; 
        cout << "Peso: " << aux->info.peso << endl; 
        cout << "Tipo : " << aux->info.tipo << endl; 

        aux = aux ->sgte; 
    }   

    return aux; 
}


void OrdenarArchivo (FILE* f, int cantreg) {
    // PASO ARCHIVO A VECTOR 
    fseek(f, 0, SEEK_END); 
    int D = ftell(f); 
    cantreg = D / sizeof(InfoArch); 
    fseek(f, 0, SEEK_SET); 

    InfoArch al; 
    InfoArch vector[cantreg]; 

    int i = 0; 
    while (fread(&al, sizeof(InfoArch), 1, f)) {
        vector[i] = al; 
        i++; 
    }

    // APLICO FUNCION DE ORDENAMIENTO BURBUJA POR CODIGO DE PRODUCTO 
    BurbujaPorCodigo(vector, cantreg); 
}

void BurbujaPorCodigo (InfoArch vector [], int n) {
    int i, j; 
    int aux; 

    for (i = 1; i < n; i++) {
        for (j = 1; j <= [n - 1]; j++) {
            if (vector[j - 1].codigo_producto > vector[j].codigo_producto) {
                aux = vector[j - 1]; 
                vector[j - 1] = vector[j]; 
                vector[j] = aux; 
            }
        }
    }
}