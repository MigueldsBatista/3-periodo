package lista5.pacote;

public class ProgramaString {

    public static void main(String[] args) {

        String [] palavrao={"panaca", "estupido"};
        System.out.println(StringUtils.obterTextoCensurado("eu nao gosto de vc panaca", palavrao));

        System.out.println(StringUtils.obterTextoCensurado(null, palavrao));

        System.out.println("maior palavra: "+StringUtils.obterMaiorPalavra("meu texto qual a maior PALAVRAaa"));
        

        String[] nomes = {"Maria", "João", "Ana", "Fernando", "Zé"};
        String[] nomesOrdenados = ArrayUtils.ordenar(nomes);
    
        for (String nome : nomesOrdenados) {
            System.out.println(nome);
        }
        int[] valores = {1, 2, 3, 4, 5};
        int[] espelhado = ArrayUtils.espelhar(valores);

        for (int i = 0; i < espelhado.length; i++) {
            System.out.println(espelhado[i]);
        } // Saída: [5, 4, 3, 2, 1]
    }
}
