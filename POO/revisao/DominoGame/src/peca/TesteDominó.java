package peca;

public class TesteDominó {

    public static void main(String[] args) {
        // Cria a lista de peças (o jogo)
        ListaPeca<Integer> jogo = new ListaPeca<>();

        // Inicia a partida com a peça [6|5]
        jogo.iniciarPartida(6, 5);
        System.out.println("Jogo iniciado com a peça: " + jogo.getHeadUp());

        // Tenta encaixar uma nova peça [5|3] na extremidade HEAD_DOWN
        boolean encaixou1 = jogo.encaixarPeca(5, 3, MetodoEncaixe.HEAD_DOWN);
        System.out.println("Peça [5|3] encaixada em HEAD_DOWN: " + encaixou1);
        System.out.println("Nova ponta HEAD_DOWN: " + jogo.getHeadDown());

        // Tenta encaixar uma nova peça [6|4] na extremidade HEAD_UP
        boolean encaixou2 = jogo.encaixarPeca(4, 6, MetodoEncaixe.HEAD_UP);
        System.out.println("Peça [6|4] encaixada em HEAD_UP: " + encaixou2);

        System.out.println("Nova ponta HEAD_UP: " + jogo.getHeadUp());

        // Tenta encaixar uma peça que não encaixa [2|1]
        boolean encaixou3 = jogo.encaixarPeca(2, 1, MetodoEncaixe.HEAD_UP);
        System.out.println("Peça [2|1] encaixada em HEAD_UP: " + encaixou3);

        boolean encaixou4= jogo.encaixarPeca(6, 3, MetodoEncaixe.HEAD_UP);
        System.out.println("Peça [6|4] encaixada em HEAD_UP: " + encaixou4);

        // Imprime o estado do jogo
        jogo.imprimirEstado();
    }
}
