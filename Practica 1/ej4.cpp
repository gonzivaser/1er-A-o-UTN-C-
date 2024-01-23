/*4. Dado tres valores determinar e imprimir una 
leyenda según sea: “Forman triangulo” o “No forman triangulo”.*/

#include<iostream>
using namespace std; 

int main () {
    int l1, l2, l3; 
    cout<<"Ingrese Lado 1: "; cin>>l1; 
    cout<<"Ingrese Lado 2: "; cin>>l2; 
    cout<<"Ingrese Lado 3: "; cin>>l3; 

    if(l1 + l2 > l3 && l1 + l3 > l2 && l2 + l3 > l1) {
        cout<<"Existe tal triangulo"<<endl; 
    } else {
        cout<<"No existe tal triangulo"<<endl; 
    }

    return 0; 
}