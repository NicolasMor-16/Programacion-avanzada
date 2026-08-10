package puj.edu.co.Control;

import puj.edu.co.Modelo.Mascota;
import puj.edu.co.Modelo.Perro;
import puj.edu.co.Modelo.Gato;
import puj.edu.co.Excepciones.CedulaDuplicadaException;
import puj.edu.co.Persistencias.GestorArchivos;
import java.util.*;

public class GestorMascotas {
    private ArrayList<Mascota> listaMascotas;
    private Set<String> cedulasRegistradas;
    private Scanner sc;

    public GestorMascotas() {
        this.listaMascotas = new ArrayList<>();
        this.cedulasRegistradas = new HashSet<>();
        this.sc = new Scanner(System.in);
        leerDesdeArchivo(); // Carga automática al iniciar [cite: 36]
    }

    public void agregarPerro() {
        try {
            System.out.println("Registro de Perro");
            System.out.print("Codigo: "); String cod = sc.nextLine();
            System.out.print("Nombre: "); String nom = sc.nextLine();
            System.out.print("Edad: "); int edad = Integer.parseInt(sc.nextLine());
            System.out.print("Cedula del Dueño: "); String ced = sc.nextLine();

            if (cedulasRegistradas.contains(ced)) {
                throw new CedulaDuplicadaException("Erroe La cedula " + ced + " ya tiene una mascota.");
            }

            System.out.print("Raza: "); String raza = sc.nextLine();
            System.out.print("¿Entrenado? (true/false): "); boolean ent = Boolean.parseBoolean(sc.nextLine());

            Perro p = new Perro(cod, nom, edad, ced, raza, ent);
            listaMascotas.add(p);
            cedulasRegistradas.add(ced);
            System.out.println("Perro agregado.");
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    public void agregarGato() {
        try {
            System.out.println("Registro de Gato");
            System.out.print("Codigo: "); String cod = sc.nextLine();
            System.out.print("Nombre: "); String nom = sc.nextLine();
            System.out.print("Edad: "); int edad = Integer.parseInt(sc.nextLine());
            System.out.print("Cedula del Dueño: "); String ced = sc.nextLine();

            if (cedulasRegistradas.contains(ced)) {
                throw new CedulaDuplicadaException("Error: La cedula " + ced + " ya tiene una mascota.");
            }

            System.out.print("Color: "); String col = sc.nextLine();
            System.out.print("¿Es cazador? (true/false): "); boolean caz = Boolean.parseBoolean(sc.nextLine());

            Gato g = new Gato(cod, nom, edad, ced, col, caz);
            listaMascotas.add(g);
            cedulasRegistradas.add(ced);
            System.out.println("Gato agregado.");
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    public void listarMascotas() {
        System.out.println(" Lista de Mascotas ");
        if (listaMascotas.isEmpty()) {
            System.out.println("Vacia.");
            return;
        }
        for (Mascota m : listaMascotas) {
            m.mostrarTipo();
            System.out.println(m.toString());
        }
    }
    public void buscarPorCedula() {
        System.out.print("\nCedula a buscar: ");
        String ced = sc.nextLine();
        for (Mascota m : listaMascotas) {
            if (m.getCedulaDueno().equals(ced)) {
                System.out.println("Encontrado: " + m.toString());
                return;
            }
        }
        System.out.println("No se encontro.");
    }

    public void guardarEnArchivo() { GestorArchivos.guardar(listaMascotas); }

    public void leerDesdeArchivo() {
        ArrayList<Mascota> cargados = GestorArchivos.cargar();
        if (cargados != null && !cargados.isEmpty()) {
            this.listaMascotas = cargados;
            this.cedulasRegistradas.clear();
            for (Mascota m : listaMascotas) cedulasRegistradas.add(m.getCedulaDueno());
            System.out.println("Datos cargados");
        }
    }

    public void menu() {
        String op = "";
        while (!op.equals("f")) {
            System.out.println("\n--- MENU ---");
            System.out.println("a) Agregar perro\nb) Agregar gato\nc) Listar\nd) Guardar\ne) Cargar\ng) Buscar por cedula\nf) Salir");
            System.out.print("Seleccione: ");
            op = sc.nextLine().toLowerCase();
            switch (op) {
                case "a": agregarPerro(); break;
                case "b": agregarGato(); break;
                case "c": listarMascotas(); break;
                case "d": guardarEnArchivo(); break;
                case "e": leerDesdeArchivo(); break;
                case "g": buscarPorCedula(); break;
                case "f": System.out.println("Saliendo..."); break;
                default: System.out.println("Opcion invalid.");
            }
        }
    }
}