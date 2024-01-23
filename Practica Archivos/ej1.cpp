/*1. Se conoce de cada alumno de un curso los siguientes datos: legajo (8digitos) y 
las notas de 2 parciales (0..10), que finaliza con un legajo negativo.
Se pide desarrollar un programa que ingrese los datos de los alumnos por teclado y 
grabe un archivo binario CURSO.BIN con una línea por cada alumno, con el número de legajo y 
su promedio (real).
*/

#include<iostream>
using namespace std; 

/*------------STRUCT--------------*/
struct alumno {
    int legajo; 
    int nota1; 
    int nota2; 
};


/*------------INT MAIN--------------*/
int main () {
    
    FILE* archivo = fopen("CURSO.BIN", "wb+"); 
    alumno al; 
    
    cout << "Ingrese el legajo del alumno: "; 
    cin >> al.legajo; 

    while (al.legajo > 0) {
        int promedio = 0; 
        promedio = (al.nota1 + al.nota2) / 2; 
        cout << "Ingrese la nota del primer parcial: "; 
        cin >> al.nota1; 
        cout << "Ingrese la nota del segundo parcial: "; 
        cin >> al.nota2; 
        cout << "Ingrese el legajo del alumno: "; 
        cin >> al.legajo; 
    }

    fwrite(&al, sizeof(alumno), 1, archivo); 
    fseek(archivo, 0, SEEK_SET); 

    alumno al2; 
    fread(&al2, sizeof(alumno), 1, archivo); 

    while (!feof(archivo)) {
        int promedio = (al2.nota1 + al2.nota2) / 2; 
        cout << "El legajo de la persona es: " << al2.legajo << endl; 
        cout << "El promedio de la persona es: " << promedio << endl; 

        fread(&al2, sizeof(alumno), 1, archivo); 
    }

    fclose(archivo); 

    return 0; 
}