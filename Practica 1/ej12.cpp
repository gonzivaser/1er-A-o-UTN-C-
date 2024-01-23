/*Dado un conjunto de Nombres y Fechas de nacimientos (AAAAMMDD), que finaliza con un Nombre= “FIN”, 
informar el nombre de la persona con mayor edad y el de la mas joven. 
Utilizar la función strcmp (<cstring>) para evaluar fin de datos.*/

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char nombre[50];
    char nombreMayor[50];
    char nombreMenor[50];
    int fecha;
    int mayor = 0;
    int menor = 99999999; // Inicializamos la menor fecha con un valor alto para asegurarnos de que cualquier fecha válida sea menor.

    cout << "Ingrese el nombre de la persona: ";
    cin >> nombre;

    while (strcmp(nombre, "FIN") != 0) {
        cout << "Ingrese la fecha de nacimiento de la persona (AAAAMMDD): ";
        cin >> fecha;

        if (fecha > mayor) {
            mayor = fecha;
            strcpy(nombreMayor, nombre);
        }

        if (fecha < menor) {
            menor = fecha;
            strcpy(nombreMenor, nombre);
        }

        cout << "Ingrese el nombre de la persona: ";
        cin >> nombre;
    }


        cout << "El nombre de la persona con mayor edad es: " << nombreMayor << endl;
        cout << "El nombre de la persona más joven es: " << nombreMenor << endl;


    return 0;
}
