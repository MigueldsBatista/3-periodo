.text

# Syscall para imprimir string (syscall 4)
li $v0, 4            # Carrega a syscall 4 (print string)
la $a0, .asciiz "Hello, World!\n"    # Carrega o endereço da string no argumento $a0
syscall              # Chama o kernel para executar a syscall

# Syscall para sair (syscall 10)
li $v0, 10           # Carrega a syscall 10 (exit)
syscall              # Chama o kernel para encerrar o programa
