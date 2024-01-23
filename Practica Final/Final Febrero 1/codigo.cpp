#include<iostream>
#include<cstring>
using namespace std; 

/*
NOTAS: 
- MATRIZ [31][2500]
*/

/*--------------STRUCTS----------------*/
/*-------ARRAY-------*/
struct Electrodomestico { // ORDENADOS POR CODIGO ELECTRO ASCENDENTE 
    char codigo_electrodomestico[6]; 
    char nombre_electrodomestico[250];
    float precio_unitario; 
};

/*-------ARCHIVO-------*/
struct InfoArch {
    char codigo_electrodomestico[6]; 
    int dia_mes; 
    int cant_vendida; 
    int dni_cliente; 
    char nombre_cliente[50]; 
};

/*-------LISTAS-------*/
struct InfoCliente {
    int dni_cliente; 
    char nombre_cliente[50];
};

struct NodoCliente {
    InfoCliente info;
    NodoCliente* sgte; 
};

/*-------MATRIZ-------*/
struct MatrizTipo {
    int cant_vendida; 
    NodoCliente* ptr; 
};


/*-------FUNCIONES PROTOTIPO-------*/
int ObtenerPosFilaEnMatriz (int); 
int ObtenerPosColumnaEnMatriz(Electrodomestico [], char);
void CargarMatriz (FILE*, Electrodomestico [], MatrizTipo [][]);
void MostrarClientes (MatrizTipo [][], int, int);


/*--------------INT MAIN----------------*/
int main () {
    return 0; 
}


/*--------------DECLARADAS----------------*/
void MostrarClientes (MatrizTipo matriz[31][2500], int fila, int columna) {
    int i, j; 

    for (i = 0; i < 31; i++) {

        for (j = 0; j < 2500; j++) {
            if (i == fila && j == columna) {
                cout << "Cantidad de Ventas: " << matriz[i][j].cant_vendida << endl; 

                NodoCliente* aux = matriz[i][j].ptr; 
                while (aux != NULL) {
                    cout << "DNI de los que compraron: " << aux->info.dni_cliente << endl; 
                    aux = aux->sgte;
                }
            }
        }
    }
}


void CargarMatriz (FILE* f, Electrodomestico vector[2500], MatrizTipo matriz[31][2500]) {
    int i, j; 
    InfoArch al; 
    InfoCliente auxiliar;

    // PRIMERO PASO ARCHIVO A VECTOR PARA PODER ORDENARLO POR CODIGO DE ELECTRODOMESTICO
    fseek(f, 0, SEEK_END); 
    int D = ftell(f); 
    int cantreg = D / sizeof(InfoArch);
    fseek(f, 0, SEEK_SET); 

    InfoArch vectorArchivo[cantreg];
    int k = 0;
    while (fread(&al, sizeof(InfoArch), 1, f)) {
        vectorArchivo[i] = al; 
        i++; 
    } 

    // ORDENO POR BURBUJA MI ARCHIVO
    BurbujaPorCodigo(vectorArchivo, cantreg); 


    // COMO YA TENGO ORDENADO MI ARCHIVO, PUEDO EMPEZAR A CARGAR LA MATRIZ
    for (i = 0; i < 31; i++) {
        for (j = 0; j < 2500; j++) {
            // PARA CARGAR MI MATRIZ, MIS CODIGOS ENTRE EL VECTOR Y ARCHIVO TIENEN QUE COINCIDIR
            if (vector[i].codigo_electrodomestico == vectorArchivo[i].codigo_electrodomestico) {
                matriz[i][j].cant_vendida = vectorArchivo[i].cant_vendida; 

                // Y CARGO EN LA LISTA DE ESTA MANERA
                auxiliar.dni_cliente = vectorArchivo[i].dni_cliente; 
                strcmp(auxiliar.nombre_cliente, vectorArchivo[i].nombre_cliente);

                InsertarOrdenado(matriz[i][j].ptr, auxiliar);
            }
        }
    }
    

    fclose(f);
}


int ObtenerPosColumnaEnMatriz(Electrodomestico vector[2500], char codigo_electrodomestico[6]) {
    int i;

    for (i = 0; i < 2500; i++) {
        if (strcmp(vector[i].codigo_electrodomestico, codigo_electrodomestico) == 0) {
            return i; 
        }
        else {
            i++;
        }
    }
}


int ObtenerPosFilaEnMatriz (int dia_del_mes) {
    int i = 0; 
    MatrizTipo matriz [31][2500]; 

    for (i = 0; i < 31; i++) {
        if (matriz[i][0] == dia_del_mes) {
            return i + 1; 
        }
    } 
}