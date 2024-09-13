#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        // Proceso padre: espera 60 segundos antes de terminar
        sleep(60);
        wait(NULL);  // Recoge el proceso zombie
    } else if (pid == 0) {
        // Proceso hijo: termina de inmediato
        printf("Proceso hijo ha terminado y es ahora un zombie.\n");
    } else {
        perror("fork");
    }

    return 0;
}
