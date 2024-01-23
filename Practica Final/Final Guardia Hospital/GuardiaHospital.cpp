#include<iostream>
#include<cstring>
using namespace std; 

/*
NOTAS: 
- UTILIZAN COLAS 
- 
*/


/*--------------STRUCTS----------------*/

/*-------LISTAS-------*/
struct ColaPrioridad {
    NodoListaPrioridad* vector [5]; 
}; 

struct InfoListaPrioridad {
    int prioridad; 
    char nombre[40]; 
};

struct NodoListaPrioridad {
    InfoListaPrioridad info; 
    NodoListaPrioridad* sgte; 
};


/*--------------INT MAIN----------------*/
int main () {
    return 0; 
}


/*--------------DECLARADAS----------------*/