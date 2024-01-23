/*Dado un valor N (<50), y una matriz MAT[NxN] que contiene valores enteros.
Se pide:
a) Leerla por fila
b) Informarla por columna
c) Informar la sumatoria de sus elementos y el valor promedio
d) Informar el máximo elemento y su ubicación (fila y columna)
e) Informar el mínimo de cada fila y el máximo de cada columna
f) Informar cuantos elementos positivos hay en la diagonal principal y 
   cuantos negativos en la diagonal secundaria. */

#include <iostream>
using namespace std;

int main(){

    int i,j,n, suma=0, max=0, min=0, col,fila;
    int contador_positivos = 0; 
    int contador_negativos = 0; 
    cout<<"Valor < 50: ";
    cin>>n;

    int mat[n][n];
    int min_fila[n]={0};
    int max_col[n] = {0};

    // SUMA Y RELLENO DE MATRIZ 
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<"Digite mat["<<i+1<<"]["<<j+1<<"]: ";
            cin>>mat[i][j];
            suma+=mat[i][j];
        }
    }

    // ORDENO MATRIZ Y LA PONGO EN MODO MATRIZ
    for(int i=0; i<n; i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
    }

    // VALOR MAXIMO Y SU UBICACION 
    for(int i=0; i<n; i++){
        for(int j=0;j<n;j++){
            if(max == 0 || max < mat[i][j]){
                max=mat[i][j];
                fila=i+1;
                col=j+1;
            }
        }
    }
    
    // MINIMO DE CADA FILA 
    for(int i=0; i<n; i++){
            for(int j=0;j<n;j++){
                if(min_fila[i] == 0 || min_fila[i]>mat[i][j]){
                    min_fila[i] = mat[i][j];
                }
        }
    }

    // MAXIMO DE CADA COLUMNA 
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (max_col[j] == 0 || max_col[j] < mat[i][j]) {
                max_col[j] = mat[i][j]; 
            }
        }
    }

    // CUANTOS VALORES POSITIVOS EN LA DIAGONAL PRINCIPAL 
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j && mat[i][j] > 0) {
                contador_positivos++;  
            }
        }
    }

    // CUANTOS VALORES NEGATIVOS EN LA DIAGONAL SECUNDARIA 
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i + j == n - 1 && mat[i][j] < 0) {
                contador_negativos++; 
            }
        }
    } 


    // IMPRIMO: 

    // IMPRIMO SUMA Y PROMEDIO 
    cout<<"La suma de sus elementos es: "<<suma<<endl;
    cout<<"El promedio de sus elementos es: "<<suma / (n * n) << endl;

    // IMPRIMO EL MAXIMO ELEMENTO 
    cout << "El maximo elemento es " <<max<< ", y se encuentra en la fila " << fila << " y en la columna " << col << endl;
    
    // IMPRIMO EL MINIMO ELEMENTO DE CADA FILA
    for(i = 0; i < n; i++){
        cout<<"Min fila "<<i+1<<": "<<min_fila[i]<<endl;
    }

    // IMPRIMO EL MAXIMO ELEMENTO DE CADA COLUMNA 
    for (j = 0; j < n; j++) {
        cout << "Max col "<< j + 1 << ": " << max_col[j] << endl;
    }

    // IMRPIMO CUANTOS VALORES POSITIVOS EN LA DIAGONAL PRINCIPAL 
    cout << "Cantidad de valores positivos en la diagonal principal son: " << contador_positivos << endl; 
    
    // IMRPIMO CUANTOS VALORES NEGATIVOS EN LA DIAGONAL PRINCIPAL 
    cout << "Cantidad de valores negativos en la diagonal secundaria son: " << contador_negativos << endl; 


    return 0;
}

   


   

