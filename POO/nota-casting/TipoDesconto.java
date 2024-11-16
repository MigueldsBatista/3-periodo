public enum TipoDesconto {
	TOTAL(1, "Total"), 
	POR_IDADE(2, "Por idade"), 
	SEM_DESCONTO(3,"Sem desconto");  
	
	private int codigo;
	private String descricao;
	
	private TipoDesconto(int codigo, String descricao) {
		this.codigo = codigo;
		this.descricao = descricao;
	}

	public int getCodigo() {
		return codigo;
	}

	public String getDescricao() {
		return descricao;
	}
	public static TipoDesconto obterPorCodigo(int codigo) {		
		TipoDesconto[] tiposDescontos = TipoDesconto.values();
		for (TipoDesconto tipoDesconto : tiposDescontos) {
			if (tipoDesconto.getCodigo() == codigo) {
				return tipoDesconto;
			}
		}
		return null;
	}

}