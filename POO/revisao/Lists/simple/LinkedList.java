package Lists.simple;

public class LinkedList<Integer> {
Node <Integer> head;

LinkedList(Integer headData){
this.head.setData(headData);
head.setNext(null);

}
LinkedList(){

}
public void insertFirst(Integer value){
Node<Integer> newNode = new Node<Integer>();
newNode.setData(value);
newNode.setNext(head);
head=newNode;
}

public void insertLast(Integer value){
Node<Integer> newNode = new Node<Integer>();
newNode.setData(value);
newNode.setNext(null);

Node<Integer> walk=head;
while(walk.getNext()!=null){
    walk=walk.getNext();
}
walk.setNext(newNode);
}
public void insertOrdered(Integer value){
    Node<Integer> newNode = new Node<>();
    newNode.setData(value);
    Node<Integer> walk=head;

    while (walk.getNext()!=null && Integer.valueOf(value) < walk.getNext().getData() ) {
        
    }
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

    Node<Integer> walk=head;
    Node<Integer> prev = null;

    while (walk.getNext()!=null) { // Caminha até o penúltimo nó
        prev = walk;
        walk=walk.getNext();
    }
    prev.setNext(null); // Remove a referência para o último nó
}
public void deleteX(Integer value){
    if(head==null) return;

    if(head.getData()==value) {
        this.deleteFirst();
        return;
    }

    Node<Integer> walk=head;

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
    Node<Integer> walk=head;
    while(walk!=null){
        System.out.print(walk);
        walk=walk.getNext();
        
    }
    System.out.println("\n");
}
}
