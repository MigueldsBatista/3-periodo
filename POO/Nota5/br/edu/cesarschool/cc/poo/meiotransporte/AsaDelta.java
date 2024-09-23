package br.edu.cesarschool.cc.poo.meiotransporte;

import br.edu.cesarschool.cc.poo.meiotransporte.naomotorizado.MeioTransporteNaoMotorizado;

public class AsaDelta extends MeioTransporteNaoMotorizado{

    public AsaDelta(
        String nome,
        double cargaMaxima,
        double velocidadeMaxima,
        TipoTracao tipoTracao
        ){
            super(nome, cargaMaxima, velocidadeMaxima, tipoTracao);
        }
}
