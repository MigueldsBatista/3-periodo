package figurasgeometricas;

import java.util.Scanner;

public class Main2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Leitura da forma do terreno
        System.out.println("Digite o número correspondente à forma do terreno (1 - triangular, 2 - retangular ou quadrado, 3 - circular):");
        int forma = scanner.nextInt();

        // Leitura dos dados do terreno
        System.out.println("Digite o valor por metro quadrado:");
        double valorPorMetroQuadrado = scanner.nextDouble();
        scanner.nextLine();  // Consome a linha após o número
        System.out.println("Digite o CEP do endereço:");
        long cep = scanner.nextLong();
        scanner.nextLine();  // Consome a linha após o número
        System.out.println("Digite o logradouro do endereço:");
        String logradouro = scanner.nextLine();
        System.out.println("Digite o número do endereço:");
        int numero = scanner.nextInt();
        scanner.nextLine();  // Consome a linha após o número
        System.out.println("Digite o complemento do endereço:");
        String complemento = scanner.nextLine();

        Endereco endereco = new Endereco(cep, logradouro, numero, complemento);
        Terreno terreno = new Terreno(valorPorMetroQuadrado, endereco);

        switch (forma) {
            case 1: // Triangular
                // Dados específicos do triângulo
                System.out.println("Digite a base do triângulo:");
                double base = scanner.nextDouble();
                System.out.println("Digite a altura do triângulo:");
                double altura = scanner.nextDouble();

                // Calcula a área do triângulo e define no terreno
                double areaTriangulo = (base * altura) / 2;
                terreno.setArea(areaTriangulo);
                break;

            case 2: // Retangular ou quadrado
                // Dados específicos do retângulo
                System.out.println("Digite a largura do retângulo:");
                double largura = scanner.nextDouble();
                System.out.println("Digite o comprimento do retângulo:");
                double comprimento = scanner.nextDouble();

                // Calcula a área do retângulo e define no terreno
                double areaRetangulo = largura * comprimento;
                terreno.setArea(areaRetangulo);
                break;

            case 3: // Circular
                // Dados específicos do círculo
                System.out.println("Digite o raio do círculo:");
                double raio = scanner.nextDouble();
                
                // Cria o objeto Circulo e calcula a área
                Circulo circulo = new Circulo(raio);
                double areaCirculo = circulo.calcularArea();
                terreno.setArea(areaCirculo);
                break;

            default:
                System.out.println("TIPO ERRADO");
                scanner.close();
                return;
        }

        // Calcula e exibe o valor do terreno
        double valorTerreno = terreno.calcularValorTerreno();
        System.out.printf("Valor do terreno: %.2f\n", valorTerreno);

        scanner.close();
    }
}
