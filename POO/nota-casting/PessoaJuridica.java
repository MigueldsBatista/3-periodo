import java.time.LocalDate;

public class PessoaJuridica extends Pessoa {
	
	private int quantidadeFuncionarios; 

	public PessoaJuridica(String nomeRazSocial, LocalDate dataNascimentoCriacao, double rendaFaturamentoBruto,
			boolean recolhedorInss, int quantidadeFuncionarios) {
		super(nomeRazSocial, dataNascimentoCriacao, rendaFaturamentoBruto, recolhedorInss);
		this.quantidadeFuncionarios = quantidadeFuncionarios;
	}

	public int getQuantidadeFuncionarios() {
		return quantidadeFuncionarios;
	}

	public void setQuantidadeFuncionarios(int quantidadeFuncionarios) {
		this.quantidadeFuncionarios = quantidadeFuncionarios;
	}
}