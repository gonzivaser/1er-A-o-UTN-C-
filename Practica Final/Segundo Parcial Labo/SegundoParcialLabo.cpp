#include<iostream>
#include<cstring>
using namespace std; 

/*
NOTAS: 
- PARA PODER CARGAR EN MI LISTA, TIENEN QUE COINCIDIR MIS ID DE TARJETA PARA QUE COINCIDA LA INFO
- TENOG UNA LISTA DE LISTAS 
  PRINCIPAL: POR ID DE LABORATORIO
  SECUNDARIA: DIA, ID PRODUCTO, CANTIDAD VENDIDA, IMPORTE TOTAL DE DESCUENTO 
*/


/*--------------STRUCTS----------------*/
/*----------ARCHIVOS----------*/
struct Paciente {
    char nombre[20]; 
    char apellido[20]; 
    int dni; 
};

struct InfoArchTarjeta { // ORDENADO POR DNI
    int id_laboratorio; 
    int id_tarjeta; 
    Paciente infopaciente; 
};

struct InfoArchCompras { // DESORDENADO
    int dia_de_compra; 
    int id_tarjeta; 
    int unidades_vendidas; 
    int id_producto; 
    int precio_venta; 
    int descuento; // %
};

/*----------LISTAS----------*/
/*-----SECUNDARIA-----*/
struct InfoDia {
    int dia_de_compra; 
    int id_producto;
    int cantidad_vendida; 
    int importe_total_descuento; 
};

struct NodoDia {
    InfoDia info; 
    NodoDia* sgte; 
};


/*-----PRINCIPAL-----*/
struct InfoLaboratorio {
    int id_laboratorio; 
    NodoDia* ptrls; 
};

struct NodoLaboratorio {
    InfoLaboratorio info; 
    NodoLaboratorio* sgte; 
};


/*----------FUNCIONES PROTOTIPO----------*/
void CargarEstructura (FILE*, NodoLaboratorio*&);
void MostrarListado (NodoLaboratorio*&); 



/*--------------INT MAIN----------------*/
int main () {

    return 0; 
}


/*--------------DECLARADAS----------------*/
void MostrarListado (NodoLaboratorio*& lista) {
    NodoLaboratorio* aux = lista; 

    while (aux != NULL) {
        cout << "Laboratorio: " << aux->info.id_laboratorio << endl; 

        while (aux->info.ptrls != NULL) {
            cout << "Dia: " << aux->info.ptrls->info.dia_de_compra << endl; 
            cout << "Id Producto: " << aux->info.ptrls->info.id_producto << endl; 
            cout << "Cantidad Vendida: " << aux->info.ptrls->info.cantidad_vendida << endl; 
            cout << "Importe Total De Descuento: " << aux->info.ptrls->info.importe_total_descuento << endl;

            aux->info.ptrls = aux->info.ptrls->sgte; 
        }
        aux = aux->sgte; 
    }

}

void CargarEstructura (FILE* f, NodoLaboratorio*& lista) {
    // PASO InfoArchTarjeta A UN VECTOR 
    fseek(f, 0, SEEK_END); 
    int D = ftell(f); 
    int cantreg = D / sizeof(InfoArchTarjeta); 
    fseek(f, 0, SEEK_SET); 

    InfoArchTarjeta al; 
    InfoArchTarjeta vector[cantreg]; 
    int i = 0; 
    while(fread(&al, sizeof(InfoArchTarjeta), 1, f)) {
        al = vector[i]; 
        i++; 
    }

    // COMO UNO DE LOS DOS ARCHIVOS YA LO TENGO COMO VECTOR, PUEDO CARGAR LA LISTA COMPARANDO AMBOS ARCHIVOS
    InfoArchCompras pas; 
    InfoDia auxiliar; 
    NodoLaboratorio* aux = NULL; 
    for (int i = 0; i < cantreg; i++) {

        if (vector[i].id_tarjeta == pas.id_tarjeta) {

            // UNA VEZ QUE COINCIDEN MIS ID DE TARJETA, EMPIEZO A CARGAR MI LISTA CON LOS DATOS NECESARIOS
            // INSERTO SIN REPETIR EL ID DE LABORATORIO Y GUARDO LA DIRECCION EN UN AUXILIAR PARA CARGAR LA SUBLISTA
            aux = InsertarSinRepetir(lista, vector[i].id_laboratorio); 

            // EMPIEZO A CARGAR EN UN AUXILIAR TODOS LOS DATOS
            pas.dia_de_compra = auxiliar.dia_de_compra; 
            pas.id_producto = auxiliar.id_producto; 
            pas.unidades_vendidas = auxiliar.cantidad_vendida; 

            // PARA CALCULAR EL DESCUENTO ES --> (PRECIO DE VENTA * UNIDADES VENDIDAS) * DESCUENTO
            int descuento_total = (pas.precio_venta * pas.unidades_vendidas) * pas.descuento; 
            descuento_total = auxiliar.importe_total_descuento; 

            // COMO YA TENGO TODOS LOS DATOS EN MI AUXILIAR, LO INSERTO ORDENADAMENTE 
            InsertarOrdenado(aux->info.ptrls, auxiliar); 
        }
    }
}