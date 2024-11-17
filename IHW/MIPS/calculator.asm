.data
prompt: .asciiz "Digite a operação que você deseja realizar: \n1-Adição\n2-Subtração\n3-Multiplicação\n4-Divisão"
prompt_first: .asciiz "Digite o primeiro número: "
prompt_second: .asciiz "\nDigite o segundo número: "
prompt_result: .asciiz "\nO resultado da operação é: "
output: .word 0

.text
main:
#Imprimir os numeros na tela do usuário
    la $a0, prompt
    li $v0, 4
    syscall

    li $v0, 10
    syscall