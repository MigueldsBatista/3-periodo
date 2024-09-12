package itemvenda;

class Produto {
String nome;
double precoBase;

double CalcularPrecoFinal(double imposto) {
	double precoFinal=precoBase*(1+imposto/100);
	return precoFinal;

}

Produto(String nome, double precoBase){
	this.precoBase=precoBase;
	this.nome=nome;
	
}

double getPreco() {
    return precoBase;
}
}
