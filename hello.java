/*Java hello world
Java Fundamentus

O que é JVM - Java virtua           l machine
1- ela interpreta e executa o codigo java compilado
2- quando nós formos executar nosso codigo compilado ela que vai ser responsavel
3- ela tambem gerencia a memoria e coleta o lixo (GC)
4- E


Pra declarar uma variavel, precisamos declarar
1 - Tipo
2- Nome 
3- Valor(não é preciso fornecer na declaração)

Tipos de int
byte(até 8 bits -128, 127)
short()
int float

String não é um tipo primitivo, é uma classe

double é pra pontos flutuantes maiores
float são pra numeros de pontos flutuantes menor
 */


public class hello{
    public static void main(String[] args){
        byte idade=19;
        if(idade>18){
            System.out.println("Você é maior de idade!");
        }
        else {
            System.out.println("Você é menor de idade!");
        }
    }
    
} 