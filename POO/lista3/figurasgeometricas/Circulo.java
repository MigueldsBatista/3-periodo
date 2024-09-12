package figurasgeometricas;

public class Circulo {
    private double raio;

    // Construtor
    public Circulo(double raio) {
        this.raio = raio;
    }

    // Método para obter o diâmetro
    public double obterDiametro() {
        return 2 * raio;
    }

    // Método para calcular a área
    public double calcularArea() {
        return Math.PI * raio * raio;
    }

    // Método para calcular o perímetro
    public double calcularPerimetro() {
        return 2 * Math.PI * raio;
    }

    // Método para calcular o comprimento do arco
    public double calcularComprimentoArco(double anguloArco) {
        // O ângulo deve ser convertido para radianos
        double anguloRadiano = Math.toRadians(anguloArco);
        return anguloRadiano * raio;
    }
}
