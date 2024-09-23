package br.edu.cesarschool.cc.poo.meiotransporte.naomotorizado;

import br.edu.cesarschool.cc.poo.meiotransporte.MeioTransporte;
import br.edu.cesarschool.cc.poo.meiotransporte.TipoTracao;

public class MeioTransporteNaoMotorizado extends MeioTransporte{
TipoTracao tipoTracao;

public MeioTransporteNaoMotorizado(String nome, double calcularAutonomia, double velocidadeMaxima, TipoTracao tipoTracao){
super(nome, calcularAutonomia,velocidadeMaxima);
this.tipoTracao=tipoTracao;
}

}

