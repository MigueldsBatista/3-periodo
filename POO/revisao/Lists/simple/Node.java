package Lists.simple;

public class Node<Integer> {
private Integer data;
private Node<Integer> next;

public Integer getData() {
    return data;
}

public void setData(Integer data) {
    this.data = data;
}

public Node<Integer> getNext() {
    return next;
}

public void setNext(Node<Integer> next) {
    this.next = next;
}
Node(Integer data, Node<Integer> next){
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
