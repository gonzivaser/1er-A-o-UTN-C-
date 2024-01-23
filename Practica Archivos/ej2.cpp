/*2. Se dispone de un conjunto de boletas de inscripción de alumnos a examen en el
mes de mayo.
Cada boleta tiene los siguientes datos: nombre y apellido, número de legajo, código
de materia, día, mes y año del examen. Los datos finalizan con un nombre y apellido =”x”.
Desarrollar un programa que a partir del ingreso de las boletas mencionadas, por
teclado, genere un archivo binario de inscripción de alumnos a exámenes finales
DIAFINALES.DAT, según el siguiente diseño:
a. Nro. de legajo (8 dígitos)
b. Código de materia (6 dígitos)
c. Día del examen (1..31)
d. Mes del examen (1..12)
e. Año del examen (4 dígitos)
f. Nombre-Apellido (25caract) 
*/

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
    fclose(archivo); 

    return 0; 
}