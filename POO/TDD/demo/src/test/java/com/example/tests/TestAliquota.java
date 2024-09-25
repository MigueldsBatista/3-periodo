package com.example.tests;
import com.example.CalcularAliquota;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class TestAliquota {

    @Test
    public void testSalarioMenor() {
        CalcularAliquota calc = new CalcularAliquota(1999, 74);//caso com idade menor e salario igual
        double aliquota = calc.calcularAliquota();
        assertEquals(0, aliquota);
    }

    @Test
    public void testIdadeMenor() {
        CalcularAliquota calc = new CalcularAliquota(2000, 75);//caso com idade maior e salario maior
        double aliquota = calc.calcularAliquota();
        assertEquals(0, aliquota);
    }

    @Test
    public void testSalarioEntre(){
        CalcularAliquota calc = new CalcularAliquota(2000, 59);//caso com idade menor e salario igual
        double aliquota=calc.calcularAliquota();
        assertEquals(10, aliquota);
    }

    @Test
    public void testSalarioMaior(){
        CalcularAliquota calc= new CalcularAliquota(5001, 59);//maior que 5000
        double aliquota=calc.calcularAliquota();
        assertEquals(20, aliquota);
    }

    @Test
    public void testDesconto(){
        CalcularAliquota calc=new CalcularAliquota(2001, 61);
        double aliquota=calc.calcularAliquota();
        assertEquals(10*0.8, aliquota);
    }

    @Test
    public void testDescontoMaior(){
        CalcularAliquota calc=new CalcularAliquota(5001, 61);
        double aliquota=calc.calcularAliquota();
        assertEquals(20*0.8, aliquota);
    }



}
