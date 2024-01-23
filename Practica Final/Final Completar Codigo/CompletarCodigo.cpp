#include<iostream>
#include<cstring>
using namespace std; 

/*
NOTAS: 
- 
- 
*/


/*--------------STRUCTS----------------*/
/*-------ARCHIVOS-------*/
struct InfoArch {
    int legajo; 
    char nombre[50]; 
    char apellido[50]; 
    int dni; 
    int edad; 
    int objetivos_logrados; // MINIMO 5 PARA RECIBIR BONO
    bool recibe_bono;     
}; 

/*-------LISTAS-------*/
struct InfoExEmpleados {
    int legajo; 
    int fecha_baja; 
};

struct NodoExEmpleados {
    InfoExEmpleados info; 
    NodoExEmpleados* sgte; 
};


/*-------FUNCIONES PROTOTIPO-------*/
void PasarArchivoaVector (FILE*, InfoArch [], int); 
void PagarBono (FILE*, InfoArch [], NodoExEmpleados*&, int);
void AgregarBaja (NodoExEmpleados*&, int, int);


/*--------------INT MAIN----------------*/
int main () {
    return 0; 
}


/*--------------DECLARADAS----------------*/
void AgregarBaja (NodoExEmpleados*& lista, int legajo, int fecha_baja) {
    InfoExEmpleados auxiliar; 
    auxiliar.legajo = legajo; 
    auxiliar.fecha_baja = fecha_baja; 

    InsertarOrdenado(lista, auxiliar); 
}


void PagarBono (FILE* f, InfoArch vector [], NodoExEmpleados*& lista, int cantreg) {
    // PASO A VECTOR PARA IR CARGANDO TODOS LOS DATOS EN EL VECTOR DEL ARCHIVO 
    PasarArchivoaVector(f, vector, cantreg); 

    // LISTA
    NodoExEmpleados* aux = lista; 

    while (aux != NULL) {
        for (int i = 0; i < cantreg; i++) {
            aux = BuscarBaja (lista, vector[i].legajo);
            if (vector[i].objetivos_logrados >= 5 && aux == NULL) {
                vector[i].recibe_bono = true;    
            }
            else {
                cout << "El empleado no cumplio con los 5 objetivos para recibir bono. " << endl; 
            }
        }

        aux = aux->sgte; 
    }

}


PasarArchivoaVector (FILE* f, InfoArch vector [], int cantreg) {
    InfoArch al; 
    fseek(f, 0, SEEK_END);
    int D = ftell(f); 
    cantreg = D / sizeof(InfoArch); 
    fseek(f, 0, SEEK_SET); 

    vector [cantreg]; 
    int i = 0; 
    while (fread(&al, sizeof(InfoArch), 1, f)) {
        vector[i] = al; 
        i++; 
    }

}