package itemvenda;

public class TipoPagamento {

    // Enum dentro da classe para representar os tipos de pagamento
    public enum Codigo {
        DINHEIRO(1),
        CREDITO(2),
        DEBITO(3),
        CHEQUE(4),
        VALE_ALIMENTACAO_PAPEL(5),
        VALE_ALIMENTACAO_CARTAO(6),
        PIX(7);

        private final int codigo;

        // Construtor do enum para inicializar o código
        Codigo(int codigo) {
            this.codigo = codigo;
        }

        // Método getter para retornar o código
        public int getCodigo() {
            return codigo;
        }

        public static Codigo getByCodigo(int codigo) {
            for (Codigo c : Codigo.values()) {
                if (c.getCodigo() == codigo) {
                    return c;
                }
            }
            throw new IllegalArgumentException("Código de pagamento inválido: " + codigo);
        }
    }
    

    // Atributos da classe TipoPagamento
    private String descricao;
    private double tarifa;
    private boolean temPagamentoEletronico;

    // Construtor da classe TipoPagamento
    public TipoPagamento(String descricao, double tarifa, boolean temPagamentoEletronico) {
        this.descricao = descricao;
        this.tarifa = tarifa;
        this.temPagamentoEletronico = temPagamentoEletronico;
    }

    // Getters para acessar os atributos
    public String getDescricao() {
        return descricao;
    }

    public double getTarifa() {
        return tarifa;
    }

    public boolean TemPagamentoEletronico() {
        return temPagamentoEletronico;
    }
}
