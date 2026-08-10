package com.puj.taller9.model;
import java.time.LocalDate;
import java.util.Date;

public class Vehiculo {

    private String placa;
    private String marca;
    private Date fechaMatricula;
    private boolean tieneRevisionTecno;
    private boolean arrendado;
    private Date fechaDevolucion;
    private Cliente clienteActual;

    public Vehiculo(String placa, String marca, Date fechaMatricula, boolean tieneRevisionTecno, boolean arrendado, Date fechaDevolucion, Cliente clienteActual) {
        this.placa = placa;
        this.marca = marca;
        this.fechaMatricula = fechaMatricula;
        this.tieneRevisionTecno = tieneRevisionTecno;
        this.arrendado = arrendado;
        this.fechaDevolucion = fechaDevolucion;
        this.clienteActual = clienteActual;
    }
    //x
    public void setPlaca(String placa) {
        this.placa = placa;
    }

    public void setFechaMatricula(Date fechaMatricula) {
        this.fechaMatricula = fechaMatricula;
    }

    public void setTieneRevisionTecno(boolean tieneRevisionTecno) {
        this.tieneRevisionTecno = tieneRevisionTecno;
    }

    public void setArrendado(boolean arrendado) {
        this.arrendado = arrendado;
    }

    public void setFechaDevolucion(Date fechaDevolucion) {
        this.fechaDevolucion = fechaDevolucion;
    }

    public void setClienteActual(Cliente clienteActual) {
        this.clienteActual = clienteActual;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public String getPlaca() {
        return placa;
    }

    public String getMarca() {
        return marca;
    }

    public Date getFechaMatricula() {
        return fechaMatricula;
    }

    public boolean isTieneRevisionTecno() {

        return tieneRevisionTecno;
    }

    public boolean isArrendado() {

        return arrendado;
    }

    public Date getFechaDevolucion() {
        return fechaDevolucion;
    }

    public Cliente getClienteActual() {
        return clienteActual;
    }
    public Boolean necesitaRevision(){
        LocalDate now = LocalDate.now();

        int anioActual = now.getYear();
        int anioMatricula = fechaMatricula.getYear() + 1900;

        int years = anioActual - anioMatricula;

        if(years > 6){
            System.out.println("El auto necesita tecnomecanica");
            return true;
        }

        System.out.println("No es necesario tecnomecanica");
        return false;
    }

    public int Es_par(int num){
        if(num%2==0){
            System.out.println("Es par");
            return 2;
        }else{
            return 1;
        }

    }
    boolean tienePicoYPlaca(LocalDate fecha){
        boolean control = false;

        int tam = placa.length();

        int UltimoDigitoPlaca = Character.getNumericValue(placa.charAt(tam-1));

        int UltimoDigitoFecha = fecha.getDayOfMonth() % 10;

        UltimoDigitoFecha = Es_par(UltimoDigitoFecha);
        UltimoDigitoPlaca = Es_par(UltimoDigitoPlaca);

        if(UltimoDigitoFecha == UltimoDigitoPlaca){
            control = true;
            System.out.println("Hay pico y placa");
        }

        return control;
    }

    @Override
    public String toString() {
        return "Vehiculo{" +
                "placa='" + placa + '\'' +
                ", marca='" + marca + '\'' +
                ", fechaMatricula=" + fechaMatricula +
                ", tieneRevisionTecno=" + tieneRevisionTecno +
                ", arrendado=" + arrendado +
                ", fechaDevolucion=" + fechaDevolucion +
                ", clienteActual=" + clienteActual +
                '}';
    }
}