package puj.edu.co.Persistencias;

import puj.edu.co.Modelo.Mascota;
import java.io.*;
import java.util.ArrayList;

public class GestorArchivos {
    private static final String ARCHIVO = "mascotas.dat";

    // Nombre exacto: guardar
    public static void guardar(ArrayList<Mascota> lista) {
        System.out.println("Guardando");
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(ARCHIVO))) {
            oos.writeObject(lista);
        } catch (IOException e) {
            System.out.println("Error al guardar: " + e.getMessage());
        }
    }

    // Nombre exacto: cargar
    public static ArrayList<Mascota> cargar() {
        System.out.println("Cargand");
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(ARCHIVO))) {
            return (ArrayList<Mascota>) ois.readObject();
        } catch (Exception e) {
            System.out.println("No hay datos");
            return new ArrayList<>();
        }
    }
}