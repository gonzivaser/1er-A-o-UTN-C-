#include<iostream>
#include<cstring>
using namespace std; 

/*
NOTAS: 
- ZONA ATLANTICA: ALTA ES VERANO
  
*/


/*--------------STRUCTS----------------*/
struct Estaciones {
    char nombre[20]; 
    int fecha_inicio; 
    int fecha_final; 
};

struct InfoArch {
    char zona[20]; 
    int dia; 
    int mes; 
    int reservas; 
};

/*-------FUNCIONES PROTOTIPO-------*/
void EstacionDelAño(Estaciones [], int, int); 
void EmitirListado (FILE*, ); 


/*--------------INT MAIN----------------*/
int main () {
    return 0; 
}


/*--------------DECLARADAS----------------*/
void EmitirListado (FILE* f, Estaciones vector [], char zona, char estacion) {
    InfoArch al; 

    // ARRANCO A LEER ARCHIVO
    while (fread(&al, sizeof(InfoArch), 1, f)) {
        
        if (strcmp(al.zona, zona) == 0) {
            Estaciones estacion = EstacionDelAño(vector, al.dia, al.mes); 

            if (strcmp(estacion.nombre, estacion) == 0) {
                cout << "Mes: " << al.mes; 
                cout << "Dia: " << al.dia; 
                cout << "Reservas: " << al.reservas; 
            }

        }

    }
}


Estaciones EstacionDelAño (Estaciones vector[], int dia, int mes) {
    // DADO UN DIA Y UN MES, HAY QUE INDICAR A QUE A QUE ESTACION DEL AÑO CORRESPONDE 
    // FECHA --> DD MM AAAA --> DD 00 00 + (00 MM 00 * 100) = FECHA
    // HAY 3 TEMPORADAS EN TOTAL EN CADA ZONA 
    int aux = 0; 
    aux = dia + (mes * 100); 

    for (int i = 0; i < 4; i++) {
        if (aux >= vector[i].fecha_inicio && aux <= vector[i].fecha_final) {
            return Estaciones[i]; 
        }
    }
}