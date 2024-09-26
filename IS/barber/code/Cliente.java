import java.util.Random;

public class Cliente extends Pessoa implements Runnable {
  private Barbearia barbearia;

  public Cliente(int id, Barbearia barbearia) {
    super(id);
    this.barbearia = barbearia;
  }

  @Override
  public void run() {
    while (true) {
      try {
        Thread.sleep((new Random().nextInt(10) + 5) * 1000); // Espera entre 5 e 15 segundos para entrar na barbearia

        if (barbearia.cortaCabelo(this)) {
          System.out.println("Cliente " + id + " entrou na barbearia e esta esperando o corte.");
          synchronized (this) {
            this.wait(); // Dorme na cadeira, esperando ser acordado pelo barbeiro em corteTerminado();
          }
          
          return;

        } else {
          System.out.println("Cliente " + id + " tentou entrar na barbearia, mas está lotada...");
        }
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
  }
}