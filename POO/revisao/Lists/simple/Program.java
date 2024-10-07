package Lists.simple;

import java.util.Scanner;

public class Program {
public static void main(String[] args) {
    LinkedList list = new LinkedList();
    final Scanner ENTRADA = new Scanner(System.in);
    int op;
    int num;
    do{
        list.display();
        System.out.println("Digite uma opção");
        System.out.println("1- Inserir no início");
        System.out.println("2- Inserir no final");
        System.out.println("3- Inserir depois de X");
        System.out.println("4- Deletar no início");
        System.out.println("5- Deletar no final");
        System.out.println("6- Deletar X");
        System.out.println("7- Inserir Ordenado");

        //delete
        System.out.println("0- Sair");
        op= ENTRADA.nextInt();
        switch (op) {
            case 1:
                num=ENTRADA.nextInt();
                list.insertFirst(num);
                break;
            case 2:
                num=ENTRADA.nextInt();
                list.insertLast(num);
                break;
            case 3:
                num=ENTRADA.nextInt();
                list.insertFirst(num);
                break;
            case 4:
                
                list.deleteFirst();
                break;
            case 5:
            list.deleteLast();
                break;
            
            case 6:
            num=ENTRADA.nextInt();
            list.deleteX(num);
                break;
            case 7:
            num=ENTRADA.nextInt();
            list.insertOrdered(num);
            default:
                System.out.println("Opção inválida\n");
                break;
        }

    }while(op!=3);
    ENTRADA.close();

}
}
