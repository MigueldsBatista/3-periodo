package exercise;

public class LinkedList<T> {
private Node<T> head;

public Node<T> getHead() {
    return head;
}

public void setHead(Node<T> head) {
    this.head = head;
}

public void insertFirst(T value){
    Node<T> newNode = new Node<>(value);
    newNode.setNext(this.head);
    this.head=newNode;

}

public void display() {

    Node<T> temp=this.head;
    
    while(temp!=null){
        System.out.print(temp.getData()+" -> ");
        temp=temp.getNext();

    }
}
}