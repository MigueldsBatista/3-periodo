package Lists.simple;

public class Node {
private int data;
private Node next;

public int getData() {
    return data;
}

public void setData(int data) {
    this.data = data;
}

public Node getNext() {
    return next;
}

public void setNext(Node next) {
    this.next = next;
}
Node(int data, Node next){
this.data=data;
this.next=next;
}
Node(){}

@Override
public String toString() {
    if (next == null) {
        return "[" + data + "|null] ->";
    }

    return "[" + data + "|" + next.getData() + "] ->";
}



}
