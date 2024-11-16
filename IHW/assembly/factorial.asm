.data 
prompt: .asciiz "Digite um número para saber seu fatorial"
input: .word 0
output: .word 0
#logica de printar o prompt
#logica de ler do teclado
#logica de passar o argumento pra funcao

#logica de pegar de volta o resultado

#logica de printar o resultado

#logica de finalizar o programa
.text
#imprimir o prompt
li $v0, 4
la $a0, prompt
syscall

#ler um inteiro do teclado
li $v0, 5
syscall

#adicione o argumento para função
move $a0, $v0

#entra na função fatorial
jal fatorial

#guarda o resultado na word output
la $t0, $v0
sw $v0, output

#imprime o resultado
li $v0, 1
lw $a0, output
syscall

j end

factorial:
add $sp, $s0, -8 #PUSH
sw $ra, 0($sp) #salva o endereço de retorno (main na primeira chamada)
sw $s0, 4($sp) #salva o estado atual de s0 (vazio na primeira chamada)

beq $a0, 1, base
beq $a0, $zero, base

else:
move $s0, $a0
addi $a0, $a0, -1
jal factorial

mul $v0, $v0, $s0

#vai ser executado a mesma quantidade de vezes que a função recursiva for chamada
base:
lw $ra, 0($sp)
lw $s0, 4($sp)
addi $sp, $sp, 8 #POP
jr $ra


end:
li $v0, 10
syscall


