package com.puj.taller9.app;

import com.puj.taller9.exceptions.ClienteNoAptoException;
import com.puj.taller9.exceptions.VehiculoNoDisponibleException;
import com.puj.taller9.exceptions.VehiculoNoEncontradoException;
import com.puj.taller9.model.Cliente;
import com.puj.taller9.model.EmpresaArrendadora;
import com.puj.taller9.model.Vehiculo;

import java.util.ArrayList;
import java.util.Date;

public class App {
    public static void main(String[] args) {

        ArrayList<Vehiculo> lista = new ArrayList<>();

        lista.add(new Vehiculo("RER123", "Renault", new Date(112, 11, 10), true, false, null, null));
        lista.add(new Vehiculo("TLY536", "Volkswagen", new Date(120, 4, 8), false, false, null, null));
        lista.add(new Vehiculo("FRB690", "Mazda", new Date(115, 2, 12), true, false, null, null));
        lista.add(new Vehiculo("QUU145", "Renault", new Date(100, 6, 15), true, false, null, null));
        lista.add(new Vehiculo("RLY287", "Chevrolet", new Date(122, 7, 21), false, false, null, null));
        lista.add(new Vehiculo("FBX567", "Ford", new Date(102, 8, 13), false, false, null, null));
        lista.add(new Vehiculo("IUJ786", "Volkswagen", new Date(101, 9, 26), true, false, null, null));
        lista.add(new Vehiculo("RBX546", "Renault", new Date(122, 9, 5), false, false, null, null));
        lista.add(new Vehiculo("RCV123", "Mazda", new Date(105, 5, 11), true, false, null, null));
        lista.add(new Vehiculo("OPI458", "Chevrolet", new Date(120, 1, 22), false, false, null, null));
        lista.add(new Vehiculo("UJM786", "Ford", new Date(107, 3, 18), true, false, null, null));
        lista.add(new Vehiculo("IGH989", "Volkswagen", new Date(116, 4, 19), false, false, null, null));
        lista.add(new Vehiculo("QAZ124", "Mazda", new Date(118, 10, 15), true, false, null, null));
        lista.add(new Vehiculo("QET456", "Ford", new Date(102, 10, 18), true, false, null, null));
        lista.add(new Vehiculo("QDV679", "Chevrolet", new Date(105, 11, 19), true, false, null, null));

        EmpresaArrendadora empresa = new EmpresaArrendadora(lista);

        Cliente c = new Cliente("CC","123","Juan","Perez", new Date(100,5,15));
        Cliente c2 = new Cliente("AA","456","Nicolas","Moreno", new Date(109,8,16));

        try {
            Vehiculo v = empresa.buscarPorMarca("Renault");
            empresa.arrendarVehiculo(v, c, 5);

        } catch (ClienteNoAptoException e) {
            System.out.println(e.getMessage());

        } catch (VehiculoNoDisponibleException e) {
            System.out.println(e.getMessage());

        } catch (VehiculoNoEncontradoException e) {
            System.out.println(e.getMessage());
        }

        empresa.imprimirVehiculosArrendados();
        empresa.imprimirVehiculosRequierenRevision();
        empresa.imprimirVehiculosPorPlaca("R");

        try {
            Vehiculo z = empresa.buscarPorMarca("Volkswagen");
            empresa.arrendarVehiculo(z, c2, 5);

        } catch (ClienteNoAptoException e) {
            System.out.println(e.getMessage());

        } catch (VehiculoNoDisponibleException e) {
            System.out.println(e.getMessage());

        } catch (VehiculoNoEncontradoException e) {
            System.out.println(e.getMessage());
        }

        empresa.imprimirVehiculosArrendados();
        empresa.imprimirVehiculosRequierenRevision();
        empresa.imprimirVehiculosPorPlaca("R");

        try {
            Vehiculo z = empresa.buscarPorMarca("tack");
            empresa.arrendarVehiculo(z, c2, 5);

        } catch (ClienteNoAptoException e) {
            System.out.println(e.getMessage());

        } catch (VehiculoNoDisponibleException e) {
            System.out.println(e.getMessage());

        } catch (VehiculoNoEncontradoException e) {
            System.out.println(e.getMessage());
        }

        empresa.imprimirVehiculosArrendados();
        empresa.imprimirVehiculosRequierenRevision();
        empresa.imprimirVehiculosPorPlaca("R");
    }
}