#include<iostream>
#include<cstring>
using namespace std; 

// 1) CREAR EL NODO CON LA INFO 
// 2) PREGUNTAMOS SI LA COLA ESTA VACIA 
//    SI --> NOTICFICAMOS A FRENTE 
//    NO --> NOTIFICAMOS AL QUE TENIAMOS DELANTE 
// 3) NOTIFICAMOS A FIN DEL NUEVO ULTIMO 

struct nodo {
    int info; 
    nodo* sgte; 
}; 

void queue(nodo*&, nodo*&, int); 
int unqueue(nodo*&, nodo*&);


int main () {
    nodo* fte = NULL; 
    nodo* fin = NULL; 

    // EJEMPLO PARA INSERTAR DATOS: 
    int dato; 
    cout << "Digite un numero: "; 
    cin >> dato; 
    queue(fte, fin, dato); 


    cout << "Digite otro numero: "; 
    cin >> dato; 
    queue(fte, fin, dato); 


    // EJEMPLO PARA SACAR LOS ELEMENTOS DE UNA COLA
    cout << "Sacando los elementos de la cola: "; 
    while (fte != NULL) {
        int aux = unqueue(fte, fin); 
        cout << aux;
    }


    return 0; 
}


void queue(nodo*& fte, nodo*& fin, int info) {
	
    nodo* p = new nodo();
	p -> info = info;
	p -> sgte = NULL; 
	
    if (fte == NULL) { //SI ESTA VACIA 
		fte = p;
	} else {
		fin->sgte = p;
	}
	
    fin = p;	//SIEMPRE FIN CONOCE AL ULTIMO
	
    return;
}

int unqueue(nodo*& fte, nodo*& fin) {

    int x; 
    nodo* p = fte; 
    x = fte -> info; 
    fte = p -> sgte; 

    if (fte == NULL) {
        fin = NULL; 
    }


    delete p; 
    return x; 
}