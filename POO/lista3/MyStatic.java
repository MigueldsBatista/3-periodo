public class MyStatic {

    // Atributos de forma static
    double raio;
    static int instancias = 0;

    MyStatic() {
        instancias++;
    }

    // Metodos
    void printQuantidade() {
        System.out.println(instancias);
    }
    
    //pra saber quantas instancias tivemos

    // Metodos

}
