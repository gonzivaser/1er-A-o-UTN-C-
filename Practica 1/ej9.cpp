/*9.Se realiza una inspección en una fábrica de pinturas, y se detectaron 20 infracciones. 
De cada infracción se tomó nota de los siguientes datos:
- Tipo de Infracción (1, 2, 3, o 4)
- Motivo de la Infracción
- Valor de la multa (un entero)
- Gravedad de la infracción (‘L’,‘M’, ‘G’)
Se pide informar al final del proceso:
• Los valores totales de la multa a pagar de acuerdo al tipo de gravedad.
• La leyenda “Clausurar fabrica” si la cantidad de infracciones 3 y 4 con gravedad “G” sean mayor a 3.
*/

#include<iostream>
using namespace std; 

int main () {
    int i, tipoInf, valorMulta, gL = 0, gM = 0, gG = 0, clausura = 0;
    char motivoInf[40]; 
    char gravedad; 

    for(i = 0; i < 4; i++) {
        cout<<"Ingrese el tipo de infraccion (1, 2, 3, 4): "; 
        cin>>tipoInf; 
        cout<<"Ingrese el motivo de la infraccion: "; 
        cin>>motivoInf; 
        cout<<"Ingrese el valor de la multa: "; 
        cin>>valorMulta; 
        cout<<"Ingrese la gravedad de la infraccion 'L' 'M' 'G': "; 
        cin>>gravedad; 

        if(gravedad == 'G') {
            gG += valorMulta; 
            if(tipoInf == 3 || tipoInf == 4) {
                clausura++; 
            }
        }
        else if (gravedad == 'L') {
            gL += valorMulta; 
        }
        else if (gravedad == 'M') {
            gM += valorMulta; 
        }
    }

    cout<<"Los valores de gravedad son: "; 
    cout<<"G: "<<gG<<endl; 
    cout<<"L: "<<gL<<endl; 
    cout<<"M: "<<gM<<endl; 
    if(clausura > 3) {
        cout<<"Clausurar fabrica "<<endl; 
    }


    return 0; 
}