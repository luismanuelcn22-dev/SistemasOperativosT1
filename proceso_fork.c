#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // Crear un nuevo proceso
    pid = fork();

    if (pid < 0) {
        // Error al crear el proceso
        perror("Error al ejecutar fork()");
        return 1;
    } 
    else if (pid == 0) {
        // --- PROCESO HIJO ---
        // Imprime números del 10,000 al 1
        for (int i = 10000; i >= 1; i--) {
            printf("[HIJO]  %d\n", i);
            fflush(stdout); // Sincroniza la salida estándar
        }
        exit(0);
    } 
    else {
        // --- PROCESO PADRE ---
        // Imprime números del 1 al 10,000
        for (int i = 1; i <= 10000; i++) {
            printf("[PADRE] %d\n", i);
            fflush(stdout); // Sincroniza la salida estándar
        }

        // Espera a que el proceso hijo termine antes de finalizar
        wait(NULL);
    }

    return 0;
}