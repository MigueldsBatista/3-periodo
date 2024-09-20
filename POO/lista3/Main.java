public class Main {

    public static void main(String[] args) {
        System.out.println("Hello, World!");
        MyStatic static1 = new MyStatic();
        static1.printQuantidade();

        MyStatic static2 = new MyStatic();
        static2.printQuantidade();

        System.out.println(MyStatic.instancias);
    }
}
