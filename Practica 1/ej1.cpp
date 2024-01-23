/*1.Dados dos valores enteros A y B, informar la suma, la resta y el producto.*/

#include<iostream>
using namespace std; 

int main () {
    int a, b, suma = 0, resta = 0, multiplicacion = 0; 
    cout<< "Ingrese el valor de A: "; cin>>a; 
    cout<< "Ingrese el valor de B: "; cin>>b;  

    suma = a + b; 
    resta = a - b; 
    multiplicacion = a * b; 

    cout<<"El valor de la suma de los dos valores es: "<<suma<<endl; 
    cout<<"El valor de la resta de los dos valores es: "<<resta<<endl;
    cout<<"El valor de la multiplicacion de los dos valores es: "<<multiplicacion<<endl;  

    return 0; 
}