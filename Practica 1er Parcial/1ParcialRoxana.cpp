/*Una empresa de viajes decide aplicar un descuento a aquellos DNI que sean divisibles por un numero 
aleatorio. Si esto ocurre, se le aplica un descuento al VALOR TOTAL del numero aleatorio por 10. 
Ejemplo: Numero = 3 --> se aplica un descuento del 30%. 

Desarrollar la funcion que recibe un archivo abierto, numero aleatorio, porcentaje impuestos, y 
el nuevo vector a cargar. */

/*El archvio de los pasajeros contiene, DNI, NOMBRE, DESTINO, VALOR TOTAL. */

/*Esta funcion tiene como objetivo, cargar un nuevo vector que en vez de tener VALOR TOTAL, tenga 
VALOR FINAL el cual sera VALOR TOTAL - DESCUENTO + IMPUESTOS y tambien tenga NOMBRE, DNI y DESTINO. */

/*Defina estructuras de datos necesarios y prototipo. */


/* COSAS A HACER: 
1. Declarar funcion, estructuras, etc. 
2. Pasar el archivo a vector. 
3. Poner las condiciones para el nuevo vector 
4. Cargar el nuevo vector 
*/

#include<iostream>
#include<cstring>
using namespace std; 

struct pasajero {
    int dni; 
    char nombre[50]; 
    char destino[50]; 
    int valor_total; 
};

struct pasajero2 {
    int dni; 
    char nombre[50]; 
    char destino[50]; 
    int valor_final; 
};

// PROTOTIPO
void CargarNuevoVector (FILE*, int, int, pasajero[]); 


// MAIN 
int main () {
    return 0; 
}


// FUNCIONES DECALRADAS 
void CargarNuevoVector (FILE* archivoP, int numero_aleatorio, int impuestos, pasajero2 vecpasajero2[]) {
    
    cout << "Ingrese el numero aleatorio: "; 
    cin >> numero_aleatorio; 
    cout << "Ingrese el porcentaje de impuestos: "; 
    cin >> impuestos; 


    // PASO ARCHIVO A VECTOR
    pasajero pas;

    fseek(archivoP, 0, SEEK_END); 
    int D = ftell(archivoP); 
    int cantreg = D / sizeof(pasajero); 
    pasajero vecpasajero1[cantreg]; 
    fseek(archivoP, 0, SEEK_SET); 

    int i = 0; 
    while(fread(&pas, sizeof(pasajero), 1, archivoP)) {
        vecpasajero1[i] = pas; 
        i++; 
    } 


    // PONGO NUEVAS CONDICIONES 
    int descuento; 
    int valor_final; 
    for (i = 0; i < cantreg; i++) {
        if (vecpasajero1[i].dni % numero_aleatorio == 0) {
            descuento = numero_aleatorio * 10; 
        }
        valor_final = vecpasajero1[i].valor_total - (vecpasajero1[i].valor_total * descuento / 100) + impuestos; 
    }

    // CARGO NUEVO VECTOR
    for (i = 0; i < cantreg; i++) {
        vecpasajero1[i].dni = vecpasajero2[i].dni; 
        strcpy(vecpasajero2[i].nombre, vecpasajero2[i].nombre); 
        strcpy(vecpasajero2[i].destino, vecpasajero1[i].destino); 
        vecpasajero1[i].valor_total = valor_final; 
    }
}

