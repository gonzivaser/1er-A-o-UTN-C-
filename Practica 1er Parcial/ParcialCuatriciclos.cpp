#include<iostream>
#include<cstring>
using namespace std; 

/*----------STRUCTS Y PROTOTIPOS------------*/

struct participante {
    int id_participante; 
    int hora_partida; 
    int hora_llegada; 
    int categoria; 
};

struct ganador {
    int id_participante; 
    int tiempo_total; 
}; 

void IngresarParticipantes(participante [], int); 
void OrdenarVector(participante [], int); 
void DeterminarPodio(participante [], int); 


/*----------INT MAIN------------*/
int main () {
    int cantidad_inscriptos = 0;
    cout << "Ingrese la cantidad de participantes: "; 
    cin >> cantidad_inscriptos; 

    participante vectorP[cantidad_inscriptos]; 

    IngresarParticipantes(vectorP, cantidad_inscriptos); 

    OrdenarVector(vectorP, cantidad_inscriptos); 





    return 0; 
}


/*----------FUNCIONES DECLARADAS------------*/

void IngresarParticipantes (participante vectorP[], int cantidad_inscriptos) {
    int aux = 0; 

    for (int i = 0; i < cantidad_inscriptos; i++) {
        cout << "Ingrese el ID: "; 
        cin >> vectorP[i].id_participante << endl; 
        cout << "Ingrese la categoria: "; 
        cin >> vectorP[i].categoria << endl; 

        cout << "Participo de todas las etapas (si = 1, no = 0) ?: "; 
        cin >> aux; 

        if (aux == 1) {
            cout << "Hora de partida: "; 
            cin >> vectorP[i].hora_partida; 
            cout << "Hora de llegada: "; 
            cin >> vectorP[i].hora_llegada; 
        } 
        else {
            cout << "Solo ganan los que participaron de las tres etapas" << endl; 
            vectorP[i].hora_llegada = 000000; 
            vectorP[i].hora_partida = 000000; 
        }
    }
}


void OrdenarVector (participante vectorP[], int k) {  // ORDENO POR ID DE PARTICIPANTE
    int aux = 0; 

    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= k - i; j++) {
            if (vectorP[j - 1].id_participante > vectorP[j].id_participante) {
                aux = vectorP[j];
                vectorP[j] = vectorP[j - 1];
                vectorP[j- 1] = aux;
            }
        }
    }
}


void DeterminarPodio (participante vector [], int cantidad_inscriptos) {
    ganador PrimeraCategoria [cantidad_inscriptos]; 
    ganador SegundaCategoria [cantidad_inscriptos]; 
    ganador TerceraCategoria [cantidad_inscriptos]; 

    for (int i = 0; i < cantidad_inscriptos; i++) {
        if (vectorP[i].categoria == 1) {
            PrimeraCategoria[i].id_participante = vectorP[i].id_participante; 
            PrimeraCategoria[i].tiempo_total = vectorP[i].hora_llegada - vectorP[i].hora_partida; 
        }
        else if (vectorP[i].categoria == 2) {
            SegundaCategoria[i].id_participante = vectorP[i].id_participante;
            SegundaCategoria[i].tiempo_total = vectorP[i].hora_llegada - vectorP[i].hora_partida;
        }
        else if (vectorP[i].categoria == 3) {
            TerceraCategoria[i].id_participante = vectorP[i].id_participante;
            TerceraCategoria[i].tiempo_total = vectorP[i].hora_llegada - vectorP[i].hora_partida;
        }
    }


}