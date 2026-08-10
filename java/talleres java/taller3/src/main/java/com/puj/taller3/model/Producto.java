package com.puj.taller3.model;

public class Producto {
    private String nombre;
    private double precio;
    private String categoria;
    private final String codigo;
    private static int contadorProductos = 0;

    public Producto(String nombre, double precio, String categoria) {
        this.nombre = nombre;
        this.precio = precio;
        this.categoria = categoria;
        contadorProductos++;
        this.codigo = categoria+contadorProductos;
    }

    public String getNombre() {
        return nombre;
    }

    public double getPrecio() {
        return precio;
    }

    public String getCategoria() {
        return categoria;
    }

    public String getCodigo() {
        return codigo;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public void setPrecio(double precio) {
        this.precio = precio;
    }

    public void setCategoria(String categoria) {
        this.categoria = categoria;
    }

    @Override
    public String toString() {
        return "Producto{" +
                "nombre='" + nombre + '\'' +
                ", precio=" + precio +
                ", categoria='" + categoria + '\'' +
                ", codigo='" + codigo + '\'' +
                '}';
    }

    public void aplicarDescuento(double porcentaje){
        double preciotemp=(precio/100);
        preciotemp*=(100-porcentaje);
        precio=preciotemp;
    }
    public void aplicarDescuento(){
        double porcentaje=10;
        double preciotemp=(precio/100);
        preciotemp*=(100-porcentaje);
        precio=preciotemp;
    }
    public static int getContadorProductos(){
        return contadorProductos;
    }
        public final void mostrarResumen() {
            System.out.println("Nombre: " + getNombre() +'\''+
                    " | Código: " + getCodigo() +'\''+
                    " | Precio: " + getPrecio()+'\'');
        }
}
