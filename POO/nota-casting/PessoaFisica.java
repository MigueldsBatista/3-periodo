import java.time.LocalDate;

public class PessoaFisica extends Pessoa {
	
	private TipoDesconto tipoDesconto;

	public PessoaFisica(String nomeRazSocial, LocalDate dataNascimentoCriacao, double rendaFaturamentoBruto,
			boolean recolhedorInss, TipoDesconto tipoDesconto) {
		super(nomeRazSocial, dataNascimentoCriacao, rendaFaturamentoBruto, recolhedorInss);
		this.tipoDesconto = tipoDesconto;
	}

	public TipoDesconto getTipoDesconto() {
		return tipoDesconto;
	}

	public void setTipoDesconto(TipoDesconto tipoDesconto) {
		this.tipoDesconto = tipoDesconto;
	}
}