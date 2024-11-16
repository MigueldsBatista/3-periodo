.data
nome: .asciiz "MIGUEL"

.text
main:
la $a0, nome
li $v0, 4
syscall

li $v0, 10
syscall
