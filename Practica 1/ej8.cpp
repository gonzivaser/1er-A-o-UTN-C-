/*8.Dados 50 números enteros, informar el promedio de los mayores que 100 y 
la suma de los menores que -10.*/

#include<iostream>
using namespace std; 

int main () {
    int n, i, contador = 0, totalValores100 = 0, sumaNegativos = 0, promedio = 0; 

    for(i = 0; i < 4; i++) {
        cout<<"Ingrese un valor: "; 
        cin>>n; 

        if (n > 100) {
            contador ++; 
            totalValores100 += n; 
        }
        else if (n < -10) {
            sumaNegativos += n; 
        }
    }

    if(contador > 0) {
        promedio = totalValores100 / contador; 
    } 

    cout<<"El promedio de los valores mayores que 100 es: "<<promedio; 
    cout<<"La suma de los negativos es: "<<sumaNegativos; 

    return 0;
}