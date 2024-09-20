package figurasgeometricas;

public class Endereco {
    private long cep;
    private String logradouro;
    private int numero;
    private String complemento;

    // Construtor
    public Endereco(long cep, String logradouro, int numero, String complemento) {
        this.cep = cep;
        this.logradouro = logradouro;
        this.numero = numero;
        this.complemento = complemento;
    }

    // Getters
    public long getCep() {
        return cep;
    }

    public String getLogradouro() {
        return logradouro;
    }

    public int getNumero() {
        return numero;
    }

    public String getComplemento() {
        return complemento;
    }
}
