package NewGame;

public class Node<Integer> {
private Integer data;
private Integer dataDown;

private Node<Integer> next;
private Node<Integer> prev;


Node(){

}

public Integer getData() {
    return data;
}


public void setData(Integer data) {
    this.data = data;
}


public Integer getDataDown() {
    return dataDown;
}


public void setDataDown(Integer dataDown) {
    this.dataDown = dataDown;
}


public Node<Integer> getNext() {
    return next;
}


public void setNext(Node<Integer> next) {
    this.next = next;
}


public Node<Integer> getPrev() {
    return prev;
}


public void setPrev(Node<Integer> prev) {
    this.prev = prev;
}


@Override
public String toString() {
    return "Node [" + dataDown + "|" + data + "]";
}



}
