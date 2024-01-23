/*14.Un buque de carga traslada 100 contenedores a tres diferentes puertos del país. 
Los puertos se identifican con los números 1, 2 y 3.
De cada contenedor que el buque traslade se registran los siguientes datos:
•Identificación del contenedor (entero)
•Peso del contenedor en kg (entero)
•Puerto de arribo(un valor de 1 a 3).
Se pide calcular e informar:
i. El peso total que el buque debe trasladar
ii. La identificación del contenedor de mayor peso
iii. La cantidad de contenedores que debe trasladar a cada puerto
*/

#include<iostream>
using namespace std; 

int main () {
    int i = 0, P1, P2, P3, ID, PC, PA, peso_total = 0, ID_mayorpeso, C1 = 0, C2 = 0, C3 = 0, pesomayor = 0;

    for(i = 0; i < 5; i++ ) {
        cout<<"Ingrese la identificacion del contenedor: "; 
        cin>>ID; 
        cout<<"Ingrese el peso del contenedor: "; 
        cin>>PC; 
        cout<<"Ingrese el puerto de arribo: "; 
        cin>>PA; 

        peso_total = PC + peso_total;

        if (PC > pesomayor) {
            ID_mayorpeso = ID; 
            pesomayor = PC;  
        } 

        if (1 == PA) {
            C1++; 
        } else if (2 == PA) {
            C2 ++; 
        } else if (3 == PA) {
            C3++; 
        }
    } 

    cout<<"El peso total que debe trasladar es: "<<peso_total<<endl; 
    cout<<"EL ID del contendor mas pesado es: "<<ID_mayorpeso<<endl; 
    cout<<"La cantidad de contenedores de puerto 1 es: "<<C1<<endl; 
    cout<<"La cantidad de contenedores de puerto 2 es: "<<C2<<endl; 
    cout<<"La cantidad de contenedores de puerto 3 es: "<<C3<<endl; 

    return 0;
}
