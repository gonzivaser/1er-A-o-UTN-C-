/*10.Se ingresa un conjunto de valores float, cada uno de los cuales 
representan el sueldo de un empleado, excepto el ultimo valor que es 
cero e indica el fin del conjunto. Se pide desarrollar un programa que determine e informe:
•Cuantos empleados ganan menos $ 1.520.
•Cuantos ganan $1.520 o mas pero menos de $2.780.
•Cuantos ganan $2.780 o mas pero menos de $5.999.
•Cuantos ganan $5.999 o mas.
*/

#include<iostream>
using namespace std; 

int main () {
    float sueldo = 1; 
    int cant1520 = 0, cant2780 = 0, cant5999 = 0, mayor = 0; 

    while(sueldo != 0) {
        cout<<"Ingrese sueldo: (0 Para terminar) "; 
        cin>>sueldo;

        if(sueldo < 1520) {
            cant1520++; 
        }
        if (sueldo > 1520 && n < 2780) {
            cant2780++; 
        }
        if (sueldo > 2780 && n < 5999) {
            cant5999++; 
        }
        if (sueldo > 5999) {
            mayor++; 
        }
    }

    cout<<"La cantidad de empleados que ganan menos de 1520$ son: "<<cant1520<<endl; 
    cout<<"La cantidad de empleados que ganan entre 1520$ y 2780$ son :"<<cant2780<<endl; 
    cout<<"La cantidad de empleados que gaan entre 2780$ y 5999$ son: "<<cant5999<<endl; 
    cout<<"La cantidad de empleados que ganan mas de 5999$ son: "<<mayor<<endl; 

    return 0;
}