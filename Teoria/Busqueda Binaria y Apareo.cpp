#include<iostream>
using namespace std; 

struct alumno {
    int legajo; 
    char nombre[50]; 
    int cantMatAprobadas; 
};

void Burbuja (alumno [], int); // BURBUJEO
int bb(alumno[], int, int); // BUSQUEDA BINARIA 
void apareo(int [], int[], int, int, int[]);

int main () {
    // DADO UN VECTOR DESORDENADO CON LA ESTRUCTURA DADA 
    // ENCONTRAR EL NOMBRE DEL LEGAJO 100
    int n, i, j; 
    int buscado = 100; 
    int pos; 
    
    cout << "Ingrese la cantidad de alumnos: "; 
    cin >> n; 
    alumno vector [n]; 

    for (i = 0; i < n; i++) {
        cout << "Ingrese el legajo del alumno: "; 
        cin >> vector[i].legajo; 

        cout << "Ingrese el nombre del alumno: "; 
        cin >> vector[i].nombre; 

        cout << "Ingrese la cantidad de materias aprobadas: "; 
        cin >> vector[i].cantMatAprobadas; 
    }

    Burbuja(vector, n); 
    pos = bb(vector, n, buscado); 
    cout << "El nombre del alumno es: " << vector[pos].nombre << endl; 

    return 0; 
}

void Burbuja (alumno vector[], int n) {
    int i, j; 
    int aux; 

    for (i = 1; i < n; i++) {
        for (j = 1; j <= (n - i); j++) {
            if (vector[j - 1].legajo > vector[j].legajo) {
                aux = vector[j - 1].legajo; 
                vector[j - 1].legajo = vector[j].legajo; 
                vector[j].legajo = aux; 
            }
        }
    }
}


void apareo(int v1[], int v2[], int n, int m, int v3[]) {
    int i = 0, j = 0, k = 0;

    while ((i < n) && (j < m)) {
        if (v1[i] < v2[j]) {
            v3[k] = v[i];
            i++; // AVANZO PORQUE PASO DE POSICION
        }
        else if (v1[i] == v2[j]) { // SI EL VALOR ESTA EN AMBOS VECTORES
            v3[k] == v2[j]; 
            j++;
            i++; 
        }
        else {
            v2[j] = v3[k]; 
            j++
        }
        k++; // VOY AVANZANDO SIEMPRE EN EL V3
    }

    while (i < n) {
        v3[k] = v1[i]; 
        i++; 
        k++; 
    }

    while (j < m) {
        v3[k] = v2[j]; 
        j++; 
        k++;
    }
}


int bb(alumno vector[], int n, int buscado) {
    int primero = 0; 
    int ultimo = n - 1; 
    int medio;

    while (primero <= ultimo) { 
        medio = (primero + ultimo) / 2; 

        if(vector[medio].legajo == buscado) {
            return medio; 
        }
        else if (vector[medio].legajo > buscado) {
            ultimo = medio - 1; // DONDE MIRE ME QUEDO CON EL VALOR DE LA IZQUIERDA
        }
        else {
            primero = medio + 1; 
        }
    }

    return -1; // si no llega a esta el valor devuelvo un valor que no sea valido en un vector
}