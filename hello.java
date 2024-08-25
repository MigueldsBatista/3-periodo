public class hello {
    public static void main(String[] args) {
        try {
            if (System.getProperty("os.name").contains("Linux") || System.getProperty("os.name").contains("Unix")) {
                new ProcessBuilder("clear").inheritIO().start().waitFor();
                System.out.println(System.getProperty("os.name"));
            }

            System.out.println("Hello, World!");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
