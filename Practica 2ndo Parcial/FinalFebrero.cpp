#include<iostream>
using namespace std; 

/*--------------STRUCTS----------------*/
struct InfoArch {
    int dni; 
    char nombre[50]; 
    int fecha_nacimiento; 
    char domicilio[50]; 
    int centro_testeo; 
    char tipo_testeo[20];
    char obra_social[20]; 
    int cantidad_dosis_aplicadas; 
    int fecha_posible_contacto_estrecho; 
    int resultado;  
};

// ----------LISTA TERCIARIA----------------
struct InfoTerciaria {
    int dni; 
    char nombre[50]; 
    int fecha_nacimiento; 
    char domicilio[50]; 
};

struct ListaTerciaria {
    InfoTerciaria info3; 
    ListaTerciaria* sgte; 
};


// ----------LISTA SECUNDARIA----------------
struct InfoSecundaria {
    char tipo_testeo[50]; 
    ListaTerciaria* pacientes; 
};

struct ListaSecundaria {
    InfoSecundaria info2; 
    ListaSecundaria* sgte; 
};


// ----------LISTA PRINCIPAL----------------
struct InfoPrincipal {
    char obra_social[50]; 
    ListaSecundaria* vector[2]; 
};

struct ListaPrinci {
    InfoPrincipal info1; 
    ListaPrinci* sgte; 
};

// -------------FUNCIONES---------------
void CargarEstructura (FILE*, ListaPrinci*&);
void ImprimirListado (); 



/*--------------INT MAIN----------------*/
int main () {
    return 0; 
}


/*--------------DECLARADAS----------------*/
void CargarEstructura (FILE* f, ListaPrinci*& lista) {
    ListaPrinci* nodoaux = NULL; 
    int contador_positivos = 0; 
    int contador_negativos = 0; 

    InfoArch al;
    while(fread(&al, sizeof(InfoArch), 1, f)) {
        // CARGO MI NODO AUXILIAR CON MI OBRA SOCIAL 
        nodoaux = InsertarOrdenado(lista, al.obra_social); 

        // CARGO MI NODO AUXILIAR CON MI RESULTADO SI ES POSITIVO O NEGATIVO
        if (al.resultado == 1) {
            InsertarOrdenado(nodoaux->info1.vector[0]->info2.tipo_testeo, al.tipo_testeo);
            contador_positivos++; 
        }
        else {
            InsertarOrdenado(nodoaux->info1.vector[1]->info2.tipo_testeo, al.tipo_testeo); 
            contador_negativos++; 
        }

        // CARGUE EL RESTO DE LA INFORMACION 
        InsertarOrdenado(nodoaux->info1.vector[0]->info2.tipo_testeo, al); 
        InsertarOrdenado(nodoaux->info1.vector[1]->info2.tipo_testeo, al); 
    }
}

void ImprimirListado (ListaPrinci*& lista) {
    while (lista != NULL) {
        cout << lista->info1.obra_social; 

    }
}