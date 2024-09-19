#include <semaphore.h>

int main(int argc, char *argv[]) {
    if(argc!=2) {
        printf("Usage: %s <semaphore name>\n", argv[0]);
        return -1;
    }

    char *block = attatch_semaphore(argv[1]);

    return 0;
}