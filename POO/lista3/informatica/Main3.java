package informatica;

import java.util.Scanner;

public class Main3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Leitura dos dados da UCP
        System.out.println("Digite o clock base da UCP:");
        double clockBase = scanner.nextDouble();
        System.out.println("Digite o fator turbo da UCP:");
        double fatorTurbo = scanner.nextDouble();
        scanner.nextLine();  // Consome a linha após o número
        System.out.println("Digite a descrição do modelo da UCP:");
        String descricaoModeloUCP = scanner.nextLine();
        System.out.println("Digite a marca do modelo da UCP:");
        String marcaModeloUCP = scanner.nextLine();

        Modelo modeloUCP = new Modelo(descricaoModeloUCP, marcaModeloUCP);
        UCP ucp = new UCP(clockBase, fatorTurbo, modeloUCP);

        // Leitura dos dados do computador
        System.out.println("Digite a descrição do modelo do computador:");
        String descricaoModeloComputador = scanner.nextLine();
        System.out.println("Digite a marca do modelo do computador:");
        String marcaModeloComputador = scanner.nextLine();
        System.out.println("Digite a capacidade de RAM (em GB):");
        int capacidadeRamEmGB = scanner.nextInt();
        System.out.println("Digite a capacidade de disco (em GB):");
        int capacidadeDiscoEmGB = scanner.nextInt();
        System.out.println("O computador é um notebook? (true/false):");
        boolean ehNotebook = scanner.nextBoolean();

        Modelo modeloComputador = new Modelo(descricaoModeloComputador, marcaModeloComputador);
        Computador computador = new Computador(ucp, modeloComputador, capacidadeRamEmGB, capacidadeDiscoEmGB, ehNotebook);

        // Exibe o clock máximo da UCP e a descrição pormenorizada do computador
        System.out.printf("Clock máximo da UCP: %.2f GHz\n", ucp.calcularClockMaximo());
        System.out.println(computador.obterDescricaoPormenorizada());

        scanner.close();
    }
}
