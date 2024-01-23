#include<iostream>
#include<cstring>
using namespace std; 

struct pacientes {  // VECTOR ORDENADO POR ID 
    int id; 
    char nombre[50]; 
    char apellido[50]; 
};

struct medicamentos {  // ARCHIVO DE MEDICAMENTOS SIN ORDEN  
    int id_medicamento; 
    int EAN; 
    char nombre_generico; 
    int dosis; 
};

struct preinscripciones {  // VECTOR DESORDENADO
    int id_paciente; 
    int id_medicamento; 
    int intervalo_horas; 
    int hora_inicio; 
};

struct horasReales {    // VECTOR SIN ORDEN 
    int id_paciente; 
    int numero_toma; 
    int dia; 
    int hora; 
};

struct listado {
    int dia; 
    char apellido[50]; 
    char nombre[50]; 
    int nombre_generico; 
    int hora_prescripta; 
    int hora_real; 
};

void PasoArchivoAVector (FILE*); 
void BurbujaPorId (preinscripciones [], int); 
void Preinscripciones (); 




int main () {
    return 0; 
}


void PasoArchivoAVector (FILE* m) {
    medicamentos med; 

    fseek(m, 0, SEEK_END); 
    int M = ftell(m); 
    int cantregM = M / sizeof(medicamentos); 
    fseek(m, 0, SEEK_SET); 

    medicamentos vectorM[cantregM]; 
    int i = 0; 
    while(fread(&med, sizeof(medicamentos), 1, m)) {
        vectorM[i] = med; 
        i++; 
    }
}


void BurbujaPorId (preinscripciones vectorPrei [], int k) {
    int i, j; 
    preinscripciones aux; 

    for (i = 0; i < k; i++) {
        for (j = 0; j < k - i; j++) {
            if (vectorPrei[j - 1].id_paciente > vectorPrei[j].id_paciente) {
                aux = vectorPrei[j - 1]; 
                vectorPrei[j - 1] = vectorPrei[j]; 
                vectorPrei[j] = aux; 
            }
        }
    }
}


void Preinscripciones (listado vectorL [], ) {
    int i = 0; 

    for (i = 0; i < k; i++) {
        if ()
    }
}
