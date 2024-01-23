/*PUNTO 1: */
/*Codifique la declaración de todas estructuras de datos inicializando adecuadamente las constantes
simbólicas a utilizar.*/

/*PUNTO 2: */
/*Codifique o diagrame la función de la función void leerArchivo(FILE* f,alumnos alumnos[],int CANT).
Que reciba un archivo abierto con los datos que necesita, el valor de CANT que ya fue ingresado por 
el usuario y un vector inicializado para almacenar los datos del archivo según el criterio descripto.*/

/*PUNTO 3: */
/*Codifique o diagrame la función void informarResultados(TipoAl alumnos[]) que reciba el vector de la
función anterior e informe cantidad de alumnos por curso, liste los legajos ordenados e informe el total.
Ej: 
CURSO: K10
Cantidad de Grupos conformados: 99
Legajos
9999…
CURSO:K20…….
------------------
TOTAL DE GRUPOS: 999. */

/*PUNTO 4*/
/*4. (1 puntos) Codifique o diagrame la función que inicializa el vector 
void inicializarVector(TipoAl alumnos[]))*/

#include<iostream>
#include<cstring>
using namespace std; 

struct alumno {
    int curso; 
    char nombre[50];
    int legajo;     
    char turno[2]; 
};

void CargarDatos (FILE*, alumno); 
void LeerArchivo(FILE*, alumno [], alumno); 
void BurbujaPorLegajo(alumno [], int); 
void InformarResultados(alumno [], int); 


int main () {
    FILE* f = fopen("ALUMNOS.DAT", "rb");
    alumno al; 

    CargarDatos(f, al);    // CARGO DATOS AL ARCHIVO

    fseek(f, 0, SEEK_END); 
    int D = ftell(f); 
    int cantreg = D / sizeof(alumno); 
    alumno vector[cantreg]; 
    fseek(f, 0, SEEK_SET); 


    LeerArchivo(f, vector, al);  // PASO ARCHIVO A VECTOR 

    BurbujaPorLegajo(vector, cantreg); // ORDENO VECTOR POR LEGAJO Y CURSO 


    fclose(f); 

    return 0; 
}


void CargarDatos (FILE* f, alumno al) {
    cout << "Ingrese el nombre: "; 
    cin >> al.nombre; 

    while(strcmp(al.nombre, "x") != 0) {
        cout << "Ingrese el curso: "; 
        cin >> al.curso; 
        cout << "Ingrese el legajo: "; 
        cin >> al.legajo; 
        cout << "Ingrese el turno: "; 
        cin >> al.turno; 

        fwrite(&al, sizeof(alumno), 1, f); 

        cout << "Ingrese el nombre: "; 
        cin >> al.nombre; 
    }
}

void LeerArchivo (FILE* f, alumno vector[], alumno al) {
    int i = 0; 
    while(fread(&al, sizeof(alumno), 1, f)) {
        vector[i] = al; 
        i++; 
    }
}

void BurbujaPorLegajo (alumno vector[], int cantreg) {
    for (int i = 0; i < cantreg; i++) {
        for (int j = 0; j < cantreg - 1 - i; j++) {

            // Primero se compara por "curso"
            if (vector[j].curso > vector[j + 1].curso) {
                // Intercambio por "curso"
                alumno aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
            }

            // Si los cursos son iguales, se compara por "legajo"
            else if (vector[j].curso == vector[j + 1].curso && vector[j].legajo > vector[j + 1].legajo) {
                // Intercambio por "legajo"
                alumno aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
            }
        }
    }
}


void InformarResultados(alumno vector [], int cantreg) {
    int i = 0; 
    int curso; 
    int cant_grupos = 0; 
    int cant_alumnos = 0; 
    int aux = 0; 

    while (i < cantreg) {
        curso = vector[i].curso; 
        cout << "CURSO: " << vector[i].curso << endl; 

        while (i < cantreg && curso == vector[i].curso) {
            cout << "Ingrese la cantidad de alumnos por grupo: "; 
            cin >> cant_grupos; 
            

        }

        
        

    }
}
