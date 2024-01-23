/* Realizar la suma de todos los números pares entre 2 y 10000*/

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