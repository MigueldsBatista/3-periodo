import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class ProgramaCalcularImposto {

/*Depois, escreva um programa que leia do console todos os atributos de 
1 pessoa, 
1 pessoa física
e de 1 pessoa jurídica, 

e que, instanciando três objetos pessoa, pessoa física e pessoa jurídica, use o método criado na
classe ControladorImposto para calcular o imposto devido para cada um dos objetos criados.
 */ 
    private static final Scanner ENTRADA = new Scanner(System.in);
    public static void main(String[] args) {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        
        System.out.println("Digite o nome da pessoa");
        String nomePessoa = ENTRADA.nextLine();

        System.out.println("Faturamento bruto");
        double rendaFaturamentoBrutoPessoa = ENTRADA.nextDouble();
        System.out.println("é recolhedor de inss? true/false");
        boolean recolhedorInssPessoa = ENTRADA.nextBoolean();

        System.out.println("Digite a data de nascimento da pessoa no formato dd/MM/yyyy");
        String dataNascimentoCriacaoPessoaString = ENTRADA.next();

        LocalDate dataNascimentoCriacaoPessoa = LocalDate.parse(dataNascimentoCriacaoPessoaString, formatter);

        Pessoa pessoa = new Pessoa(nomePessoa, dataNascimentoCriacaoPessoa, rendaFaturamentoBrutoPessoa, recolhedorInssPessoa);

        PessoaFisica pessoaFisica = new PessoaFisica(nomePessoa, dataNascimentoCriacaoPessoa, rendaFaturamentoBrutoPessoa, recolhedorInssPessoa, null);

        PessoaJuridica pessoaJuridica = new PessoaJuridica(nomePessoa, dataNascimentoCriacaoPessoa, rendaFaturamentoBrutoPessoa, recolhedorInssPessoa, 5);
        double imposto = ControladorImposto.calcularImposto(pessoa, 0.1);
        System.out.println("Imposto para "+pessoa.getNomeRazSocial()+": "+imposto);

        double impostoPessoaJuridica = ControladorImposto.calcularImposto(pessoaJuridica, 0.1);
        System.out.println("Imposto para "+pessoaJuridica.getNomeRazSocial()+": "+impostoPessoaJuridica);

        double impostoPessoaFisica = ControladorImposto.calcularImposto(pessoaFisica, 0.1);
        System.out.println("Imposto para "+pessoaFisica.getNomeRazSocial()+": "+impostoPessoaFisica);



    }
}
