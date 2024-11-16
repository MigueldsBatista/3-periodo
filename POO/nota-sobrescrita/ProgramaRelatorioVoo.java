import java.util.Scanner;

public class ProgramaRelatorioVoo {

    private static final Scanner ENTRADA = new Scanner(System.in);

    public static void main(String[] args) {
        /*
        4. Escreva um programa que leia do teclado o fator aeroportuário e dados de quatro voos, um de cada tipo diferente, e que gere relatórios sobre tais voos, usando a classe geradora de relatório criada na questão anterior.
        */

        RelatorioVoo relatorioVoo = new RelatorioVoo();

        System.out.print("Digite o fator aeroportuário: ");
        double fatorAeroportuario = ENTRADA.nextDouble();

        
        System.out.print("Digite a velocidade media voo: ");
        double velocidadeMedia = ENTRADA.nextDouble();
        System.out.print("Digite o tipo do voo: ");
        String tipo = ENTRADA.next();
        System.out.print("Digite a distancia do voo: ");
        double distancia = ENTRADA.nextDouble();
        Voo voo = new Voo(distancia, velocidadeMedia, tipo);

        
        System.out.print("Digite a velocidade media voo comercial: ");
        double velocidadeMediaComercial = ENTRADA.nextInt();
        System.out.print("Digite a distancia do voo comercial: ");
        double distanciaComercial = ENTRADA.nextDouble();
        VooComercial vooComercial = new VooComercial(distanciaComercial, velocidadeMediaComercial);

        System.out.print("Digite a velocidade média do voo charter: ");
        double velocidadeMediaCharter = ENTRADA.nextDouble();
        System.out.print("Digite a distância do voo charter: ");
        double distanciaCharter = ENTRADA.nextDouble();
        System.out.print("Digite a quantidade de passageiros do voo charter: ");
        int quantidadeDePassageiros = ENTRADA.nextInt();
        VooCharter vooCharter = new VooCharter(distanciaCharter, velocidadeMediaCharter, quantidadeDePassageiros);

        System.out.print("Digite a velocidade média do voo privado: ");
        double velocidadeMediaPrivado = ENTRADA.nextDouble();
        System.out.print("Digite a distância do voo privado: ");
        double distanciaPrivado = ENTRADA.nextDouble();
        VooPrivado vooPrivado = new VooPrivado(distanciaPrivado, velocidadeMediaPrivado);

        relatorioVoo.imprimirDadosDoVoo(voo, fatorAeroportuario);
        relatorioVoo.imprimirDadosDoVoo(vooComercial, fatorAeroportuario);
        relatorioVoo.imprimirDadosDoVoo(vooCharter, fatorAeroportuario);
        relatorioVoo.imprimirDadosDoVoo(vooPrivado, fatorAeroportuario);
    }
}
