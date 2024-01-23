#include<iostream>
#include<cstring>
using namespace std; 

/*
NOTAS: 
- LISTA CIRCULAR --> ULTIMO ELEMENTO APUNTA AL PRIMERO
*/

/*--------------STRUCTS----------------*/
/*----------LISTA----------*/
struct InfoPasajero {
    char nombre[50]; 
    char apellido[50]; 
    char destino[30]; 
    char vuelo[6]; 
    int asiento; 
    int salida; 
    int llegada;  
};

struct NodoPasajero {
    InfoPasajero info; 
    NodoPasajero* sgte;
};


/*----------FUNCIONES PROTOTIPO----------*/
void IngresarPasajero (NodoPasajero*&, char, char, char, char, int, int, int);
void VisualizarPasajero (NodoPasajero*&, char); 
void VisualizarListaTotal (NodoPasajero*&); 
void VisualizarListaDestino (NodoPasajero*&, char);
void EliminarPasajero (NodoPasajero*&, char); 
void ModificarDatosDePasajero (NodoPasajero*&, char, char, char, int, int, int); 


/*--------------INT MAIN----------------*/
int main () {
    NodoPasajero* lista = NULL; 
    int opcion; 

    // IMPLEMENTO LA CONSOLA 
    do {
        cout << "MENU: " << endl; 
        cout << "1: Ingresar Pasajero: " << endl; 
        cout << "2: Visualizar Pasajero: " << endl; 
        cout << "3: Visualizar Lista Total: " << endl; 
        cout << "4: Visualizar Lista Destino: " << endl; 
        cout << "5. Eliminar Pasajero: " << endl; 
        cout << "6. Modificar Datos Pasajero: " << endl; 
        cout << "0. Salir del programa" << endl; 
        cout << "Seleccione una opcion: " << endl;
        cin >> opcion; 

        switch (opcion) 
        {
            case 1: 
            char nombre[50];
            char apellido[50];  
            char destino[6];
            char vuelo[6]; 
            int asiento, salida, llegada; 
            cout << "Ingrese Nombre: " << endl; 
            cin >> nombre;
            cout << "Ingrese Apellido: " << endl; 
            cin >> apellido; 
            cout << "Ingrese Destino: " << endl; 
            cin >> destino; 
            cout << "Ingrese Vuelo: " << endl; 
            cin >> vuelo; 
            cout << "Asiento: " << endl; 
            cin >> asiento; 
            cout << "Hora de salida: " << endl; 
            cin >> salida; 
            cout << "Hora de llegada: " << endl; 
            cin >> llegada; 
            IngresarPasajero(lista, nombre, apellido, destino, vuelo, asiento, salida, llegada); 
            break; 


            case 2: 
            char nombre_2[20]; 
            cout << "Ingrese el nombre que desea visualizar datos: " << endl;
            cin >> nombre_2;  
            VisualizarPasajero(lista, nombre_2); 
            break; 


            case 3: 
            cout << "Lista total: " << endl; 
            VisualizarListaTotal(lista); 
            break;


            case 4: 
            char destino_elegido[6]; 
            cout << "Ingrese un Destino: " << endl; 
            cin >> destino_elegido; 
            VisualizarListaDestino(lista, destino_elegido); 
            break; 


            case 5: 
            char nombre_elegido[20]; 
            cout << "Ingrese el nombre del pasajero que desea eliminar: " << endl; 
            cin >> nombre_elegido; 
            EliminarPasajero(lista, nombre_elegido); 
            break;


            case 6: 
            char nombre_elegido_modificar [20]; 
            cout << "Ingrese el nombre del pasajero que quiere modificar los datos: " << endl; 
            cin >> nombre_elegido_modificar; 
            ModificarDatosDePasajero(lista, nombre_elegido_modificar);
            break;


            case 0:
            cout << "Saliendo del programa... " << endl; 
            break; 


            default: 
            cout << "La opcion seleccionada es invalida " << endl; 
        }

    } while (opcion != 0); 


    return 0; 
}


/*--------------DECLARADAS----------------*/
void ModificarDatosDePasajero (NodoPasajero*& lista, char nombre, char apellido, char destino, char vuelo, int asiento, int salida, int llegada) {
    NodoPasajero* aux = lista; 
    NodoPasajero* primer_nodo = lista; 
    InfoPasajero al; 

    while (aux != NULL && aux->sgte != primer_nodo) {
        if(strcmp(nombre, aux->info.nombre) == 0) {
            strcpy(al.nombre, nombre); 
            strcpy(al.apellido, apellido); 
            strcpy(al.destino, destino);
            strcpy(al.vuelo, vuelo); 
            al.asiento = asiento; 
            al.salida = salida; 
            al.llegada = llegada; 

            InsertarSinRepetir(lista, al);  
        }

        aux = aux->sgte; 
    }
}


void EliminarPasajero (NodoPasajero*& lista, char nombre) {
    NodoPasajero* aux = lista; 
    NodoPasajero* primer_nodo = lista; 

    while (aux != NULL && aux->sgte != primer_nodo) {
        if (strcmp(nombre, aux->info.nombre)) {
            pop(aux->info); 

            cout << "Pasajero Eliminado De La Lista. " << endl; 
        }
        
        aux = aux->sgte; 
    }
}


void VisualizarListaDestino (NodoPasajero*& lista, char destino) {
    NodoPasajero* aux = lista; 
    NodoPasajero* primer_nodo = lista; 
    int contador = 0; 

    while (aux != NULL && aux->sgte != primer_nodo) {
        
        if (strcmp(destino, aux->info.destino) == 0) {
            contador++; 
        }
        aux = aux->sgte; 
    }

    cout << "Totalidad de pasajeros en ese destino es: " << contador << endl; 
}


void VisualizarListaTotal (NodoPasajero*& lista) {
    NodoPasajero* aux = lista; 
    NodoPasajero* primer_nodo = lista; 

    while (aux != NULL && aux->sgte != primer_nodo) {

        cout << "Nombre: " << aux->info.nombre;
        cout << "Apellido: " << aux->info.apellido; 
        cout << "Destino: " << aux->info.destino; 
        cout << "Vuelo: " << aux->info.vuelo; 
        cout << "Asiento: " << aux->info.destino; 
        cout << "Salida: " << aux->info.salida;
        cout << "LLegada: " << aux->info.llegada; 
        
        aux = aux->sgte; 
    }

}


void VisualizarPasajero (NodoPasajero*& lista, char nombre) {
    NodoPasajero* aux = lista; 
    NodoPasajero* primer_nodo = lista; 

    while (aux != NULL && aux->sgte != primer_nodo) {

        if (strcmp(nombre, aux->info.nombre) == 0) {
            cout << "Apellido: " << aux->info.apellido; 
            cout << "Destino: " << aux->info.destino; 
            cout << "Vuelo: " << aux->info.vuelo; 
            cout << "Asiento: " << aux->info.destino; 
            cout << "Salida: " << aux->info.salida;
            cout << "LLegada: " << aux->info.llegada; 
        }

        aux = aux->sgte; 
    }

}


void IngresarPasajero (NodoPasajero*& lista, char nombre, char apellido, char destino, char vuelo, int asiento, int salida, int llegada) {
    NodoPasajero* aux = NULL; 
    InfoPasajero al; 
    
    strcpy(al.nombre, nombre); 
    strcpy(al.apellido, apellido); 
    strcpy(al.destino, destino);
    strcpy(al.vuelo, vuelo); 
    al.asiento = asiento; 
    al.salida = salida; 
    al.llegada = llegada; 

    InsertarSinRepetir(lista, al);  
}