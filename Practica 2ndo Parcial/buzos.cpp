#include<iostream>
#include<cstring>
using namespace std; 

/*--------------STRUCTS----------------*/
struct infoArch {
    char nombre[50]; 
    int dni; 
    int edad; 
    char pais_origen[50]; 
    int fecha; 
    char sitio_buceo[50]; 
    char dificultad[50]; 
    int profundidad_maxima; 
    int tiempo_buceo; 
    int hora_inicio; 
};

struct InfoLista {
    char pais_origen[50]; 
    int profundida_maxima; 
    int hora_inicio; 
};

struct Lista {
    InfoLista info; 
    Lista* sgte; 
};

void CargarEstructura (FILE*, Lista*&);
void ListarEstadisticas (Lista*&);

/*--------------INT MAIN----------------*/
int main () {
    return 0; 
}


/*--------------DECLARADAS----------------*/
void CargarEstructura (FILE* f, Lista*& lista) {
    infoArch al; 
    while(fread(&al, sizeof(infoArch), 1, f)) {
        // INSERTO LOS PAISES SIN REPETIR 
        InsertarSinRepetir(lista->info.pais_origen, al.pais_origen); 

        // VEO CUANTOS BUCEOS SI HICIERON A 30 METROS O MAS 
        InsertarOrdenado(lista->info.profundida_maxima, al.profundidad_maxima); 
        
        // VEO CUANTOS BUCEOS NOCTURNOS SE HICIERON Y CARGO A LA LISTA
        InsertarOrdenado(lista->info.hora_inicio, al.hora_inicio);
    }
}

void ListarEstadisticas (Lista*& lista) {
    
    // SACO LA LISTA POPEANDO Y LO GUARDO EN UN AUXILIAR 
    Lista* aux1 = NULL; 
    aux1 = lista;
    while (aux1 != NULL) {                
        // MUESTRO LOS DISTINTOS PAISES 
        cout << "Los distintos paises son: " << aux1->info.pais_origen << endl; 
        aux1 = aux1->sgte; 
    }


    Lista* aux2 = NULL; 
    aux2 = lista;
    int contador_profundidad_maxima = 0;
    while (aux2 != NULL) {
        // VEO CUANTOS BUCEOS HICIERON 30 METROS O MAS 
        if (aux2->info.profundida_maxima >= 30) {
            contador_profundidad_maxima++: 
        }
        aux2 = aux2->sgte;
    }
    cout << "La cantidad de buceos de 30 metros o mas son: " << contador_profundidad_maxima << endl; 


    Lista* aux3 = NULL; 
    aux3 = lista; 
    int cantidad_buceos_nocturnos = 0; 
    while (aux3 != NULL) {
        // VEO CUANTOS BUCEOS NOCTURNOS SE HICIERON
        if (aux3->info.profundida_maxima >= 19) {
            cantidad_buceos_nocturnos++; 
        }
        aux3 ->sgte; 
    }
    cout << "La cantidad de buceos nocturnos son: " << cantidad_buceos_nocturnos << endl; 

}
