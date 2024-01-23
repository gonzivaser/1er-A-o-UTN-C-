#include<iostream>
using namespace std; 

// STRUCTS DECLARADAS 
struct alumno {
    int codMateria; 
    char nombreMateria[20]; 
    char nombre[50]; 
    int nota; 
};

// PROTOTIPO DE FUNCIONES 
void Burbuja(alumno[], int); 
void CorteDeControl (alumno [], int); 


// INT MAIN 
int main () {
    int n, i = 0; 

    cout << "Cantidad de materias: "; 
    cin >> n; 
    alumno vector[n]; 

    for (i = 0; i < n; i++) {
        cout << "Codigo de materia: "; 
        cin >> vector[i].codMateria; 

        cout << "Nombre de materia: "; 
        cin >> vector[i].nombreMateria; 

        cout << "Nombre de alumno: "; 
        cin >> vector[i].nombre; 

        cout << "Nota de alumno: "; 
        cin >> vector[i].nota; 
    }

    Burbuja (vector, n); 
    CorteDeControl(vector, n);


    return 0;
}


// FUNCIONES DECLARADAS 

// ORDENAMIENTO BURBUJA POR CODIGO DE MATERIA 
void Burbuja (alumno vector[], int n) {
    int i, j;
    alumno aux;   

    for (i = 1; i < n; i++) {
        for (j = 1; j <= (n - i); j++) {
            if (vector[j - 1].codMateria > vector[j].codMateria) {
                aux = vector[j - 1];
                vector[j - 1] = vector[j]; 
                vector[j] = aux; 
            }
        }
    }
}


// CORTE DE CONTROL 
void CorteDeControl (alumno vector[], int n) {
    int i = 0; 
    int contarGrupos = 0; 
    int total = 0; 
    int promedio = 0;
    int materiaAux; 
    int contadorNotas = 0; 
    int suma = 0; 

    while (i < n) {
        materiaAux = vector[i].codMateria; 
        contarGrupos = 0; 

        //MUESTRO TITULO DEL GRUPO 
        cout << "Materia: " << vector[i].nombreMateria << "\t" << "Codigo: " << materiaAux << "\t" << endl; 
        
        // EMPIEZO A ITERAR EN LA MATERIA 
        while (i < n && materiaAux == vector[i].codMateria) {
            cout << vector[i].nombre << "\t" << vector[i].nota << endl; // MUESTRO NOMBRE DEL ALUMNO Y NOTA
            contarGrupos++; 
            contadorNotas++; 
            suma = suma + vector[i].nota; 
            total++; 
            i++; 
        }
        promedio = suma / contadorNotas; 

        cout << "Promedio de las notas es: " << promedio << endl; 
        cout << "Total: " << contarGrupos << endl; 
        cout << "-------" << endl; 
    }

    cout << "Cantidad de registros procesados: " << total << endl; 
}