package br.edu.cesarschool.cc.poo.figurageometrica;

public class Elipse extends FiguraGeometrica{
    double raioMenor;
    double raioMaior;

    public Elipse(String descricao, double raioMenor, double raioMaior){
        super(descricao);
        this.raioMenor=raioMenor;
        this.raioMaior=raioMaior;
    }

    public double calcularArea(){
        return Math.PI*raioMenor*raioMaior;
    }

    public double calcularPerimetro(){
        return Math.PI*(raioMenor+raioMaior);
    }

    public double getRaioMaior() {
        return raioMaior;
    }
    public double getRaioMenor() {
        return raioMenor;
    }
    
}
