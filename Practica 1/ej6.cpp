/*6. Se ingresa una edad, mostrar por pantalla alguna de las siguientes leyendas:
•‘menor’ si la edad es menor o igual a 12
•‘cadete’ si la edad esta comprendida entre 13 y 18
•‘juvenil’ si la edad es mayor que 18 y no supera los 26
•‘mayor’ en el caso que no cumpla ninguna de las condiciones anteriores
*/

#include<iostream>
using namespace std; 

int main () {
    int edad; 
    cout<<"Ingrese su edad: "; cin>>edad; 

    if(edad <= 12) {
        cout<<"Menor"<<endl; 
    }
    else if (edad > 13 && edad < 18) {
        cout<<"Cadete"<<endl; 
    }
    else if (edad > 18 && edad < 26) {
        cout<<"Juvenil"<<endl; 
    }
    else {
        cout<<"Mayor"<<endl; 
    }

    return 0;
}
