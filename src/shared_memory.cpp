/*
  shared_memory.cpp - IPC using Shared Memory

  This program demonstrates inter-process communication using System V Shared Memory.
  It writes a message into a shared memory segment and logs the usage for monitoring.

  Author: Gaurav Singh Tanwar
  Date: April 2025
*/

#include <iostream>     // For standard input/output
#include <sys/ipc.h>    // For ftok()
#include <sys/shm.h>    // For shmget(), shmat(), shmdt(), shmctl()
#include <cstring>      // For strcpy()
#include <unistd.h>     // For getpid(), getuid()

int main() {

    // Display the current process ID and user ID
    std::cout << "Process ID: " << getpid() << ", User ID: " << getuid() << std::endl;

    // Generate a unique key using ftok
    key_t key = ftok("shmfile", 65);

    // Create a shared memory segment of size 1024 bytes with permissions
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    // Attach the shared memory to the process's address space
    char* str = (char*) shmat(shmid, nullptr, 0);

    // Write a message into shared memory
    strcpy(str, "Hello from shared memory!");

    // Output the written message
    std::cout << "Data written: " << str << std::endl;

    // Detach the shared memory segment
    shmdt(str);

    // Destroy the shared memory segment
    shmctl(shmid, IPC_RMID, nullptr);

    // Log this IPC activity to be picked up by Python monitor
    FILE* logFile = fopen("monitor/ipc_event.txt", "a");
    fprintf(logFile, "[SHARED_MEMORY] Used by UID %d (PID %d)\n", getuid(), getpid());
    fclose(logFile);

    return 0;
}
