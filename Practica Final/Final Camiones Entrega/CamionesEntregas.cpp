#include<iostream>
#include<cstring>
using namespace std; 

/*
NOTAS: 
- 
- 
*/


/*--------------STRUCTS----------------*/
struct InfoArchCamiones { // ORDENADO POR ID DE CAMION 
    int id_camion; 
    int CP; 
};

struct InfoArchEnvios { // ORDENADO POR HORA DE ENTREGA
    char codigo_paquete[25]; 
    char direccion[50]; 
    int CP; 
    int id_camion; 
    int hora_entrega; // HH:MM
};


/*-------LISTAS-------*/
struct NodoCola {
    char codigo_paquete[25]; 
    NodoCola* sgte; 
} 

struct NodoLista {
    int CP; 
    NodoCola* ptr; 
    NodoLista* sgte;
};

struct VectorCamion {
    int id_camion; 
    NodoLista* ptr; 
};  


/*-------FUNCIONES PROTOTIPO-------*/
void LeerVehiculos (FILE*, VectorCamion []);
void PlanificarEntregas (FILE*, VectorCamion []);
void EntregarPaquete (int, int, VectorCamion []); 



/*--------------INT MAIN----------------*/
int main () {
    return 0; 
}


/*--------------DECLARADAS----------------*/
void EntregarPaquete (int id_camion, int CP, VectorCamion vector []) {

    for (int i = 0; i < 100; i++) {
        if (vector[i].id_camion == id_camion) {
            
            NodoLista* aux = vector[i].ptr; 
            
            while (aux != NULL) {
                if (aux->CP == CP) {
                    NodoCola* fte = aux->ptr; 
                    NodoCola* fin = aux->ptr;
                    unqueue(fte, fin); 
                }

                aux = aux->sgte; 
            }
        }
    } 
}


void PlanificarEntregas (FILE* r, VectorCamion vector []) {
    InfoArchEnvios al; 
    NodoCola* fte = NULL; 
    NodoCola* fin = NULL; 

    while (fread(&al, sizeof(InfoArchEnvios), 1, r)) {
        for (int i = 0; i < 100; i++) {
            if (vector[i].ptr->CP == al.CP) {
                queue(fte, fin, al.codigo_paquete); 
            }
        }
    }

    fclose(r); 
}


void LeerVehiculos (FILE* f, VectorCamion vector []) {
    InfoArchCamiones al; 
    // 100 CANTIDAD DE CAMIONES 

    // ARRANCO A LEER EL ARCHIVO DE CAMIONES 
    while(fread(&al, sizeof(InfoArchCamiones), 1, f)) {
        for (int i = 0; i < 100; i++) {
            vector[i].id_camion = al.id_camion; 
            InsertarOrdenado (vector[i].ptr, al.CP); 
        }
    }

    fclose(f); 
}