#1 - crie o algoritmo   que mostre “hello world” na tela.

.data
hello: .asciiz "hello world!" 

.text#execução do trecho de código onde ficam as instruções
main: #função princilap
la $a0, hello #carrega o endereço de hello para o argumento 0 da chamada de sistema
li $v0, 4 #Impresão de string
syscall

li $v0, 10 #Sair do programa
syscall