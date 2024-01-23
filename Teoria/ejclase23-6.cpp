/*
Dado Un vector de estructura con el maestro de articulos (ordenado x producto):
  	- idproducto int
  	- nombre char(50)
  	- cantidadVendida int

Se tiene otro vector con las novedades de articulos y ventas (desordenado):
	- idproducto int
  	- nombre char(50)
  	- cantidadVendida int
este segundo vector contiene las ventas del dia.

EJERCICIO: 
Se pide obtener una tercera estructura del mismo tipo
ordenada por producto que incluya el maestro actualizado con
las ventas del dia.

Ejemplo:
Maestro:
    - 7 lapiz azul,  0 unidades
	- 8  lapiz verde, 20 unidades
	- 20 goma de borrar, 100 unidades
	
Ventas:
   - 7  lapiz azul, 5 unidades
   - 10  cuaderno, 100 unidades
   - 8 lapiz verde, 23 unidades
   - 5 lapiz negro, 40 unidades
  
Nuevo Maestro:	
    - 5 lapiz negro, 40 unidades
	- 7  lapiz azul, 5 unidades
	- 8  lapiz verde, 43 unidades
	- 10 cuaderno, 100 unidades
	- 20 goma de borrar, 100 unidades
*/

#include<iostream>
using namespace std; 

struct Maestro {
    int idproducto; 
    char nombre[50]; 
    int cantidadVendida;
};

// PROTOTIPO DE FUNCIONES: 
void Burbuja(Maestro [], int &); 
void Apareo(Maestro [], Maestro [], int, int, Maestro [], int &);


// FUNCION MAIN
int main () {
    int i;
    int n = 3; 
    int m = 4;  
    int k = 0; 

    Maestro v1[n] = {{7, "lapiz azul", 0},{8,  "lapiz verde", 20}, {20, "goma de borrar", 100}}; 
    Maestro v2[m] = {{7, "lapiz azul", 20}, {10, "cuadernos", 100}, {8, "lapiz verde", 23}, {5, "lapiz negro", 40}}; 
    Maestro v3[n + m]; 

    Burbuja(v2, m); 
    Apareo(v1, v2, n, m, v3, k); 
    
    for (i = 0; i < k; i++) {
        cout << "El id del producto es: " << v3[i].idproducto << " el nombre del producto es: " << 
        v3[i].nombre << " la cantidad vendida es: " << v3[i].cantidadVendida << endl; 
    }
 


    return 0;
}


// FUNCIONES DECLARADAS 
void Burbuja (Maestro vector[], int &n) {
    int i, j; 
    Maestro aux; 

    for (i = 1; i < n; i++) {
        for (j = 1; j <= (n - i); j++) {
            if (vector[j - 1].idproducto > vector[j].idproducto) {
                aux = vector[j - 1].idproducto; 
                vector[j - 1].idproducto = vector[j].idproducto; 
                vector[j].idproducto = aux; 
            }
        }
    }
}

void Apareo(Maestro v1[], Maestro v2[], int n, int m, Maestro v3[], int &k) {
    int i = 0, j = 0; 
    int suma = 0; 

    while ((i < n) && (j < m)) {
        if (v1[i].idproducto < v2[j].idproducto) {
            v3[k] = v1[i];
            i++; // AVANZO PORQUE PASO DE POSICION
        }
        else if (v1[i].idproducto == v2[j].idproducto) { // SI EL VALOR ESTA EN AMBOS VECTORES
            suma = v1[i].cantidadVendida + v2[j].cantidadVendida; 
            v3[k] = v2[j];
            j++;
            i++; 
            v3[k].cantidadVendida = suma; 
        }
        else {
            v2[j] = v3[k]; 
            j++; 
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



