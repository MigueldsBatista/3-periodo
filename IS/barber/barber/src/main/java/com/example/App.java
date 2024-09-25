package com.example;

import com.example.domain.entity.Barbeiro;
import com.example.domain.entity.Cliente;


public class App 
{
    private static final int NUM_CLIENTES = 10;
    private static final int NUM_BARBEIROS = 3;
    private static final int NUM_CADEIRAS= 5;
    
    public static void main( String[] args )
    {

        new Thread(() -> {
        for (int i = 0; i < NUM_CLIENTES; i++) {
            Cliente cliente = new Cliente(i);
            cliente.cortaCabelo(cliente);
        }
        
        }).start();
        
        for (int i = 0; i < NUM_BARBEIROS; i++) {
            Barbeiro barbeiro = new Barbeiro(i);
            barbeiro.proximoCliente();
        }
    }
}
