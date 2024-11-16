public class Motor {
private long codigo;
private double potencia;
private double vazao;
private String nome;

Motor(long codigo, String nome){
    if (String.valueOf(codigo).length() != 13) {
        throw new IllegalArgumentException("O código deve ter 13 dígitos.");
    }
    this.codigo=codigo;
    this.nome=nome;
}

Motor(long codigo, String nome, double potencia, double vazao){
    this(codigo, nome);
    this.potencia=potencia;
    this.vazao=vazao;
}

Motor(){}//pq?
    
public double getPotencia() {
    return potencia;
}

public double getVazao() {
    return vazao;
}

public String getNome() {
    return nome;
}

public void setNome(String nome) {
    this.nome = nome;
}
public void setPotencia(double potencia) {
    this.potencia = potencia;
}

public void setVazao(double vazao) {
    this.vazao = vazao;
}
public long getCodigo() {
    return codigo;
}
}
