package br.edu.cesarschool.cc.poo.meiotransporte;

public class ProgramaTransporte {

    public static void main(String[] args) {

        Carro carro= new Carro("BMW M3", 5000, 250, 500, 60, 4);
        carro.calcularEficiencia();
        System.out.printf("Eficiencia do %s: %.2f\n", carro.getNome(), carro.getConsumoMedio());

        
        AsaDelta asaDelta = new AsaDelta("Great Glider", 120, 70, TipoTracao.VENTO);
        System.out.printf("Cuidado pra não se espatifar na parede com a incrivel velocidade de %.2f km da %s \n", asaDelta.getVelocidadeMaxima(), asaDelta.getNome());

        System.out.println(asaDelta.equals(asaDelta)+"\n");
        System.out.println(asaDelta.hashCode()+"\n");
        System.out.println(asaDelta.toString()+"\n");

    }
}
