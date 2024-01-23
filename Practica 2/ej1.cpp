/*1. Dado un número N (<30), 
genere e informe un vector VEC de N elementos 
que contenga los primeros N números naturales pares.*/

#include<iostream>
using namespace std; 

int main () {
    int i, n; 

    cout << "Ingrese un valor MENOR que 30: "; 
    cin >> n; 
    int vect[n]; 

    for (i = 0; i < n; i++) {
        vect[i] = i; 
        if (vect[i] % 2 == 0 && vect[i] > 0) {
            cout << vect[i] << endl; 
        }
    }

    return 0; 
}