.data
prompt: .asciiz "Digite a posição de um número na sequencia de fibbo para saber o correspondente: "
output: .word 0


.text
main:
la $a0, prompt
li $v0, 4
syscall


li $v0, 5
syscall

move $a0, $v0

jal fibbonaci

sw $v0, output

lw $a0, output
li $v0, 1
syscall


j end
#em tese ele precisa entrar na função, ai ele vai ate o caso base de n-1 da sequencia, 
#depois quando ele voltar ele vai ate o caso base de n-2 da sequencia

fibbonaci:
addi $sp, $sp, -8
sw $ra, 0($sp)
sw $s0, 4($sp)

li $v0, 1
beq $a0, 1, one_case
beq $a0, $zero, zero_case

move $s0, $a0

addi $a0, $a0, -1

jal fibbonaci

move $t0, $v0

move $a0, $s0
addi $a0, $a0, -2

jal fibbonaci
move $t1, $v0

add $v0, $t0, $t1


return:
    lw $ra, 0($sp)           # Restaurar o endereço de retorno
    lw $s0, 4($sp)           # Restaurar o valor de $s0
    addi $sp, $sp, 8         # Restaurar o ponteiro da pilha
    jr $ra                   # Retornar para a função chamadora
    
#isso aq vai fazer ele voltar pra depois da recursão pra fazer o necessario
zero_case:
    li $v0, 0                # Retornar 0
    j return

# Caso base 1
one_case:
    li $v0, 1                # Retornar 1
    j return

end:
    li $v0, 10               # Finalizar o programa
    syscall