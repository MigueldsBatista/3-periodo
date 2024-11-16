import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class Pessoa {
	private String nomeRazSocial;
	private LocalDate dataNascimentoCriacao;
	private double rendaFaturamentoBruto;
	private boolean recolhedorInss;
    
	public Pessoa(String nomeRazSocial, LocalDate dataNascimentoCriacao, double rendaFaturamentoBruto,
			boolean recolhedorInss) {
		super();
		this.nomeRazSocial = nomeRazSocial;
		this.dataNascimentoCriacao = dataNascimentoCriacao;
		this.rendaFaturamentoBruto = rendaFaturamentoBruto;
		this.recolhedorInss = recolhedorInss;
	}
	public String getNomeRazSocial() {
		return nomeRazSocial;
	}
	public void setNomeRazSocial(String nomeRazSocial) {
		this.nomeRazSocial = nomeRazSocial;
	}
	public LocalDate getDataNascimentoCriacao() {
		return dataNascimentoCriacao;
	}
	public void setDataNascimentoCriacao(LocalDate dataNascimentoCriacao) {
		this.dataNascimentoCriacao = dataNascimentoCriacao;
	}
	public double getRendaFaturamentoBruto() {
		return rendaFaturamentoBruto;
	}
	public void setRendaFaturamentoBruto(double rendaFaturamentoBruto) {
		this.rendaFaturamentoBruto = rendaFaturamentoBruto;
	}
	boolean isRecolhedorInss() {
		return recolhedorInss;
	}
	void setRecolhedorInss(boolean recolhedorInss) {
		this.recolhedorInss = recolhedorInss;
	}

	long calcularIdade() {
		if (dataNascimentoCriacao != null) {
			LocalDate dataAtual = LocalDate.now();
			return dataAtual.until(dataNascimentoCriacao, ChronoUnit.YEARS);
		} else {
			return 0; 
		}
	}
}