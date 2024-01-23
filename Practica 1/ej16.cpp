/*16.	Dado un conjunto de valores enteros, calcular e informar 
a) cuantos valores cero hubo, 
b) promedio de valores positivos, 
c) sumatoria de valores negativos.
Resolver el ejercicio para los siguientes lotes de datos:
a.	167 valores enteros
b.	N valores, donde el valor de N debe ser leido previamente
c.	El conjunto de valores termina con un valor igual al anterior
d.	Se dan N valores, pero el proceso deberá finalizar si se procesan todos los valores o si la cantidad de ceros supera a cuatro
e.	Se dan N valores, pero el proceso deberá finalizar si se cumple alguna de las condiciones d) o si el promedio de positivos resulta mayor que seis.
*/


#include<iostream>
using namespace std; 

int main () {
    int i = 0, n; 
    int valor; 
    int contador0 = 0, contadorP = 0, contadorN = 0; 
    int sumaN = 0; 
    int sumaP = 0; 
    float promedioP = 0; 

    cout << "Ingrese Cuantos Valores Quiere: "; 
    cin >> n; 

    for(i = 0; i < n; i++) {
        cout << "Ingrese valor " << i+1 << ":"; 
        cin >> valor; 

        if (valor == 0) {
            contador0++; 
        }
        else if (valor > 0) {
            contadorP++; 
            sumaP = valor + sumaP;
        } 
        else if (valor < 0) {
            contadorN++; 
            sumaN = valor + sumaN; 
        }
    }

    promedioP = sumaP / contadorP; 
    cout << "La cantidad de valores 0 que hubo son: " << contador0 << endl; 
    cout << "El promedio de los positivos es: " << promedioP << endl; 
    cout << "La suma de los numeros negativos es: " << sumaN << endl; 

    return 0;
}
