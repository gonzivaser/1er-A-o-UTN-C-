#include<iostream>
#include<string> 
using namespace std; 

struct alumno {
    int legajo; 
    char nombre [50]; 
    int promedio; 
}; 

void burbuja(alumno v[], int);


int main () {
    int i, j; 
    int n = 6; 
    alumno vector[] = {{50, "Juan", 7}, {22, "Analia", 8}, {10, "Axel", 6}, 
    {100, "Roxana", 10}, {9, "Camila", 9}, {11, "Dario", 7}}; 
    
    burbuja (vector, n); 

    for (i = 0; i < n; i++) {
        cout << vector[i].legajo << ", " << vector[j].nombre << endl; 
    }

    return 0;
}

void burbuja(alumno v[], int n) {
    int i, j;
    auto aux = 0; 
    for (i = 1; i < n; i++) {   // CONTANDO PASOS
        
        for (j = 1; j <= (n - i); j++) {  // COMPARACIONES
            if (v[j - 1].legajo > v[j].legajo) {
                aux = v[j - 1]; 
                v[j - 1] = v[j]; 
                v[j] = aux; 
            }
        }
    }  
}

