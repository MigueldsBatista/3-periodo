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
.globl   
factorial: