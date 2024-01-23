/*1. Se conoce de cada alumno de un curso los siguientes datos: legajo (8digitos) y 
las notas de 2 parciales (0..10), que finaliza con un legajo negativo.
Se pide desarrollar un programa que ingrese los datos de los alumnos por teclado y 
grabe un archivo binario CURSO.BIN con una línea por cada alumno, con el número de legajo y 
su promedio (real).
*/

#include<iostream>
using namespace std; 

struct alumno {
    int legajo;
    int nota1; 
    int nota2; 
};

int main () {
    
    FILE* archivo = fopen("CURSO.BIN", "wb+"); 
    alumno al; 

    cout << "Legajo: "; 
    cin >> al.legajo; 

    while (al.legajo > 0) {
        int promedio = 0; 
        promedio = (al.nota1 + al.nota2) / 2; 
        cout << "Nota 1: "; 
        cin >> al.nota1; 
        cout << "Nota 2: "; 
        cin >> al.nota2; 
        cout << "Legajo: "; 
        cin >> al.legajo; 
    }

    fwrite(&al, sizeof(alumno), 1, archivo); 

    fclose(archivo); 

    return 0; 
}