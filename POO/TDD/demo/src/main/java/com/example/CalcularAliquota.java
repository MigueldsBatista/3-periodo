package com.example;

public class CalcularAliquota {
    private double salario;
    private int idade;

    public CalcularAliquota(double salario, int idade) {
        this.salario = salario;
        this.idade = idade;
    }

    public double calcularAliquota() {
        double aliquota=0;
        if (idade >= 75 || salario<2000) {
            return 0;
        }

       else if (salario >= 2000 && salario <=5000) {//teste salario entre
            aliquota = 10;
    }   

       else if (salario > 5000)  //teste salario maior
            aliquota = 20;
    

    if(idade>=60 && idade<=74) { //teste desconto
        aliquota = aliquota*0.8;
    }
    return aliquota;
}
}