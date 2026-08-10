#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void llenar(int **matrizf, int filas, int columnas){
    for(int i=0; i<filas;i++){
        for(int j=0; j<columnas; j++){
            *(*(matrizf+i)+j) = -1;
        }
    }
}

void mostrar_matriz(int **matrizf, int filas, int columnas){
    for(int i=0; i<filas;i++){
        for(int j=0; j<columnas; j++){
            cout << *(*(matrizf+i)+j) << " ";
        }
        cout << endl;
    }
}
void organizar_unidades(int **matriz, int *arr, int filas, int columnas, int tam_arr){
    for(int k=0; k<tam_arr; k++){

        cout << *(arr+k) << endl;

        int ultimo = (*(arr + k)) % 10;
        cout << "El numero es " << ultimo << endl;

        int t = 0;
        while(t < columnas){

            if(*(*(matriz + ultimo) + t) == -1){
                *(*(matriz + ultimo) + t) = *(arr + k);
                break;
            }else{
                t++;
            }
        }
    }
}
void mostrar_arr(int *arr, int tam_arr){
    cout<<"Ahora vamos a mostrar como quedo el arreglo"<<endl;
    for(int i = 0; i < tam_arr; i++){
        cout << *(arr + i) << " ";
    }
    cout << endl;
}
void organizar_arr(int** matriz,int *arr, int filas, int columnas, int tam_arr){
    int pos=0;
    cout<<"El arreglo ahora esta organizado"<<endl;

    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(*(*(matriz + i) + j) != -1){
                int temp = *(*(matriz + i) + j);
                *(arr+pos)=temp;
                pos++;
            }
        }
    }

    mostrar_arr(arr, tam_arr);
}

void organizar_decenas(int** matriz,int *arr, int filas, int columnas, int tam_arr){
    for(int k=0; k<tam_arr; k++){

        cout << *(arr+k) << endl;

        int ultimo = (*(arr + k)) / 10;
        ultimo=ultimo%10;
        cout << "El numero es " << ultimo << endl;

        int t = 0;
        while(t < columnas){

            if(*(*(matriz + ultimo) + t) == -1){
                *(*(matriz + ultimo) + t) = *(arr + k);
                break;
            }else{
                t++;
            }
        }
    }
    cout<<endl;
    
}
void organizar_centenas(int** matriz,int *arr, int filas, int columnas, int tam_arr){
    for(int k=0; k<tam_arr; k++){
    cout<<"El numero :"<<k+1<<endl;
        cout << *(arr+k) << endl;

        int ultimo = (*(arr + k)) / 100;
        ultimo=ultimo%10;
        cout << "El numero es " << ultimo << endl;

        int t = 0;
        while(t < columnas){

            if(*(*(matriz + ultimo) + t) == -1){
                *(*(matriz + ultimo) + t) = *(arr + k);
                break;
            }else{
                t++;
            }
        }
    }
    cout<<endl;
    
}
int main()
{   
    
    int tam_arr = 0;
    cout<<"Introduzca el tamaño del arreglo"<<endl;
    cin>>tam_arr;
    cout<<tam_arr<<endl;
    int *arr = new int[tam_arr];
    srand(time(NULL));

    for(int i=0;i<tam_arr;i++){
    *(arr+i) = rand() % 1000; // números de 0 a 999
    }


    int columnas = tam_arr;
    int filas = 10;

    // matriz correcta
    int **matriz = new int*[filas];

    for(int i = 0; i < filas; i++){
        *(matriz+i) = new int[columnas];
    }
       mostrar_arr(arr, tam_arr);
    llenar(matriz, filas, columnas);
    cout<<"matriz vacia"<<endl;
    mostrar_matriz(matriz, filas, columnas);
    organizar_unidades(matriz, arr, filas, columnas, tam_arr);
    cout<<"Esta fue ordenada por el digito de unidades."<<endl;
    mostrar_matriz(matriz, filas, columnas);
    
    organizar_arr(matriz, arr, filas, columnas, tam_arr);
    mostrar_arr(arr, tam_arr);
    
    cout<<endl;
    llenar(matriz, filas, columnas);
    mostrar_matriz(matriz, filas, columnas);
    organizar_decenas(matriz, arr, filas, columnas, tam_arr);
       cout<<"Esta fue ordenada por el digito de decenas."<<endl;
    mostrar_matriz(matriz, filas, columnas);
    organizar_arr(matriz, arr, filas, columnas, tam_arr);
       mostrar_arr(arr, tam_arr);
    
    cout<<endl;
    llenar(matriz, filas, columnas);
    mostrar_matriz(matriz, filas, columnas);
    organizar_centenas(matriz, arr, filas, columnas, tam_arr);
    cout<<"Esta fue ordenada por el digito de centenas."<<endl;
    
    mostrar_matriz(matriz, filas, columnas);
    organizar_arr(matriz, arr, filas, columnas, tam_arr);
       mostrar_arr(arr, tam_arr);
   
    cout<<"fin"<<endl;
    for(int i=0; i<filas; i++){
    delete[] matriz[i];
    }

    delete[] matriz;
delete[] arr;
    return 0;
}