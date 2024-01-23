/*3.Dado el archivo binario generado en el ejercicio anterior, desarrolle un programa
que solicitando por teclado un código de materia permita seleccionar todos los registros que se anotaron 
para rendirla y los grabe en otro archivo (MATFINALES.DAT), con el mismo diseño. */

#include<iostream>
#include<cstring>
using namespace std; 

struct boleta {
    int legajo; 
    int codigo_mat; 
    int dia; 
    int mes; 
    int año; 
    char nombre[50]; 
};

int main () {
   
    FILE* archivo = fopen("DIAFINALES.DAT", "wb+");
    boleta persona; 
    int codigonuevo; 
   
    cout << "Ingrese el nombre y apellido: "; 
    cin >> persona.nombre; 
    
    while(strcmp(persona.nombre , "x") != 0) {
        cout << "Ingrese el legajo: "; 
        cin >> persona.legajo; 
        cout << "Ingrese el codigo de materia: "; 
        cin >> persona.codigo_mat; 
        cout << "Ingrese el dia: "; 
        cin >> persona.dia; 
        cout << "Ingrese el mes: "; 
        cin >> persona.mes; 
        cout << "Ingrese el año: "; 
        cin >> persona.año; 
        cout << "Ingrese el nombre y apellido: "; 
        cin >> persona.nombre; 
    }

    fwrite(&persona, sizeof(boleta), 1, archivo); 
    fseek(archivo, 0, SEEK_SET); 

    boleta persona2; 
    fread(&persona2, sizeof(boleta), 1, archivo); 

    
    /*-----------------NUEVO ARCHIVO--------------------------------*/

    FILE* archivo2 = fopen("MATFINALES.DAT", "wb+"); 

    cout << "Ingrese el codigo de materia que quiere saber la cantidad que rinden: "; 
    cin >> codigonuevo; 

    fseek(archivo, 0, SEEK_SET); 
    fread(&persona2, sizeof(boleta), 1, archivo); 
    
    while (!feof(archivo)) {

        if (persona2.codigo_mat = codigonuevo) {
            fwrite(&persona2, sizeof(boleta), 1, archivo2);
        }

        fread(&persona2, sizeof(boleta), 1, archivo); 
    }

    fclose(archivo); 
    fclose(archivo2); 

    
    return 0; 
}
