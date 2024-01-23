#include<iostream>
#include<cstring>
using namespace std; 

/*
NOTAS: 
- 
*/

/*--------------STRUCTS----------------*/
/*-------ARCHIVO-------*/
struct InfoArch {
    char nombre[50]; 
    int sueldo; 
    int antiguedad; 
};

/*-------LISTAS-------*/
struct InfoEmpleado {
    char nombre[50]; 
    int sueldo; 
    int antiguedad;
};

struct NodoEmpleado {
    InfoEmpleado info; 
    NodoEmpleado* sgte; 
};

/*-------LISTA EMPLEADOS ANTIGUEDAD MAYOR-------*/
struct InfoEmpleadoAntiguo {
    char nombre[50]; 
    int sueldo; 
    int antiguedad;
};

struct NodoEmpleadorAntiguo {
    InfoEmpleadoAntiguo info; 
    NodoEmpleado* sgte; 
};


/*-------FUNCIONES PROTOTIPO-------*/
NodoEmpleado* InsertarOrdenadoPorSueldoCreciente(NodoEmpleado*&, InfoEmpleado);
NodoEmpleado* CargarListaEmpleado (FILE*);
NodoEmpleado* ReconocimientoSalarial (NodoEmpleado*&, int, int, int, int, int, int); 
NodoEmpleado* InsertarOrdenadoPorSueldoDecreciente (NodoEmpleado*&, InfoEmpleadoAntiguo); 


/*--------------INT MAIN----------------*/
int main () {
    return 0; 
}


/*--------------DECLARADAS----------------*/
NodoEmpleadorAntiguo* ReconocimientoSalarial (NodoEmpleadorAntiguo*& lista_nueva, int P1, int P2, int X1, int X2, int X3, int años) {
    NodoEmpleado* lista = NULL; 
    NodoEmpleado* aux = lista; 
    InfoEmpleado auxiliar3; 

    InfoEmpleadoAntiguo auxiliar2; 


    // PUNTO 1 y PUNTO 2
    while (aux != NULL) {
        if (aux->info.sueldo < P1) {
            aux->info.sueldo = aux->info.sueldo * (1 + (X1/100)); 
        }
        else if (aux->info.sueldo >= P1 && aux->info.sueldo <= P2) {
            aux->info.sueldo = aux->info.sueldo * (1 + (X2/100)); 
            cout << "Empleados cuyo salario esta entre P1 y P2: " << aux->info.nombre << endl; 
        }
        else {
            aux->info.sueldo = aux->info.sueldo * (1 + (X3/100)); 
        }

        aux = aux ->sgte; 
    }


    // PUNTO 3 
    while (aux != NULL) {
        if (aux->info.antiguedad >= años) {
            auxiliar3 = pop(aux->info); 

            // LO PASO A TIPO INFOEMPLEADOANTIGUO
            auxiliar2.antiguedad = auxiliar3.antiguedad; 
            strcpy(auxiliar2.nombre, auxiliar3.nombre); 
            auxiliar2.sueldo = auxiliar3.sueldo; 

            InsertarOrdenadoPorSueldoDecreciente(lista_nueva, auxiliar2);
        }

        aux = aux->sgte; 
    }

    return lista_nueva; 
}


NodoEmpleado* CargarListaEmpleado (FILE* f) {
    InfoArch al; 
    InfoEmpleado auxiliar; 
    NodoEmpleado* lista = NULL; 
    NodoEmpleado* aux = lista; 

    // ARRANCO A LEER ARCHIVO
    while (fread(&al, sizeof(InfoArch), 1, f)) {
        auxiliar.antiguedad = al.antiguedad; 
        strcpy(auxiliar.nombre, al.nombre); 
        auxiliar.sueldo = al.sueldo; 

        aux = InsertarOrdenadoPorSueldoCreciente(lista, auxiliar);
    }

    return aux; 
}


NodoEmpleadorAntiguo* InsertarOrdenadoPorSueldoDecreciente (NodoEmpleadorAntiguo*& lista, InfoEmpleadoAntiguo al) {
    NodoEmpleadorAntiguo* p = new NodoEmpleadorAntiguo(); 
    p->info = al; 
    p->sgte = NULL; 

    if (lista == NULL || al.sueldo > lista->info.sueldo) {
        p -> sgte = lista; 
        lista = p; 
    }
    else {
        NodoEmpleadorAntiguo* q = lista; 
        while (q -> sgte != NULL && q -> sgte->info.sueldo > al.sueldo) {
            q = q -> sgte; 
        }
        p -> sgte = q -> sgte; 
        q -> sgte = p; 
    }

    return p; 
}


NodoEmpleado* InsertarOrdenadoPorSueldoCreciente(NodoEmpleado*& lista, InfoEmpleado al) {
    NodoEmpleado* p = new NodoEmpleado(); 
    p->info = al; 
    p->sgte = NULL; 

    if (lista == NULL || al.sueldo < lista->info.sueldo) {
        p -> sgte = lista; 
        lista = p; 
    }
    else {
        NodoEmpleado* q = lista; 
        while (q -> sgte != NULL && q -> sgte->info.sueldo < al.sueldo) {
            q = q -> sgte; 
        }
        p -> sgte = q -> sgte; 
        q -> sgte = p; 
    }

    return p; 
}