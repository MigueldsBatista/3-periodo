public class Voo {
private double distancia;
private double velocidadeMedia;
private String tipo;

public double getDistancia() {
    return distancia;
}
public String getTipo() {
    return tipo;
}

public double getVelocidade_media() {
    return velocidadeMedia;
}

public void setDistancia(double distancia) {
    this.distancia = distancia;
}

public void setTipo(String tipo) {
    this.tipo = tipo;
}

public void setVelocidade_media(double velocidadeMedia) {
    this.velocidadeMedia = velocidadeMedia;
}
Voo(){}

Voo(double distancia, double velocidadeMedia, String tipo){
this.distancia = distancia;
this.velocidadeMedia = velocidadeMedia;
this.tipo = tipo;
}

Voo(double distancia, double velocidadeMedia){
this(distancia, velocidadeMedia, "COMERCIAL");
}

public double calcularTempoTotalDeVoo(double fatorAeroportuario){
    return calcularTempoTotalDeVoo(fatorAeroportuario, 0);
}
public double calcularTempoTotalDeVoo(double fatorAeroportuario, double arrasteDoVento){
    return (this.distancia / (this.velocidadeMedia + arrasteDoVento)) * (1 + fatorAeroportuario/100);
}

}