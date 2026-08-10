package puj.edu.co.Modelo;

import puj.edu.co.Excepciones.DatoInvalidoException;

public class Gato extends Mascota {
    private String color;
    private boolean esCazador; //

    public Gato(String codigo, String nombre, int edad, String cedulaDueno, String color, boolean esCazador) throws DatoInvalidoException {
        super(codigo, nombre, edad, cedulaDueno);
        setColor(color);
        this.esCazador = esCazador;
    }

    public void setColor(String color) throws DatoInvalidoException {
        if (color == null || color.trim().isEmpty()) throw new DatoInvalidoException("sin color.");
        this.color = color;
    }

    @Override
    public void mostrarTipo() { System.out.println("gato de color " + color); }

    @Override
    public String toString() {
        return super.toString() + " gato Color=" + color + ", cazador=" + esCazador ;
    }
}