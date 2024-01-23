#include<iostream>
#include<cstring>
using namespace std; 

/*
NOTAS: 
- MATRIZ DE LISTAS 
- MATRIZ DE 15(sectores) x 31(dias) 
  FILAS: SECTORES 
  COLUMNAS: DIAS 
  --> CADA POSICION REPRESENTA EL GASTO DE ESE SECTOR EN ESE DIA 
- CADA REGISTRO DEL ARCHIVO ES UN GASTO EFECTUADO 
*/

/*--------------STRUCTS----------------*/
/*-------ARCHIVO-------*/
struct InfoArch { // NO ORDENADO
    int numero_sector; 
    int dia_mes; 
    char detalle[20]; 
    int importe_gastado; 
};

/*-------LISTAS-------*/
struct InfoLista {
    char detalle[20]; 
    int importe_gastado; 
}; 

struct NodoLista {
    InfoLista info;
    NodoLista* sgte; 
};

struct MatrizTipo {
    NodoLista* ptrlista; 
};

/*-------FUNCIONES PROTOTIPO-------*/
void CargarEstructura (FILE*, MatrizTipo); 
void MostrarEstructura (MatrizTipo); 
void MayorGasto (MatrizTipo); 

/*--------------INT MAIN----------------*/
int main () {
    return 0; 
}


/*--------------DECLARADAS----------------*/
void MayorGasto (MatrizTipo matriz[15][31]) {
    int mayor; 
    int sector_mayor;
    int dia_mayor; 

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 31; j++) {
            NodoLista* aux = matriz[i][j].ptrlista; 

            // RESUELVO PROBLEMA DE MAXIMO
            while (aux != NULL) {
                if (aux->info.importe_gastado > mayor) {
                    mayor = aux->info.importe_gastado; 
                    sector_mayor = i + 1; 
                    dia_mayor = j + 1; 

                    aux = aux->sgte; 
                }
            }
        }
    }

    cout << "El sector con mayor gasto es: " << sector_mayor << "en el dia: " << dia_mayor << endl; 
}


void MostrarEstructura (MatrizTipo matriz[15][31]) {
    // RECORRO LA MATRIZ 
    // I FILAS, J COLUMNAS 
    for (int i = 0; i < 15; i++) {
        cout << "Sector " << i + 1 << endl; 
        for (int j = 0; j < 31; j++) {
            cout << "Dia " << j + 1 << endl; 

            // ESTABLEZCO EL AUXILIAR
            NodoLista* aux = matriz[i][j].ptrlista; 

            while (aux != NULL) {
                cout << "Importe: " << aux->info.importe_gastado; 
                cout << "Detalle: " << aux->info.detalle; 
                aux = aux->sgte; 
            }
        } 
    }
}


void CargarEstructura (FILE* f, MatrizTipo matriz[15][31]) {
    InfoArch al; 
    InfoLista auxiliar; 

    // LEO ARCHIVO PARA PODER CARGAR LA MATRIZ
    while (fread(&al, sizeof(InfoArch), 1, f)) {
        strcpy(auxiliar.detalle, al.detalle); 
        auxiliar.importe_gastado = al.importe_gastado; 

        // INSERTO ORDENADO 
        InsertarOrdenado(matriz[al.numero_sector][al.dia_mes].ptrlista, auxiliar); 
    }
}