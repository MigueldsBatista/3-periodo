package lista;

public class Node<Integer> {
private Integer data;
private Node<Integer> next;



public Node(Integer data) {
    this.data = data;
    this.next = null;
}
public Node(Integer data, Node<Integer> next) {
    this.data = data;
    this.next = next;
}

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

@Override
public String toString() {
    return "Node [data=" + data + ", next=" + next + "]";
}


}
