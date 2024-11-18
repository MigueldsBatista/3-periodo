.data
prompt_inf: .asciiz "Digite o limite inferior: "
prompt_sup: .asciiz "Digite o limite superior: "
result_msg: .asciiz "A soma dos números primos no intervalo é: "
newline:    .asciiz "\n"

.text
.globl main

main:
    # Ler o limite inferior
    li $v0, 4               # Syscall para imprimir string
    la $a0, prompt_inf
    syscall

    li $v0, 5               # Syscall para ler inteiro
    syscall
    move $t0, $v0           # Armazena limite inferior em $t0

    # Ler o limite superior
    li $v0, 4
    la $a0, prompt_sup
    syscall

    li $v0, 5
    syscall
    move $t1, $v0           # Armazena limite superior em $t1

    # Inicializar soma
    li $t2, 0               # $t2 armazena a soma dos números primos

    # Loop para verificar números no intervalo
loop:
    bgt $t0, $t1, end_loop  # Se limite inferior > limite superior, termina o loop

    # Verificar se o número atual ($t0) é primo
    move $a0, $t0           # Passa o número para $a0
    jal is_prime            # Chama a função is_prime
    beq $v0, 0, next_num    # Se não for primo, vai para o próximo número

    # Se for primo, adiciona à soma
    add $t2, $t2, $t0

next_num:
    addi $t0, $t0, 1        # Incrementa o número atual
    j loop                  # Repetir o loop

end_loop:
    # Imprimir o resultado
    li $v0, 4
    la $a0, result_msg
    syscall

    move $a0, $t2           # Passa a soma para $a0
    li $v0, 1               # Imprimir inteiro
    syscall

    li $v0, 4
    la $a0, newline
    syscall

    li $v0, 10              # Encerrar o programa
    syscall

# Função para verificar se um número é primo
# Entrada: $a0 = número a ser verificado
# Saída: $v0 = 1 se o número for primo, 0 caso contrário
is_prime:
    li $t3, 2               # Iniciar divisor em 2
    ble $a0, 1, not_prime   # Se o número for <= 1, não é primo

check_divisor:
    mul $t4, $t3, $t3       # $t4 = $t3 * $t3 (verifica até a raiz quadrada)
    bgt $t4, $a0, prime     # Se o quadrado do divisor > número, é primo

    # Verificar se o número é divisível por $t3
    rem $t5, $a0, $t3       # Resto da divisão $a0 / $t3
    beqz $t5, not_prime     # Se o resto for 0, não é primo

    addi $t3, $t3, 1        # Incrementa o divisor
    j check_divisor         # Repetir o loop

prime:
    li $v0, 1               # Retorna 1 (é primo)
    jr $ra

not_prime:
    li $v0, 0               # Retorna 0 (não é primo)
    jr $ra
