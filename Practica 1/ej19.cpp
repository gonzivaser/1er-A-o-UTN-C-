/*19. Desarrolle un procedimiento que reciba el costo en pesos de un abono telefónico, 
la cantidad de minutos libres que incluye el abono, 
el cargo en pesos por minuto excedente y la cantidad de minutos utilizados por un abonado, 
retorne la cantidad de minutos excedidos y 
el monto en pesos a abonar (costo del abono mas minutos excedidos por el costo de minutos excedidos) 
mas el 21% del valor del IVA.
UTILICE FUNCIONES.
*/

#include<iostream> 
using namespace std; 

float MinEx (float a, float b); 
float MontoPagar (float p, float m, float e); 

int main () {
    float costo = 0, minlib, cargoxminx, minutil, minex, montoab; 
    cout << "Costo en pesos del abono telefonico: "; 
    cin >> costo; 
    cout << "Cantidad de minutos libres que incluye el abono: "; 
    cin >> minlib; 
    cout << "El cargo en pesos por minuto excedente: "; 
    cin >> cargoxminx; 
    cout << "La cantidad de minutos utilizados: "; 
    cin >> minutil; 

    minex = MinEx (minutil,minlib); 
    montoab = MontoPagar (costo,minex,cargoxminx); 

    cout << "La cantidad de minutos excedidos es: " << minex << endl; 
    cout << "El monto en pesos a abonar es: " << montoab << endl; 

    return 0; 
}

float MinEx (float a, float b) {
    return a - b; 
}
float MontoPagar (float p, float m, float e) {
    float resultado; 
    resultado = (p + m * e) + (p + m* e) * 0,21;
    return resultado; 
}