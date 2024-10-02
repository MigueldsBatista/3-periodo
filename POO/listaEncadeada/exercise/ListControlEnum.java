package exercise;

public enum ListControlEnum {
INSERT_FIRST(1),
INSERT_LAST(2),
END_PROGRAM(3);

private final int operation;

ListControlEnum(int operation){
    this.operation=operation;
}
public int getOperation() {
    return operation;
}


}
