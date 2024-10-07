package Lists.simple;

public class LinkedList{
Node head;

LinkedList(int headData){
this.head.setData(headData);
head.setNext(null);

}
LinkedList(){

}
public void insertFirst(int value){
Node newNode = new Node();
newNode.setData(value);
newNode.setNext(head);
head=newNode;
}

public void insertLast(int value){
Node newNode = new Node();
newNode.setData(value);
newNode.setNext(null);

Node walk=head;
while(walk.getNext()!=null){
    walk=walk.getNext();
}
walk.setNext(newNode);
}

public void insertOrdered(int value){
    if(head==null){
        insertFirst(value);
        return;
    }
    Node newNode = new Node();
    newNode.setData(value);

    if(head.getData() > value){
        insertFirst(value);
        return;
    }
    Node walk=head;
    
    while (walk.getNext()!=null && value > walk.getNext().getData() ) {
        walk=walk.getNext();
    }
    if(walk.getNext()==null){
        insertLast(value);
        return;
    }

    newNode.setNext(walk.getNext());
    walk.setNext(newNode);
    // [3] -> [5] -> [7]
}

public void deleteFirst(){
    if(head==null) return;

    head=head.getNext();
}

public void deleteLast(){
    if(head==null) return; // Se a lista estiver vazia, não faz nada

    if(head.getNext() == null) { // Se a lista tem apenas um elemento
        head = null; // Remove o único elemento
        return;
    }

    Node walk=head;
    Node prev = null;

    while (walk.getNext()!=null) { // Caminha até o penúltimo nó
        prev = walk;
        walk=walk.getNext();
    }
    prev.setNext(null); // Remove a referência para o último nó
}
public void deleteX(int value){
    if(head==null) return;

    if(head.getData()==value) {
        this.deleteFirst();
        return;
    }

    Node walk=head;

    while(walk.getNext()!=null && walk.getNext().getData()!=value){
        walk=walk.getNext();
        //3 -> 4 -> 5 -> 6
    }

    if(walk.getNext()==null){
        this.deleteLast();
        return;
    }
    
    walk.setNext(walk.getNext().getNext());

    
}
public void display(){
    if(head==null) return;
    Node walk=head;
    while(walk!=null){
        System.out.print(walk);
        walk=walk.getNext();
        
    }
    System.out.println("\n");
}
}
