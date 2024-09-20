package informatica;

public class Modelo {
    private String descricao;
    private String marca;

    // Construtor
    public Modelo(String descricao, String marca) {
        this.descricao = descricao;
        this.marca = marca;
    }

    // Getters
    public String getDescricao() {
        return descricao;
    }

    public String getMarca() {
        return marca;
    }
}
