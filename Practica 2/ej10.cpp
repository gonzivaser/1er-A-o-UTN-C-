/*Genere e informe una matriz MUL[10x10] con las tablas de multiplicar.*/
#include<iostream>
using namespace std; 


// i filas 
// j columnas 
// i = 0, 

int main () {
    int MUL[10][10]; 
    int i = 0; 

    for (i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            MUL[i][j] = (i + 1) * (j + 1); 
        }
    }
    
    // MUESTRO MATRIZ
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << MUL[i][j] << "\t"; 
        }
        cout << endl; 
    } 

    return 0; 
}