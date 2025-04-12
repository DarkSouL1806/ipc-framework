#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <cstring>
#include <unistd.h>

int main() {

    std::cout << "Process ID: " << getpid() << ", User ID: " << getuid() << std::endl;

    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    char* str = (char*) shmat(shmid, nullptr, 0);
    strcpy(str, "Hello from shared memory!");

    std::cout << "Data written: " << str << std::endl;

    shmdt(str);
    shmctl(shmid, IPC_RMID, nullptr);

    FILE* logFile = fopen("monitor/ipc_event.txt", "a");
    fprintf(logFile, "[SHARED_MEMORY] Used by UID %d (PID %d)\n", getuid(), getpid());
    fclose(logFile);


    return 0;
}