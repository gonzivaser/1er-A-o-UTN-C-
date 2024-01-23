#include<iostream>
#include<cstring>
using namespace std; 

/*
NOTAS: 
- 20 OPERADORES EN TOTAL 
- HARIA UNA LISTA DE LISTAS CON EL OPERADOR EN LA LISTA PRINCIPAL Y UNA SUBLISTA
  CON LOS DISTINTOS PAISES QUE RECIBIO, CUANTOS BUCEOS DE PROFUNDIDAD, CUANTOS BUCEOS NOCTURNOS 

*/


/*--------------STRUCTS----------------*/
/*----------ARCHIVO----------*/
struct InfoArch {
    char operador[20]; 
    int dni; 
    int edad; 
    char pais_origen[20]; 
    int fecha; 
    char sitio_buceo[20]; 
    int nivel_dificultad; 
    int profundidad_max; 
    int tiempo_buceo; 
    int hora_inicio; 
};


/*----------LISTAS----------*/
struct InfoListaPorOperador {
    char pais_origen[20]; 
    int acumulador_buceos_profundos; 
    int acumulador_buceos_nocturnos;
}

struct ListaPorOperador {
    InfoListaPorOperador info; 
    ListaPorOperador* sgte; 
};

struct InfoListaOperador {
    char operador [20]; 
    ListaPorOperador* ptr; 
};

struct ListaOperador {
    InfoListaOperador info; 
    ListaOperador* sgte; 
};

/*----------FUNCIONES PROTOTIPOS----------*/
void CargarEstructura (FILE*, ListaOperador*&);
void listarEstadisticas (ListaOperador*&); 


/*--------------INT MAIN----------------*/
int main () {
    return 0; 
}


/*--------------DECLARADAS----------------*/
void ListarEstadisticas (ListaOperador*& lista) {
    ListaOperador* lista_aux = lista; 
    int contador = 0; 
    int contador2 = 0;

    while (lista_aux != NULL) {
        cout << "Operador: " << lista_aux->info.operador; 

        while (lista_aux->info.ptr->sgte != NULL) {
            cout << "Paises: " << lista_aux->info.ptr->info.pais_origen; 
            
            if (lista_aux->info.ptr->info.acumulador_buceos_profundos > 30) {
                contador++; 
            }
            else if (lista_aux->info.ptr->info.acumulador_buceos_nocturnos > 1900) {
                contador2++; 
            }

            lista_aux->info.ptr = lista_aux->info.ptr->sgte; 
        }

        cout << "Cantidad de buceos profundos: " << contador << endl; 
        cout << "Cantidad de buceos nocturnos: " << contador2 << endl; 

        lista_aux = lista_aux->sgte; 
    }
}


void CargarEstructura (FILE* f, ListaOperador*& lista) {
    InfoArch al; 
    InfoListaOperador aux_info; 
    ListaOperador* lista_aux = NULL; 

    while(fread(al, sizeof(InfoArch), 1, f)) {
        lista_aux = InsertarSinRepetir(lista, al.operador);

        strcpy(aux_info, al.pais_origen); 
        aux_info = al.hora_inicio; 
        aux_info = al.profundidad_max;

        InsertarSinRepetir(lista_aux->info.ptr, aux_info); 
    }
}
