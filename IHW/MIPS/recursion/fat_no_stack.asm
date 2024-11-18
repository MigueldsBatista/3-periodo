.data
prompt: .asciiz "Enter a number to find its fatorial: "
result: .asciiz "\nThe fatorial of the number is:  "
answer: .word 0
number: .word 0

#Em asselmby geralmente as chamadas seguem um modelo to from

.text
	.globl main
	main:
	#display the prompt message
	li $v0, 4
	la $a0, prompt
	syscall
    
	li $v0, 5		#read the number from the standard output
	syscall
	
	sw $v0, number		#store the value of $v0 in number
	
	#call the fatorial function
	
	
	lw $a0, number		#add the number as an argument to the fatorial function
	jal fatorial
    
	#retriving the function result
	
    
	sw $v0, answer		#store the value of $v0 in answer
	
    
	li $v0, 1		#syscall to print an integer
	lw $a0, answer		#load adress of answer in $a0
	syscall
	
	j end
	
	end:
	li $v0, 10
	syscall
#-------------------------------------------------------------------
#find fatorial function

#store the local variables and the return address to the stack

.globl fatorial
# fatorial (n)
fatorial:
    # Caso base: Se n <= 1, retornar 1
    li $t0, 1            # Carregar 1 no registrador $t0 (valor do caso base)
    bge $a0, $t0, verifica_recursao   # Se n >= 1, vamos fazer a recursão

    # Caso base: Se n <= 1
    move $v0, $t0        # Retorna 1 como resultado (caso base)
    jr $ra               # Retorna para o endereço de retorno

verifica_recursao:
    # Preparar a chamada recursiva
    move $t1, $a0        # Salvar o valor atual de n em $t1
    subi $a0, $a0, 1     # Decrementar n para chamar fatorial(n-1)
    jal fatorial         # Chama fatorial(n-1)
    
    # Multiplicar o resultado da recursão por n
    mul $v0, $v0, $t1    # Multiplicar fatorial(n-1) pelo valor original de n
    jr $ra               # Retorna para o endereço de retorno
