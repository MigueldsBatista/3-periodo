public class Node<T> {
private int data;
private int dataDown;

private Node<T> next;
private Node<T> prev;


Node(int data, Node<T> next){
this.data=data;
this.next=next;
}

public int getData() {
    return data;
}
public int getDataDown() {
    return dataDown;
}
public void setData(int data) {
    this.data = data;
}
public void setDataDown(int dataDown) {
    this.dataDown = dataDown;
}
public Node<T> getNext() {
    return next;
}


public Node<T> getPrev() {
    return prev;
}

public void setPrev(Node<T> prev) {
    this.prev = prev;
}
public void setNext(Node<T> next) {
    this.next = next;
}


}
