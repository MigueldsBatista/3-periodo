#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


pthread_rwlock_t rwlock; // Read-Write lock para controlar o acesso à área
pthread_mutex_t lock_cont; // Mutex para controle do número de escritores esperando
int nw = 0; // Número de escritores esperando

// Função para leitores
void* leitor(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock_cont);
        // Verifica se há escritores esperando
        while (nw > 0) {
            pthread_mutex_unlock(&lock_cont); // Libera o mutex e aguarda
            sched_yield(); // Evita espera ocupada
            pthread_mutex_lock(&lock_cont);
        }
        pthread_mutex_unlock(&lock_cont);
        
        // Tenta adquirir bloqueio de leitura
        pthread_rwlock_rdlock(&rwlock);
        
        printf("Leitor %d lendo.\n", *(int*)arg);
        // Simula operação de leitura
        sleep(1);
        
        // Libera o bloqueio de leitura
        pthread_rwlock_unlock(&rwlock);
        
        // Pausa para leitura repetida
        sleep(1);
    }
    return NULL;
}

// Função para escritores
void* escritor(void* arg) {
    while (1) {
        // Incrementa número de escritores esperando
        pthread_mutex_lock(&lock_cont);
        nw++;
        pthread_mutex_unlock(&lock_cont);

        // Adquire bloqueio de escrita
        pthread_rwlock_wrlock(&rwlock);
        
        printf("Escritor %d escrevendo.\n", *(int*)arg);
        // Simula operação de escrita
        sleep(2);
        
        // Libera o bloqueio de escrita
        pthread_rwlock_unlock(&rwlock);
        
        // Decrementa número de escritores esperando
        pthread_mutex_lock(&lock_cont);
        nw--;
        pthread_mutex_unlock(&lock_cont);
        
        // Pausa para escrita repetida
        sleep(3);
    }
    return NULL;
}

int main() {
    pthread_t leitores[5], escritores[2];
    int ids_leitores[5], ids_escritores[2];
    
    // Inicializa rwlock e mutex
    pthread_rwlock_init(&rwlock, NULL);
    pthread_mutex_init(&lock_cont, NULL);
    
    // Cria leitores
    for (int i = 0; i < 5; i++) {
        ids_leitores[i] = i + 1;
        pthread_create(&leitores[i], NULL, leitor, &ids_leitores[i]);
    }
    
    // Cria escritores
    for (int i = 0; i < 2; i++) {
        ids_escritores[i] = i + 1;
        pthread_create(&escritores[i], NULL, escritor, &ids_escritores[i]);
    }
    
    // Espera as threads terminarem (nunca acontece nesse caso)
    for (int i = 0; i < 5; i++) {
        pthread_join(leitores[i], NULL);
    }
    for (int i = 0; i < 2; i++) {
        pthread_join(escritores[i], NULL);
    }
    
    // Destroi rwlock e mutex
    pthread_rwlock_destroy(&rwlock);
    pthread_mutex_destroy(&lock_cont);
    
    return 0;
}
