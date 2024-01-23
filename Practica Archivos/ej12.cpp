/*12. Una empresa que distribuye mercadería hacia distintas localidades del interior 
dispone de dos archivos de registros:

Uno denominado DESTINOS con información de la distancia a cada uno de los destinos: 
a) Nro. De destino (3 dígitos) 
b) Distancia en kilómetros (NNN.NNN)

Otro denominado VIAJES con los viajes realizados por cada camión (< 200), donde cada registro contiene:
a) Patente del camión (6 caracteres)
b) Nro. de destino
c) Nro. de chofer (1 a 150)

Desarrollar estrategia, algoritmo y codificación del programa que determine e imprima:
1) Cantidad de viajes realizados a cada destino (solo si > 0).
2) Nro. de chofer con menor cantidad de Km (entre los que viajaron).
3) Patente de los camiones que viajaron al destino 116 sin repeticiones de las mismas.
*/

#include<iostream>
#include<cstring>
using namespace std; 

struct destinos {
    int numero_destino; 
    int distancia; 
};

struct viajes {
    char patente[30]; 
    int numero_destino; 
    int numero_chofer; 
};

void CantidadDeViajes(FILE*, FILE*, destinos [], viajes []);


int main () {
    FILE* archivoD = fopen("DESTINOS.DAT", "rb"); 
    FILE* archivoV = fopen("VIAJES.DAT", "rb"); 

    destinos alD; 
    viajes alV; 

    int i = 0, k = 0; 
    // PASO ARCHIVO DESTINOS A VECTOR
    fseek(archivoD, 0, SEEK_END); 
    int D = ftell(archivoD); 
    int cantregD = D / sizeof(destinos); 
    destinos vectorD[cantregD]; 
    fseek(archivoD, 0, SEEK_SET); 

    while(fread(&alD, sizeof(destinos), 1, archivoD)) {
        vectorD[i] = alD;
        i++;  
    }

    // PASO ARCHIVO DESTINOS A VECTOR
    fseek(archivoV, 0, SEEK_END); 
    int V = ftell(archivoV); 
    int cantregV = V / sizeof(viajes); 
    viajes vectorV[cantregV]; 
    fseek(archivoV, 0, SEEK_SET); 

    while(fread(&alV, sizeof(viajes), 1, archivoV)) {
        vectorV[k] = alV; 
        k++; 
    } 


    fclose(archivoD); 
    fclose(archivoV); 

    return 0; 
}

void CantidadDeViajes(destinos vectorD [], viajes vectorV[], int cantregV, int cantregD) {
    int cantidad_viajes = 0; 
    for (int i = 0; i < cantregV; i++) {
        if (vectorV[i].numero_destino == vectorD[i].numero_destino) {
            cantidad_viajes++; 
        }
    }
}

void NumeroDeChofer () {
    int menor_distancia = vectorD[0].distancia; 
    for (int i = 0; i < cantregD; i++) {
        if (vectorD[i].distancia < menor_distancia) {
            menor_distancia = vectorD[i].distancia; 
        }

        

    }
}

