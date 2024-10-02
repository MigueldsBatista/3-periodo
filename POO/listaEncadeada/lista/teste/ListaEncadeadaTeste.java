package lista.teste;

import lista.ListaEncadeada;

public class ListaEncadeadaTeste {

    public static void main(String[] args) {
        ListaEncadeada<Integer> lista= new ListaEncadeada<>();

        lista.insertLast(1);
        lista.insertLast(2);
        lista.insertLast(3);

        lista.display();
    }
}
