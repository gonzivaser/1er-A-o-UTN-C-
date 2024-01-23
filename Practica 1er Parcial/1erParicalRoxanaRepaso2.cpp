/*Una empresa de viajes decide aplicar un descuento a aquellos DNI que sean divisibles por un numero 
aleatorio. Si esto ocurre, se le aplica un descuento al VALOR TOTAL del numero aleatorio por 10. 
Ejemplo: Numero = 3 --> se aplica un descuento del 30%. 

Desarrollar la funcion que recibe un archivo abierto, numero aleatorio, porcentaje impuestos, y 
el nuevo vector a cargar. */

/*El archvio de los pasajeros contiene, DNI, NOMBRE, DESTINO, VALOR TOTAL. */

/*Esta funcion tiene como objetivo, cargar un nuevo vector que en vez de tener VALOR TOTAL, tenga 
VALOR FINAL el cual sera VALOR TOTAL - DESCUENTO + IMPUESTOS y tambien tenga NOMBRE, DNI y DESTINO. */

/*Defina estructuras de datos necesarios y prototipo. */

#include<iostream>
#include<cstring>
using namespace std;

struct pasajero {
    int dni; 
    char nombre[50]; 
    char destino[50]; 
    int valor_total: 
};

struct nuevo_pasajero {
    int dni; 
    char nombre[50]; 
    char destino[50]; 
    int valor_final; 
}; 

void CargarArchivoEnVector(FILE*, int, int, nuevo_pasajero []); 

int main () {
    return 0; 
}

void CargarArchivoEnVector (FILE* f, int aleatorio, int porcentaje_impuestos, nuevo_pasajero vectorN []) {
    
    cout << "Ingrese el numero aleatorio: "; 
    cin >> aleatorio; 
    cout << "Ingrese el porcentaje de impuestos: "; 
    cin >> porcentaje_impuestos; 

    // PASO ARCHIVO A VECTOR 
    fseek(f, 0, SEEK_END); 
    int D = ftell(f); 
    int cantreg = D / sizeof(pasajero); 
    fseek(f, 0, SEEK_SET); 

    pasajero pas;
    pasajero vectorP [cantreg]; 
    
    int i = 0; 
    while(fread(&pas, sizeof(pasajero), 1, f)) {
        vectorP[i] = pas; 
        i++; 
    }


    // PONGO NUEVAS CONDICIONES
    int descuento = 0; 
    int valor_final = 0;
    for (i = 0; i < cantreg; i++) {
        if (vectorP[i].dni % aleatorio == 0) {
            descuento = aleatorio * 10; 
        }
        valor_final = vectorP[i].valor_total - (vectorP[i].valor_total * descuento / 100) + (vectorP[i].valor_total * porcentaje_impuestos / 100); 
    }


    // PONGO NUEVO VECTOR
    for (i = 0; i < cantreg; i++) {
        vectorN[i].dni = vectorP[i].dni; 
        strcpy(vectorN[i].nombre, vectorP[i].nombre); 
        strcpy(vectorN[i].destino, vectorP[i].destino); 
        vectorN[i].valor_final = valor_final; 
    }

}

