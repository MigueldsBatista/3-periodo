import java.math.BigDecimal;

public class Programa {

    public static void main(String[] args) {
        int baseInt=3, expoenteInt=3;

        byte expoenteByte=3;
        double expoenteDouble=3.0;
        long baseLong=3;
        double expoenteFloat=3.0;
        BigDecimal baseBig = new BigDecimal(3), expoenteBig = new BigDecimal(3);

        System.out.println(Calculadora.exponenciar(baseInt, expoenteByte));
        System.out.println(Calculadora.exponenciar(baseLong, expoenteInt));
        System.out.println(Calculadora.exponenciar(baseInt, expoenteDouble));
        System.out.println(Calculadora.exponenciar(baseBig, expoenteBig));
        System.out.println(Calculadora.exponenciar(baseBig, expoenteFloat));
    }
}