.data
primeiro_termo: .word 0
razao: .word 0
qnt: .word 0
prompt_primeiro_termo: .asciiz "Digite o primeiro termo: "
prompt_razao: .asciiz "\nDigite a razão: "
prompt_qnt: .asciiz "\nDigite a quantidade de termos desejada: "
newline: .asciiz "\n"

.text
main:
    # Le o primeiro termo
    la $a0, prompt_primeiro_termo
    jal print_and_read
    move $t0, $v0  # Armazena o primeiro termo em $t0

    # Le a razão
    la $a0, prompt_razao
    jal print_and_read
    move $t1, $v0  # Armazena a razão em $t1

    # Le a quantidade de termos
    la $a0, prompt_qnt
    jal print_and_read
    move $t2, $v0  # Armazena a quantidade de termos em $t2

    # Inicializa o contador e imprime a PA
    li $t3, 0       # Contador de termos
    move $t4, $t0   # Termo atual da PA

imprimir_pa:
    # Imprime o termo atual
    move $a0, $t4
    li $v0, 1
    syscall

    # Imprime nova linha
    la $a0, newline
    li $v0, 4
    syscall

    # Atualiza o termo atual: termo = termo + razão
    add $t4, $t4, $t1

    # Incrementa o contador
    addi $t3, $t3, 1

    # Verifica se alcançou a quantidade de termos
    blt $t3, $t2, imprimir_pa

    # Finaliza o programa
    li $v0, 10
    syscall

# Função para imprimir a mensagem e ler um inteiro
print_and_read:
    li $v0, 4          # Imprime a string
    syscall
    li $v0, 5          # Lê o inteiro
    syscall
    jr $ra             # Retorna para o chamador
