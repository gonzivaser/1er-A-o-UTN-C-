#include<iostream>
#include<cstring>
using namespace std; 

/*NOTAS: 
- INFORMAR AL USUARIO DE QUE LLEGO UN MENSAJE 

- LA FUNCION QUE TENGO QUE HACER LO QUE HACE ES: 

*/

/*--------------STRUCTS----------------*/
struct infoLista {
    int id_conversacion; 
    char nombre[50]; 
    bool notificar; 
    bool vistaprevia; 
}; 

struct NodoLista {
    infoLista info; 
    NodoLista* sgte; 
};

struct contactos {
    int id_usuario; 
    char nombre_contacto[50]; 
    bool indicador_bloqueado; 
};


// FUNCIONES QUE ME DA EL EJERCICIO 
char NumeroTelefonicoDelUsuario(int); 
char VistaPreviaMensaje (mensaje); 
void EmitirNotificacion(char, char);

// FUNCIONES QUE TENGO QUE REALIZAR 
void NotificarMensajeRecibido (NodoLista&*, contactos [], int, int, int, mensaje);



/*--------------INT MAIN----------------*/
int main () {
    NodoLista* lista = NULL; 
    return 0; 
}


/*--------------DECLARADAS----------------*/
void NotificarMensajeRecibido (NodoLista&* lista, contactos vector[], int n, int id_conversacion, int id_emisor, mensaje mensaje) {
    n = 200; // CAPACIDAD MAXIMA DE CONVERSACIONES o USUARIOS 

    // BUSCO EL ID CONVERSACION 
    NodoLista* aux = NULL; 
    aux = BuscarLista(lista, id_conversacion);

    // BUSCO EL CONTACTO 
    int posicion_contacto; 
    posicion_contacto = BuscarContacto(vector, id_emisor); 
    bool bloqueado; 
    char nombre_contacto; 

    if (posicion_contacto != -1) {
        bloqueado = vector[posicion_contacto].indicador_bloqueado; 
        nombre_contacto = vector[posicion_contacto].nombre_contacto; 
    }
    else {
        bloqueado = false; 
        nombre_contacto = NumeroTelefonicoDelUsuario(id_emisor); 
    }

    if (aux ->info.vistaprevia == "") {
        
    }


    

}

int BuscarContacto (contactos vector [], int id_emisor) {
    int i; 
    int posicion = -1; 
    for (i = 0; i < 200; i++) {
        if (vector[i].id_usuario == id_emisor) {
            posicion = i; 
        }
    }
    return posicion; 
}

NodoLista* BuscarLista (NodoLista*& lista, int id_conversacion) {
    while (lista != NULL && lista->info.id_conversacion == id_conversacion) {
        lista = lista -> sgte; 
    }
    return lista; 
}