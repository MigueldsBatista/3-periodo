.data
prompt: .asciiz "Digite o número da sequencia de Fibonacci: "
output: .word 0

.text
main:
    la $a0, prompt
    li $v0, 4               # Imprime a string do prompt
    syscall

    li $v0, 5               # Lê um número inteiro
    syscall
    move $a0, $v0           # Move a entrada para $a0

    jal fib                 # Chama a função Fibonacci

    sw $v0, output          # Armazena o resultado

    lw $a0, output          # Carrega o resultado
    li $v0, 1               # Imprime o inteiro
    syscall

    li $v0, 10              # Sai do programa
    syscall

# Função Fibonacci Recursiva
fib:
    addi $sp, $sp, -12      # Aloca espaço na pilha
    sw $ra, 0($sp)          # Salva o endereço de retorno
    sw $a0, 4($sp)          # Salva o argumento $a0 (n)
    sw $s0, 8($sp)          # Salva o registrador $s0

    # Caso base: fib(0) = 0 e fib(1) = 1
    li $v0, 0
    beq $a0, $v0, fib_base  # Se n == 0, retorna 0

    li $v0, 1
    beq $a0, $v0, fib_base  # Se n == 1, retorna 1

    # Caso recursivo
    addi $a0, $a0, -1       # n-1
    jal fib                 # fib(n-1)
    move $s0, $v0           # Salva fib(n-1) em $s0

    lw $a0, 4($sp)          # Restaura o valor de n
    addi $a0, $a0, -2       # n-2
    jal fib                 # fib(n-2)

    add $v0, $s0, $v0       # fib(n-1) + fib(n-2)
    
fib_base:
    lw $ra, 0($sp)          # Restaura o endereço de retorno
    lw $a0, 4($sp)          # Restaura o valor de $a0
    lw $s0, 8($sp)          # Restaura o valor de $s0
    addi $sp, $sp, 12       # Libera espaço na pilha
    jr $ra                  # Retorna
