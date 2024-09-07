#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define PESSOAS_APERTADAS 10

typedef struct {
    pthread_mutex_t chaveDoBanheiro;//Encapsulamento (Banheiro vai estar bem trancado)
    int senhaAbencoada;
} Banheiro;

void abrirBanheiro(Banheiro *banheiro) {
    pthread_mutex_init(&banheiro->chaveDoBanheiro, NULL);
    banheiro->senhaAbencoada = 0;
}

void entrarNoBanheiro(Banheiro *banheiro) {//lock
    pthread_mutex_lock(&banheiro->chaveDoBanheiro);//hora de iniciar as necessidades 💩
}

void sairDoBanheiro(Banheiro *banheiro) {
    pthread_mutex_unlock(&banheiro->chaveDoBanheiro);//hora do alivio
}

void matarEncanador(Banheiro *banheiro) {
    pthread_mutex_destroy(&banheiro->chaveDoBanheiro);//hora de acabar com a vida do encanador
}

void* pessoaNoBanheiro(void* arg) {
    Banheiro *banheiro = (Banheiro*)arg;

    usleep(rand() % 500000);

    entrarNoBanheiro(banheiro);

    banheiro->senhaAbencoada++;
    printf("Pessoa %d entrou no banheiro e pegou a chave para fazer suas necessidades! senhaAbencoada: %d\n", pthread_self(), banheiro->senhaAbencoada);

    usleep(2000000);//💩💩💩💩💩

    printf("Pessoa %d terminou e está aliviada! Senha do 💩: %d\n", pthread_self(), banheiro->senhaAbencoada);

    sairDoBanheiro(banheiro);

    return NULL;
}

int main() {
    Banheiro banheiro;
    pthread_t pessoas[PESSOAS_APERTADAS];//Numero de pessoas apertadas

    abrirBanheiro(&banheiro);

    //Recepcionista do banheiro
    for(int i = 0; i < PESSOAS_APERTADAS; ++i) {
        //numero de pessoas que vao usar o banheiro | pessoas não apertadas(NULL)| Oq a pessoa vai fazer no banheiro | O banheiro que a pessoa vai fazer suas necessidades
        pthread_create(&pessoas[i], NULL, pessoaNoBanheiro, &banheiro);
    }

    // Espera pelas pessoas terminarem terminarem de usar o banheiro
    for(int i = 0; i < PESSOAS_APERTADAS; ++i) {
        pthread_join(pessoas[i], NULL);
    }

    matarEncanador(&banheiro);
    return 0;
}
