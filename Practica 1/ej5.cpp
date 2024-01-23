/*5. Dado un triángulo representado por sus lados L1, L2, L3, 
determinar e imprimir una leyenda según sea: equilátero, isósceles o escalenos.*/

#include<iostream>
using namespace std; 

int main () {
    int l1, l2, l3; 
    cout<<"Ingrese Lado 1: "; cin>>l1; 
    cout<<"Ingrese Lado 2: "; cin>>l2; 
    cout<<"Ingrese Lado 3: "; cin>>l3; 

    if(l1 == l2 || l1 == l3 || l3 == l2) {
        cout<<"El triangulo es isoceles"<<endl; 
    } else if (l1 == l2 && l2 == l3) {
        cout<<"El triangulo es equilatero"<<endl; 
    } else if (l1 != l2 != l3) {
        cout<<"El Triangulo es escaleno"<<endl; 
    }

    return 0;
}