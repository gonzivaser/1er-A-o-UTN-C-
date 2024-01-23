/*17.Desarrolle la función
float CalcularPorcentajeDiferencia(int A ,int B) que recibe dos valores y retorne el siguiente calculo:
(B-A) *100 / (A+B)
*/

#include<iostream>
using namespace std; 

    float CalcularPorcentajeDiferencia (int a, int b); 

    int main () {
        int numA, numB; 
        cout << "Ingrese el valor de A: "; 
        cin >> numA; 
        cout << "Ingrese el valor de B: "; 
        cin >> numB; 

        float resultado = CalcularPorcentajeDiferencia (numA, numB); 
        cout << "El resultado del calculo (B-A) *100 / (A+B) es: " << resultado << "%" << endl; 

        return 0;
    }

    float CalcularPorcentajeDiferencia (int a, int b) {
        float porcentaje = ((b - a) * 100) / (a + b); 
        return porcentaje; 
    }

