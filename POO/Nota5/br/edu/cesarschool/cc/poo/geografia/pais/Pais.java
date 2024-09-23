package br.edu.cesarschool.cc.poo.geografia.pais;
public final class Pais {
    long populacao;
    String nome;
    private int tipoDependencia;
    static final int DEPENDENTE = 1;
    static final int INDEPENDENTE = 2;
    private static int qtdInstancias;

    Pais(long populacao, String nome, int tipoDependencia) {
    this.populacao = populacao;
    this.nome = nome;
    this.tipoDependencia = tipoDependencia;
    qtdInstancias++;
}

static int getQtdInstancias() {
    return qtdInstancias;
}
/*static*/ String getNome() {
    return nome;//nao é estatico
}
long getPopulacao() {
    return populacao;
}
static void printDados() {
//System.out.println(getQtdInstancias() + "," + getPopulacao());//nao é estatico tambem
}
void setDependenciaIndependente(int valor) {
//INDEPENDENTE = valor;//inalterancia
//DEPENDENTE = INDEPENDENTE - 1;//inalterancia
}
}