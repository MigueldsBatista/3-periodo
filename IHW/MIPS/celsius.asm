# Passo a Passo da Conversão
#Multiplique a temperatura em Celsius por 9.
#Divida o resultado por 5.
#Adicione 32 ao resultado.

.data
pergunta_celsius: .asciiz "Digite o valor em celsius: "
resultado: .asciiz "Resultado: "

.text
main:

li $v0, 4
la $a0, pergunta_celsius
syscall

li $v0, 5                   # ler um inteiro
syscall
move $t0, $v0               # copiamos para t0 o valor lido

li, $t1, 9                  #valor que precisamos multiplicar

mult	$t0, $t1			# $t0 * $t1 = Hi and Lo registers
mflo	$t2					# copy Lo to $t2

li $t1, 5 #numero pelo qual vamos dividir

div $t2, $t1 #dividindo o valor lido por 5 que está em t1

mflo $t0 # jogamos de volta pra t0 o resultado

li $t1, 32 #numero pelo qual vamos somar

add $t2, $t0, $t1 #resultado aq da soma

li $v0, 4 #argumento pra imprimir uma string
la $a0, resultado
syscall

li $v0, 1 #argumento pra imprimir um inteiro
move $a0, $t2
syscall

