public class Main {
  public static void main(String[] args) {
    int barbeiros, cadeiras, totalClientes;
    barbeiros = Integer.parseInt(args[0]);
    cadeiras = Integer.parseInt(args[1]);
    totalClientes = Integer.parseInt(args[2]);

    Barbearia barbearia = new Barbearia(cadeiras);

    for (int i = 1; i <= barbeiros; i++) {
      Barbeiro barbeiro = new Barbeiro(i, barbearia);
      new Thread(barbeiro).start();
    }

    for (int i = 1; i <= totalClientes; i++) {
      Cliente cliente = new Cliente(i, barbearia);
      new Thread(cliente).start();
    }
  }
}
