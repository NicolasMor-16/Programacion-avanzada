package puj.edu.co.Main;

import puj.edu.co.Control.GestorMascotas;

public class App {
    public static void main(String[] args) {
        System.out.println("Mascotas Javeriana ");
        GestorMascotas gestor = new GestorMascotas();
        gestor.menu();
        System.out.println(" fin del programa");
    }
}