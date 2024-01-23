/*2.Dado un numero entero de la forma (AAAAMMDD), 
que representa una fecha valida mostrar el dia, mes y año que representa. */

#include<iostream>
using namespace std; 

int main () {
    int fecha, año= 0, mes = 0, dia = 0, resto = 0, restomes = 0; 
    cout<<"Ingrese una fecha valida: ";
    cin>>fecha; 

    año = fecha / 10000; 
    resto = fecha % 10000; 
    mes = resto / 100; 
    dia = resto % 100; 

    cout<<"El año es: "<<año<<endl; 
    cout<<"El mes es: "<<mes<<endl; 
    cout<<"El dia es: "<<dia<<endl; 

    return 0; 
}