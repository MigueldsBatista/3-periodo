package lista5.pacote;

public class ArrayUtils {

    public static String [] ordenar(String[] nomes){//length pra puxar os elementos de um array
        if(nomes==null) return null;
        for(int i=0;i<nomes.length;i++){
            for(int j=0;j<nomes.length-1 - i;j++){
                if(nomes[j].compareTo(nomes[j+1])>0){//4-3
                    String temp=nomes[j];
                    nomes[j]=nomes[j+1];
                    nomes[j+1]=temp;
                }
            }
        }
        return nomes;

    }

    public static int [] espelhar(int[] valores){
        if(valores==null) return null;
        int espelhado[] = new int[valores.length];
        for (int i = 0, j = valores.length-1 ; i < valores.length && j >= 0; i++, j--) {
            espelhado[j]=valores[i];
        }
        return espelhado;
    }

}
