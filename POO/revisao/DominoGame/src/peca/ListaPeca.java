package peca;

public class ListaPeca<T>{
private Node<T> headUp;
private Node<T> headDown;
private Node<T> center;

void iniciarPartida(T dataUp, T dataDown){
Node<T> newNode = new Node<T>();

newNode.setDataDown(dataDown);
newNode.setDataUp(dataUp);

newNode.setNextDown(null);
newNode.setNextUp(null);

center=newNode;

headUp=newNode;
headDown=newNode;
//a mesma peça
}
public Node<T> getCenter() {
    return center;
}

public Node<T> getHeadDown() {
    return headDown;
}

public Node<T> getHeadUp() {
    return headUp;
}
/**
 * Encaixa uma peca em uma lista. 
 * @param newNode   a peca que se deseja encaixar
 * @param encaixe o metodo de encaixe a ser utilizado
 * @return true se a peca foi encaixada com sucesso, false caso contrario
 */

boolean encaixarPeca(T dataUp, T dataDown, MetodoEncaixe encaixe){
    Node<T> newNode = new Node<T>(dataUp, dataDown);
    if (encaixe.equals(MetodoEncaixe.HEAD_UP)) {
        if(headUp.getDataUp().equals(newNode.getDataUp()) || headUp.getDataUp().equals(newNode.getDataDown())){
            newNode.setNextUp(headUp);
            headUp=newNode;
            return true;
        }

}

    else if(encaixe.equals(MetodoEncaixe.HEAD_DOWN)){
        if(headDown.getDataDown().equals(newNode.getDataDown()) || headDown.getDataDown().equals(newNode.getDataUp())){
            newNode.setNextDown(headDown);
            headDown=newNode;
            return true;
        }
    }
    

return false;

}
public void imprimirEstado() {
    // Imprime as peças a partir do topo (headUp)
    System.out.println("Peça central +: " + center);

    System.out.println("Peças conectadas a partir do topo:");
    Node<T> walk = headUp;
    while (walk != null) {
        System.out.print(walk); // Usa o método toString() de Node para imprimir a peça
        if(walk.getNextUp()!=null){
            System.out.print(" ->");
        }        
        walk = walk.getNextUp();

    }

    // Imprime as peças a partir da base (headDown)
    System.out.println("\nPeças conectadas a partir da base:");
    walk = headDown;
    while (walk != null) {

        System.out.print(walk); // Usa o método toString() de Node para imprimir a peça
        if(walk.getNextDown()!=null){
            System.out.print(" ->");
        }
        walk = walk.getNextDown();

    }
}

}
