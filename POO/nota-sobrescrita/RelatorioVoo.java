public class RelatorioVoo {

/*3. Escreva uma classe que gere relatório sobre voos, considerando as classes mencionadas na questão 1. No relatório, que
deve ser impresso no console, devem constar os seguintes dados: distância, velocidade média, tempo de voo e, se o
voo for do tipo charter, a quantidade de passageiros. Para imprimir o tempo de voo, deve-se receber como parâmetro
adicional no método de imprimir dados do voo o valor do fator aeroportuário e considerar velocidade de arrasto do
vento zero. */

    public void imprimirDadosDoVoo(Voo voo, double fatorAeroportuario){
        System.out.println("Distancia: " + voo.getDistancia());
        System.out.println("Velocidade media: " + voo.getVelocidade_media());
        System.out.println("Tempo de voo: " + voo.calcularTempoTotalDeVoo(fatorAeroportuario));
        if(voo instanceof VooCharter){
            System.out.println("Quantidade de passageiros: " + ((VooCharter) voo).getQuantidadeDePassageiros());
        }
    }
}
