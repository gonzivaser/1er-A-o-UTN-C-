#include<iostream>
#include<cstring>
using namespace std; 

/* NOTAS: 
LLEGA EL MENSAJE 
- N ES LA LONGITUD MAXIMA DE PALABRAS, SI ES MENOR ESTA OK, SINO ES RIESGOSO 
- LA FUNCION ES RIESGOSO RECIBE EL MENSAJE, Y LO QUE HACES ES VER SI ES MAYOR A N O MENOR, SI ES MENOR
LO CARGA EN LA PILA (OSEA QUE NO ES RIEGOSOS), Y SI ES MAYOR RETURN FALSE 
*/

/*--------------STRUCTS----------------*/
struct mensaje {
    int id_mensaje; 
    int id_conversacion; 
    int id_emisor; 
    int id_receptor; 
    char texto[50]; 
};

struct NodoPalabra {
    char texto[50]; 
    NodoPalabra* sgte; 
};

// FUNCIONES QUE ME OTORGA EL EJERCICIO 
bool ObtenerProximo(mensaje&); 
void Enviar(mensaje, int); 
void Alertar(int);
NodoPalabra* CrearPilaDePalabras(char);

// FUNCIONES A CREAR 
bool EsRiesgoso (mensaje, int);
void ProcesarPendientes (); 

/*--------------INT MAIN----------------*/
int main () {
    return 0; 
}


/*--------------DECLARADAS----------------*/
// FUNCIONES A DECLARAR 
void ProcesarPendientes () {
    
}

bool EsRiesgoso (mensaje m, int N) {
    if (m.texto.lenght() < N) {
        CrearPilaDePalabras(m.texto); 
        return true; 
    }
    else {
        return false; 
    }
}



// FUNCIONES QUE ME DA EL EJERCICIO 
bool ObtenerProximo(mensaje& m); 
void Enviar(mensaje m, int id_receptor); 
void Alertar(int id_emisor);
NodoPalabra* CrearPilaDePalabras(char texto);