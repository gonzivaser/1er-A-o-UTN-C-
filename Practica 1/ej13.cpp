/*13.Dado un conjunto de valores, que finaliza con un valor nulo, determinar e 
imprimir (si hubo valores):
•El valor máximo negativo
•El valor mínimo positivo
•El valor mínimo dentro del rango -17.3 y 26.9
•El promedio de todos los valores.
*/

#include<iostream>
using namespace std; 

int main() { 
    
    double minPositivo = 999999, maxNegativo = -999999, valor, valorMinrango, promedio = 0, suma = 0;
    int contador = 0;

    cout << "Ingresar Numeros: ";
    cin >> valor;

    while (valor != 0) {

        if (valor < 0 && valor > maxNegativo)
        {
            maxNegativo = valor;
        } else if (valor > 0 && valor < minPositivo)
        {
            minPositivo = valor;
        }

        if (valor >= -17.3 && valor <= 26.9 && valor < valorMinrango)
        {
            valorMinrango = valor;
        }

        suma += valor;
        contador++;
        cout << "Ingresar Numeros: (0 para terminar)";
        cin >> valor;
    }

    promedio = suma / contador;
    cout << "El valor Minimo Positivo es: " << minPositivo << endl;
    cout << "El valor Maximo Negativo es: " << maxNegativo << endl;
    cout << "El valor minimo dentro del rango de -17.3 y 26. 9 es: " << valorMinrango << endl;
    cout << "El promedio de todos los valores es: " << promedio << endl;

    return 0;
}