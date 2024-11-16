public class VooComercial extends Voo{ 

    //nao eh possivel mais ter a velocidade de arrasto do vento
    //b. Para VooNormal, a forma de cálculo fica igual à implementada em Voo.
    @Override
    public double calcularTempoTotalDeVoo(double fatorAeroportuario){
        return super.calcularTempoTotalDeVoo(fatorAeroportuario, 0);
    }

    VooComercial(){
        super.setTipo("COMERCIAL");
    }

    VooComercial(double distancia, double velocidade_media){
        super(distancia, velocidade_media, "COMERCIAL");
    }
}
