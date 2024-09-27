
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Barbearia {
  private int cadeiras;
  private Queue<Cliente> filaClientes = new LinkedList<>();
  private Queue<Barbeiro> barbeirosDormindo = new LinkedList<>();

  ArrayList<Cliente> clientesCortando = new ArrayList<>();

  public Barbearia(int capacidadeCadeiras) {
    this.cadeiras = capacidadeCadeiras;
  }

  public synchronized boolean cortaCabelo(Cliente cliente) {
    if (cadeiras == filaClientes.size()) {
      return false; // Barbearia lotada
    } else {
      filaClientes.add(cliente);
      acordaBarbeiro(cliente);
      return true;
    }
  }

  public synchronized Cliente proximoCliente(Barbeiro barbeiro) {
    if (filaClientes.isEmpty() == false) {
      Cliente cliente = filaClientes.poll();
      clientesCortando.add(cliente);

      System.out.println("Cliente " + cliente.getID() + " cortando cabelo.");

      return cliente;
    }
    else {
      adormecerBarbeiro(barbeiro);
      return null;
    }
  }

  public synchronized void corteTerminado(Cliente cliente) {
    int clienteCortandoIndex = clientesCortando.indexOf(cliente);
    Cliente clienteCortando = clientesCortando.remove(clienteCortandoIndex);

    synchronized (clienteCortando) {
      clienteCortando.notify();
    }
  }

  private synchronized void acordaBarbeiro(Cliente cliente) {
    if (!barbeirosDormindo.isEmpty()) {
      Barbeiro barbeiro = barbeirosDormindo.poll();

      synchronized(barbeiro) {
        barbeiro.notify();
      }
    }
  }

  public synchronized void adormecerBarbeiro(Barbeiro barbeiro) {
    barbeirosDormindo.add(barbeiro);
  }
}