package puj.edu.co.Modelo;

import puj.edu.co.Excepciones.DatoInvalidoException;
import java.io.Serializable;

public abstract class Mascota implements Serializable {
    private String codigo;
    private String nombre;
    private int edad;
    private String cedulaDueno;

    public Mascota(String codigo, String nombre, int edad, String cedulaDueno) throws DatoInvalidoException {
        System.out.println("Creando mascota");
        setCodigo(codigo);
        setNombre(nombre);
        setEdad(edad);
        setCedulaDueno(cedulaDueno);
    }

    public abstract void mostrarTipo();


    public String getCodigo() {
        return codigo;
    }
    public void setCodigo(String codigo) throws DatoInvalidoException {
        if (codigo == null || codigo.isEmpty()) throw new DatoInvalidoException("Codigo vacio");
        this.codigo = codigo;
    }

    public String getNombre() {
        return nombre;
    }
    public void setNombre(String nombre) throws DatoInvalidoException {
        if (nombre == null || nombre.isEmpty()) throw new DatoInvalidoException("Nombre vacio");
        this.nombre = nombre;
    }

    public int getEdad() {
        return edad;
    }
    public void setEdad(int edad) throws DatoInvalidoException {
        if (edad < 0) throw new DatoInvalidoException("Edad negativa"); // Validación básica [cite: 25]
        this.edad = edad;
    }

    public String getCedulaDueno() {
        return cedulaDueno;
    }
    public void setCedulaDueno(String cedulaDueno) throws DatoInvalidoException {
        if (cedulaDueno == null || cedulaDueno.isEmpty()) throw new DatoInvalidoException("Cedula vacia");
        this.cedulaDueno = cedulaDueno;
    }

    @Override
    public String toString() {
        return "Mascota: Codigo=" + codigo + ", Nombre=" + nombre + ", Edad=" + edad + ", Dueño=" + cedulaDueno ;
    }
}