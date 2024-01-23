#include<iostream>
using namespace std; 

void burbuja(int [], int); 

int main () {
    int i; 
    int n = 6; 
    int vector[] = {3, 67, 2, 100, 99, 4}; 
    burbuja (vector, n); 

    for (i = 0; i < n; i++) {
        cout << vector[i] << endl; 
    }

    return 0;
}

void burbuja(int v[], int n) {
    int i, j;
    int aux; 
    for (i = 1; i < n; i++) {   // CONTANDO PASOS
        
        for (j = 1; j <= (n - i); j++) {  // COMPARACIONES
            if (v[j - 1] > v[j]) {
                aux = v[j - 1]; 
                v[j - 1] = v[j]; 
                v[j] = aux; 
            }
        }
    }  
}