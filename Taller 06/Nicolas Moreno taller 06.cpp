#include <iostream>
#include <iomanip>
#include<fstream>
#include<cstring>
#include <cstdlib>
using namespace std;
struct Mueble{
    char tipo[20];
    float precio;
    int unidades;
    float costo;
    float costoTotal;
    float ingreso;
    float utilidad;
};

struct Estudiante{
    char nombre[30];
    int edad;
    float promedio;
};


void menu(){
        cout << "Menu" << endl;
        cout << "1. Opcion 1" << endl;
        cout << "2. Opcion 2" << endl;
        cout << "3. Opcion 3" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
      
}
int contarMuebles(){
    ifstream archivo("muebles.txt");

    if(!archivo.is_open()){
        cout<<"No se pudo abrir muebles.txt"<<endl;
        return 0;
    }

    int contador = 0;
    char linea[200];

    while(archivo.getline(linea,200)){
        if(strlen(linea) > 1)
            contador++;
    }

    archivo.close();
    return contador;
}
void leerMuebles(Mueble *mueb, int ttam){

    ifstream archivo("muebles.txt");

    if(!archivo.is_open()){
        cout<<"No se pudo abrir muebles.txt"<<endl;
        return;
    }

    int cont = 0;

    while(cont < ttam){

        archivo >> (mueb+cont)->tipo;
        archivo >> (mueb+cont)->precio;
        archivo >> (mueb+cont)->unidades;
        archivo >> (mueb+cont)->costo;

        cont++;
    }

    archivo.close();
}
void calcular(Mueble *mueb, int ttam){

    int cont = 0;

    while(cont < ttam){

        (mueb+cont)->costoTotal =
            (mueb+cont)->costo * (mueb+cont)->unidades;

        (mueb+cont)->ingreso =
            (mueb+cont)->precio * (mueb+cont)->unidades;

        (mueb+cont)->utilidad =
            (mueb+cont)->ingreso - (mueb+cont)->costoTotal;

        cont++;
    }
}
void ordenarMuebles(Mueble *mueb, int ttam){

    int i = 0;

    while(i < ttam-1){

        int j = 0;

        while(j < ttam-1-i){

            Mueble *actual = (mueb + j);
            Mueble *siguiente = (mueb + j);
            siguiente++;

            if(actual->utilidad < siguiente->utilidad){
                Mueble temp = *actual;
                *actual = *siguiente;
                *siguiente = temp;
            }

            j++;
        }

        i++;
    }
}
void crearReporte(Mueble *mueb, int ttam){

    ofstream archivo("reporte.txt");

    if(!archivo.is_open()){
        cout<<"No se pudo crear reporte.txt"<<endl;
        return;
    }

    archivo<<"Tipo        Unidades    Precio      CostoProd      Ingreso      Utilidad"<<endl;

    int cont = 0;

    while(cont < ttam){

        archivo<<left<<setw(12)<<(mueb+cont)->tipo
               <<right<<setw(10)<<(mueb+cont)->unidades
               <<setw(12)<<fixed<<setprecision(0)<<(mueb+cont)->precio
               <<setw(15)<<(mueb+cont)->costoTotal
               <<setw(12)<<(mueb+cont)->ingreso
               <<setw(12)<<(mueb+cont)->utilidad
               <<endl;

        cont++;
    }

    archivo.close();
}
int contarLineas() {
    ifstream archivo("empleados.txt");

    if(!archivo.is_open()){
        cout<<"No se pudo abrir el archivo"<<endl;
        return 0;
    }

    int contador = 0;
    char linea[200];

    while(archivo.getline(linea,200)){
        if(strlen(linea) > 1)   // 🔥 ignora líneas vacías
            contador++;
    }

    archivo.close();
    return contador;
}
void crear_archivo(float plb, int pkg){
    ofstream archivo("peso.txt");
    if(!archivo){
        cout<<"No se pudo crear el archivo"<<endl;
        return;
    }
    archivo<<"Peso kg "<<pkg<<endl;
    archivo<<"peso lb "<<fixed << setprecision(2) <<plb<<endl;
    archivo.close();
    return;
}
struct Empleados{
 char numero[5];
 char nombre [20] ;
 char apellido[20];
 char salario[10];
 char aumento[5];
};

void ordenar(Empleados *empl, int ttam){

    int i = 0;

    while(i < ttam-1){

        int j = 0;

        while(j < ttam-1-i){

            Empleados *actual = (empl + j);
            Empleados *siguiente = (empl + j);
            siguiente++;

            float s1 = atof(actual->salario);
            float s2 = atof(siguiente->salario);

            if(s1 < s2){
                Empleados temp = *actual;
                *actual = *siguiente;
                *siguiente = temp;
            }

            j++;
        }

        i++;
    }
}
void Aumento(Empleados *empl, int ttam){

    ofstream archivo("aumentos.txt");

    if(!archivo.is_open()){
        cout<<"No se pudo crear aumentos.txt"<<endl;
        return;
    }

    int cont = 0;

    while(cont < ttam){

        archivo<<right<<setw(3)<<(empl+cont)->numero<<" "
               <<left<<setw(20)<<(empl+cont)->nombre
               <<left<<setw(20)<<(empl+cont)->apellido
               <<right<<setw(15)<<fixed<<setprecision(4)
               <<atof((empl+cont)->salario)
               <<endl;

        cont++;
    }

    archivo.close();
}
void leerempl(Empleados *empl, int ttam){
    ifstream archivo("empleados.txt");

    if(!archivo.is_open()){
        cout<<"No se pudo abrir el archivo"<<endl;
        return;
    }

    int cont = 0;

    while(cont < ttam){
        archivo>>(empl+cont)->numero;
        archivo>>(empl+cont)->nombre;
        archivo>>(empl+cont)->apellido;
        archivo>>(empl+cont)->salario;
        archivo>>(empl+cont)->aumento;

        cont++;
    }
    cout<<"Fin funcion de lectura "<<endl;
    archivo.close();
}
void aplicarAumento(Empleados *empl, int ttam){

    int cont = 0;

    while(cont < ttam){

        float salario = atof((empl+cont)->salario);

        char copia[5];
        strcpy(copia, (empl+cont)->aumento);
        copia[strlen(copia)-1] = '\0';  // quitar %

        float porcentaje = atof(copia);

        float nuevo = salario + salario*(porcentaje/100.0);

        sprintf((empl+cont)->salario,"%.4f",nuevo);

        cont++;
    }
}

void guardarEstudiantes(){

    fstream archivo("estudiantes.dat", ios::binary | ios::out | ios::app);

    if(!archivo){
        cout<<"No se pudo abrir el archivo"<<endl;
        return;
    }

    int n;
    cout<<"Ingrese numero de estudiantes: ";
    cin>>n;

    Estudiante *est = new Estudiante[n];

    int cont = 0;

    while(cont < n){

        cout<<"Nombre: ";
        cin.ignore();
        cin.getline((est+cont)->nombre,30);

        cout<<"Edad: ";
        cin>>(est+cont)->edad;

        cout<<"Promedio: ";
        cin>>(est+cont)->promedio;

        archivo.write((char*)(est+cont), sizeof(Estudiante));

        cont++;
    }

    delete[] est;

    archivo.close();
}


void mostrarBuenos(){

    fstream archivo("estudiantes.dat", ios::binary | ios::in);

    if(!archivo){
        cout<<"No se pudo abrir estudiantes.dat"<<endl;
        return;
    }

    Estudiante est;

    cout<<"Estudiantes con promedio mayor a 4.0"<<endl;

    while(archivo.read((char*)&est, sizeof(Estudiante))){

        Estudiante *ptr = &est;

        if(ptr->promedio > 4.0){
            cout<<ptr->nombre<<" - "<<ptr->promedio<<endl;
        }

    }

    archivo.close();
}
int main()
{
    std::cout<<"Hello World";
    int opcion=-1;

    do {
        menu();
        cin>>opcion;
        switch(opcion) {
            case 1:{
            float conversor=2.20462;
            float pesolb=0.0;
            int pesokg=0;
                    cout<<"Por favor ingresa tu peso"<<endl;
                    cin>>pesokg;
                    pesolb=pesokg*conversor;
                    cout<<pesolb<<endl;
                    
                    cout <<fixed << setprecision(2) << pesolb <<endl;
                    
                    
                    
                    crear_archivo(pesolb, pesokg);
                    
                break;
            }
                    case 2:{
        
                cout<<"Leyendo empleados..."<<endl;
            
                int tam = contarLineas();
            
                if(tam == 0){
                    cout<<"Archivo vacio"<<endl;
                    break;
                    }
                
                    Empleados *empleados = new Empleados[tam];
                
                    leerempl(empleados, tam);
                
                    aplicarAumento(empleados, tam);   // 🔥 ahora sí se actualiza salario
                
                    ordenar(empleados, tam);
                
                    Aumento(empleados, tam);          // 🔥 ahora solo escribe
                
                    delete[] empleados;
                
                    cout<<"Archivo aumentos.txt generado correctamente"<<endl;
                
                    break;
                }

   
                
            
                
            case 3:{

                cout<<"Procesando muebles..."<<endl;
            
                int tam = contarMuebles();
            
                if(tam == 0){
                    cout<<"Archivo vacio"<<endl;
                    break;
                }
            
                Mueble *muebles = new Mueble[tam];
            
                leerMuebles(muebles, tam);
            
                calcular(muebles, tam);
            
                ordenarMuebles(muebles, tam);
            
                crearReporte(muebles, tam);
            
                delete[] muebles;
            
                cout<<"reporte.txt generado correctamente"<<endl;

                break;
            }
            case 4:{
                

                    guardarEstudiantes();
                
                    mostrarBuenos();
                
                    break;
                }
                
            
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        
        case 0:{
            cout<<"Saliendo del programa"<<endl;
            break;
        }
        }
            cout<<endl;
    }while(opcion != 0);

    
    
    

    return 0;
}