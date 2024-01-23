/*3. Dado un conjunto (<100) de valores enteros de los cuales el último es cero y no
debe procesarse:
a.	informe el valor mínimo, su posición dentro del conjunto, si el mínimo no es único, informar 
    todas las posiciones donde se encuentre.
b.	informe el producto de los elementos impares que ocupen posición par.
*/

#include<iostream>
using namespace std; 

int main () {
    int n, i = 0, valor_minimo, posicion_minimo, producto = 0; 
    int vect[100]; 

    cout << "Ingrese un valor: "; 
    cin >> n; 

    while (n != 0) {
        vect[i] = n; 
        if (vect[i] < valor_minimo || i == 0) {
            valor_minimo = vect[i]; 
            posicion_minimo = i; 
        } 
       
        if (i % 2 == 0 && vect[i] % 2 != 0) {
            producto = producto * vect[i]; 
        }
        
        i++; 
        cout << "Ingrese un valor: "; 
        cin >> n; 
    }

    cout << "El valor minimo es: " << valor_minimo << endl; 
    cout << "La posicion del valor minimo es: " << posicion_minimo << endl; 
    cout << "El producto de los elementos impares que ocupan posicion par es: " << producto << endl;
    

    return 0;
}

/*
int main()
{
    int n, i = 0, valor_minimo, posicion_minimo, producto = 1;
    bool unico = true;
    int vect[100];

    cout << "Ingrese un valor: ";
    cin >> n;
    while (n != 0)
    {
        vect[i] = n;
        if (vect[i] < valor_minimo || i == 0)
        {
            valor_minimo = vect[i];
            posicion_minimo = i;
            unico = true;
        }
        else if (vect[i] == valor_minimo) unico = false;
        if ((i % 2 == 0) && !(vect[i] % 2 == 0))
        {
            producto = producto * vect[i];
        }
        i++;
        cout << "Ingrese un valor: ";
        cin >> n;
    }

    cout << "El valor minimo es: " << valor_minimo << endl;

    if (!unico)
    {
        cout << "Se encuentra en: " << endl;
        for (int k = 0; k < 100; k++)
        {
            if (vect[k] == valor_minimo)
            {
                cout << k << ", ";
            }
        }
    }
    else
        cout << "Su posicion es: " << posicion_minimo << endl;
    cout << "El producto de bla bla es: " << producto;

    return 0;
}
*/