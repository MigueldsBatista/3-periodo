import java.util.Scanner;

public class soma {
private static final Scanner ENTRADA = new Scanner(System.in);

    public static void main(String[] args) {

        double num=0;
        double soma=0;
        while(num>0){
            num=ENTRADA.nextDouble();
            if(num>=5 && num <= 5000){
                soma=soma+num;
            }
            else if(num<0) break;

            
            System.out.println("Soma: "+soma);
        }
    }
}
