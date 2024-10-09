public class ProgramTwo {
    public static void main(String[] args) {
        // Criação do objeto c1 que contém uma CPU com nome "I5" e clock de 2.1 GHz
        Computer c1 = new Computer(new Cpu("I5", 2.1), "C021", "DELL");

        // c2 é uma referência ao mesmo objeto que c1. Ambas referenciam o mesmo Computer.
        Computer c2 = c1;

        // c3 é um novo objeto Computer, mas sua CPU é a mesma que a de c1 e c2 (I5, 2.1).
        Computer c3 = new Computer(c2.cpu, "Macbook", "Apple");

        // cp1 é uma referência ao mesmo objeto Cpu que c1.cpu. Assim, cp1 refere-se a "I5, 2.1".
        Cpu cp1 = c1.cpu;

        // c1 agora aponta para um novo objeto Cpu com nome "I7" e clock de 2.8 GHz.
        // O objeto original (I5, 2.1) ainda é referenciado por c2, c3 e cp1.
        c1.cpu = new Cpu("I7", 2.8); 

        // Chama overClock no objeto referenciado por cp1 (I5, 2.1)
        cp1.overClock(1.1); // O clock do objeto original (I5) agora se torna 2.1 * 1.1 = 2.31

        // Exibe o clock do novo objeto Cpu referenciado por c1 (I7, 2.8)
        System.out.println(c1.cpu.clock); // PONTO 1 // Exibe 2.8. (c1 é afetado, I5 não)

        // Chama overClock no objeto referenciado por c3 (que ainda aponta para o objeto original I5)
        c3.cpu.overClock(1.3); // O clock do objeto original (I5) agora se torna 2.31 * 1.3 = 3.003

        // Exibe o clock do objeto original, que foi alterado pelo overClock acima
        System.out.println(cp1.clock); // Exibe 3.003. (I5 foi afetado, I7 não)

        // Alteração da referência de c3, mas c3.cpu continua referenciando o objeto original (I5)
        c3 = new Computer(c3.cpu, "A540", "HP"); // PONTO 2

        // Exibe o clock do objeto original (I5) que ainda é referenciado por c3
        System.out.println(c3.cpu.clock); // Exibe 3.003. (I5 é afetado, I7 não)

        // Chama a função que altera a referência da CPU em c2 para um novo objeto Cpu
        changeCpu(c2); // PONTO 3

        // Exibe o nome da CPU em c1, que não foi alterado na função changeCpu
        System.out.println(c1.cpu.name); // Exibe o nome da CPU, que é "I7" (c1 não é afetado)

        // Chama a função que altera a CPU em c1 também
        changeCpu(c1); // c1.cpu é agora alterado para "RYZEN9"

        // Exibe o nome da CPU de c2, que agora foi alterada para "RYZEN9"
        System.out.println(c2.cpu.name); // Exibe "RYZEN9" (c2 é afetado, I5 e I7 não)
    }

    // Função que altera a CPU de um Computer passado como parâmetro
    static void changeCpu(Computer c) {
        // c.cpu é alterado para um novo objeto Cpu com nome "RYZEN9" e clock 3.3
        c.cpu = new Cpu("RYZEN9", 3.3); // Muda a referência da CPU em c. O objeto original não é afetado.
    }
}
