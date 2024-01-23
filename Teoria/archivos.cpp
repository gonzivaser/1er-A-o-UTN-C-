#include<iostream>
using namespace std; 

struct alumno {
    int legajo; 
    char nombre[50]; 
};

int main () {

    FILE* archivo = fopen("alumnos.bin", "wb+");
    
    alumno al;
    cout << "Ingrese el legajo "; 
    cin >> al.legajo;
    cout << "Ingrese el nombre: "; 
    cin >> al.nombre; 

    fwrite(&al, sizeof(alumno), 1, archivo); 
    fseek(archivo, 0, SEEK_SET); 

    alumno al2; 
    fread(&al2, sizeof(alumno), 1, archivo); 

    cout << "el nombre y el legajo es: " << al2.nombre << "y " << al2.legajo << endl;  

    fclose(archivo); 

    return 0; 
}