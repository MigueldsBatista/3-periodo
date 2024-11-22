.data 
prompt: .asciiz "Digite a posi��o de um n�mero da sequ�ncia de fibbonaci: "
output: .asciiz "O num�ro nesta posi��o �: "

.text
main:
la $a0, prompt
jal print_string
jal read

move $a0, $v0
jal fibboanci

#Carrega o resultado
sw $v0, output
lw $a0, output
jal print_integer
#Finaliza a execu��o do programa 
j end


# deffibbonaci(int num):
#   if(num==0 or num ==1)
#       return num
#   else:
#       return fibbonaci(num-1)+fibbonaci(num-2)

#passos
#calcular o valor de fibbonaci

# 1. salvar o endere�o de retorno na pilha
# 2. salvar o valor de n original na pilha
# 3. salvar o valor da primeira chamada na pilha

# 4. usar esse valor na segunda chamada de n
# 5. salvar o valor da segunda chamada e adicionar os dois e retornar

fibboanci:
    addi $sp, $sp, -12 # Reservamos espa�o na pilha pra 3 opera��es de push
    sw $ra, 0($sp)            # Salvamos o endere�o de retorno na pilha
    sw $s0, 4($sp)             # Salvamos o valor da vez da sequencia
    sw $a0, 8($sp)

    # Caso base: fib(0) = 0 e fib(1) = 1
    li $v0, 0
    beq $a0, $v0, base  # Se n == 0, retorna 0

    li $v0, 1
    beq $a0, $v0, base  # Se n == 1, retorna 1


    addi $a0, $a0, -1 # n-1
    jal fibboanci     # enter fib(n-1)
    move $s0, $v0     # save the return

    lw $a0, 8($sp)    # restores the value of n
    addi $a0, $a0, -2
    jal fibboanci

    add $v0, $v0, $s0


base:
    lw $ra, 0($sp)            # Restauramos o endere�o de retorno na pilha
    lw $a0, 4($sp)            # Restauramos o valor do argumento da chamada
    lw $s0, 8($sp)             # Restauramos o valor da vez da sequencia
    addi $sp, $sp, 12 # Reservamos espa�o na pilha pra 3 opera��es de push
    jr $ra

print_string:
    li $v0, 4
    syscall
    jr $ra

print_integer:
    li $v0, 1
    syscall
    jr $ra

read:
    li $v0, 5
    syscall
    jr $ra

end:
    li $v0, 10
    syscall