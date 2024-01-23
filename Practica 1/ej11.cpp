/*11. Dados N valores informar el mayor, el menor y en que posición del conjunto fueron ingresados.*/

#include <iostream>
using namespace std;

int main() {
    int N;
    int mayor, menor;
    int posicionMayor, posicionMenor;

    cout << "Cantidad de valores que quiere ingresar: ";
    cin >> N;

    cout << "Ingrese el valor 1: ";
    cin >> mayor;

    menor = mayor;
    posicionMayor = 1;
    posicionMenor = 1;

    for (int i = 2; i <= N; i++) {
        int valor;
        cout << "Ingrese el valor " << i << ": ";
        cin >> valor;

        if (valor > mayor) {
            mayor = valor;
            posicionMayor = i;
        }

        if (valor < menor) {
            menor = valor;
            posicionMenor = i;
        }
    }

    cout << "El mayor valor es: " << mayor << " en la posición: " << posicionMayor << endl;
    cout << "El menor valor es: " << menor << " en la posición: " << posicionMenor << endl;

    return 0;
}
