#3 - crie um algoritmo que receba duas notas e o percentual de frequência.
#Calcule a Média e exiba a média das notas

#li - load immetidate //atribui um valor constante a um registrador

.data
pergunta_nota1: .asciiz "Digite a primeira nota: "
pergunta_nota2: .asciiz "Digite a segunda nota: "
pergunta_frequencia: .asciiz "Digite a frequência: "
frequencia: .asciiz "Frequência: "
resultado: .asciiz "Media: "
aprovado_string: .asciiz "\nAprovado!"
reprovado_string: .asciiz "\nReprovado!"
media: .word 7
media_frequencia: .word 75
#Com o algoritmo do problema 3 informe se o aluno foi aprovado. ( aprovado média >=7 e frequência >= 75)
.text
main:

lw $s3, media
lw $s4, media_frequencia

li $v0, 4 # imprimir uma string
la $a0, pergunta_frequencia
syscall

li $v0, 5
syscall
move $s0, $v0

li $v0, 4 # imprimir uma string
la $a0, pergunta_nota1
syscall

li $v0, 5 # receber um inteiro
syscall
move $t0, $v0 # movemos para t0 o valor lido que foi armazenado em v0

#Simula entrada da primeira nota

li $v0, 4 # imprimir uma string
la $a0, pergunta_nota2
syscall

li $v0, 5 # receber um inteiro
syscall
move $t1, $v0 # movemos para t0 o valor lido que foi armazenado em v0

add $t2, $t0, $t1 # soma t0 e t1 e manda pra t2

li $t3, 2

div $t2, $t3
mflo $s1

li $v0, 4 # imprimir um inteiro
la $a0, frequencia # o resultado da entrada da frequencia
syscall


li $v0, 1 # imprimir um inteiro
move $a0, $s0 # o resultado da entrada da frequencia
syscall

li $v0, 4 # imprimir uma string
la $a0, resultado
syscall


li $v0, 1
move $a0, $s1
syscall


blt $s1, $s3, reprovado
blt $s0, $s4, reprovado

j aprovado 

aprovado:
li, $v0, 4
la, $a0, aprovado_string
syscall
j end

reprovado:
li, $v0, 4
la, $a0, reprovado_string
syscall
j end


end:
li $v0, 10
syscall



