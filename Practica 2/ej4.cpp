/*4. Dado un número N (<25), y dos vectores A y B de N elementos que contenga
valores reales
a) genere e informe un tercer vector C intercalando los valores de posición impar de A y 
   los valores de posición par de B.
b) genere e informe un tercer vector D donde cada elemento contenga un valor cero si
los elementos de una misma posición de A y B son iguales, o un valor uno si no lo
son.*/

#include<iostream>
using namespace std; 

int main () {
    int n, i = 0; 
    cout << "Ingrese un valor MENOR que 25: "; 
    cin >> n; 
    
    int A[n], B[n], C[n], D[n];
    for (i = 0; i < n; i++) {
        cout << "Ingrese los valores para A: "; 
        cin >> A[i]; 
        cout << "Ingrese los valores para B: "; 
        cin >> B[i]; 
    }

    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            C[i] = B[i]; 
        }
        else {
            C[i] = A[i]; 
        }
        cout << "El vector C es: " << C[i] << endl; 
    }

    for (i = 0; i < n; i++) {
        if (A[i] == B[i]) {
            D[i] = 0; 
        }
        else {
            D[i] = 1; 
        }
        cout << "El vector D es: " << D[i] << endl; 
    }
    
    return 0;
}