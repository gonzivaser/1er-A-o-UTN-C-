/*9.Dado un archivo binario ‘ACTASFINALES.dat’ que contiene las actas de los exámenes finales 
de las distintas materias, ordenado por libro y folio y con el siguiente diseño 
a.	Libro (6 digitos) 
b.	Folio ( 1..999) 
c.	Fecha (aaaammdd)
d.	Código materia (6 dígitos)
e.	Legajo (10 digitos)
f.	Apellido y nombre (20 caracteres)
g.	Nota (1..10, 0 indica ausente)

Se pide desarrollar todos los pasos necesarios para realizar un algoritmo que grabe 
un archivo ‘TOTALES.dat’ ordenado por libro y folio con el siguiente diseño:
Libro (6 digitos)
Folio ( 1..999)
Total alumnos inscriptos (1..20)
Total alumnos ausentes (1..20)
Total alumnos aprobados (1..20)
Total alumnos desaprobados (1..20)
*/

#include<iostream>
#include<cstring>
using namespace std; 

struct actas {
    int libro; 
    int folio; 
    int fecha; 
    int cod_mat; 
    int legajo; 
    char nombre[50]; 
    int nota; 
};

struct total {
    int libro; 
    int folio; 
    int nota; 
    int total_ausentes; 
    int total_aprobados; 
    int total_desaprobados;
};


int main () {
    FILE* archivo1 = fopen("ACTASFINALES.DAT", "rb"); 
    FILE* archivo2 = fopen("TOTALES.DAT", "wb+"); 

    actas al; 

    fseek(archivo1, 0, SEEK_END); 
    int D = ftell(archivo1); 
    int cantreg = D / sizeof(actas); 
    actas vector[cantreg]; 
    fseek(archivo1, 0, SEEK_SET); 

    int i = 0;
    while(fread(&al, sizeof(actas), 1, archivo1)) {
        vector[i] = al; 
        i++; 
    }

    int cant_ausentes = 0; 
    int cant_aprobados = 0; 
    int cant_desaprobados = 0;
    int cantidad_total = cantreg; 

    for (i = 0; i < cantreg; i++) {
        if (vector[i].nota == 0) {
            cant_ausentes++; 
        } 
        else if (vector[i].nota >= 6 && vector[i].nota <= 10) {
            cant_aprobados++; 
        }
        else {
            cant_desaprobados++; 
        }
    }

    for(i = 0; i < cantreg; i++) {
        total al; 
        al.libro = vector[i].libro; 
        al.folio = vector[i].folio; 
        al.nota = vector[i].nota;
        al.total_ausentes = cant_ausentes;
        al.total_aprobados = cant_aprobados;
        al.total_desaprobados = cant_desaprobados;
        fwrite(&al, sizeof(total), 1, archivo2);
    }

    fclose(archivo1);
    fclose(archivo2);

    return 0; 
}