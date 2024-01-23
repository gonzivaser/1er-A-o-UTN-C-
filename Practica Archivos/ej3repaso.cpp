/*3.Dado el archivo binario generado en el ejercicio anterior, desarrolle un programa
que solicitando por teclado un código de materia permita seleccionar todos los registros que se anotaron 
para rendirla y los grabe en otro archivo (MATFINALES.DAT), con el mismo diseño. */

#include<iostream>
using namespace std; 

struct boleta {
    char nombre[50]; 
    int legajo; 
    int cod_mat; 
    int dia; 
    int mes; 
    int año; 
};

int main () {
    FILE* archivo1 = fopen("DIAFINALES.DAT", "rb"); 
    FILE* archivo2 = fopen("MATFINALES.DAT", "wb+"); 
    boleta al; 

    int codigo_nuevo; 
    cout << "Ingrese el codigo que quiere saber: "; 
    cin >> codigo_nuevo; 

    while(fread(&al, sizeof(boleta), 1, archivo1)) {
        if(al.cod_mat == codigo_nuevo) {
            fwrite(&al, sizeof(boleta), 1, archivo2); 
        }
    }
    
    fclose(archivo1); 

    fseek(archivo2, 0, SEEK_SET); 
    while(fread(&al, sizeof(boleta), 1, archivo2)) {
        cout << "Los alumnos son: " << al.nombre << endl; 
    }

    fclose(archivo2); 


    return 0; 
}