#include <iostream>
#include <unistd.h>
#include <cstring>

int main() {

    std::cout << "Process ID: " << getpid() << ", User ID: " << getuid() << std::endl;

    int fd[2];
    char msg[] = "Hello from parent!";
    char buffer[100];

    if (pipe(fd) == -1) {
        std::cerr << "Pipe failed\n";
        return 1;
    }

    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        read(fd[0], buffer, sizeof(buffer));
        std::cout << "Child received: " << buffer << std::endl;
    } else {
        // Parent process
        write(fd[1], msg, strlen(msg) + 1);
    }

    FILE* logFile = fopen("monitor/ipc_event.txt", "a");
    fprintf(logFile, "[PIPE] Used by UID %d (PID %d)\n", getuid(), getpid());
    fclose(logFile);


    return 0;
}

