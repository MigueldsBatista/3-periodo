package br.edu.cesarschool.cc.poo.geografia.pais;

import br.edu.cesarschool.cc.poo.geografia.ElementoGeografico;

public class Estado extends ElementoGeografico {
    private String sigla;
    private long populacao;

public Estado(String sigla, long populacao, double area) {
this.sigla = sigla;
this.populacao = populacao;

    //super.setNome(sigla);// inacessivel (nao estao na mesma classe)
    super.area = area;
}
}