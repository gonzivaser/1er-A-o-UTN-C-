#include<iostream>
#include<cstring>
using namespace std; 

/*--------------STRUCTS----------------*/
/*
ZONAS ATLANTICAS 
--> ALTA ES VERANO
--> BAJA OTOÑO E INVIERNO 
--> MEDIA PRIMAVERA  

ESTRUCTURA DE FECHA: EJEMPLO: 02 24 DIVIDO POR 100 Y ME DA EL MES FEBRERO 
*/

struct Estaciones {
    char nombre[30]; 
    int fecha_inicio; 
    int fecha_finalizacion;     
};

struct InfoArch {
    char zona[30]; 
    int dia; 
    int mes; 
    int reservas; 
};





Estaciones EstacionDelAño (Estaciones [], int, int); 
void Mostrar (InfoArch, FILE*, Estaciones); 


/*--------------INT MAIN----------------*/
int main () {
    Estaciones vectorEst[];
    FILE* f = fopen("RESERVAS.DAT", "rb"); 
    return 0; 
}


/*--------------DECLARADAS----------------*/
Estaciones EstacionesDelAño (Estaciones vectorEst [], int dia, int mes) {
    int i = 0; 

    // PASO A FORMATO DE NUMERO LOS DIAS Y LOS MESES 
    int aux = mes * 100 + dia; 

    for (i = 0; i < 4; i++) {
        if (aux >= vectorEst[i].fecha_inicio[i] && aux <= vectorEst[i].fecha_finalizacion) {
            return Estaciones[i];  
        }
    }

}

void Mostrar (InfoArch al, FILE* f, Estaciones vectorEst, char zona, char estacion) {
   
    while(fread(&al, sizeof(InfoArch), 1, f)) {
        
        // VERIFICO QUE EL ARCHIVO COINCIDA CON LA LISTA PEDIDA ESTA EN LA ZONA ATLANTICA
        if (strcmp(al.zona, zona) == 0) {

            // APLICO FUNCION PARA BUSCAR LAS FECHAS EN EL AÑO 
            Estaciones estacion = EstacionesDelAño(vectorEst, al.dia, al.mes); 

            // VERIFICO QUE LA ESTACION COINCIDA CON LA ESTACION BUSCADA 
            if (strcmp(estacion.nombre, estacion) == 0) {
                cout << "Mes: " << al.mes; 
                cout << "Dia: " << al.dia; 
                cout << "Reservas: " << al.reservas; 
            }
        }
    }
    
}




