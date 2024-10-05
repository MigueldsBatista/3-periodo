package NewGame;


public class Match {
public static void main(String[] args) {
    LinkedList lista = new LinkedList();
    lista.iniciarPartida(DominoPiece.FOUR_FIVE);
    System.out.println(lista.getHead());

    lista.encaixar(DominoPiece.FIVE_SIX, MetodoEncaixe.HEAD_DOWN);

    lista.encaixar(DominoPiece.THREE_THREE, MetodoEncaixe.HEAD_UP);

    
}   

}
