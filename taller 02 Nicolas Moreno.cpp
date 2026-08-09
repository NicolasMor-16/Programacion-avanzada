#include <iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

struct Estudiantes{
    char nombre[30];
    char apellido[30];
    char codigo[10];
    char estado[15];
};

void guardar_estudiantes(Estudiantes etemporal[], int Tam_estudiantes){
    cin.ignore();
    for(int i=0; i<Tam_estudiantes;i++){
        cout<<"Ingresa el nombre del estudiante "<<i+1<<endl;
        cin.getline(etemporal[i].nombre,30);

        cout<<"Ingresa el apellido del estudiante numero: "<<i+1<<endl;
        cin.getline(etemporal[i].apellido,30);
        cout<<"Ingrese el codigo del estudiante numero: "<<i+1<<endl;
        cin.getline(etemporal[i].codigo,10);
        cout<<"Ingrese el estado del estudiante [activo o inactivo] numero: "<<i+1<<endl;
        cin.getline(etemporal[i].estado,15);

        if(strcmp(etemporal[i].estado, "activo") != 0 && strcmp(etemporal[i].estado, "inactivo") != 0){
            cout<<"Opcion invalida"<<endl;
            break;
        }
    }
    
}

int comparar_codigos(Estudiantes etemporal[], int tamtemporal){
    for(int i = 0; i < tamtemporal; i++){
        
        for(int j = i + 1; j < tamtemporal; j++){
            if(strcmp(etemporal[i].codigo, etemporal[j].codigo) == 0){
                cout<<"Hay dos estudiantes con el mismo codigo, reinicie el programa"<<endl;
                exit(0);
            }
        }
    }
    return 2;
}

void menu(){
    cout<<"Las opciones del menu son:"<<endl;
    cout<<"(1) Mostrar todos los estudiantes."<<endl;
    cout<<"(2) Buscar un estudiante por codigo."<<endl;
    cout<<"(3) Mostrar cuantos estudiantes estan en estado activo."<<endl;
    cout<<"(4) Mostrar la longitud del nombre de cada estudiante usando strlen."<<endl;
    cout<<"(5) Buscar estudiantes cuyo apellido contenga una subcadena (usar strstr)."<<endl;
    cout<<"(6) Salir."<<endl;
    
}

int pedir_tam_estudiantes(int tam){
    int temporal;
    cout<<"Cuantos estudiantes hay: ";
    cin>>temporal;
    
    return temporal;
}

void imprimir_estudiantes(Estudiantes etemporal[], int tamtemporal){
    for(int i = 0; i < tamtemporal; i++){
        cout<<"El nombre del estudiante "<<i+1<<" es "<<etemporal[i].nombre<<endl;
        cout<<"El apellido del estudiante "<<i+1<<" es "<<etemporal[i].apellido<<endl;
        cout<<"El codigo del estudiante "<<i+1<<" es "<<etemporal[i].codigo<<endl;
            cout<<"El estado del estudiante "<<i+1<<" es "<<etemporal[i].estado<<endl;
    }
}

void añadir_2025(Estudiantes etemporal[], int tamtemporal){
    char sufijo[6]="_2025";
    
    for(int j=0; j<tamtemporal; j++){
        strcat(etemporal[j].apellido,sufijo);
        cout<<"El apellido con sufijo es "<<etemporal[j].apellido<<endl;
    }
}

void contar_activos(Estudiantes estudiantes[], int Tam_estudiantes){
    cout<<"Contar estudiantes activos actualmente"<<endl;
    
    int contador_activos=0;

    for(int y=0; y<Tam_estudiantes; y++){
        if(strcmp(estudiantes[y].estado, "activo")==0){
            contador_activos++;
            
        }
    }

    cout<<"Actualmente hay: "<<contador_activos<<endl;
}

void longitud_nombres(Estudiantes estudiantes[], int Tam_estudiantes){
    cout<<"Medir la longitud de cada nombre"<<endl;
    int temporallenght=0;

    for(int w=0; w<Tam_estudiantes;w++){
        temporallenght=strlen(estudiantes[w].nombre);
        cout<<"La longitud del nombre numero "<<w+1<<" es "<<temporallenght<<endl;
        
    }
}

void buscar_subcadena(Estudiantes estudiantes[], int Tam_estudiantes){
    cin.ignore();
    char subcadena[10];

    cout<<"Por favor ingresar la subcadena para buscar coincidencias con apellidos"<<endl;
    cin.getline(subcadena,10);

    for(int u=0; u<Tam_estudiantes; u++){
        char *p=strstr(estudiantes[u].apellido,subcadena);
        if(p!=NULL){
            cout<<"Se ha encontrado una coincidencia"<<endl;
            cout<<"El estudiante con apellido "<<estudiantes[u].apellido<<" concuerda con "<<subcadena<<endl;
        }
    }
    
}

int main()
{
    int Tam_estudiantes=pedir_tam_estudiantes(Tam_estudiantes);
    if(Tam_estudiantes > 50){
        cout<<"Solo se permiten maximo 50 estudiantes"<<endl;
        return 0;
    }
    Estudiantes estudiantes[50];

    cout<<"Se han registrado "<<Tam_estudiantes<<"estudiantes"<<endl;
    cout<<"Ahora vamos a llenar cada estudiante."<<endl;

    guardar_estudiantes(estudiantes,Tam_estudiantes);
    añadir_2025(estudiantes,    Tam_estudiantes);

    int control=comparar_codigos(estudiantes, Tam_estudiantes);


    int option=0;
    while(option!=6){

        menu();
        cout<<"Ingresa la opcion que deseas "<<endl;
        cin>>option;

        switch(option){
            
            case 1:{
                cout<<"Vamos a imprimir todos los estudiantes "<<endl;
                    imprimir_estudiantes(estudiantes, Tam_estudiantes);
                break;
            }

            case 2:{
                cin.ignore();
                cout<<"Por favor ingresa el codigo para buscar al estudiante"<<endl;
                char enter_code[15];
                
                cin.getline(enter_code,15);

                int supervisor=54;
                
                for(int x=0; x<Tam_estudiantes;x++){
                    supervisor=strcmp(estudiantes[x].codigo,enter_code);
                    if(supervisor==0){
                        cout<<"El estudiante con ese codigo es "<<estudiantes[x].nombre<<endl;
                    }
                } 
                
                
                break;
            }

            case 3:{
                contar_activos(estudiantes, Tam_estudiantes);
                break;
            }

            case 4:{
                longitud_nombres(estudiantes, Tam_estudiantes);
                break;
                }

            case 5:{
                buscar_subcadena(estudiantes, Tam_estudiantes);
                break;
                
            }

            default:{
                cout<<"Opcion invalida"<<endl;
            }
        }
    }

    return 0;
}