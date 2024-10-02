package lista;
public class ListaEncadeada<T>{
    private Node<Integer> head;

    public Node<Integer> getHead() {
        return head;
    }

    public void setHead(Node<Integer> head) {
        this.head = head;
    }

    public void insertFirst(Integer value){
        Node<Integer> newNode = new Node<>(value, this.head);
        this.head=newNode;
    }

    public void insertLast(Integer value){
    Node<Integer> newNode = new Node<>(value);

    if(this.head==null){
        insertFirst(value);
        return;
    }
    
    Node<Integer> walk=this.head;

    while(walk.getNext()!=null){
        walk=walk.getNext();
    }
    walk.setNext(newNode);
    }


    @Override
    public String toString() {
        return "ListaEncadeada [head=" + head + "]";
    }

    public void display(){
        Node<Integer> temp=this.head;
        while (temp!=null) {
            System.out.print(temp.getData()+" -> ");
            temp=temp.getNext();
        }
    }
}