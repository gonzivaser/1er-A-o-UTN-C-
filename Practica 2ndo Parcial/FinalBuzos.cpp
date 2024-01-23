#include<iostream>
#include<cstring>
using namespace std; 

/*
NOTAS DE COMO ENCARARLO: 
- HAY 20 OPERADORES DE BUCEO EN TOTAL 
- EL ARCHIVO NO ESTA ORDENADO Y ES UN ARCHIVO DE CON LA INFORMACION DE CADA BUZO 

¿QUE TENGO QUE HACER?
POR CADA OPERADOR --> DE QUE PAISES RECIBIO BUZOS? 
POR CADA OPERADOR --> CUANTOS BUCEOS A 30 METROS O MAS 
POR CADA OPERADOR --> CUANTOS BUCEOS NOCTURNOS SE HICIERON (X > 19) 

¿QUE VOY A HACER? 
YO USARIA UNA LISTA PRINCIPAL QUE CONTIENE --> CADA OPERADOR, ACUMULADOR DE 30 METROS y ACUMULADOR DE 
BUCEOS NOCTURNOS 

Y UNA SUBLISTA QUE CONTEGA --> POR CADA OPERADOR, QUE PAISES RECIBIO (INSERTAR SIN REPETIR)
*/


/*--------------STRUCTS----------------*/
struct InfoArch {
    char operador[20]; 
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

/*------------LISTA SECUNDARIA-----------*/
struct InfoListaSecundaria {
    char pais_origen[50]; 
};

struct ListaSecundaria {
    InfoListaSecundaria info; 
    ListaSecundaria* sgte; 
};


/*------------LISTA PRINCIPAL-----------*/
struct InfoListaPrincipal {
    char operador[20]; 
    int acumulador_profundos = 0; 
    int acumulador_nocturnos = 0;
    ListaSecundaria* ptrSecu; 
};

struct ListaPrincipal {
    InfoListaPrincipal info; 
    ListaPrincipal* sgte;
};

void CargarEstructura(ListaPrincipal*&, FILE*);
void ListarEstadisticas(ListaPrincipal*&); 


/*--------------INT MAIN----------------*/
int main () {
    return 0; 
}

/*--------------DECLARADAS----------------*/
void ListarEstadisticas (ListaPrincipal*& lista) {
    ListaPrincipal* lista_aux = lista; 

    // ARRANCO A RECORRER LA LISTA PRINCIPAL 
    while (lista_aux != NULL) {
        // MUESTRO DE QUE OPERADOR HABLO PRIMERO 
        cout << "Operador: " << lista_aux->info.operador; 

        // ENTRO AL WHILE DE MI LISTA SECUNDARIA 
        while (lista_aux->info.ptrSecu->sgte != NULL) {
            // MUESTRO LOS PAISES QUE SE ENCUENTRAN ALMACENADOS EN ESE OPERADOR 
            cout << "Paises: " << lista_aux->info.ptrSecu->info.pais_origen; 

            // MUESTRA PAIS Y AVANZA AL SIGUIENTE PARA MOSTRAR TODOS 
            lista_aux->info.ptrSecu = lista_aux->info.ptrSecu->sgte;
        }

        // MUESTRO LOS ACUMULADORES 
        cout << "Cantidad de buceos profundos: " << lista_aux->info.acumulador_profundos; 
        cout << "Cantidad de bueceos nocturnos: " << lista_aux->info.acumulador_nocturnos; 

        lista_aux = lista_aux->sgte; 
    }
}


void CargarEstructura (ListaPrincipal*& lista, FILE* f) {
    InfoArch al; 
    ListaPrincipal* lista_aux = lista; 

    // ARRANCO A LEER EL ARCHIVO PARA CARGAR MI LISTA
    while(fread(&al, sizeof(InfoArch), 1, f)) {

        // INSERTO SIN REPETIR LOS OPERADORES Y ME GUARDO LA DIRECCION 
        lista_aux = InsertarSinRepetir(lista->info.operador, al.operador);

        // INSERTO TAMBIEN SIN REPETIR LOS DISTINTOS PAISES QUE HAY
        InsertarSinRepetir(lista_aux->info.ptrSecu->info.pais_origen, al.pais_origen); 

        // PONGO CONDICIONES 
        if (al.profundidad_maxima >= 30) {
            lista->info.acumulador_profundos++; 
        }
        if (al.tiempo_buceo >= 19) {
            lista->info.acumulador_nocturnos++; 
        }
    }
}