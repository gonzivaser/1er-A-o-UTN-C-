/*7.Dado un conjunto de N cursos (<=20) de la cátedra de algoritmos, de cada uno
de ellos código de curso (4 caracteres) y cantidad de alumnos, y de cada 
curso el número de legajo y nota (0..10) de los alumnos.
Se pide:
• Informar de cada curso la cantidad de alumnos que tuvieron como nota 0, 1, ...,9, 10
• Informar al final del proceso el código de curso, el % de aprobados y el de 
  insuficientes de cada curso. */

#include<iostream> 
using namespace std; 

struct curso {
    char codigo[6]; 
    int cantAlumnos; 
    int curso_notas[]; 
};

struct alumno {
    int legajo; 
    int nota; 
};

int main () {
    int n, i = 0; 

    cout << "Ingrese el numero de cursos MENOR O IGUAL a 20: "; 
    cin >> n; 
    curso vector[n]; 
    alumno VEC[]; 

    // RELLENO VECTOR DE CURSO
    cout << "Ingrese el codigo de curso: "; 
    cin >> vector[n].codigo; 

    cout << "Ingrese la cantidad de alumnos: "; 
    cin >> vector[n].cantAlumnos; 

    // RELLENO VECTOR DE ALUMNOS
    for (i = 0; i < n; i++) {
        vector[i].cantAlumnos; 
        cout << "Ingrese el legajo de cada alumno: "; 
        cin >> 
    }


   
    return 0; 
}