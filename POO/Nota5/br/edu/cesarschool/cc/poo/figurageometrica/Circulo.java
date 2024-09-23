package br.edu.cesarschool.cc.poo.figurageometrica;

public class Circulo extends Elipse{

    public Circulo(
        String descricao,
        double raio
    ){
        super("OBJETO CIRCULAR", raio, raio);
    }

    public double getRaio(){/*poderia ser getRaioMenor também */
        return getRaioMaior();//como é um circulo é indiferente o raio que eu herdo
    }
    
}
