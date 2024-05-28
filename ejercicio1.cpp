/*Desarrollar un programa que permita crear un archivo agenda.dat de 
direcciones, cuyos registros constan de los siguientes campos:
Nombre, edad, direccion, ciudad, telefono*/

#include <iostream>
#include <fstream>
#define MAX_STR 60
#define MAX_REG 100

using namespace std;

struct AGENDA{
    char nombre[MAX_STR];
    char edad[MAX_STR];
    char direccion[MAX_STR];
    char ciudad[MAX_STR];
    char telefono[MAX_STR];
};

AGENDA agendas[MAX_REG];

int main(){
    FILE *archivo;
    archivo = fopen("agenda.dat", "wb");
    if(archivo == NULL){
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }

    int j;
    cout << "Ingrese la cantidad de registros: ";
    cin >> j;

    for(int i = 0; i < j; i++){
        cout << "Ingrese el nombre: ";
        cin >> agendas[i].nombre;
        cout << "Ingrese la edad: ";
        cin >> agendas[i].edad;
        cout << "Ingrese la dirección: ";
        cin >> agendas[i].direccion;
        cout << "Ingrese la ciudad: ";
        cin >> agendas[i].ciudad;
        cout << "Ingrese el teléfono: ";
        cin >> agendas[i].telefono;
        
        fwrite(&agendas[i], sizeof(AGENDA), 1, archivo);
    }

    fclose(archivo);

    cout << "Archivo creado" << endl;

}