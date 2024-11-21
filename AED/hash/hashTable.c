#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10  // Define o tamanho máximo da tabela hash
#define TOMBSTONE -1   // Marca entradas excluídas para reutilização do slot

// Estrutura que representa uma entrada da tabela hash (par chave-valor)
typedef struct {
    int key;   // Chave da entrada
    int value; // Valor associado à chave
} Entry;

Entry* hashTable[TABLE_SIZE]; // Declaração da tabela hash como um array de ponteiros para Entry

// Função de hash para calcular o índice a partir de uma chave
int hash(int key) {
    return key % TABLE_SIZE; // Retorna o resto da divisão da chave pelo tamanho da tabela
}

// Insere um par chave-valor na tabela hash
void insert(int key, int value) {
    int index = hash(key);       // Calcula o índice inicial
    int originalIndex = index;   // Salva o índice inicial para detectar ciclos (tabela cheia)

    // Encontra um slot vazio ou reutilizável
    while (hashTable[index] != NULL && hashTable[index]->key != TOMBSTONE && hashTable[index]->key != key) {
        index = (index + 1) % TABLE_SIZE; // Move para o próximo índice (sondagem linear)
        if (index == originalIndex) {    // Detecta se a tabela está cheia
            printf("Table is full!\n");
            return;
        }
    }

    // Aloca memória para uma nova entrada, se necessário
    if (hashTable[index] == NULL || hashTable[index]->key == TOMBSTONE) {
        hashTable[index] = (Entry*) malloc(sizeof(Entry));
    }
    // Insere ou atualiza o par chave-valor no índice encontrado
    hashTable[index]->key = key;
    hashTable[index]->value = value;
}

// Busca um valor na tabela hash usando a chave
int search(int key) {
    int index = hash(key);       // Calcula o índice inicial
    int originalIndex = index;   // Salva o índice inicial para detectar ciclos

    // Percorre a tabela procurando pela chave
    while (hashTable[index] != NULL) {
        if (hashTable[index]->key == key) { // Chave encontrada
            return hashTable[index]->value;
        }
        index = (index + 1) % TABLE_SIZE; // Move para o próximo índice (sondagem linear)
        if (index == originalIndex) {    // Ciclo completo, chave não encontrada
            break;
        }
    }

    return -1; // Retorna -1 se a chave não for encontrada
}

// Remove uma entrada da tabela hash usando a chave
void delete(int key) {
    int index = hash(key);       // Calcula o índice inicial
    int originalIndex = index;   // Salva o índice inicial para detectar ciclos

    // Percorre a tabela procurando pela chave
    while (hashTable[index] != NULL) {
        if (hashTable[index]->key == key) { // Chave encontrada
            hashTable[index]->key = TOMBSTONE; // Marca o slot como excluído
            hashTable[index]->value = 0;      // Opcional: limpa o valor
            return;
        }
        index = (index + 1) % TABLE_SIZE; // Move para o próximo índice
        if (index == originalIndex) {    // Ciclo completo, chave não encontrada
            break;
        }
    }

    printf("Key not found for deletion!\n"); // Mensagem se a chave não for encontrada
}

// Exibe o conteúdo da tabela hash
void displayTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        // Verifica se o slot está ocupado e não é um "túmulo" (exclusão)
        if (hashTable[i] != NULL && hashTable[i]->key != TOMBSTONE) {
            printf("Index %d: Key = %d, Value = %d\n", i, hashTable[i]->key, hashTable[i]->value);
        } else {
            printf("Index %d: ~\n", i); // Exibe "~" para slots vazios ou excluídos
        }
    }
}


// Função principal para testar as operações da tabela hash
int main() {
    insert(1, 10);  // Insere chave 1 com valor 10
    insert(2, 20);  // Insere chave 2 com valor 20
    insert(12, 30); // Insere chave 12, causa colisão com chave 2
    insert(22, 40); // Insere chave 22, causa mais colisões

    displayTable(); // Exibe o estado atual da tabela hash

    printf("\n\nValor na chave 12: %d\n", search(12)); // Busca e exibe o valor da chave 
