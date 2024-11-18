.data
prompt_t0: .asciiz "Digite o primeiro termo (t0): "
prompt_t1: .asciiz "Digite o segundo termo (t1): "
prompt_n:  .asciiz "Digite o número de termos (n): "
newline:   .asciiz "\n"

.text
.globl main

main:
    # Ler o primeiro termo (t0)
    li $v0, 4               # Syscall para imprimir string
    la $a0, prompt_t0
    syscall

    li $v0, 5               # Syscall para ler inteiro
    syscall
    move $t0, $v0           # Armazena t0

    # Ler o segundo termo (t1)
    li $v0, 4
    la $a0, prompt_t1
    syscall

    li $v0, 5
    syscall
    move $t1, $v0           # Armazena t1

    # Ler o número de termos (n)
    li $v0, 4
    la $a0, prompt_n
    syscall

    li $v0, 5
    syscall
    move $t2, $v0           # Armazena n

    # Imprimir o primeiro termo (t0)
    move $a0, $t0
    li $v0, 1
    syscall

    li $v0, 4               # Imprimir nova linha
    la $a0, newline
    syscall

    # Imprimir o segundo termo (t1)
    move $a0, $t1
    li $v0, 1
    syscall

    li $v0, 4
    la $a0, newline
    syscall

    # Inicializar variáveis para o loop
    move $t3, $t0           # t3 = termo anterior (t0)
    move $t4, $t1           # t4 = termo atual (t1)
    li $t5, 3               # Contador (começa do 3º termo)

loop:
    # Verificar se já imprimimos n termos
    bge $t5, $t2, end_loop

    # Se o índice for ímpar, calcular a soma
    andi $t6, $t5, 1        # t6 = $t5 & 1 (verifica paridade)
    beqz $t6, even_term     # Se t6 == 0, é par, vai para even_term

    # Índice ímpar: soma dos dois termos anteriores
    add $t7, $t3, $t4       # t7 = t3 + t4
    j print_term

even_term:
    # Índice par: subtração dos dois termos anteriores
    sub $t7, $t4, $t3       # t7 = t4 - t3

print_term:
    # Imprimir o termo atual (t7)
    move $a0, $t7
    li $v0, 1
    syscall

    li $v0, 4
    la $a0, newline
    syscall

    # Atualizar termos para o próximo cálculo
    move $t3, $t4           # t3 = termo anterior (atualiza para t4)
    move $t4, $t7           # t4 = termo atual (atualiza para t7)
    addi $t5, $t5, 1        # Incrementa o contador

    j loop                  # Repetir o loop

end_loop:
    li $v0, 10              # Encerrar o programa
    syscall
