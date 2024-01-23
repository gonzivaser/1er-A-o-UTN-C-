#include<iostream>
#include<cstring>
using namespace std; 

/*NOTAS: 
- UN REGISTRO POR LOCALIDAD 
- LISTA DE LISTAS. LISTA PRINCIPAL DE MESES Y SUB LISTA CON LA INFO DE: NOMBRE LOCALIDAD
  TOTAL DE HORAS DE CORTE, UNIDADES DE LA MULTA 
- TENGO DOS FUNCIONES, CARGAR LA ESTRUCTURA Y MOSTRARLA. LA CARGO CON EL ARCHIVO DADO EN LA LISTA, 
  Y LA MUESTRO CON LAS CONDICIONES PEDIDAS   
*/

/*--------------STRUCTS----------------*/
/*----------ARCHIVO----------*/
struct InfoArch { // SIN ORDEN 
    int hora_inicio; 
    int hora_final; 
    int id_subestacion; 
    int dia; 
    int mes; 
    int id_localidad; 
};

/*----------VECTOR DE LOCALIDADES----------*/
struct VectorLocalidades { // ORDENADO POR ID LOCALIDAD (PUP)
    char nombre_localidad[50]; 
    int cantidad_habitantes; 
};

/*----------LISTAS----------*/
/*----------SECUNDARIA----------*/
struct InfoListaLocalidades {
    char nombre_localidad[50]; 
    int total_horas_corte; 
    int unidades_multa; 
    int cant_horas_promedio; 
};

struct ListaLocalidades {
    InfoListaLocalidades info; 
    ListaLocalidades* sgte; 
};

/*----------PRINCIPAL----------*/
struct InfoListaMes {
    int mes; 
    ListaLocalidades* ptr; 
};

struct ListaMes {
    InfoListaMes info; 
    ListaMes* sgte; 
};


/*----------PROTOTIPO FUNCIONES----------*/
void CargarEstructuras (FILE*, ListaMes*&); 
void MostrarListado (ListaMes*&); 


/*--------------INT MAIN----------------*/
int main () {

    return 0; 
}


/*--------------DECLARADAS----------------*/
void MostrarListado (ListaMes*& lista) {
    ListaMes* aux = lista; 

    // ARRANCO A RECORRER LA LISTA AUXILIAR PARA MOSTRAR 
    while (aux != NULL) {
        cout << "Mes: " << aux->info.mes; 

        // RECORRO SECUNDARIA 
        while (aux->info.ptr != NULL) {
            cout << "Horas Promedio: " << aux->info.ptr->info.cant_horas_promedio << endl; 
            cout << "Localidad: " << aux->info.ptr->info.nombre_localidad << endl; 
            cout << "Total Horas Corte: " << aux->info.ptr->info.total_horas_corte << endl; 
            cout << "Unidades De Multa: " << aux->info.ptr->info.unidades_multa << endl; 

            aux->info.ptr = aux->info.ptr->sgte; 
        }

        aux = aux->sgte;
    }
}


void CargarEstructuras (FILE* f, ListaMes*& lista, int N) {
    InfoArch al; 
    VectorLocalidades vector[N]; 
    InfoListaLocalidades auxiliar; 
    ListaMes* aux = NULL; 

    // LEO ARCHIVO 
    while(fread(&al, sizeof(InfoArch), 1, f)) {
        aux = InsertarSinRepetir(lista, al.mes); 

            if (vector[al.id_localidad] == al.id_localidad) {
                // GUARDO EL NOMBRE
                auxiliar.nombre_localidad = vector[al.id_localidad].nombre_localidad; 

                // GUARDO EL TOTAL DE HORAS DE CORTE 
                int total = al.hora_final - al.hora_inicio; 
                auxiliar.total_horas_corte = total; 

                // CALCULO LAS UNIDADES DE MULTA 
                if (total < 3) {
                    auxiliar.unidades_multa = 0; 
                }
                else if (total >= 3 && total <= 6) {
                    auxiliar.unidades_multa = 8 * total; 
                }
                else if (total >= 6) {
                    auxiliar.unidades_multa = 12 * total; 
                }

                // CALCULO EL PROMEDIO 
                // PROMEDIO = cant de horas de corte / cant cortes que hubieron 
                // como hay un solo corte por mes --> total / 1 = promedio
                auxiliar.cant_horas_promedio = total / 1; 

                // COMO YA TENGO TODO INSERTO ORDENADO A LA LISTA CON EL NODO GUARDADO DEL MES
                InsertarOrdenado(aux->info.ptr, auxiliar);
            }
    }
}

 