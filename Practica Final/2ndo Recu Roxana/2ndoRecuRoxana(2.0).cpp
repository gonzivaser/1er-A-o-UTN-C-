#include<iostream>
#include<cstring>
using namespace std; 

/*
NOTAS: 
- MATRIZ DE LISTAS
- FILAS SECTORES; COLUMNAS DIAS 
- CADA ELEMENTO ES LA LISTA CON EL GASTO DE ESE DIA 
- 
*/

/*--------------STRUCTS----------------*/
/*-------ARCHIVO-------*/
struct InfoArch {
    int numero_sector; 
    int dia; 
    char detalle[5]; 
    int importe_gastado; 
};

/*-------LISTAS-------*/
struct InfoGastoDia {
    int importe_gastado;
    char detalle[5]; 
};

struct NodoGastoDia {
    InfoGastoDia info;
    NodoGastoDia* sgte; 
};

struct MatrizTipo {
    NodoGastoDia* ptr; 
};

/*-------FUNCIONES PROTOTIPO-------*/
void CargarEstructura (FILE*, MatrizTipo [][]);
void MostrarGastos (MatrizTipo[][]);
void MayorGasto (MatrizTipo[][]);

/*--------------INT MAIN----------------*/
int main () {
    return 0; 
}


/*--------------DECLARADAS----------------*/
void MayorGasto (MatrizTipo matriz[15][31]) {
    int mayor; 
    int sector_mayor; 
    int dia; 

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 31; j++) {
            NodoGastoDia* aux = matriz[i][j]; 
            while (aux != NULL) {
                if (aux->info.importe_gastado > mayor) {
                    mayor = aux->info.importe_gastado; 
                    sector_mayor = i + 1; 
                    dia = j + 1; 
                }

                aux = aux->sgte; 
            }
        }
    }

    cout << "El mayor gasto lo realizo el sector " << sector_mayor << "en el dia: " << dia << endl; 
}


void MostrarGastos (MatrizTipo matriz[15][31]) {
    // TENGO QUE LEER LA MATRIZ PARA PODER IR MOSTRANDO LA LISTA
    for (int i = 0; i < 15; i++) {
        cout << "Sector : " << i + 1 << endl; 

        for (int j = 0; j < 31; j++) {
            cout << "Dia: " << j + 1 << endl; 

            NodoGastoDia* aux = matriz[i][j]; 
            while (aux != NULL) {
                cout << "Importe: " << aux->info.importe_gastado << endl; 
                cout << "Detalle: " << aux->info.detalle << endl; 

                aux = aux->sgte;
            }
        }
    }

}


void CargarEstructura (FILE* f, MatrizTipo matriz[15][31]) {
    InfoArch al; 
    InfoGastoDia auxiliar;

    // ARRANCO A LEER EL ARCHIVO
    while (fread(&al, sizeof(InfoArch), 1, f)) {
        strcpy(auxiliar.detalle, al.detalle); 
        auxiliar.importe_gastado = al.importe_gastado; 

        InsertarOrdenado(matriz[al.numero_sector][al.dia], auxiliar); 
    }
}