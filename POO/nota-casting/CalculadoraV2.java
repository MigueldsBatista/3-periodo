/*Lógica para cálculo do imposto
Primeiro, deve se calcular o fatorMultiplicador
se a pessoa for do tipo pessoa física E se o tipoDesconto for total
fatorMultiplicador = 0;
senão se rendaFaturamentoBruto > 200000
se idade < 5
fatorMultiplicador = 1.5;
senão se a pessoa for do tipo pessoa jurídica
se quantidadeFuncionarios > 100
fatorMultiplicador = 1.25;
senão
fatorMultiplicador = 1.4;
senão
fatorMultiplicador = 1.35;
senão
se idade < 5
fatorMultiplicador = 1.3;
senão
fatorMultiplicador = 1.2;
se recolhedorInss is true
fatorMultiplicador = fatorMultiplicador * 0.75
imposto = fatorMultiplicador * aliquotaPadrao */

public class CalculadoraV2 {
	public double calcularImposto(Pessoa pessoa, double aliquotaPadrao) {
        double fatMultiplicador;
		if (pessoa instanceof PessoaFisica && ((PessoaFisica)pessoa).getTipoDesconto().equals(TipoDesconto.TOTAL))  {
            fatMultiplicador = 0;
		}
        else if (pessoa.getRendaFaturamentoBruto()<20000) {
            if(pessoa.calcularIdade()<5) fatMultiplicador = 1.5;
            else if (pessoa instanceof PessoaJuridica) {
                if (((PessoaJuridica)pessoa).getQuantidadeFuncionarios()>100) fatMultiplicador = 1.25;
                else fatMultiplicador = 1.4;
            }
            else fatMultiplicador = 1.35;
        }
        else {
            if(pessoa.calcularIdade()<5) fatMultiplicador = 1.3;
            else fatMultiplicador = 1.2;
        }
        if(pessoa.isRecolhedorInss()) fatMultiplicador = fatMultiplicador * 0.75;
        return fatMultiplicador * aliquotaPadrao;
	}
}
