package exercise;

import java.util.Scanner;

public class Programa {

private final Scanner ENTRADA = new Scanner(System.in);

public static void main(String[] args) {
    Programa programa = new Programa();
    
    LinkedList<Integer> list = new LinkedList<>();
ListControlEnum operation = ListControlEnum.INSERT_FIRST;
do {
    
    int escolha = programa.ENTRADA.nextInt();
    
    switch (operation) {
        case ListControlEnum.INSERT_FIRST:
            list.insertFirst(3);
            break;
        case ListControlEnum.INSERT_LAST:

        default:
            System.out.println("Escolha inválida! \n");
            break;
    }
}while(!operation.equals(ListControlEnum.END_PROGRAM));
}
}
