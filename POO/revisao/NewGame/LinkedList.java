package NewGame;

public class LinkedList {
    Node<Integer> head;
    Node<Integer> tail;
    Node<Integer> center;

    public LinkedList() {
        // Construtor vazio
    }

    // Método para iniciar a partida com uma peça de dominó
    public void iniciarPartida(DominoPiece piece) {
        int data = piece.getValue1();    // Pega o valor da peça
        int dataDown = piece.getValue2(); // Pega o valor de baixo da peça
        
        this.head = new Node<>(); // Inicializa a cabeça da lista
        this.head.setData(data);  // Seta o valor da cabeça
        this.head.setDataDown(dataDown); // Seta o valor de baixo
        this.head.setNext(null);  // Próximo da cabeça é nulo (pois é a única peça)
        this.head.setPrev(null);  // Anterior da cabeça também é nulo
        
        this.tail = this.head;    // Tail aponta para a mesma peça
        this.center = head;       // Center aponta para a mesma peça
    }

    // Método para encaixar novas peças
    void encaixar(DominoPiece piece, MetodoEncaixe metodo) {
        int data = piece.getValue1();    // Pega o valor da peça
        int dataDown = piece.getValue2(); // Pega o valor de baixo da peça
        if (metodo.equals(MetodoEncaixe.HEAD_UP)) {

            if (head.getData() != data && head.getData() != dataDown) {
                System.err.println("Encaixe falhou [" + data + "|" + dataDown + "]");
                return;
            }

            Node<Integer> newNode = new Node<>();
            newNode.setData(data);
            newNode.setDataDown(dataDown);

            newNode.setNext(null);
            newNode.setPrev(head);

            head.setPrev(newNode);
            head = newNode;

            System.out.println("Encaixe bem sucedido! " + newNode);

            return;
        } else if (metodo.equals(MetodoEncaixe.HEAD_DOWN)) {
            if (tail.getDataDown() != data && tail.getDataDown() != dataDown) {
                System.err.println("Encaixe falhou [" + data + "|" + dataDown + "]");
                return;
            }
            Node<Integer> newNode = new Node<>();
            newNode.setData(data);
            newNode.setDataDown(dataDown);
            newNode.setNext(tail);
            newNode.setPrev(null);
            tail.setPrev(newNode);
            tail = newNode;

            System.out.println("Encaixe bem sucedido! " + newNode);
            return;
        }
        System.out.println("Encaixe inválido [" + data + "|" + dataDown + "]");
    }

    public Node<Integer> getHead() {
        return head;
    }

    public Node<Integer> getTail() {
        return tail;
    }

    public void setHead(Node<Integer> head) {
        this.head = head;
    }

    public void setTail(Node<Integer> tail) {
        this.tail = tail;
    }

    void display() {
        if (head == null) return;

        Node<Integer> walk = head;
        while (walk != null) {
            System.out.print(walk.getData());
            if (walk.getNext() != null) {
                System.out.print(" -> ");
            }
            walk = walk.getNext();
        }
        System.out.println(" -> null");
    }

    void displayReverse() {
        if (head == null) return;

        Node<Integer> walk = head;
        while (walk.getNext() != null) {
            walk = walk.getNext();
        }
        while (walk != null) {
            System.out.print(walk.getData());
            if (walk.getPrev() != null) {
                System.out.print(" -> ");
            }
            walk = walk.getPrev();
        }
        System.out.print(" -> null");
    }
}
