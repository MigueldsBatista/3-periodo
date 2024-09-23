package br.edu.cesarschool.cc.poo.geografia.pais;

import br.edu.cesarschool.cc.poo.geografia.ElementoGeografico;

class Microrregiao {
    String nome;
    ElementoGeografico elementoAssociado;
void imprimirDados() {
    System.out.println(nome);
    //System.out.println(elementoAssociado.area);//inacessivel (nao esta no mesmo pacote)
}
}