public class Program {
    public static void main(String[] args) {
        Node<Integer> head=null;
        LinkedList<Integer> list = new LinkedList<>(head);

        list.insertFirst(2);
        list.insertFirst(3);

        list.insertLast(5);
        list.insertLast(7);

        list.insertAfterX(5, 3);

        list.display();
        System.out.println("\nREVERTIDA\n");
        list.displayReverse();
    }
}
