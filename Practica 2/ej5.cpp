/*Escriba un programa que permita ingresar la tirada de un par de dados 50 veces
y muestre una lista donde se vea cuántas veces se dio cada uno de los resultados posibles. 
Por cada tirada se deberán ingresar 2 valores, cada uno representa el valor de un dado. 
El formato de la salida debe ser el siguiente:
2 salió ... veces
3 salió ... veces
. . 12 salió ... veces */
#include<iostream> 
using namespace std; 

int main () {
    int dado1, dado2, suma = 0, max_resultado = 12; 
    int resultados[12] = {0}; 

    // Cantidad de tiradas de dado 
    for (int i = 0; i < 4; i++) {
        cout << "Ingrese valor de Dado 1: "; 
        cin >> dado1; 
        cout << "Ingrese valor de Dado 2: "; 
        cin >> dado2; 

        suma = dado1 + dado2; 
        resultados[suma]++; // El ++ es para pasar a la siguiente posicion 
    } 

    for (int i = 2; i <= max_resultado; i++) {
        cout << "Suma " << i << ": " << resultados[i] << " veces" << endl; 
    }

    return 0;
}