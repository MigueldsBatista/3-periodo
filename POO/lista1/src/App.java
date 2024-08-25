//if num < 0 print menor que zero
//if num > 16 print overflow
//fatorial

//leia varios numeros reais e calcule e imprima no console a soma dos numeros lidos entre 5 e 5000, if num <0 break

//3 5 num Media aritimetica, geometrica, harmonica

//4 1 num int e 2 reais
/*
 * case 1 soma
 * case 2 subtração
 * case 3 divisao
 * case 4 multiplicacao
 * 
 * if num not >=1<=4 OPC ERRADA;
 * 
 * if num/0 DIV ZERO
 */

import java.util.Scanner;


    
public class App {
    private static final Scanner ENTRADA = new Scanner(System.in);

    public static int fatorialNum(int num){
        int fatorial=1;
        for(int i=num;i>0;i--){
            System.out.println(i+"x"+fatorial+"="+(fatorial=fatorial*i));
        }
        return fatorial;
    }

    public static void main(String[] args) throws Exception {
        
        System.out.println("Digite um número: ");
        int num=ENTRADA.nextInt();
        if(num<0){
            System.err.println("MENOR QUE ZERO\n");
        }
        else if(num>16){
            System.err.println("OVERFLOW\n");
        }
        fatorialNum(num);
    }
}
