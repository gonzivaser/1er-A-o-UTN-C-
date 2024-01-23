/*5. Se dispone un archivo binario de inscripción de alumnos a exámenes finales
MAESTROFINALES.DAT y otro con las inscripciones del día de hoy DIAFINALES.DAT,
ambos ordenados ascendente por código de materia y con el siguiente diseño:
a. Nro de legajo (8 dígitos)
b. Código de materia (6 dígitos)
c. ApellidoNombre(25caract)
Se pide desarrollar un programa que genere un nuevo archivo de inscripciones a finales
FINALESACT.DAT resultante del apareo de los dos archivos anteriores, con el mismo orden
y diseño.
*/

#include<iostream>
using namespace std; 

struct alumno {
    int legajo; 
    int cod_mat; 
    char nombre[50]; 
}; 

void Apareo (alumno [], int, alumno [], int, alumno []); 

int main () {
    FILE* archivoM = fopen("MAESTROFINALES.DAT", "rb"); 
    FILE* archivoD = fopen("DIAFINALES.DAT", "rb"); 
    FILE* archivoF = fopen("FINALESACT.DAT", "wb+");

    alumno alM; 
    alumno alD;

    // PASO A VECTOR EL ARCHIVO DE MAESTRO
    fseek(archivoM, 0, SEEK_END); 
    int D = ftell(archivoM); 
    int cantregM = D / sizeof(alumno); 
    alumno vectorM[cantregM]; 
    fseek(archivoM, 0, SEEK_SET); 

    int i = 0; 
    while(fread(&alM, sizeof(alumno), 1, archivoM)) {
        vectorM[i] = alM; 
        i++;  
    }
  
    // PASO A VECTOR EL ARCHIVO DE DIAFINALES
    fseek(archivoD, 0, SEEK_END); 
    int A = ftell(archivoD); 
    int cantregD = A / sizeof(alumno); 
    alumno vectorD[cantregD]; 
    fseek(archivoD, 0, SEEK_SET); 
    int i = 0; 
    while(fread(&alD, sizeof(alumno), 1, archivoD)) {
        vectorD[i] = alD; 
        i++;  
    }

    alumno alF[cantregD + cantregM]; 

    // APLICO FUNCION APAREO
    Apareo (vectorM, cantregM, vectorD, cantregD); 


    // ESCRIBO ARCHIVO NUEVO
    fwrite(&alF, sizeof(alumno), 1, archivoF); 
    

    // CIERRE DE ARCHIVOS 
    fclose(archivoM); 
    fclose(archivoD); 
    fclose(archivoF); 


    return 0; 
}


void Apareo(alumno alM[], int cantregM, alumno alD[], int cantregD, alumno alF[]) {
    int i = 0, j = 0, k = 0;
    
    while (i < cantregM && j < cantregD) {
        alumno alF[k]; 
        if (alM[i].cod_mat < alD[j].cod_mat) {
            alF[k] = alM[i];
            i++;
        } else if (alM[i].cod_mat > alD[j].cod_mat) {
            alF[k] = alD[j];
            j++;
        } else {
            alF[k] = alM[i];
            i++;
            j++;
        }
        k++;
    }

    // Copiar los registros restantes de alM (si los hay)
    while (i < cantregM) {
        alF[k] = alM[i];
        i++;
        k++;
    }

    // Copiar los registros restantes de alD (si los hay)
    while (j < cantregD) {
        alF[k] = alD[j];
        j++;
        k++;
    }

}

