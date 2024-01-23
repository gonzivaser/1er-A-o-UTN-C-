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

struct pasajero1 {
    int dni; 
    char nombre[50]; 
    char destino; 
    int valor_total; 
};

struct pasajero2 {
    int dni; 
    char nombre[50]; 
    char destino; 
    int valor_final; 
}; 

void CargarNuevoVector(FILE*, int, int, pasajero2 []);


int main () {
    FILE* archivo1 = fopen("PASAJERO1.DAT", "wb+"); 

    pasajero1 pas1; 
    pasajero2 pas2; 

    fclose(archivo1); 

    return 0; 
}


void CargarNuevoVector(FILE* archivo1, int aleatorio, int impuestos, pasajero2 nuevo_vec[]) {

    pasajero1 pas1; 
    pasajero2 pas2; 


    // INGRESO VALORES ALEATORIOS 
    cout << "Ingrese el numero aleatorio: "; 
    cin >> aleatorio; 
    cout << "Ingrese el porcentaje de impuestos: "; 
    cin >> impuestos; 


    // PASO ARCHIVO A VECTOR
    fseek(archivo1, 0, SEEK_END); 
    int D = ftell(archivo1); 
    int cantreg = D / sizeof(pasajero1); 
    pasajero1 vector[cantreg]; 
    fseek(archivo1, 0, SEEK_SET); 

    int i = 0; 
    while(fread(&pas1, sizeof(pasajero1), 1, archivo1)) {
        vector[i] = pas1; 
        i++; 
    }


    // CONDICIONES
    int valorfinal = 0; 
    int descuento = 0; 

    for (i = 0; i < cantreg; i++) {
        if (vector[i].dni % aleatorio == 0) {
            descuento = aleatorio * 10; 
        }
        valorfinal = vector[i].valor_total - (vector[i].valor_total * descuento / 100) + (impuestos * vector[i].valor_total / 100); 
    }


    // CARGO NUEVO VECTOR
    for (i = 0; i < cantreg; i++) {
        vector[i].dni = nuevo_vec[i].dni; 
        strcpy(nuevo_vec[i].nombre, vector[i].nombre); 
        strcpy(nuevo_vec[i].destino, vector[i].destino); 
        nuevo_vec[i].valor_final = valorfinal; 
    }
}