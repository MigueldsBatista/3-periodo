package informatica;

public class UCP {
    private double clockBase;
    private double fatorTurbo;
    private Modelo modelo;

    // Construtor
    public UCP(double clockBase, double fatorTurbo, Modelo modelo) {
        this.clockBase = clockBase;
        this.fatorTurbo = fatorTurbo;
        this.modelo = modelo;
    }

    // Método para calcular o clock máximo
    public double calcularClockMaximo() {
        return clockBase * fatorTurbo;
    }

    // Getter para o modelo
    public Modelo getModelo() {
        return modelo;
    }
}
