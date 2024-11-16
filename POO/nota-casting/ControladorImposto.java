/*
 * implementar um método na classe ControladorImposto (a ser criada) que receba dados de uma pessoa, a alíquota padrão, e que calcule o imposto
segundo a lógica dada.


Lógica para cálculo do imposto
Primeiro, deve se calcular o fatorMultiplicador
se rendaFaturamentoBruto > 200000
se idade < 5
fatorMultiplicador = 1.5;
senão
fatorMultiplicador = 1.4;
senão
se idade < 5
fatorMultiplicador = 1.3;
senão
fatorMultiplicador = 1.2;
se recolhedorInss is true
fatorMultiplicador = fatorMultiplicador * 0.75
imposto = fatorMultiplicador * aliquotaPadrao

 * 
 */

public class ControladorImposto {

public static double calcularImposto(Pessoa pessoa, double aliquotaPadrao){
    double fatorMultiplicador;

    if(pessoa.getRendaFaturamentoBruto()>200000){
        if(pessoa.calcularIdade()<5) fatorMultiplicador=1.5;

        else fatorMultiplicador = 1.4;        
    }
    else{
        if(pessoa.calcularIdade()<5) fatorMultiplicador=1.3;

        else fatorMultiplicador=1.2;
    }
    if(pessoa.isRecolhedorInss()) fatorMultiplicador=fatorMultiplicador*0.75;

    return fatorMultiplicador*aliquotaPadrao;


    
}
}
