.data
tamanho: .word 5 # Tamanho de um array array

.text
main:
    # Carregar o tamanho do array
    la $t2, tamanho        # Carrega o endereço da variável 'tamanho'
    lw $t3, 0($t2)         # Carrega o valor de 'tamanho' em $t3