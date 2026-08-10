#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void menu(){
    cout<<"1.Crear e imprimir el vector V"<<endl;
    cout<<"2.Crear e imprimir el vector numero"<<endl;
    cout<<"3.Crear e imprimir el vector numero_ocurrencias"<<endl;
    cout<<"4.Actualizar e imprimir el vector V"<<endl;
    cout<<"5.Crear la matriz"<<endl;
    cout<<"6.Generar el reporte"<<endl;
    cout<<"7.Salir"<<endl;
}

void imprimirVector(int v[], int tam){
    for(int i=0;i<tam;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void llenarMatriz(int m[][30], int f, int c){
    for(int i=0;i<f;i++){
        for(int j=0;j<c;j++){
           m[i][j] = 1 + rand() % 10;
        }
    }
}
void minimoPorColumna(int matriz[][30], int x, int y){
    cout<<"número fila columna"<<endl;
    
    for(int j=0;j<y;j++){
        int min = matriz[0][j];
        int fila = 0;
        for(int i=0;i<x;i++){
            if(matriz[i][j] <= min){
            min = matriz[i][j];
            fila = i;
            }
    }
        cout<<min<<" "<<(fila+1)<<" "<<(j+1)<<endl;
    }
}

int main(){
    srand(time(0));
    int v[20];
    int max = 20;
        for(int i=0;i<max;i++){
        v[i] = 1 + rand() % 10;
        }
    int numero[20];
    int numero_ocurrencias[20];
    int tamNumero = 0;
    bool numero_creado = false;
    int matriz5[100][30];
    int f5 = 0, c5 = 0;
    bool matriz5_creada = false;
    int opcion = 0;
    while(opcion != 7){
        menu();
        cin>>opcion;
        switch(opcion){
            case 1:{
                imprimirVector(v, max);
                
                break;
            }

            case 2:{
                tamNumero = 0;
                for(int i=0;i<max;i++){
                    bool rep = false;
                    for(int j=0;j<tamNumero;j++){
                        if(v[i] == numero[j]){
                        rep = true;
                    }
                    }
                    if(!rep){
                    numero[tamNumero] = v[i];
                        tamNumero++;
                    }
                }
                numero_creado = true;
                imprimirVector(numero, tamNumero);
                break;
                
            }
            case 3:{
            if(!numero_creado){
                tamNumero = 0;
                        for(int i=0;i<max;i++){
                            bool rep = false;
                            for(int j=0;j<tamNumero;j++){
                                if(v[i] == numero[j]){
                                    rep = true;
                        }
                    }
                        if(!rep){
                            numero[tamNumero] = v[i];
                            tamNumero++;
                    }
                    }
                numero_creado = true;
        }

                for(int i=0;i<tamNumero;i++){
                int cont = 0;
                    for(int j=0;j<max;j++){
                        if(numero[i] == v[j]){
                            cont++;
                            
                        }
                    }
                    numero_ocurrencias[i] = cont;
                    
                }
                for(int i=0;i<tamNumero;i++){
                    cout<<numero[i]<<" -> "<<numero_ocurrencias[i]<<endl;
                }
                break;
            }
            case 4:{
                int nuevoV[20];
                int nuevoTam = 0;
                for(int i=0;i<max;i++){
                        bool rep = false;
                    for(int j=0;j<nuevoTam;j++){
                        if(v[i] == nuevoV[j]){
                            rep = true;
                        }
                    }
                        if(!rep){

                        nuevoV[nuevoTam] = v[i];
                        nuevoTam++;
                        
                    }
                }
            max = nuevoTam;
                for(int i=0;i<max;i++){
                    v[i] = nuevoV[i];
                }
                imprimirVector(v, max);
                break;
            }

            case 5:{
                cout<<"Filas:"<<endl;
                cin>>f5;
            cout<<"Columnas:"<<endl;
            cin>>c5;
                if(f5>100 || c5>30){
                    cout<<"Invalido"<<endl;
                    break;
                }

                llenarMatriz(matriz5, f5, c5);
                matriz5_creada = true;

                for(int i=0;i<f5;i++){
                    for(int j=0;j<c5;j++){
                        cout<<" "<<matriz5[i][j];
                    }
                    cout<<endl;
                }
                break;
            }

            case 6:{
                int x,y;
                cout<<"Filas:"<<endl;
                cin>>x;
                cout<<"Columnas:"<<endl;
                cin>>y;

                if(x>100 || y>30){
                    cout<<"Invalido"<<endl;
                    break;
                }

            int matriz[100][30];
            llenarMatriz(matriz, x, y);

                for(int i=0;i<x;i++){
                    for(int j=0;j<y;j++){
                        cout<<" "<<matriz[i][j];
                    }
                    cout<<endl;
                }

                minimoPorColumna(matriz, x, y);

            if(matriz5_creada){
                cout<<"Reporte matriz opcion 5"<<endl;
                minimoPorColumna(matriz5, f5, c5);
            }
            break;
            }
        }
    }

    return 0;
}