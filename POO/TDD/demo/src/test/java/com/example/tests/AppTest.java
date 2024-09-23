package com.example.tests;

import com.example.Calculadora;

import org.junit.jupiter.api.Test; // Import JUnit 5
import static org.junit.jupiter.api.Assertions.*; // Assertions para JUnit 5

public class AppTest {

    @Test
    public void testSoma() {
        Calculadora calc = new Calculadora();
        int resultado = calc.soma(2, 3);
        assertEquals(5, resultado);
    }

    @Test
    public void testSubtracao() {
        Calculadora calc = new Calculadora();
        int resultado = calc.subtrai(5, 3);
        assertEquals(2, resultado);
    }
}
