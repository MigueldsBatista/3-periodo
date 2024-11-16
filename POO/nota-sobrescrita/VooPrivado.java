public class VooPrivado extends Voo{
private double velocidadeMinima;

//d. Para VooPrivado, o tempo de voo é igual à distância dividida pela velocidade mínima dividida pelo fator
//aeroportuário, sendo a velocidade mínima um novo atributo da classe VooPrivado.

VooPrivado(){
    super.setTipo("PRIVADO");
}

VooPrivado(double distancia, double velocidadeMinima){
    super(distancia, 0, "PRIVADO");
    this.velocidadeMinima = velocidadeMinima;
}


public double getVelocidadeMinima() {
    return velocidadeMinima;
}
public void setVelocidadeMinima(double velocidadeMinima) {
    this.velocidadeMinima = velocidadeMinima;
}

@Override
public double calcularTempoTotalDeVoo(double fatorAeroportuario){
    return (this.getDistancia() / this.getVelocidadeMinima()) * (1 + fatorAeroportuario/100);
}
}