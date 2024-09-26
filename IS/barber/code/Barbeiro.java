
import java.util.Random;

public class Barbeiro extends Pessoa implements Runnable {
  private Barbearia barbearia;

  public Barbeiro(int id, Barbearia barbearia) {
    super(id);
    this.barbearia = barbearia;
  }

  @Override
  public void run() {
    while (true) {
      try {
        Cliente cliente = barbearia.proximoCliente(this);

        if (cliente != null) {
          System.out.println("Barbeiro " + id + " cortando cabelo do Cliente " + cliente.getID());
          
          Thread.sleep(new Random().nextInt(5000) + 5000); // Corte de cabelo de 5 a 10 segundos
          System.out.println("Barbeiro " + id + " terminou corte do Cliente " + cliente.getID());

          barbearia.corteTerminado(cliente);
        } else {
          System.out.println("Barbeiro " + id + " indo dormir... não há clientes na barbearia.");
          
          synchronized (this) {
            this.wait(); // Espera ate um cliente chamar o metodo cortaCabelo(), que vai notificar esse barbeiro dormindo.
          }
        }
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
  }
}