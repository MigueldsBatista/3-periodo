

public class LinkedList<T> {
Node<T> head;
Node<T> tail;

public LinkedList(Node<T> head){
    this.head=head;
}

void insertFirst(int value){
    Node<T> newNode = new Node<>(value, head);

    //1 -> 2 -> 3
    if(head==null){
    newNode.setNext(null);
    newNode.setPrev(null);
    head=newNode;
    return;
    }

    newNode.setNext(head);
    head.setPrev(newNode);
    head=newNode;
}

void insertLast(int value){
    Node<T> newNode = new Node<>(value, head);
    newNode.setNext(null);

    if(head==null){
        insertFirst(value);
        return;

    }

    Node<T> walk;
    walk=head;

    while(walk.getNext()!=null){
        walk=walk.getNext();
    }
    newNode.setPrev(walk);
    walk.setNext(newNode);
    


}

void insertAfterX(int before, int value){
    Node<T> newNode = new Node<>(value, head);
    newNode.setData(value);
    
    Node<T> walk = head;

    while(walk.getNext() !=null && walk.getNext().getData()!=before){
        walk=walk.getNext();
    }
    if(walk.getNext()==null){
        insertLast(value);
        return;
    }
    newNode.setNext(walk.getNext());
    newNode.setPrev(walk);
    
    walk.getNext().setPrev(newNode);

    walk.setNext(newNode);

}


void display(){
    if(head==null) return;

    Node<T> walk=head;
    while(walk!=null){
        System.out.print(walk.getData());
        if(walk.getNext()!=null){
            System.out.print(" -> ");
        }
        walk=walk.getNext();

    }   System.out.println(" -> null");
}

void displayReverse(){
    if(head==null) return;
    
    Node<T> walk=head;
    while(walk.getNext()!=null){
        walk=walk.getNext();
    }
    while (walk!=null) {
        System.out.print(walk.getData());
        if(walk.getPrev()!=null){
            System.out.print(" -> ");
        }
        walk=walk.getPrev();
    }   System.out.print(" -> null");
}

}
