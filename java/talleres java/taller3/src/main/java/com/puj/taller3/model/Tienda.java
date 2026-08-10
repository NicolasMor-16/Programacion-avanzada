package com.puj.taller3.model;

import java.util.ArrayList;

public class Tienda {
    private String nombre;
    private ArrayList<Producto> inventario;
    private static final double IVA = 0.19;

    @Override
    public String toString() {
        return "Tienda{"+ '\n'+
                "Nombre tienda:"+ nombre+  '\n' +
                "Productos"+inventario;

    }

    public Tienda(String nombre) {
        this.nombre = nombre;
        this.inventario = new ArrayList<>();
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public void setInventario(ArrayList<Producto> inventario) {
        this.inventario = inventario;
    }

    public String getNombre() {
        return nombre;
    }

    public ArrayList<Producto> getInventario() {
        return inventario;
    }

    public void agregarProducto(Producto p) {

        inventario.add(p);
    }
    public void mostrarInventario(){
        for (Producto p : inventario) {
            p.mostrarResumen();
        }

    }
    public void mostrarProductoPorNombre(String nombreBuscado) {
        boolean encontrado = false;

        for (Producto p : inventario) {
            if (p.getNombre().equals(nombreBuscado)) {
                p.mostrarResumen(); // 👈 aquí está el cambio
                encontrado = true;
            }
        }

        if (!encontrado) {
            System.out.println("Producto no encontrado");
        }
    }
    public void aplicarDescuentoPorNombre(String nombreBuscado, double porcentaje) {
        boolean existe = false;
        for (Producto p : inventario) {
            if (p.getNombre().equals(nombreBuscado)) {
                p.aplicarDescuento(porcentaje);
                existe=true;
            }
        }
        if (!existe) {
            System.out.println("Producto no encontrado");
        }
    }
    public void aplicarDescuentoPorNombre(String nombreBuscado) {
        boolean existe = false;
        for (Producto p : inventario) {
            if (p.getNombre().equals(nombreBuscado)) {
                p.aplicarDescuento();
                existe=true;
            }
        }
        if (!existe) {
            System.out.println("Producto no encontrado");
        }
    }
    public static double calcularPrecioConIVA(double precioBase) {

        return precioBase * (1 + IVA);
    }
    public void mostrarPrecioConIVA(String nombreBuscado) {
        boolean existe = false;

        for (Producto p : inventario) {
            if (p.getNombre().equals(nombreBuscado)) {
                double precioIVA = calcularPrecioConIVA(p.getPrecio());
                System.out.println("Precio con IVA: " + precioIVA);
                existe = true;
            }
        }

        if (!existe) {
            System.out.println("Producto no encontrado");
        }
    }
}
