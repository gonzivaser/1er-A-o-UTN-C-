#include<iostream>
using namespace std; 

/*--------------STRUCTS----------------*/
struct InfoArch {
    int id_curso; 
    int id_estudiante; 
    int parcial; 
    int nota_parcial; 
};


/*----------LISTA NOTAS POR CADA PARCIAL DE CADA ESTUDIANTE-------------*/
struct InfoListaEvaluaciones {
    int notas; 
    int recuperatorios; 
};

struct ListaEvaluaciones {
    InfoListaEvaluaciones info; 
    ListaEvaluaciones* sgte; 
};


/*----------LISTA ESTUDIANTES-------------*/
struct InfoListaEstudiantes {
    int id_estudiante; 
    ListaEvaluaciones* Arreglo[4]; // PUNTERO A LISTA DE NOTAS 
};

struct ListaEstudiante {
    InfoListaEstudiantes info; 
    ListaEstudiante* sgte; 
};


/*----------LISTA CURSOS-------------*/
struct InfoListaCursos {
    int id_curso; 
    int promocionados; 
    int regularizados; 
    int recursantes; 
    ListaEstudiante* ptrEstudiantes; // PUNTERO A LISTA DE ESTUDIANTES 
};

struct ListaCursos {
    InfoListaCursos info; 
    ListaCursos* sgte; 
};

void ProcesarNovedades(FILE*, ListaCursos*&);  
void AgregarNota (ListaCursos*&, InfoArch, InfoArch, InfoArch, InfoArch);
void CalcularEstadisticas (ListaCursos*&); 

/*--------------INT MAIN----------------*/
int main () {
    return 0; 
}


/*--------------DECLARADAS----------------*/
void CalcularEstadisticas (ListaCursos*& lista) {
    ListaCursos* aux = lista; 
    int auxiliar; 
    
    // RECORRO LISTA
    while (aux != NULL) {
        // RECORRO LOS ESTUDIANTES Y ME FIJO QUE NO SEA NULL
        while(aux->info.ptrEstudiantes->info.id_estudiante != NULL) {

            // INVOCO FUNCION GET ESTADO Y LO GUARDO EN MI AUXILIAR 
            auxiliar = GetEstado(aux->info.ptrEstudiantes->info.Arreglo); 

            // HAGO MIS IF PARA VER SI ESTA PROMO, REGU O RECUR Y LO CARGO EN LA LISTA
            if (auxiliar == 1) {
                lista->info.promocionados++;// PROMOCIONADO
            }
            else if (auxiliar == 2) {
                lista->info.regularizados++; // REGULARIZADO
            }
            else {
                lista->info.recursantes++; // RECURSANTE
            }
        }
    }
}


void AgregarNota (ListaCursos*& lista, InfoArch curso, InfoArch estudiante, InfoArch parcial, InfoArch nota) {
    
    // RECORREMOS LA LISTA 
    // BUSCAMOS EN EL INFOARCH UN CURSO Y BUSCAMOS AL ESTUDIANTE 
    ListaCursos* aux = lista; 
    int i = 0; 

    // ARRANCO A RECORRER LISTA
    while (aux != NULL) {

        // MIENTRAS RECORRO SI EL ID CURSO COINCIDE CON EL DEL PARAMETRO QUE ENTRE AL WHILE 
        if (aux->info.id_curso == curso.id_curso) {

            // MIENTRAS QUE LA LISTA DE ESTUDIANTES NO SEA NULL, LA RECORRO
            while(aux->info.ptrEstudiantes != NULL) {

                // SI EL ID DE ESTUDIANTES COINCIDE CON EL DEL PARAMETRO DADO QUE ENTRE AL FOR
                if (aux->info.ptrEstudiantes->info.id_estudiante == estudiante.id_estudiante) {

                    // RECORRO EL VECTOR DE ARREGLO, (< 4 PORQUE HAY 4 INSTANCIAS DE EVALUACION)
                    for (i = 0; i < 4; i++) {
                        // SI EL VECTOR DE ARREGLO COINCIDE CON EL NUMERO DE PARCIAL PASADO POR PARAMETRO
                        // QUE INSERTE ORDENADAMENTE A LA LISTA LA NOTA DEL PARCIAL 
                        if (aux->info.ptrEstudiantes->info.Arreglo[i] == parcial.parcial) {
                            InsertarOrdenado(lista, nota.nota_parcial);
                        }
                    }
                }
                // SI NO COINCIDE EL ID, QUE SIGA AVANZANDO EN LA LISTA
                else {
                    aux->info.ptrEstudiantes = aux->info.ptrEstudiantes->sgte; 
                }
            }
        } 
        
        aux = aux->sgte;
    }
}


void ProcesarNovedades (FILE* f, ListaCursos*& lista) {
    InfoArch al;
    // LEO EL ARCHIVO DE MIENTRAS QUE UTILIZO LA FUNCION QUE DECLARO DESPUES PARA CARGAR LOS DATOS 
    while(fread(al, sizeof(InfoArch), 1, f)) {
        if (al.nota_parcial != 0) {
            AgregarNota(lista, al.id_curso, al.id_estudiante, al.parcial, al.nota_parcial); 
        }
    }
    
}

