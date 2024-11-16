public class VooCharter extends Voo{
    private int quantidadeDePassageiros;

    public int getQuantidadeDePassageiros() {
        return quantidadeDePassageiros;
    }

    public void setQuantidadeDePassageiros(int quantidadeDePassageiros) {
        this.quantidadeDePassageiros = quantidadeDePassageiros;
    }

    VooCharter(){
        super.setTipo("CHARTER");
    }

    VooCharter(double distancia, double velocidade_media, int quantidadeDePassageiros){
        super(distancia, velocidade_media, "CHARTER");
        this.quantidadeDePassageiros = quantidadeDePassageiros;
    }
    @Override
    public double calcularTempoTotalDeVoo(double fatorAeroportuario){
        if(quantidadeDePassageiros >= 50){
            return super.calcularTempoTotalDeVoo(fatorAeroportuario);
        }else{
            return super.calcularTempoTotalDeVoo(3);
        }
    }
    //c. Para VooCharter, a forma de cálculo fica igual à implementada em Voo se um novo atributo de VooCharter,
    //quantidade de passageiros, for maior ou igual a 50. Se ele for menor do que 50, considerar no cálculo feito em
    //Voo um valor fixo de fator aeroportuário igual a 3.
}
