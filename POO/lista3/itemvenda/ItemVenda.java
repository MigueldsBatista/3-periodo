package itemvenda;

public class ItemVenda {
Produto produto;
TipoPagamento tipoPagamento;
int quantidade;
double aliquotaImposto;
boolean possuiIsencao;

ItemVenda(Produto produto, TipoPagamento tipoPagamento, int quantidade, double aliquotaImposto, boolean possuiIsencao) {
    this.produto = produto;
    this.tipoPagamento = tipoPagamento;
    this.quantidade = quantidade;
    this.aliquotaImposto = aliquotaImposto;
    this.possuiIsencao = possuiIsencao;
}

public double calcularImposto() {
    if (possuiIsencao) {
        return 0.0;
    }
    return (aliquotaImposto / 100) * produto.getPreco() * quantidade;
}

public double calcularValorTotal() {
    double imposto = calcularImposto();

    if (possuiIsencao) {
        return (produto.getPreco() * quantidade) + imposto;
    }
    return (produto.getPreco() * quantidade) + imposto;
}

public double calcularLucroItem(double custoRateado) {
    double valorTotal = calcularValorTotal();
    double imposto = calcularImposto();

    return valorTotal - imposto - custoRateado - tipoPagamento.getTarifa();

}


    /*O lucro
por item é igual ao valor total menos o imposto, menos o custoRateado,
menos a tarifa do tipo de pagamento. */


}