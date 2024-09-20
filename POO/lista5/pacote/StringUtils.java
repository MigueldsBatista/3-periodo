package lista5.pacote;

public class StringUtils {


public static String obterTextoCensurado(String textoOriginal, String [] palavrasProibidas){
if(textoOriginal==null){
    System.out.println("Texto original vazio!");
    return null;
}

if(palavrasProibidas==null){
    return textoOriginal;
}
for(int i=0;i<palavrasProibidas.length;i++){
    if(textoOriginal.contains(palavrasProibidas[i])){
        textoOriginal=textoOriginal.replace(palavrasProibidas[i], "#@!-M*+*");
    }
}
    
    return textoOriginal;
}

public static String obterMaiorPalavra(String texto){
    String palavra="";
    String maiorPalavra="";
    int indexInicio=0;
    for(int i=0;i<=texto.length();i++){
        
        if(i == texto.length() || texto.charAt(i)==' '){
            palavra=texto.substring(indexInicio, i);
        
        if(palavra.length()>maiorPalavra.length()){
            maiorPalavra=palavra;
        }
            indexInicio = i + 1 ;

        }

    }
    return maiorPalavra;
}
}


