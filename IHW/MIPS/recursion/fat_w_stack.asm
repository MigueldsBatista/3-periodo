.data
prompt: .asciiz "Enter a number to find its factorial: "
result: .asciiz "\nThe factorial of the number is:  "
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
	
	#call the factorial function
	
	
	lw $a0, number		#add the number as an argument to the factorial function
	jal factorial
    
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
#find factorial function

#store the local variables and the return address to the stack

.globl factorial
factorial:
	#8 bits in total 4 to the return address and 4 to the local variable
	addi $sp, $sp, -8
	sw $ra, 0($sp) 		#store the return address on top of the stack
	sw $s0, 4($sp)		#store the current state of the factorial on the below the top
	
	#base case
if_base_case:
	li $v0, 1
	beq $a0, $v0, baseCase
	beq $a0, $zero, baseCase

else:
    #move to from
	move $s0, $a0 		#move the content of $s0 to $a0
    #sub to from minus
	subi $a0, $a0, 1	#decreases $a0 <=> (n-1)

	jal factorial       #jump and link to factorial with argument n-1
	

	mul $v0, $s0, $v0	#the value of return is the previous returned values times the current state of the factorial result

baseCase:
	lw $ra, 0($sp)      #address that was saved in the last callc
	lw $s0, 4($sp)
	addi $sp, $sp, 8
	jr $ra