/*8. Dado un numero N (<50), y un vector VEC de N valores enteros positivos ordene 
  el contenido del vector y lo informe, aplicando el procedimiento Burbujeo:
• En orden ascendente
• En orden descendente
*/

#include<iostream>
using namespace std; 

void burbuja_as(int [], int); 
void burbuja_des(int [], int); 

int main () {
    int n, i = 0; 
    cout << "Ingrese la longitud del vector: ";    // VECTOR ASCENDENTE 
    cin >> n; 
    int vec[n]; 

    for (i = 0; i < n; i++) {
        cout << "Ingrese el valor " << i+1 << ": "; 
        cin >> vec[i]; 
    }

    burbuja_as(vec, n); // IMPRIMO VECTOR ASCENEDENTE
    for (i = 0; i < n; i++) {
        cout << "Los valores del vector ascendente son: " << vec[i] << endl; 
    }

    burbuja_des(vec, n);  // IMPRIMO VECTOR DESCENDENTE
    for (i = 0; i < n; i++) {
        cout << "Los valores del vector descendente son: " << vec[i] << endl; 
    }

    
    return 0; 
}

void burbuja_as (int vec[], int n) {
    int i, j; 
    int aux; 

    for (i = 1; i < n; i++) {
        for (j = 1; j <= (n - i); j++) {
            if (vec[j - 1] > vec[j]) {
                aux = vec[j - 1]; 
                vec[j - 1] = vec[j]; 
                vec[j] = aux; 
            }
        }
    }
}

void burbuja_des (int vec[], int n) {
    int i, j; 
    int aux2; 

    for (i = 1; i < n; i++) {
        for (j = 1; j < (n - i + 1); j++) {
            if (vec[j] > vec[j - 1]) {
                aux2 = vec[j]; 
                vec[j] = vec[j - 1]; 
                vec[j - 1] = aux2;  
            }
        }
    }
}