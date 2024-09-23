package br.edu.cesarschool.cc.poo.meiotransporte;

import br.edu.cesarschool.cc.poo.meiotransporte.motorizado.MeioTransporteMotorizado;

public class Carro extends MeioTransporteMotorizado{


    public Carro(
        String nome,
        double cargaMaxima,
        double  velocidadeMaxima,     
        double potenciaMotor,
        double capaciadeCombustivel,
        double consumoMedio
        ){
        super(
        nome,
        cargaMaxima,//father of the father
        velocidadeMaxima,

        potenciaMotor, 
        capaciadeCombustivel, //father
        consumoMedio);
}

        public double calcularEficiencia(){
            return getCargaMaxima()/getConsumoMedio();
        }   
}
