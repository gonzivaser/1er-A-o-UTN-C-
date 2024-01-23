/*2. Ingresar un valor entero N (< 30) y a continuación un conjunto de N elementos. 
Si el último elemento del conjunto tiene un valor menor que 10 imprimir los negativos y 
en caso contrario los demás*/

#include<iostream>
using namespace std; 

int main () {
    int n; 
    cout << "Ingrese un valor < 30: "; 
    cin >> n; 
    int vect[n]; 

    for (int i = 0; i < n; i++) {
        cout << "Ingrese un valor para completar el conjunto: "; 
        cin >> vect[i]; 
    }

    for (int j = 0; j < n; j++) {
        if (vect[n - 1] < 10) {
            if (vect[j] < 0) {
                cout << "Los negativos son: " << vect[j] << endl; 
            }
        }
        else if (vect [n - 1] >= 10) {
                if (vect[j] > 0) {
                    cout << "Los positivos son: " << vect[j] << endl; 
                }
            }
    }


    return 0;
}