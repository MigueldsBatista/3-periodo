package NewGame;

public enum MetodoEncaixe {
HEAD_UP(1),
HEAD_DOWN(2);

private int codigo;

MetodoEncaixe(int codigo){
    this.codigo=codigo;
}

public int getCodigo() {
    return codigo;
}
public void setCodigo(int codigo) {
    this.codigo = codigo;
}

}
