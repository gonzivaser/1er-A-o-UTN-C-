/*9. Dado un numero N (<=50) y un conjunto de Nombres y Fechas de nacimientos (AAAAMMDD),
informar el conjunto:
• ordenado por nombre
• ordenado por fecha y nombre
• ordenado por nombre y fecha
NOTA: Modifique y utilice el procedimiento Burbujeo. */

#include<iostream>
#include<cstring>
using namespace std; 

struct persona {
    char nombre[50]; 
    int fecha; 
};

void BurbujaNombre (char [], char); 
void BurbujaFechaNombre (int [], int);

int main () {
    int n, i, aux, j;
    char auxn[50]; 

    cout << "Cantidad de personas: "; 
    cin >> n; 
    persona fyn[n]; 

    for(i = 0; i < n; i++) {
        cout << "Nombre " << i+1 << ": "; 
        cin >> fyn[i].nombre; 

        cout << "Ingrese fecha de nacimiento (AAAAMMDD) " << i+1 << ": "; 
        cin << fyn[i].fecha; 
    } 

    return 0; 
}

void BurbujaNombre (int fyn[].nombre, char ) {
    int i, j; 
    int aux; 

    for (i = 1; i < n; i++) {
        for (j = 1; j <= (n - i); j++) {
            if 
        }
    }
}