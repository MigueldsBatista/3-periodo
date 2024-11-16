public class MotorCombustao extends Motor{
double consumoMedio;

public double getConsumoMedio() {
    return consumoMedio;
}

public void setConsumoMedio(double consumoMedio) {
    this.consumoMedio = consumoMedio;
}

public MotorCombustao() {
    super(); // Chama o construtor vazio da superclasse
}

// Construtor com atributos obrigatórios da superclasse e o novo atributo
public MotorCombustao(long codigo, String nome, double consumoMedio) {
    super(codigo, nome); // Chama o construtor da superclasse
    this.consumoMedio = consumoMedio;
}

// Construtor com todos os atributos (superclasse + subclasse)
public MotorCombustao(long codigo, String nome, double potencia, double vazao, double consumoMedio) {
    super(codigo, nome, potencia, vazao); // Chama o construtor da superclasse com todos os atributos
    this.consumoMedio = consumoMedio;
}

}
