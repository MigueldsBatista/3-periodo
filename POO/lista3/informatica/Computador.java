package informatica;

public class Computador {
    private UCP ucp;
    private Modelo modelo;
    private int capacidadeRamEmGB;
    private int capacidadeDiscoEmGB;
    private boolean ehNotebook;

    // Construtor
    public Computador(UCP ucp, Modelo modelo, int capacidadeRamEmGB, int capacidadeDiscoEmGB, boolean ehNotebook) {
        this.ucp = ucp;
        this.modelo = modelo;
        this.capacidadeRamEmGB = capacidadeRamEmGB;
        this.capacidadeDiscoEmGB = capacidadeDiscoEmGB;
        this.ehNotebook = ehNotebook;
    }

    // Método para obter a descrição pormenorizada
    public String obterDescricaoPormenorizada() {
        String tipo = ehNotebook ? "Notebook" : "Desktop";
        return String.format("%s com processador %s %s , %d GB de RAM , %d GB de disco.",
                tipo, modelo.getMarca(), modelo.getDescricao(), capacidadeRamEmGB, capacidadeDiscoEmGB);
    }
}
