public class Conta {
private int agencia;
private long numero;
private double saldo;

public Conta(){

}

public int getAgencia() {
    return agencia;
}

public long getNumero() {
    return numero;
}

public double getSaldo() {
    return saldo;
}

public void setAgencia(int agencia) {
    this.agencia = agencia;
}

public void setNumero(long numero) {
    this.numero = numero;
}

public void setSaldo(double saldo) {
    this.saldo = saldo;
}

void creditar(double valor){

}

protected boolean debitar(double valor){
if(this.saldo-valor > 0){
    this.saldo=this.saldo-valor;
    return true;
}
return false;

}


}
