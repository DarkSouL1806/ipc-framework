/*
  pipe.cpp - Inter-Process Communication using Unnamed Pipes

  This program demonstrates how a parent process can send a message to a child
  process using an unnamed pipe. It also logs the usage event to a monitor file
  for tracking IPC usage.
*/

#include <iostream>     // For standard I/O
#include <unistd.h>     // For pipe(), fork(), getpid(), getuid()
#include <cstring>      // For string functions like strlen()

int main() {

    // Display current process ID and user ID
    std::cout << "Process ID: " << getpid() << ", User ID: " << getuid() << std::endl;

    int fd[2];                          // File descriptors: fd[0] = read, fd[1] = write
    char msg[] = "Hello from parent!"; // Message to send
    char buffer[100];                  // Buffer to receive message

    // Create a pipe
    if (pipe(fd) == -1) {
        std::cerr << "Pipe failed\n";
        return 1;
    }

    // Fork the current process
    pid_t pid = fork();

    if (pid == 0) {
        // 👶 Child process
        read(fd[0], buffer, sizeof(buffer)); // Read from pipe
        std::cout << "Child received: " << buffer << std::endl;
    } else {
        // 👨 Parent process
        write(fd[1], msg, strlen(msg) + 1);  // Write to pipe
    }

    // Log IPC usage for tracking (used by Python monitor)
    FILE* logFile = fopen("monitor/ipc_event.txt", "a");
    fprintf(logFile, "[PIPE] Used by UID %d (PID %d)\n", getuid(), getpid());
    fclose(logFile);

    return 0;
}
