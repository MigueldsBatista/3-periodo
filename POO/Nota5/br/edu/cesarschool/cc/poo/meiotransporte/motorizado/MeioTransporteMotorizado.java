package br.edu.cesarschool.cc.poo.meiotransporte.motorizado;

import br.edu.cesarschool.cc.poo.meiotransporte.MeioTransporte;

public class MeioTransporteMotorizado extends MeioTransporte{
    private double potenciaMotor;
    private double capaciadeCombustivel;
    private double consumoMedio;
    
    public MeioTransporteMotorizado(
        String nome,
        double capaciadeMaxima,
        double velocidadeMaxima,//super

        double potenciaMotor,//child
        double capaciadeCombustivel,
        double consumoMedio
        
        ){
        super(nome, capaciadeMaxima, velocidadeMaxima);
        this.potenciaMotor=potenciaMotor;
        this.capaciadeCombustivel=capaciadeCombustivel;
        this.consumoMedio=consumoMedio;
    }

    public double getCapaciadeCombustivel() {
        return capaciadeCombustivel;
    }

    public double getConsumoMedio() {
        return consumoMedio;
    }

    public double getPotenciaMotor() {
        return potenciaMotor;
    }

    public void setCapaciadeCombustivel(double capaciadeCombustivel) {
        this.capaciadeCombustivel = capaciadeCombustivel;
    }

    public void setConsumoMedio(double consumoMedio) {
        this.consumoMedio = consumoMedio;
    }

    public void setPotenciaMotor(double potenciaMotor) {
        this.potenciaMotor = potenciaMotor;
    }

    protected double  calcularAutonomia(){
        return consumoMedio*capaciadeCombustivel;
    }
}
