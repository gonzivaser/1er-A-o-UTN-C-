#include<iostream>
using namespace std;

// VECTORES 
int main() {
	int vector[4] = { 0 };
	int i; 

	for (i = 0; i < 4; i++) {  
		cout << "Ingrese un valor: "; 
		cin >> vector[i]; 
	}
	for (i = 0; i < 4; i++) {
		cout << "El valor es: " 
		<< vector[i] << endl; 
	}

	return 0; 
}

// MATRICES 
int main() {
	int matriz[23][12];  // es fila y columnas
	int i, j; 

	for (i = 0; i < 23; i++) {
		for (j = 0; j < 12; j++) {
			cout << "Ingrese el valor: "; // el usuario ingresa los valores
			cin >> matriz[i][j]; 
		}
	}
}

// FUNCIONES

// prototipo
int suma (int[], int); 

int main () {
    int N = 10; 
    int vector [10]={3,4,5,6,7,8,9,90,11,22}; 
    cout << "El resultado es: "<< suma(vector,N); 
}


// funcion
int suma (int vector[], int N) {
    int i, suma = 0; 
    for (i = 0; i < n; i++) {
        suma = suma + vector[i]; 
    }
    return suma; 
} 