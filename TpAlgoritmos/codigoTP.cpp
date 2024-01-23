#include <iostream>
#include <cstring>
using namespace std;

/*-------------------------------STRUCTS Y PROTOTIPOS---------------------------------*/
struct Medicamento
{
    int idMedicamento;
    char descripcion[100 + 1];
    char presentacion[50 + 1];
};

struct Paciente
{
    int idPaciente;
    char nombre[10 + 1];
    char apellido[20 + 1];
    int fechaNacimiento;
    int DNI;
    int telefono;
};

struct Atencion
{
    int idAtencion;
    int fecha;
    int idMedico;
    int idPaciente;
    int idMedicamento;
    char diagnostico[130 + 1];
};

struct Medico
{
    int idMedico;
    char nombre[10 + 1];
    char apellido[20 + 1];
    char matricula[6 + 1];
    char especialidad[20 + 1];
};

struct InfoAtencion
{
    int idAtencion;
    int fecha;
    int idMedico;
    int idMedicamento;
    char diagnostico[130 + 1];
};

struct Nodo
{
    InfoAtencion info;
    Nodo *sgte;
};

void CargarVectorMedicamentos(Medicamento[]);
Paciente buscarPacientePorDNI(FILE *, int);
void mostrarPaciente(Paciente);

Medico buscarMedicoPorApellidoYNombre(FILE *, char[], char[]);
void mostrarMedico(Medico);
Medico buscarMedicoId(FILE *, int);

void buscarAtenciones(FILE *, int, Nodo *&);
void transformarFecha(int, char[]);
void mostrarAtencion(Medico, InfoAtencion, Medicamento); 

Nodo *insertarOrdenado(Nodo *&, InfoAtencion);
InfoAtencion pop(Nodo *&);


/*-------------------------------MAIN---------------------------------*/
int main()
{
    int opcion = 5;
    int dni = 0;
    char apellido[20 + 1];
    char nombre[10 + 1];
    Paciente pacienteEncontrado;
    Medico medicoEncontrado;
    Nodo *listaAtenciones = NULL;
    FILE *M = fopen("MEDICOS.dat", "rb");
    FILE *P = fopen("PACIENTES.dat", "rb");
    FILE *A = fopen("ATENCIONES.dat", "rb");

    Medicamento medicamentos[50];
    CargarVectorMedicamentos(medicamentos);

    // MENU
    do
    {
        cout << "-------------MENU DE ADMNISTRACION DE INFORMES-------------" << endl;
        cout << "1. Consulta de pacientes por DNI" << endl;
        cout << "2. Consulta de medicos por Apellido y Nombre" << endl;
        cout << "3. Consulta de atenciones por paciente por DNI" << endl;
        cout << "0. Salir" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Ingrese el DNI del paciente: ";
            cin >> dni;

            pacienteEncontrado = buscarPacientePorDNI(P, dni);
            mostrarPaciente(pacienteEncontrado);
            break;


        case 2:
            cout << "Ingrese el Apellido del medico: ";
            cin >> apellido;
            cout << "Ingrese el Nombre del medico: ";
            cin >> nombre;

            medicoEncontrado = buscarMedicoPorApellidoYNombre(M, apellido, nombre);
            mostrarMedico(medicoEncontrado);
            break;


        case 3:
            cout << "Ingrese el DNI para consultar la atencion: ";
            cin >> dni;

            pacienteEncontrado = buscarPacientePorDNI(P, dni);
            if (pacienteEncontrado.idPaciente != -1)
            {
                buscarAtenciones(A, pacienteEncontrado.idPaciente, listaAtenciones);
                if (listaAtenciones == NULL)
                {
                    cout << "El paciente " << pacienteEncontrado.apellido << " no tiene atenciones registradas en el sistema." << endl;
                }
                else
                {
                    cout << "Paciente: " << pacienteEncontrado.nombre << " " << pacienteEncontrado.apellido << endl;
                    while (listaAtenciones != NULL)
                    {
                        medicoEncontrado = buscarMedicoId(M, listaAtenciones->info.idMedico);
                        mostrarAtencion(medicoEncontrado, pop(listaAtenciones), medicamentos);
                    }
                }
            }
            else
                cout << "No existe el paciente." << endl;

            break;


        case 0:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "La opcion seleccionada es invalida." << endl;
        }
    } while (opcion != 0);

    return 0;
}
/*-------------------------------DECLARADAS---------------------------------*/
void CargarVectorMedicamentos(Medicamento m[])
{
    int n = 50;
    char descripcionesMedicamentos[50][100 + 1] = {
        "Suplemento vitamínico para el sistema inmunológico",
        "Analgésico de acción rápida para aliviar el dolor",
        "Crema hidratante para la piel seca", // 3
        "Antibiótico de amplio espectro",
        "Antiácido para aliviar la acidez estomacal", // 5
        "Jarabe expectorante para la tos",
        "Protector solar SPF 50 para la piel",
        "Suplemento de calcio para huesos fuertes",
        "Antiinflamatorio para el alivio de la inflamación",
        "Enjuague bucal antibacteriano",
        "Parche para aliviar el dolor muscular",
        "Gotas para los ojos lubricantes",
        "Pastillas para mejorar la digestión", // 13
        "Loción repelente de insectos",
        "Solución salina para la limpieza nasal",
        "Antidiarreico de acción rápida",
        "Antihistamínico para aliviar las alergias",
        "Pomada cicatrizante para heridas leves",             // 18
        "Suplemento de omega-3 para la salud cardiovascular", // 19
        "Spray nasal descongestionante",                      // 20
        "Pastillas para aliviar el estrés",
        "Desodorante antitranspirante de larga duración",
        "Vitaminas y minerales para la energía diaria",
        "Gel para aliviar la irritación cutánea",
        "Pastillas para mejorar la memoria",
        "Crema para el alivio de la picazón",
        "Jarabe multivitamínico para niños",
        "Tiras reactivas para medir el nivel de glucosa",
        "Pastillas efervescentes para la hidratación",
        "Bálsamo labial con protección solar",
        "Suplemento de hierro para prevenir la anemia",
        "Cepillo dental eléctrico de alta tecnología",
        "Spray desinfectante para superficies",
        "Acondicionador de aire nasal para el sueño",
        "Aceite esencial relajante para aromaterapia",
        "Pasta dental blanqueadora",
        "Té herbal para la relajación",
        "Cinta adhesiva resistente para vendajes",
        "Pastillas para aliviar el mareo",
        "Shampoo anticaspa con extractos naturales",
        "Gel para el alivio de picaduras de insectos",
        "Compresas frías para lesiones musculares",
        "Parches para el alivio de dolores articulares",
        "Spray bucal refrescante",
        "Vendaje elástico para soporte muscular",
        "Cápsulas de probióticos para la salud intestinal",
        "Tónico facial revitalizante"};

    char presentacionesMedicamentos[50][50 + 1] = {
        "VitaliVit C",
        "DolorEase Forte",
        "DermoSoothe Crema",
        "BacteriKill Plus",
        "GastroRelief",
        "TosStop Jarabe",
        "SunGuard Ultra",
        "Suplemento HuesoFuerte",
        "InflammaRelief",
        "OralGuard Enjuague",
        "MusclePatch Pro",
        "ClearView Gotas Oculares",
        "DigestoAid Pastillas",
        "BugOff Loción",
        "NasalClear Solución",
        "DiaBlock Rápido",
        "AllerRelief Antihistamínico",
        "HealFast Ungüento",
        "CardioOmega-3 Plus",
        "NasoFree Descongestionante",
        "StressLess Pastillas",
        "EverFresh Desodorante",
        "EnergyPlus Multivitamínico",
        "SkinSoothe Gel",
        "MindBoost Pastillas",
        "ItchAway Crema",
        "KidsVita Jarabe",
        "GlucoCheck Tiras",
        "HydrateFizz Efervescente",
        "LipGuard Protector Solar Labial",
        "IronMax Suplemento",
        "TechDent Cepillo Dental Eléctrico",
        "SurfaceSafe Desinfectante",
        "NasalEase Ayuda para Dormir",
        "RelaxZen Aceite de Aromaterapia",
        "WhiteSmile Pasta Dental",
        "HerbalCalm Té",
        "HealTape Adhesivo Fuerte",
        "DizzyRelief Pastillas",
        "CalmScalp Shampoo Anticaspa",
        "InsectBite Gel",
        "CoolCompress para Lesiones Musculares",
        "JointEase Parches para el Dolor",
        "MintyFresh Spray Bucal",
        "MuscleSupport Venda Elástica",
        "ProBioCaps Probiótico",
        "Revitalize Tónico Facial"};
    for (int i = 0; i < n; i++)
    {
        m[i].idMedicamento = i;
        strcpy(m[i].descripcion, descripcionesMedicamentos[i]);
        strcpy(m[i].presentacion, presentacionesMedicamentos[i]);
    }
}

Paciente buscarPacientePorDNI(FILE *P, int dni)
{
    Paciente paciente;
    while (fread(&paciente, sizeof(Paciente), 1, P))
    {
        if (paciente.DNI == dni)
        {
            // Devuelve el registro del paciente
            return paciente;
        }
    }
    // Si no se encuentra, devuelve un paciente con id -1
    return {-1, "", "", 0, 0, 0};
}

Medico buscarMedicoPorApellidoYNombre(FILE *M, char apellido[], char nombre[])
{
    Medico medico;
    while (fread(&medico, sizeof(Medico), 1, M))
    {
        if (strcmp(medico.nombre, nombre) == 0 && strcmp(medico.apellido, apellido) == 0)
        {
            return medico;
        }
    }
    // Si no se encuentra, devuelve un médico con id -1
    return {-1, "", "", "", ""};
}

Medico buscarMedicoId(FILE *M, int id)
{
    Medico medico;
    while (fread(&medico, sizeof(Medico), 1, M))
    {
        if (medico.idMedico = id)
        {
            return medico;
        }
    }
    // Si no se encuentra, devuelve un médico con id -1
    return {-1, "", "", "", ""};
}

void mostrarPaciente(Paciente paciente)
{
    if (paciente.idPaciente != -1)
    {
        char fechaTransformada[11];
        transformarFecha(paciente.fechaNacimiento, fechaTransformada);
        // Imprimir los datos del paciente encontrado
        cout << "Datos del paciente:\n";
        cout << "ID: " << paciente.idPaciente << endl;
        cout << "Nombre: " << paciente.nombre << endl;
        cout << "Apellido: " << paciente.apellido << endl;
        cout << "Fecha de Nacimiento: " << fechaTransformada << endl;
        cout << "DNI: " << paciente.DNI << endl;
        cout << "Telefono: " << paciente.telefono << endl;
    }
    else
        cout << "Paciente no encontrado." << endl;
}

void mostrarMedico(Medico medico)
{
    if (medico.idMedico != -1)
    {
        // Imprimir los datos del médico encontrado
        cout << "Datos del medico:\n";
        cout << "ID: " << medico.idMedico << endl;
        cout << "Nombre: " << medico.nombre << endl;
        cout << "Apellido: " << medico.apellido << endl;
        cout << "Matricula: " << medico.matricula << endl;
        cout << "Especialidad: " << medico.especialidad << endl;
    }
    else
        cout << "Medico no encontrado." << endl;
}

void transformarFecha(int fechaOriginal, char fechaTransformada[])
{
    int año = fechaOriginal % 10000;
    int mes = (fechaOriginal / 10000) % 100;
    int dia = fechaOriginal / 1000000;

    // Convertir cada componente a caracteres
    int d1 = dia / 10;
    int d2 = dia % 10;
    int m1 = mes / 10;
    int m2 = mes % 10;
    int a1 = año / 1000;
    int a2 = (año / 100) % 10;
    int a3 = (año / 10) % 10;
    int a4 = año % 10;

    // Asignar los caracteres a la cadena de fechaTransformada
    fechaTransformada[0] = '0' + m1;
    fechaTransformada[1] = '0' + m2;
    fechaTransformada[2] = '/';
    fechaTransformada[3] = '0' + d1;
    fechaTransformada[4] = '0' + d2;
    fechaTransformada[5] = '/';
    fechaTransformada[6] = '0' + a1;
    fechaTransformada[7] = '0' + a2;
    fechaTransformada[8] = '0' + a3;
    fechaTransformada[9] = '0' + a4;
    fechaTransformada[10] = '\0'; // Carácter nulo al final
}

void mostrarAtencion(Medico medico, InfoAtencion info, Medicamento medicamentos[])
{
    char fechaTransformada[11];
    transformarFecha(info.fecha, fechaTransformada);
    cout << "-----------------------------------------" << endl;
    cout << "Fecha de la atencion: " << fechaTransformada << endl;
    cout << "Dr/a. " << medico.nombre << " " << medico.apellido << endl;
    cout << "Diagnostico: " << info.diagnostico << endl;
    if(info.idMedicamento != -1)
    {
        cout << "Medicamento/s: " << medicamentos[info.idMedicamento - 1].presentacion << endl;
        cout << "Descripcion: " << medicamentos[info.idMedicamento - 1].descripcion << endl;
    }
}

void buscarAtenciones(FILE *A, int idBuscado, Nodo *&lista)
{
    Atencion atencion;
    InfoAtencion auxInfo;
    while (fread(&atencion, sizeof(Atencion), 1, A))
    {
        if (atencion.idPaciente == idBuscado)
        {
            auxInfo.fecha = atencion.fecha;
            auxInfo.idMedico = atencion.idMedico;
            auxInfo.idAtencion = atencion.idAtencion;
            strcpy(auxInfo.diagnostico, atencion.diagnostico);
            auxInfo.idMedicamento = atencion.idMedicamento;
            insertarOrdenado(lista, auxInfo);
        }
    }
}

Nodo *insertarOrdenado(Nodo *&lista, InfoAtencion info)
{
    Nodo *p = new Nodo();
    p->info = info;
    p->sgte = NULL;

    // 1 y 2 si esta vacia o es menor que el primero
    if (lista == NULL || info.idAtencion < lista->info.idAtencion)
    {
        p->sgte = lista;
        lista = p;
    } // 3 y 4 medio o final je
    else
    {
        Nodo *q = lista;                                                      // auxiliar para no perder la lista
        while (q->sgte != NULL && q->sgte->info.idAtencion < info.idAtencion) // Encontrar la posicion de la lista
            q = q->sgte;

        p->sgte = q->sgte;
        q->sgte = p;
    }
    return p;
}

InfoAtencion pop(Nodo *&lista) // recibe la lista y retorna la info del primer nodo
{
    InfoAtencion x;
    x = lista->info; // Guardo la info antes de borrarlo, para retornarlo

    Nodo *p = lista; // el puntero al comienzo de la estructura para poder eliminar ese nodo

    lista = p->sgte; // avanzar en la lista un nodo, ya que el primero se elimina, puede apuntar a un nodo como a NULL

    delete p; // elimina el primer nodo de la lista
    return x;
}
