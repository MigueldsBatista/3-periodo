package figurasgeometricas;

public class Terreno {
    private double area;
    private double valorPorMetroQuadrado;
    private Endereco endereco;

    // Construtor
    public Terreno(double valorPorMetroQuadrado, Endereco endereco) {
        this.valorPorMetroQuadrado = valorPorMetroQuadrado;
        this.endereco = endereco;
    }

    // Método para calcular o valor do terreno
    public double calcularValorTerreno() {
        return area * valorPorMetroQuadrado;
    }

    // Setter para área
    public void setArea(double area) {
        this.area = area;
    }
}
