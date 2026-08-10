package com.puj.taller3.app;

import com.puj.taller3.model.Producto;
import com.puj.taller3.model.Tienda;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args )
    {
        Scanner sc= new Scanner(System.in);
        String nombreTienda;
        System.out.println("Ingrese el nombre de la tienda");
        nombreTienda=sc.nextLine();
        Tienda tienda=new Tienda(nombreTienda);
        System.out.println(tienda.toString());
        ArrayList<Producto> productos=new ArrayList<>();
        System.out.println("Cuantos productos ingresara? recomendados 3 ");

        int cuantos_productos= sc.nextInt();
        sc.nextLine();
        for(int i=0; i<cuantos_productos;i++){

            System.out.println("Ingrese el nombre del producto:"+(i+1));
            String nombre=sc.nextLine();
            System.out.println("Ingrese el precio del producto:"+(i+1));
            double precio=sc.nextDouble();
            sc.nextLine();
            System.out.println("Ingrese la categoria del producto:"+(i+1));
            String categoria=sc.nextLine();
            Producto p = new Producto(nombre, precio, categoria);
            productos.add(p);
        }
        System.out.println(productos.toString());
        System.out.println(Producto.getContadorProductos());
        System.out.println( "Hello World!" );


        for (Producto temp : productos) {


            tienda.agregarProducto(temp);
        }

        System.out.println("Mostrando inventario");
        tienda.mostrarInventario();
        System.out.println("Total de productos : "+Producto.getContadorProductos());
        System.out.println("Ingresa e nombre del producto del que desea hacer descuento automatico" );
        String nombreDescuento =sc.nextLine();
        tienda.aplicarDescuentoPorNombre(nombreDescuento);

        System.out.println("Descuento del 10%aplicado a "+nombreDescuento);
        tienda.mostrarProductoPorNombre(nombreDescuento);
        System.out.println("iNgrese el nombre del producto del cual desea hacer descuento espeficio");
        nombreDescuento=sc.nextLine();
        System.out.println("Ingrese el porcentaje que desea ingresar ej:20%");

        Double Descuento=sc.nextDouble();
        sc.nextLine();
        tienda.aplicarDescuentoPorNombre(nombreDescuento, Descuento);
        System.out.println("Aplicadno descuento a "+nombreDescuento+" Con un orcentaje del "+Descuento+"%");
        tienda.mostrarProductoPorNombre(nombreDescuento);
        System.out.println("Ahora ingrese el nombre del producto que quiere saber su precio con Iva");
        nombreDescuento=sc.nextLine();
        tienda.mostrarPrecioConIVA(nombreDescuento);


    }
}
