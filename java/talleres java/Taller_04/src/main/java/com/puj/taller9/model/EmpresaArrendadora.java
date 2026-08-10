package com.puj.taller9.model;

import com.puj.taller9.exceptions.ClienteNoAptoException;
import com.puj.taller9.exceptions.VehiculoNoDisponibleException;
import com.puj.taller9.exceptions.VehiculoNoEncontradoException;

import java.util.ArrayList;
import java.util.Date;
import java.time.LocalDate;

public class EmpresaArrendadora {
    private ArrayList<Vehiculo> vehiculos;

    public EmpresaArrendadora(ArrayList<Vehiculo> vehiculos) {
        this.vehiculos = vehiculos;
    }

    public Vehiculo buscarPorMarca(String marca) throws VehiculoNoEncontradoException {
        for(Vehiculo v : vehiculos){
            if(v.getMarca().equalsIgnoreCase(marca)){
                return v;
            }
        }
        throw new VehiculoNoEncontradoException("Marca no encontrado");
    }

    public void imprimirVehiculosRequierenRevision() {
        int t = 0;

        for(Vehiculo temp : vehiculos) {
            if(temp.necesitaRevision()){
                System.out.println("Mostrando vehiculo numero: " + (t+1));
                System.out.println(temp.toString());
                t++;
            }
        }
    }

    public void arrendarVehiculo(Vehiculo v, Cliente c, int dias)
            throws ClienteNoAptoException, VehiculoNoDisponibleException {

        int edad = c.CalcularEdad();

        if(edad < 18){
            throw new ClienteNoAptoException("Cliente no apto");
        }

        if(v.necesitaRevision()){
            throw new VehiculoNoDisponibleException("Vehiculo no disponible");
        }

        if(v.isArrendado()){
            throw new VehiculoNoDisponibleException("Vehiculo ya arrendado");
        }

        Date hoy = new Date();
        Date fechaDev = new Date(hoy.getYear(), hoy.getMonth(), hoy.getDate() + dias);

        LocalDate fechaLocal = LocalDate.of(
                fechaDev.getYear() + 1900,
                fechaDev.getMonth() + 1,
                fechaDev.getDate()
        );

        v.tienePicoYPlaca(fechaLocal);

        v.setArrendado(true);
        v.setClienteActual(c);
        v.setFechaDevolucion(fechaDev);

        System.out.println("Vehiculo arrendado correctamente");
    }

    public void imprimirVehiculosArrendados() {
        int t = 0;

        for(Vehiculo temp : vehiculos) {
            if(temp.isArrendado()==true){
                System.out.println("Vehiculos arrendados");
                System.out.println("Mostrando vehiculo numero: " + (t+1));
                System.out.println(temp.toString());
                t++;
            }
        }
        System.out.println("Todos los vehiculos arrendados se han imprimido");
    }

    public void imprimirVehiculosPorPlaca(String placa){
        System.out.println("Mostrando vehiculos por placa: " + placa);
        int cont=0;

        for(Vehiculo temp : vehiculos){
            String placatemp= temp.getPlaca();
            if(placatemp.contains(placa)){
                System.out.println(temp.toString());
                System.out.println("Mostrando vehiculo :" + (cont+1));
                cont++;
            }
        }
    }
}