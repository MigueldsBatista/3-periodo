package exercise;

public class Node<T> {
T data;
Node<T> next;

public Node(T data){
this.data=data;
this.next=null;
}
public Node(T data, Node<T> next){
    this.data=data;
    this.next=next;
}

public T getData() {
    return data;
}

public Node<T> getNext() {
    return next;
}

public void setHead(T data) {
    this.data = data;
}

public void setNext(Node<T> next) {
    this.next = next;
}

@Override
public String toString() {
    // TODO Auto-generated method stub
    return super.toString();
}
}
