package itemvenda;

import java.util.Scanner;


public class Main1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Leitura dos dados do produto
        System.out.println("Digite o código do produto:");
        double codigoProduto = scanner.nextLong();
        scanner.nextLine();  // Consome a linha após o número
        System.out.println("Digite o nome do produto:");
        String nomeProduto = scanner.nextLine();
        System.out.println("Digite o preço do produto:");
        double precoProduto = scanner.nextDouble();

        Produto produto = new Produto(nomeProduto, precoProduto);

        // Leitura do código do tipo de pagamento
        System.out.println("Digite o código do tipo de pagamento:");
        int codigoPagamento = scanner.nextInt();

        // Usando getByCodigo sem values() para obter o TipoPagamento correto
        Codigo codigo = Codigo.getByCodigo(codigoPagamento);
        TipoPagamento pagamento = new TipoPagamento(codigo);

        // Leitura dos dados do item de venda
        System.out.println("Digite a quantidade:");
        int quantidade = scanner.nextInt();
        System.out.println("Digite a alíquota de imposto:");
        double aliquotaImposto = scanner.nextDouble();
        System.out.println("O item é isento de imposto? (true/false):");
        boolean isentoImposto = scanner.nextBoolean();

        ItemVenda itemVenda = new ItemVenda(produto, pagamento, quantidade, aliquotaImposto, isentoImposto);

        // Cálculo e exibição dos resultados
        System.out.printf("Imposto incidente: %.2f\n", itemVenda.calcularImposto());
        System.out.printf("Valor total do item: %.2f\n", itemVenda.calcularValorTotal());

        System.out.println("Digite o custo rateado:");
        double custoRateado = scanner.nextDouble();
        System.out.printf("Lucro do item: %.2f\n", itemVenda.calcularLucroItem(custoRateado));

        scanner.close();
    }
}
