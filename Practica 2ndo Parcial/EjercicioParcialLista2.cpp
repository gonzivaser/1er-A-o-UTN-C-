/*Dado un archivo de registros con ID vendedor, cantidad vendida, mes y idsucursal. 
Meterlos todos en una lista de listas y devolver el total vendido por mes*/

#include<iostream>
using namespace std; 

/*--------------STRUCTS----------------*/
struct InfoArch {
    int id_vendedor; 
    int cantidad_vendida; 
    int mes; 
    int id_sucursal; 
};

/*---------------LISTA SECUNDARIA----------------*/
struct InfoListaSecu {
    int cantidad_vendida; 
    int id_vendedor; 
}; 

struct ListaSecu {
    InfoListaSecu info; 
    ListaSecu*sgte; 
};


/*---------------LISTA PRINCIPAL----------------*/
struct InfoListaPrinci {
    int id_sucursal; 
    ListaSecu* Arreglo[12]; 
};

struct ListaPrinci {
    InfoListaPrinci info; 
    ListaPrinci* sgte; 
};

void CargarLista(FILE*, ListaPrinci*&); 
void MostrarCantidadVendida (ListaPrinci*&); 


/*--------------INT MAIN----------------*/
int main () {
    return 0; 
}


/*--------------DECLARADAS----------------*/
void MostrarCantidadVendida (ListaPrinci*& lista) {
    ListaPrinci* aux = lista; 
    InfoListaSecu auxiliar; 
    int i = 0;

    while (aux != NULL) {
        cout << "Sucursal: " << aux->info.id_sucursal;
        for (i = 0; i < 12; i++) {
            cout << "Mes: " << i + 1; 

            while (aux->info.Arreglo[i] != NULL) {
                auxiliar = pop(aux->info.Arreglo[i]); 
                cout << "Vendedor: " << auxiliar.id_vendedor; 
                cout << "Cantidad vendida: " << auxiliar.cantidad_vendida;
            }
        }
        aux = aux ->sgte; 
    }
}

void CargarLista (FILE* f, ListaPrinci*& lista) {
    InfoArch al;  
    ListaPrinci* aux1 = lista; 
    InfoListaSecu auxiliar; 

    // ARRANCO A LEER EL ARCHIVO
    while (fread(&al, sizeof(InfoArch), 1, f)) {
        
        // INSERTO SIN REPETIR EL ID DE SUCURSAL, Y ME GUARDO LA DIRECCION EN UN NODO AUX
        aux1 = InsertarSinRepetir(lista, al.id_sucursal); // INSERTO SIN REPETIR LA SUCURSAL 

        // CREO EL AUX 2 PORQUE EL INSERTAR ORDENADO SOLO ACEPTA DOS PARAMETROS 
        // HACER UNN FOR 
        auxiliar.id_vendedor = al.id_vendedor; 
        auxiliar.cantidad_vendida = al.cantidad_vendida;

        // CON EL TIPO INFO LISTA SECU QUE CREE, LLAMO A INSERTAR ORDENADO 
        InsertarOrdenado(aux1->info.Arreglo[al.mes - 1], auxiliar);
    }
}