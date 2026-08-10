package puj.edu.co.Modelo;

import  puj.edu.co.Excepciones.DatoInvalidoException;

public class Perro extends Mascota {
    private String raza;
    private boolean tieneEntrenamiento;

    public Perro(String codigo, String nombre, int edad, String cedulaDueno, String raza, boolean tieneEntrenamiento) throws DatoInvalidoException {
        super(codigo, nombre, edad, cedulaDueno);
        System.out.println(" Asignando atributos especificos de Perro");
        setRaza(raza);
        this.tieneEntrenamiento = tieneEntrenamiento;
    }

    public String getRaza() {
        return raza;
    }

    public void setRaza(String raza) throws DatoInvalidoException {
        if (raza == null || raza.trim().isEmpty()) {
            throw new DatoInvalidoException("La raza no puede estar vacia."); //
        }
        this.raza = raza;
    }

    public boolean isTieneEntrenamiento() {
        return tieneEntrenamiento;
    }

    public void setTieneEntrenamiento(boolean tieneEntrenamiento) {

        this.tieneEntrenamiento = tieneEntrenamiento;
    }

    @Override
    public void mostrarTipo()
    {
        System.out.println("Perro de raza " + raza);
    }

    @Override
    public String toString() { // [cite: 29]
        return super.toString() + "perro" +
                "raza='" + raza + '\'' +
                ", tieneEntrenamiento=" + tieneEntrenamiento +
                '}';
    }
}