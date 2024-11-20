.data
prompt: .asciiz "\nDigite a operação que você deseja realizar: \n1-Adição\n2-Subtração\n3-Multiplicação\n4-Divisão\n0-Sair\n"
prompt_first: .asciiz "Digite o primeiro número: "
prompt_second: .asciiz "\nDigite o segundo número: "
prompt_result: .asciiz "\nO resultado da operação é: "
output: .word 0

.text
main:

la $a0, prompt
jal print_string
jal read_integer

beq $v0, $zero, end

beq $v0, 1, adicao
beq $v0, 2, subtracao
beq $v0, 3, multiplicacao
beq $v0, 4, divisao

display_result:
la $a0, prompt_result
jal print_string

move $a0, $s0
jal print_integer

j main

adicao:
#Display and read the first number from user
la $a0, prompt_first
jal print_string
jal read_integer

#Store the first value retrived
move $t0, $v0

#Display and second read the number from user
la $a0, prompt_second
jal print_string
jal read_integer

#Store the second value retrived
move $t1, $v0

add $s0, $t0, $t1
j display_result

subtracao:
#Display and read the first number from user
la $a0, prompt_first
jal print_string
jal read_integer

#Store the first value retrived
move $t0, $v0

#Display and second read the number from user
la $a0, prompt_second
jal print_string
jal read_integer

#Store the second value retrived
move $t1, $v0

sub $s0, $t0, $t1
j display_result

multiplicacao:
#Display and read the first number from user
la $a0, prompt_first
jal print_string
jal read_integer

#Store the first value retrived
move $t0, $v0

#Display and second read the number from user
la $a0, prompt_second
jal print_string
jal read_integer

#Store the second value retrived
move $t1, $v0

mul $s0, $t0, $t1
j display_result


divisao:
#Display and read the first number from user
la $a0, prompt_first
jal print_string

jal read_integer

#Store the first value retrived
move $t0, $v0

#Display and second read the number from user
la $a0, prompt_second
jal print_string
jal read_integer

#Store the second value retrived
move $t1, $v0

div $t0, $t1
mflo $s0

j display_result

#Utils

print_string:
li $v0, 4
syscall
jr $ra

print_integer:
li $v0, 1
syscall
jr $ra

read_integer:
li $v0, 5
syscall
jr $ra


end:
    li $v0, 10
    syscall
