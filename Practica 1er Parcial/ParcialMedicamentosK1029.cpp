#include<iostream>
#include<cstring>
using namespace std; 

struct pacientes {  // ARCHIVO ORDENADO POR ID 
    int id; 
    char nombre[50]; 
    char apellido[50]; 
    int edad; 
    int diagnostico; 
};

struct medicamentos { // ARCHIVO SIN ORDEN 
    int EAN; 
    char nombre_generico[50]; 
    int dosis; 
};

struct preiscripciones { // VECTOR DESORDENADO
    int id_pacientes; 
    int EAN; 
    int intervalo_horas; 
    int hora_inicio; 
};

struct listado {  // NUEVO LISTADO A CREAR Y MOSTRAR 
    int id; 
    char nombre[50]; 
    char apellido[50]; 
    int EAN; 
    char nombre_generico[50]; 
    int dosis; 
    int hora_inicio; 
};

void PasoArchivosAVector (FILE*, FILE*); 
void BurbujaPorId (preiscripciones [], int); 
void CargarListado (pacientes [], medicamentos [], preiscripciones[], listado [], int); 
void BurbujaPorHorario (listado [], int); 
void ListasPreinscripciones (listado [], int); 
void PacientesSinPreinscripcion (pacientes [], preiscripciones [], int); 


int main () {
    return 0; 
}


void PasoArchivosAVector (FILE* p, FILE* m) {
    pacientes pa; 
    medicamentos me; 

    // PASO ARCHVIO DE PACIENTES A VECTOR
    fseek(p, 0, SEEK_END); 
    int D = ftell(p); 
    int cantregP = D / sizeof(pacientes);
    fseek(p, 0, SEEK_SET); 

    pacientes vectorP [cantregP]; 
    int i = 0; 
    while(fread(&pa, sizeof(pacientes), 1, p)) {
        vectorP[i] = pa; 
        i++; 
    }

    // PASO ARCHIVO DE MEDICAMENTOS A VECTOR 
    fseek(m, 0, SEEK_END); 
    int M = ftell(m); 
    int cantregM = M / sizeof(medicamentos); 
    fseek(m, 0, SEEK_SET); 

    medicamentos vectorM[cantregM]; 
    while (fread(&me, sizeof(medicamentos), 1, m)) {
        vectorM[i] = me; 
        i++; 
    }
}


void BurbujaPorId (preiscripciones vectorPrei [], int k) {
    int i, j; 
    preiscripciones aux; 

    for (i = 0; i < k; i++) {
        for (j = 0; j < k - i; j++) {
            if (vectorPrei[j - 1].id_pacientes > vectorPrei[j].id_pacientes) {
                aux = vectorPrei[j - 1]; 
                vectorPrei[j - 1] = vectorPrei[j]; 
                vectorPrei[j] = aux; 
            }
        }
    }
}


void CargarListado (pacientes vectorP [], medicamentos vectorM [], preiscripciones vectorPrei[], listado vectorL [], int n) {
    int i = 0; 
    int m = 0; 

    for (i = 0; i < n; i++) {
        if (vectorP[i].id == vectorPrei[i].id_pacientes) {
            strcpy(vectorL[i].nombre, vectorP[i].nombre); 
            strcpy(vectorL[i].apellido, vectorP[i].apellido); 
            vectorL[i].hora_inicio = vectorPrei[i].hora_inicio;  
            
            while (vectorPrei[i].EAN != vectorM[m].EAN) {
                m++; 
            }

            vectorL[i].nombre_generico = vectorM[m].nombre_generico; 
            vectorL[i].dosis = vectorM[m].dosis;
        }
    }
}


void BurbujaPorHorario (listado vectorL [], int k) {
    int i, j; 
    listado aux; 

    for (i = 0; i < k; i++) {
        for (j = 0; j < k -i; j++) {
            if (vectorL[j - 1].hora_inicio > vectorL[j].hora_inicio) {
                aux = vectorL[j - 1]; 
                vectorL[j - 1] = vectorL[j]; 
                vectorL[j] = aux; 
            }
        }
    }
}


void ListarPreinscripciones (listado vectorL [], int n) {
    int i = 0; 

    for (i = 0; i < n; i++) {
        cout << vectorL[i].id << "\t" << vectorL[i].nombre << "\t" << vectorL[i].apellido << "\t" << 
        vectorL[i].EAN << "\t" << vectorL[i].nombre_generico << "\t" << vectorL[i].dosis << "\t" << 
        vectorL[i].hora_inicio; 
    }
}


void PacientesSinPreinscripcion (pacientes vectorP [], preiscripciones vectorPrei [], int n) {
    for (int i = 0; i < n; i++) {
        if (vectorP[i].id != vectorPrei[i].id_pacientes) {
            cout << vectorP[i].id << "\t" << vectorP[i].apellido << "\t" << vectorP[i].nombre; 
        }
    }
}