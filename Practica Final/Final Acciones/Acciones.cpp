#include<iostream>
#include<cstring>
using namespace std; 


/*
NOTAS: 
- ARCHIVO OPERACIONES.DAT CON INFO 
- VECTOR DE LISTAS. CADA POSICION DEL VECTOR (25 EN TOTAL) REPRESENTA EL NOMBRE DE UNA ACCION 
  Y CADA NODO TIENE UNA UNA LISTA ENLAZADA QUE CONTIENE EL RESUMEN DIARIO 
*/

/*--------------STRUCTS----------------*/
struct InfoArch {
    int fecha; 
    char especie[4]; 
    int precio_minimo; 
    int precio_maximo; 
    int cant_operada; 
};

/*-------LISTAS-------*/
struct InfoResumen {
    int fecha; 
    int precio_minimo; 
    int precio_maximo; 
    int cant_operada; 
};

struct NodoResumen {
    InfoResumen info; 
    NodoResumen* sgte; 
};

struct ResumenOperaciones {
    char especie[4]; 
    NodoResumen* lista; 
}; 

/*-------FUNCIONES PROTOTIPO-------*/
void AgregarOperaciones (FILE*, ResumenOperaciones [], NodoResumen*&); 
void Promedio (ResumenOperaciones []); 


/*--------------INT MAIN----------------*/
int main () {
    return 0; 
}


/*--------------DECLARADAS----------------*/
void Promedio (ResumenOperaciones vector []) {
    int i = 0; 
    int promedio = 0; 
    // COMO CALCULO PROMEDIO --> PROMEDIO = (MAX + MINIMO) / 2; 
    
    for(i = 0; i <= 25; i++) {
        if (vector[i].lista->info.fecha != 0) {
            promedio = (vector[i].lista->info.precio_maximo + vector[i].lista->info.precio_minimo) / 2;
            cout << "El valor promedio de la accion " << vector[i].especie << " es: " << promedio << endl; 
        }
        else {
            cout << "No hubo movimientos de esa accion en ningun dia. " << endl; 
        }
    }
}


void AgregarOperaciones (FILE* f, ResumenOperaciones vector []) {
    InfoArch al; 
    InfoResumen auxiliar; 
    int i = 0; 

    // EMPIEZO A LEER EL ARCHIVO 
    while (fread(&al, sizeof(InfoArch), 1, f)) {
        // RECORRO EL VECTOR
        for (i = 0; i <= 25; i++) {
            // PONGO CONDICIONES 
            if (strcmp(vector[i].especie, al.especie) == 0) {
                auxiliar.cant_operada = al.cant_operada; 
                auxiliar.fecha = al.fecha; 
                auxiliar.precio_maximo = al.precio_maximo; 
                auxiliar.precio_minimo = al.precio_minimo; 

                InsertarOrdenado (vector[i].lista, auxiliar); 
            }
            else {
                i++; 
            }
        }   
    }

    fclose(f); 
}