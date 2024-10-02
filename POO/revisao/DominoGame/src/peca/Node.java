package peca;

public class Node<T>{
private T dataUp;
private T dataDown;

private Node<T> nextUp;  
private Node<T> nextDown;

Node(){

}
Node(T dataUp, T dataDown){
this.dataUp=dataUp;
this.dataDown=dataDown;
}



public T getDataUp() {
    return dataUp;
}


public T getDataDown() {
    return dataDown;
}

public void setDataDown(T dataDown) {
    this.dataDown = dataDown;
}

public void setDataUp(T dataUp) {
    this.dataUp = dataUp;
}
public Node<T> getNextDown() {
    return nextDown;
}

public Node<T> getNextUp() {
    return nextUp;
}


public void setNextDown(Node<T> nextDown) {
    this.nextDown = nextDown;
}

public void setNextUp(Node<T> nextUp) {
    this.nextUp = nextUp;
}
@Override
public String toString() {
    return "[" + dataUp + "|" + dataDown + "]";
}


}
