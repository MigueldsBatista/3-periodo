import java.math.BigDecimal;

public class Calculadora {

    public static  double exponenciar(int base, byte expoente){
        return exponenciar(BigDecimal.valueOf(base), BigDecimal.valueOf(expoente));
    }

    public static  double exponenciar(long base, int expoente){
        return exponenciar(BigDecimal.valueOf(base), BigDecimal.valueOf(expoente));
    }

    public static double exponenciar(int base, double expoente){
        return exponenciar(BigDecimal.valueOf(base), BigDecimal.valueOf(expoente));
    }

    public static double exponenciar(BigDecimal base, double expoente){
        return exponenciar(base, BigDecimal.valueOf(expoente));
    }

    public static  double exponenciar(BigDecimal base, BigDecimal expoente){
        return base.pow(expoente.intValue()).doubleValue();
    }
}
