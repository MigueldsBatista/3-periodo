public class MeioTransporte {}
public class Aereo extends MeioTransporte {}
public class Terrestre extends MeioTransporte {}
public class Aviao extends Aereo {}
public class Carro extends Terrestre {}
public class Carroca extends Terrestre {}

public class ProgramaConversaoExplicita2 {
    public static void main(String[] args) {

        Aereo a1 = new Aviao();           // Válido, Aviao é um tipo de Aereo
        MeioTransporte m1 = (Aereo)a1;    // Válido, Aereo é uma subclasse de MeioTransporte
        
        MeioTransporte m2 = new Carroca(); // Válido, Carroca é uma subclasse de MeioTransporte

        // Erro 1: Casting de Aereo para Carro
        Terrestre t1 = (Carro)m1; // ERRO: m1 é do tipo Aereo, não é possível convertê-lo para Terrestre/Carro.
        
        // Explicação: Imagine que você tem um "Aereo" (como um avião) e tenta tratá-lo como um "Carro". Assim como não podemos esperar que um avião tenha rodas e motor como os de um carro, o Java impede essa conversão porque Aereo e Carro são de famílias diferentes e não podem ser trocados um pelo outro.

        // Erro 2: Casting de Aereo para Carroca
        Carroca ca1 = (Carroca)a1; // ERRO: a1 é do tipo Aviao (um Aereo), então não pode ser convertido para Carroca.
        
        // Explicação: Novamente, estamos tentando tratar um objeto "Aviao" (Aereo) como uma "Carroca" (Terrestre). É como tentar usar um barco como se fosse uma bicicleta – são coisas de naturezas completamente diferentes.

        Terrestre t2 = new Carro(); // Válido, Carro é um tipo de Terrestre
        
        Aviao av1 = new Aviao(); // Válido, av1 é do tipo Aviao
        
        // Erro 3: Casting de Carro para Carroca
        Carroca ca2 = (Carro)t2; // ERRO: t2 é do tipo Terrestre/Carro, então não pode ser convertido para Carroca.
        
        // Explicação: Aqui estamos tentando transformar um "Carro" em uma "Carroca". Imagine que o "Carro" é um veículo com motor, enquanto "Carroca" é um veículo puxado a cavalo. A estrutura deles é completamente diferente, então Java impede a conversão direta entre eles.

        // Erro 4: Casting de Carro para Carroca
        Carroca c3 = (Carroca)t2; // ERRO: t2 é do tipo Carro, então não pode ser convertido para Carroca.

        // Explicação: É a mesma situação anterior. Tentamos transformar um Carro em uma Carroca, o que é inválido.

        Aviao av2 = new Aviao(); // Válido, av2 é do tipo Aviao
        
        MeioTransporte mt2 = (Aereo)av2; // Válido, av2 é um Aviao (um tipo de Aereo)

        // Erro 5: Casting de Aereo para Terrestre
        t2 = (Terrestre)mt2; // ERRO: mt2 é do tipo Aereo, então não pode ser convertido para Terrestre.

        // Explicação: Aqui tentamos tratar um "Aereo" como se fosse um "Terrestre". É como tentar estacionar um helicóptero em uma garagem de carros – os dois são meios de transporte, mas completamente diferentes.

        // Erro 6: Casting de Aereo para Aviao
        av1 = (Aereo)mt2; // ERRO: av1 é do tipo Aviao, que não pode ser tratado diretamente como um Aereo.

        // Explicação: Mesmo sendo da mesma "família", como um carro elétrico e um carro a gasolina, não podemos tratar diretamente um Aereo como Aviao. Precisaríamos de uma conversão mais específica para fazer isso.

        // Erro 7: Casting de MeioTransporte para Carro
        t2 = (Carro)m2; // ERRO: m2 é do tipo MeioTransporte/Carroca, não pode ser convertido para Carro.

        // Explicação: Aqui tentamos tratar uma "Carroca" como se fosse um "Carro". Mesmo que ambos sejam "Terrestre", não é possível converter diretamente um tipo específico de veículo em outro.
    }
}
