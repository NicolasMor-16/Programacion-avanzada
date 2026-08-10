package puj.edu.co;

import java.util.Scanner;

public class main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        Integer opcion;
        Float a;
        Float b;
        Float resultado;
        do {

            System.out.println("\n1. Suma");
            System.out.println("2. Restaurante");
            System.out.println("3. Multiplicación");
            System.out.println("4. División");
            System.out.println("5. Potencia");
            System.out.println("6. Raíz cuadrada");
            System.out.println("7. Salir");
            System.out.println("Ingrese opcion");
            opcion = sc.nextInt();
            switch (opcion) {
                case 1:
                    System.out.println("Elegiste suma");
                    System.out.print("Ingrese el primer numero: ");
                    a = sc.nextFloat();
                    System.out.print("Ingrese el segundo numero: ");
                    b = sc.nextFloat();
                    resultado=sumar(a,b);
                    System.out.println("Resultado:"+resultado);
                    break;
                case 2:
                    System.out.println("Elegiste resta");
                    System.out.print("Ingrese el primer numero: ");
                    a = sc.nextFloat();
                    System.out.print("Ingrese el segundo numero: ");
                    b = sc.nextFloat();
                    resultado=restar(a,b);
                    System.out.println("Resultado:"+resultado);
                    break;
                case 3:
                    System.out.println("Elegiste multiplicación");
                    System.out.print("Ingrese el primer numero: ");
                    a = sc.nextFloat();
                    System.out.print("Ingrese el segundo numero: ");
                    b = sc.nextFloat();
                    resultado = multiplicar(a, b);

                    System.out.println("Resultado: " + resultado);
                    break;
                case 4:
                    System.out.println("Elegiste división");
                    System.out.print("Ingrese el primer numero: ");
                    a = sc.nextFloat();
                    System.out.print("Ingrese el segundo numero: ");
                    b = sc.nextFloat();
                    resultado=dividir(a,b);
                    System.out.println("Resultado:"+resultado);
                    break;
                case 5:
                    System.out.println("Elegiste potencia");
                    System.out.print("Ingrese el primer numero: ");
                    a = sc.nextFloat();
                    System.out.print("Ingrese el segundo numero: ");
                    b = sc.nextFloat();

                    resultado =  potencia(a, b);
                    System.out.println("Resultado:"+resultado);
                    break;
                case 6:
                    System.out.println("Elegiste raíz");
                    System.out.print("Ingrese la base: ");
                    a = sc.nextFloat();
                    resultado=raiz(a);
                    if(resultado==null){
                        System.out.println("No es posible por que el numero es negativo");
                        break;
                    }
                    System.out.println("Resultado:"+resultado);
                    break;
                case 7:
                    System.out.println("Saliendo...");
                    break;
                default:
                    System.out.println("Opción inválida");
            }

        } while(opcion !=7);

        sc.close();
    }

    public static Float restar(Float a, Float b){

        return a-b;
    }

    public static Float multiplicar(Float a, Float b) {
        return a * b;
    }
    public static Float dividir(Float a, Float b){
        Float temp =a/b;
        return temp;
    }
    public static Float sumar(Float a, Float b){
        Float temp=a+b;
        return temp;
    }
    public static Float potencia(Float a, Float b){
        Float temp = (float) Math.pow(a, b);
        return temp;
    }
    public static Float raiz(Float a){
        if (a < 0) {
            System.out.println("Error: no se puede raíz de número negativo");
            return null;
        }
        Float temp=(float)Math.sqrt(a);
        return temp;
    }
}
