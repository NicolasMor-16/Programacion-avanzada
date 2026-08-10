#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

struct Estudiante{
    char codigo[10];  
    char nombre[30];
    char carrerra[30];
    char fecha[20];
    char datos[70];
};

void menu(){
    cout<<" 1. Insertar estudiante."<<endl;
    cout<<" 2. Mostrar estudiantes recorriendo el arreglo principal."<<endl;
    cout<<" 3. Mostrar estudiantes recorriendo el indice por codigo."<<endl;
    cout<<" 4. Mostrar estudiantes recorriendo el indice por nombre."<<endl;
    cout<<" 5. Buscar estudiante por codigo."<<endl;
    cout<<" 6. Calcular el promedio de notas del estudiante."<<endl;
    cout<<" 7. Liberar toda la memoria y salir."<<endl;
}

void llenar_datos(Estudiante *temp){
   
    char copia[70]="";
    char temporal[20];

    cout<<"Formato: Materia1-Nota1|Materia2-Nota2|Materia3-Nota3"<<endl;

        for(int i=0; i<3; i++){
        cout<<"Ingresa la materia "<<i+1<<endl;
        cin.getline(temporal,20);

        strcat(copia,temporal);
        strcat(copia,"-");
        
        cout<<"Ingresa la nota "<<i+1<<endl;
        cin.getline(temporal,20);


        strcat(copia,temporal);

         if(i<2)
            strcat(copia,"|");
    }

    strcpy(temp->datos,copia);
}

void añadirEstudiante(Estudiante **&etemp , int &ttam) {
    cout<<endl;
    Estudiante** temp = new Estudiante*[ttam+1];

    for(int i=0;i<ttam; i++){
        *(temp+i) = *(etemp+i);
    }

    *(temp+ttam) = new Estudiante;

    cout<<"Llenar codigo del estudiante"<<endl;
    cin.getline((*(temp+ttam))->codigo,10);
    cout<<"Llenar nombre del estudiante"<<endl;
    cin.getline((*(temp+ttam))->nombre,30);
    cout<<"Llenar carrera del estudiante"<<endl;
    cin.getline((*(temp+ttam))->carrerra,30);
    cout<<"Llenar fecha del estudiante (DD/MM/AAAA)"<<endl;
    cin.getline((*(temp+ttam))->fecha,20);
     llenar_datos(*(temp+ttam));
    delete[] etemp;
    etemp = temp;
    
    ttam++;
}

void imprimir_fecha(Estudiante *est){

    char copia[20];
    strcpy(copia, est->fecha);

    char *token = strtok(copia,"/");

    cout<<"Dia: "<<token<<endl;
    token = strtok(NULL,"/");
    cout<<"Mes: "<<token<<endl;
    token = strtok(NULL,"/");

    cout<<"Aniio: "<<token<<endl;
    
}

void mostrar_arreglo(Estudiante **arr, int ttam){

    cout<<"Listado de estudiantes"<<endl;

    for (int i = 0; i < ttam; i++) {
      
        cout<<"Codigo: "<<(*(arr+i))->codigo<<endl;
        cout<<"Nombre: "<<(*(arr+i))->nombre<<endl;
        cout<<"Carrera: "<<(*(arr+i))->carrerra<<endl;
        imprimir_fecha(*(arr+i));


        cout<<"Datos: "<<(*(arr+i))->datos<<endl;
        cout<<endl;
    }
    
}
void imprimir_codigo(Estudiante **arr, int ttam, int *indice_codigo){
    cout<<"\nListado de estudiantes\n"<<endl;

    for (int i = 0; i < ttam; i++) {
      
        cout<<"Codigo: "<<(*(arr+*(indice_codigo+i)))->codigo<<endl;
        cout<<"Nombre: "<<(*(arr+*(indice_codigo+i)))->nombre<<endl;
        cout<<"Carrera: "<<(*(arr+*(indice_codigo+i)))->carrerra<<endl;

        imprimir_fecha(*(arr+*(indice_codigo+i)));

        cout<<"Datos: "<<(*(arr+*(indice_codigo+i)))->datos<<endl;
        cout<<endl;
    }
    
}
void organizar_codigo(Estudiante **arr, int ttam, int *indice_codigo){

    int temp=0;

    for(int i = 0; i < ttam-1; i++){
    for(int j = i+1; j < ttam; j++){

        if(strcmp((*(arr+*(indice_codigo+i)))->codigo, (*(arr+*(indice_codigo+j)))->codigo) < 0){

            temp = *(indice_codigo+i);
            *(indice_codigo+i) = *(indice_codigo+j);
            *(indice_codigo+j) = temp;
        }
    }
    }
    imprimir_codigo(arr, ttam, indice_codigo);
}
   void imprimir_nombre(Estudiante **arr, int ttam, int *indice_nombre){
    cout<<"Listado de estudiantes"<<endl;

    for (int i = 0; i < ttam; i++) {
      
        cout<<"Codigo: "<<(*(arr+*(indice_nombre+i)))->codigo<<endl;
        cout<<"Nombre: "<<(*(arr+*(indice_nombre+i)))->nombre<<endl;
        cout<<"Carrera: "<<(*(arr+*(indice_nombre+i)))->carrerra<<endl;
        imprimir_fecha(*(arr+*(indice_nombre+i)));

         cout<<"Datos: "<<(*(arr+*(indice_nombre+i)))->datos<<endl;
        cout<<"-------------------------"<<endl;
    }
} 
void organizar_nombre(Estudiante **arr, int ttam, int *indice_nombre){
    int temp=0;
    for(int i=0; i<ttam-1; i++){
     for(int j=i+1; j<ttam; j++){
        
        if(strcmp((*(arr+*(indice_nombre+i)))->nombre, (*(arr+*(indice_nombre+j)))->nombre) < 0){
            temp= *(indice_nombre+i);
            *(indice_nombre+i)=*(indice_nombre+j);
            *(indice_nombre+j)=temp;
            
        }   
    }
    
    }
    imprimir_nombre(arr, ttam, indice_nombre);
}
int buscar_codigo(Estudiante **arr, int ttam, const char *codigo_buscar){

    for(int i=0; i<ttam; i++){
        if(strcmp((*(arr+i))->codigo, codigo_buscar) == 0){
            cout<<"Estudiante encontrado"<<endl;
            
            return i;
        }
    }
    cout<<"Estudiante no encontrado"<<endl;
    return -1;
}

void promedio(Estudiante  **arr, int ttam, int pos){

    if(pos < 0 || pos >= ttam){
        cout<<"Posicion invalida"<<endl;
        return;
    }
    

    char copia[70];
    strcpy(copia, (*(arr+pos))->datos);

    float suma = 0;
    int contador = 0;
    char *bloque = strtok(copia, "|");

    while(bloque != NULL){
        char *materia = strtok(bloque, "-");
        char *nota = strtok(NULL, "-");

         if(nota != NULL){
            suma += atof(nota);
            contador++;
        }

        bloque = strtok(NULL, "|");
    }
    if(contador > 0)
        cout<<"Promedio: "<<suma/contador<<endl;
    else
        cout<<"No hay notas registradas"<<endl;
}

int main()
{
    int opcion;
    int n = 0;
    Estudiante **estudiante = new Estudiante*[0];
    int *indice_codigo;
         int *indice_nombre ;
    do{
        cout<<endl;
        menu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion){

            case 1:{
                cout<<endl;
                añadirEstudiante(estudiante, n);
                break;
}
            case 2:{
                cout<<endl;
                if(n == 0){
                    cout << "No hay estudiantes registrados.\n";
                }else{
                    mostrar_arreglo(estudiante, n);
                }
                break;
                
                
}   
        case 3:{
            cout<<endl;
             if(n == 0){
                cout<<"No hay estudiantes\n";
                break;
            }
            indice_codigo = new int[n];
             for(int i = 0; i < n; i++){
         *(indice_codigo+i) = i;
        }

            cout<<"Imprimir estudiante por codigo"<<endl;
            organizar_codigo(estudiante, n, indice_codigo);
            delete[] indice_codigo;
            break;
        }
        
        case 4:{
            cout<<endl;
            if(n == 0){
                cout<<"No hay estudiantes\n";
                break;
            }
            indice_nombre = new int[n];
             for(int i = 0; i < n; i++){
        *  (indice_nombre+i)=i;
            }
            cout<<"Imprimir estudiantes por nombre"<<endl;
            organizar_nombre(estudiante, n, indice_nombre);
            delete[] indice_nombre;
            break;
        }
        case 5:{
            cout<<endl;
            int pos=0;
            cout<<"Buscar estudiantes por nombre "<<endl; 
            char codigo_buscar[10];
            cout<<"Ingrese el codigo: ";
            cin.getline(codigo_buscar,10);
            pos = buscar_codigo(estudiante, n, codigo_buscar);
            if(pos != -1){
                cout<<"El estudiante es:"<<endl;
                cout<<(*(estudiante+pos))->nombre<<" Con el codigo:"<<(*(estudiante+pos))->codigo<<endl;
                
            }
            break;
                    }
                    
         case 6:{
             cout<<endl;
                    cout<<"Calcular el promedio de notas"<<endl;
                    int pos=0;
                cout<<"Buscar estudiantes por nombre "<<endl; 
                char codigo_buscar[10];
                cout<<"Ingrese el codigo: ";
                cin.getline(codigo_buscar,10);
                pos = buscar_codigo(estudiante, n, codigo_buscar);
                    if(pos != -1){
                        promedio(estudiante, n, pos);
                        
                            }
                        break;
                    }
            case 7:{

                for(int i=0;i<n;i++){
                    delete *(estudiante+i);
                }
 
                delete[] estudiante;

                cout << "Memoria liberada salir";
                break;

            default:
                cout << "Opcion no valida"<<endl;
        }
}
    }while(opcion != 7);

    return 0;
}