.data
    prompt_N: .asciiz "Digite o valor de N (>= 6): "
    invalid_N: .asciiz "N inválido\n"
    prompt_value: .asciiz "Digite o valor para x["
    end_prompt: .asciiz "]: "
    newline: .asciiz "\n"

.text
    .globl main

main:
    # Solicitar o valor de N
    li $v0, 4
    la $a0, prompt_N
    syscall

    # Ler o valor de N
    li $v0, 5
    syscall
    move $t0, $v0       # $t0 = N

    # Verificar se N < 6
    li $t1, 6
    blt $t0, $t1, invalid_input

    # Calcular o tamanho de (N-5)
    sub $t2, $t0, 5     # $t2 = N - 5

    # Alocar memória para o array de entrada x (N * 4 bytes)
    li $v0, 9
    mul $a0, $t0, 4
    syscall
    move $s0, $v0       # $s0 aponta para o array x

    # Alocar memória para o array de saída y ((N-5) * 4 bytes)
    li $v0, 9
    mul $a0, $t2, 4
    syscall
    move $s1, $v0       # $s1 aponta para o array y

    # Ler os valores para o array de entrada x
    li $t3, 0           # Índice i = 0
read_loop:
    bge $t3, $t0, compute_y   # Se i >= N, vá para o cálculo de y

    # Exibir o prompt para x[i]
    li $v0, 4
    la $a0, prompt_value
    syscall

    # Imprimir o índice i
    li $v0, 1
    move $a0, $t3
    syscall

    # Exibir ": "
    li $v0, 4
    la $a0, end_prompt
    syscall

    # Ler o valor de x[i]
    li $v0, 5
    syscall
    sw $v0, 0($s0)      # Salvar em x[i]
    addi $s0, $s0, 4    # Avançar o ponteiro de x

    # Incrementar o índice i
    addi $t3, $t3, 1
    j read_loop

# Resetar o ponteiro do array x
reset_x_pointer:
    sub $s0, $s0, $t0, 4

# Cálculo do array y
compute_y:
    li $t3, 0           # Índice para y
    li $t4, 0           # Índice para x

compute_loop:
    bge $t4, $t2, print_x  # Se o índice de x atingir N-5, termine

    # Calcular a média móvel
    lw $t5, 0($s0)      # x[i]
    lw $t6, 4($s0)      # x[i+1]
    lw $t7, 8($s0)      # x[i+2]
    lw $t8, 12($s0)     # x[i+3]
    lw $t9, 16($s0)     # x[i+4]
    lw $a1, 20($s0)     # x[i+5]

    add $t5, $t5, $t6
    add $t5, $t5, $t7
    add $t5, $t5, $t8
    add $t5, $t5, $t9
    add $t5, $t5, $a1

    # Dividir por 6
    li $a0, 6
    div $t5, $a0
    mflo $t5

    # Salvar em y[j]
    sw $t5, 0($s1)
    addi $s1, $s1, 4    # Avançar o ponteiro de y

    # Incrementar os índices
    addi $t3, $t3, 1
    addi $s0, $s0, 4    # Avançar o ponteiro de x
    j compute_loop

# Imprimir o array de entrada x
print_x:
    li $v0, 4
    la $a0, newline
    syscall

    li $t3, 0
print_x_loop:
    bge $t3, $t0, print_y

    lw $a0, 0($s0)
    li $v0, 1
    syscall

    li $v0, 4
    la $a0, newline
    syscall

    addi $t3, $t3, 1
    addi $s0, $s0, 4
    j print_x_loop

# Imprimir o array de saída y
print_y:
    li $t3, 0
print_y_loop:
    bge $t3, $t2, exit

    lw $a0, 0($s1)
    li $v0, 1
    syscall

    li $v0, 4
    la $a0, newline
    syscall

    addi $t3, $t3, 1
    addi $s1, $s1, 4
    j print_y_loop

# Mensagem de entrada inválida
invalid_input:
    li $v0, 4
    la $a0, invalid_N
    syscall
    j main

exit:
    li $v0, 10
    syscall
