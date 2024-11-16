#Replicar
# a) for(i=0;i<=10;i++)
# printf("%d\n",i);

#Para implementar usamos a ideia dos branches e de voltar ao ponto específico do código usando j(ump)
#addi add immediate adiciona um valor imediato a um registrador

#os 3 valores de addi são registrador de destino, registrador de origem e valor imediato



.data
new_line: .asciiz "\n"

.text
main:
li $t1, 10
li $t0, 0

loop_start:
jal print_value # jump to print value
jal print_newline
addi $t0, $t0, 1
bgt $t0, $t1, end_loop

j loop_start 

print_value:
li $v0, 1
move $a0, $t0
syscall
jr $ra #retorna ao ponto de chamada

print_newline:
li $v0, 4
la $a0, new_line
syscall
jr $ra #retorna ao ponto de chamada

end_loop:
li $v0, 10
syscall