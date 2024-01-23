/*Se dispone de un conjunto de boletas de inscripción de alumnos a examen en el mes de mayo.
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
    char nombre[50]; 
    int legajo; 
    int cod_mat; 
    int dia; 
    int mes; 
    int año; 
};


int main () {
    FILE* archivo1 = fopen("DIAFINALES.DAT", "wb+");
    boleta al; 

    cout << "Ingrese nombre de la persona: "; 
    cin >> al.nombre; 

    while(strcmp(al.nombre, "x") != 0) {
        cout << "Ingrese el legajo: "; 
        cin >> al.legajo; 
        cout << "Ingrese el codigo de materia: "; 
        cin >> al.cod_mat; 
        cout << "Ingrese el dia: "; 
        cin >> al.dia; 
        cout << "Ingrese el mes: "; 
        cin >> al.mes; 
        cout << "Ingrese el año: "; 
        cin >> al.año; 

        fwrite(&al, sizeof(boleta), 1, archivo1); 

        cout << "Ingrese el nombre de la persona: "; 
        cin >> al.nombre; 
    }

    fclose(archivo1); 


    return 0; 
}