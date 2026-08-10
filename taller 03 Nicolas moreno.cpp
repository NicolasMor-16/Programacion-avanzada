#include <iostream>
#include <ctime>
using namespace std;
void imprimir(int ntemp[], int tamtemp){
    cout<<"Ahora vamos a imprimir el arreglo num "<<endl;
    cout<<endl;
    for(int i=0; i<10; i++){
        cout<<"El numero "<<i+1<<" es: "<<ntemp[i]<<endl;
    }
    
}
void imprimir_direcciones_numeros(int ntem[], int tamtemp){
    cout<<endl;
    cout<<"vamos a imprimir las direcciones del arreglo num "<<endl;
    cout<<endl;
    for(int i=0; i<10;i++){
        
        cout<<"direcciones de areglo num"<<&ntem[i]<<endl;
    }
    
}
void crea_arreglo_ptr(int *apuntardortemp[],int tamtemp, int numtemp[], int tam_numt){
    cout<<endl;
    cout<<"vamos a crear el arreglo apuntadores con las direcciones de arreglo num "<<endl;
    
    for(int i=0; i<10;i++){
      apuntardortemp[i]=&numtemp[i];
      cout<<"Se a llenado la casilla: "<<i+1<<" del arreglo ptr con "<<apuntardortemp[i]<<endl;
  }
}
void imprimir_direcciones_numeros_ptr(int*apuntardortemp[], int tamtemp, int ntem[], int tam_numt){
    cout<<"vamos a imprimir las direcciones del arreglo num y ptr donde ambas coinciden"<<endl;
    cout<<endl;
    for(int i=0; i<10;i++){
        
        cout<<"direcciones de arreglo num "<<&ntem[i]<<endl;
        cout<<"direcciones de arreglo ptr "<<apuntardortemp[i]<<endl;
    }
}
void imprimir_contenido_numeros_ptr(int*apuntardortemp[], int tamtemp, int ntem[], int tam_numt){
    cout<<"imprimir el contenido de los arreglos num y ptr"<<endl;
    cout<<endl;
    for(int i=0; i<10;i++){
        
        cout<<"contenido de areglo num:  "<<ntem[i]<<endl;
        cout<<"contenido de arreglo ptr:"<<*apuntardortemp[i]<<endl;
    }
}
void organizar_ptr(int*apuntardortemp[], int tamtemp, int ntem[], int tam_numt){
    cout<<"Vamos a organizar ahora el arreglo ptr"<<endl;
    cout<<endl;
    int *guardado_temp;
    for(int i=0; i<10;i++){
        for(int j=i+1;j<10;j++){
            if(*apuntardortemp[i]>*apuntardortemp[j]){
                guardado_temp=apuntardortemp[i];
                apuntardortemp[i]=apuntardortemp[j];
                apuntardortemp[j]=guardado_temp;
                
            }
        }
        
        
    }
       for(int i=0; i<10; i++){
        cout<<"contenido de arreglo ptr: "<<*apuntardortemp[i]<<endl;
        cout<<"contenido arreglo num:"<<ntem[i]<<endl;
    }
}
void imprimir_direcciones_desde_ptr(int*apuntardortemp[], int tamtemp){
    cout<<"Numeros impresos desde el arreglo ptr:"<<endl;

    for(int i=0; i<tamtemp; i++){
        cout<< *apuntardortemp[i] << endl;
    }
}
int main(){
    srand(time(NULL));

    int num[10];

for(int i=0; i<10; i++){
    num[i] = rand() % 100;  // números entre 0 y 99
}
    int *ptr[10];
    imprimir(num, 10);
  
    imprimir_direcciones_numeros(num,10);
    cout<<endl;
    crea_arreglo_ptr(ptr,10,num,10);
    cout<<endl;
    imprimir_direcciones_numeros_ptr(ptr,10,num,10);
    cout<<endl;
    imprimir_contenido_numeros_ptr(ptr,10, num,10); 
    cout<<endl;
    organizar_ptr(ptr,10, num,10);
    imprimir_direcciones_desde_ptr(ptr,10);
    
    
    return 0;
}