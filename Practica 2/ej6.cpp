/*6. En un club social se abrieron las inscripciones de los socios distintos deportes,
codificados de 1 a 20, y de cada inscripción se conoce número de socio y código de deporte.
Las inscripciones finalizan con un número de socio igual a 0.
Se pide informar:
• La cantidad de inscriptos en cada deporte
• El código de deporte con la mayor cantidad de inscriptos. */

#include<iostream>
using namespace std; 

int main () {
    int i = 0, Nrosocio, codigo_deporte, posicion;
    int deporte[20] = {0};  
    
    cout << "Ingresar numero de socio: "; 
    cin >> Nrosocio; 

    while (Nrosocio != 0) {
        cout << "Ingrese codigo de deporte: "; 
        cin >> codigo_deporte; 

        posicion = codigo_deporte - 1; 
        deporte[posicion] = deporte[posicion] + 1; 

        cout << "Ingresar numero de socio: "; 
        cin >> Nrosocio;
    }

    for (i = 0; i < 20; i++) {
        cout << "El deporte " << i+1 << " tiene " << deporte[i] << " inscriptos" << endl; 
    }

    return 0;
}