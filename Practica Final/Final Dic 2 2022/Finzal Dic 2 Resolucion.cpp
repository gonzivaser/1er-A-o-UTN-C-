#include<iostream>
#include<cstring>
using namespace std; 

/*
NOTAS: 
- 
*/

/*--------------STRUCTS----------------*/
/*-------VECTOR-------*/
struct VectorOctavos {
    char nombre_pais[50]; 
    char resultado[4]; 
};

/*-------FUNCIONES PROTOTIPO-------*/
void ActualizarVector (VectorOctavos [], char, char, int, char);


/*--------------INT MAIN----------------*/
int main () {
    return 0; 
}


/*--------------DECLARADAS----------------*/
void ActualizarVector (VectorOctavos vector[16], char pais1, char pais2, int instancia, char resultado) {
    int i = 0; 

    // EMPIEZO A RECORRER VECTOR
    for (i = 0; i < 16; i++) {
        if (strcmp(vector[i].nombre_pais, pais1) == 0 && strcmp(vector[i].nombre_pais, pais2) == 0) {
            if (vector[i].resultado[instancia] == instancia) {
                
            }
        }
    }
}