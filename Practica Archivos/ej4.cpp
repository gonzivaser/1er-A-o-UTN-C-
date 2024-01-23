/*4. Dado el archivo binario generado en el ejercicio anterior, desarrolle un programa
que genere un archivo ordenado por número de legajo (cada registro debe tener 
los campos legajo y apellido y nombre) para todos los alumnos que se inscribieron una o más veces. 
*/

#include<iostream>
#include<cstring>
using namespace std; 

struct boleta {
    char nombre[50]; 
    int legajo; 
    int cod_mat; 
    int dia; 
    int mes; 
    int año; 
};

struct boleta2 {
    char nombre[50]; 
    int legajo; 
}; 

void burbuja (boleta [], int); 


int main () {
    FILE* archivoM = fopen("MATFINALES.DAT", "rb"); 
    FILE* archivoL = fopen("LEGAJO.DAT", "wb+"); 
    boleta al; 
    boleta2 al2; 

    fseek(archivoM, 0, SEEK_END); 
    int D = ftell(archivoM); 
    int cantreg; 
    cantreg = D / sizeof(boleta); 
    fseek (archivoM, 0, SEEK_SET); 

    boleta vector[cantreg]; 
    boleta2 vector2[cantreg]; 

    int i = 0; 
    while(fread(&al, sizeof(boleta), 1, archivoM)) {
        vector[i] = al; 
        i++;  
    }

    burbuja(vector, cantreg); 

    for (i = 0; i < cantreg; i++) {
        cout << "Nombre: " << vector[i].nombre << endl; 
        cout << "Legajo: " << vector[i].legajo << endl; 
    }

    // ACHICAR VECTOR
    // CON VECTOR ACHICADO LO ESCRIVO EN EL ARCHIVO 2
    // ESCRIBIR EL ARCHVIO 2

    for (i = 0; i < cantreg; i++) {
        vector2[i].legajo = vector[i].legajo; 
        strcpy(vector2[i].nombre, vector[i].nombre); 
    }

    for (i = 0; i < cantreg; i++) {
        cout << "El legajo es : " << vector2[i].legajo << endl; 
        cout << "El nombre es : " << vector2[i].nombre << endl;
        fwrite(&vector2[i], sizeof(boleta2), 1, archivoL); 
    }


    fclose(archivoM); 
    fclose(archivoL); 

    return 0; 
}

void burbuja (boleta vector[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (vector[j].legajo > vector[j+1].legajo) {
                int aux = vector[j].legajo; 
                vector[j].legajo = vector[j+1].legajo; 
                vector[j+1].legajo = aux; 
            }
        }
    }
}

