/*7.Calcular la velocidad (metros/segundo) de los participantes de una carrera de 
1500mts dado el tiempo en segundos en recorrerla y determinar el nombre del mas veloz. 
Y si el tiempo fuera en minutos + segundos?*/

#include<iostream>
using namespace std; 

int main () {
    float velocidadS = 0, velocidadJ = 0, metros = 1500, tjulian, tsebi;

    cout<<"Ingrese en cuanto tiempo corrio Julian: "; cin>>tjulian; 
    cout<<"Ingrese en cuanto tiempo corrio Sebi: "; cin>>tsebi; 

    velocidadS = metros / tsebi;
    velocidadJ = metros / tjulian;

    if(velocidadS > velocidadJ) {
        cout<<"El mas rapido fue Sebi"<<endl; 
    }
    else {
        cout<<"El mas rapido fue Julian"<<endl; 
    }

    return 0; 
}