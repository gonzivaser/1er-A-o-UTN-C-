#include<iostream>
#include<cstring>
using namespace std; 

/*
NOTAS: 
- MATRIZ [60][7]
- VECTOR
*/

/*--------------STRUCTS----------------*/
/*-------MATRIZ-------*/
struct MatrizTipo {
    int parcial1; 
    int parcial2; 
    int recu1_parcial1; 
    int recu1_parcial2; 
    int recu2_parcial1; 
    int recu2_parcial2; 
    int trabajo_practico; 
};

/*-------VECTOR-------*/
struct VectorAlumno { // ORDENADO POR LEGAJO
    int legajo; 
    char apellido[50]; 
    char nombre[50]; 
};

/*-------FUNCIONES PROTOTIPO-------*/
void BurbujaPorNomYAp (VectorAlumno [], int);
void MostrarNotas (MatrizTipo [][], VectorAlumno []);



/*--------------INT MAIN----------------*/
int main () {
    return 0; 
}


/*--------------DECLARADAS----------------*/
void MostrarNotas (MatrizTipo matriz[60][7], VectorAlumno vector[60]) {
    // ANTES DE EMPEZAR A MOSTRAR VOY A ORDENAR MI VECTOR POR NOMBRE Y APELLIDO
    BurbujaPorNomYAp(vector, 60); 

    // ARMO LISTA
    cout << "Orden " << "\t Apellido " << "\t Situacion Academica " << endl; 

    // COMO YA TENGO ORDENADO EL VECTOR, PUEDO UTILIZAR MATRIZ PARA ESTABLECER CONDICIONES
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 7; j++) {
            // PROMOCIONA
            if ((matriz[i][j].parcial1 >= 8 || matriz[i][j].recu1_parcial1 >= 8) && (matriz[i][j].parcial2 >= 8 || matriz[i][j].recu1_parcial2 >= 8) && matriz[i][j].trabajo_practico >= 8) {
                cout << i + 1 << "\t" << vector[i].apellido << "\t Promociona " << endl; 
            }
            else if (((matriz[i][j].parcial1 >= 6 || matriz[i][j].parcial1 < 8) || (matriz[i][j].recu1_parcial1 >= 6 || matriz[i][j].recu1_parcial1 < 8)) && ((matriz[i][j].parcial2 >= 6 || matriz[i][j].parcial2 < 8) || (matriz[i][j].recu1_parcial2 >= 6 || matriz[i][j].recu1_parcial2 < 8)) && (matriz[i][j].trabajo_practico >= 6)) {
                cout << i + 1 << "\t" << vector[i].apellido << "\t Regulariza " << endl; 
            }
            else {
                cout << i + 1 << "\t" << vector[i].apellido << "\t No Aprobado " << endl; 
            }
        }
    }
}


void BurbujaPorNomYAp (VectorAlumno vector[], int N) {
    int i, j; 
    VectorAlumno aux; 

    for (i = 1; i < N; i++) {
        for (j = 1; j < (N - i); j++) {
            (strcmp(vector[j - 1].apellido, vector[j].apellido) == 1) {
                aux = vector[j - 1];
                vector[j - 1] = vector[j]; 
                vector[j] = aux; 
            }
        }
    }
}