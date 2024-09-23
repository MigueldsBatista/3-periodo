package br.edu.cesarschool.cc.poo.geografia;

public class ProgramaElementosGeograficos {
    public static void main(String[] args) {
    ElementoGeografico eg = new ElementoGeografico();
    eg.area = 200.11;
    eg.setNome("ELEM 1");

    //System.out.println(eg.nome); inacessivel (nao estao na mesma classe)
    }
    }