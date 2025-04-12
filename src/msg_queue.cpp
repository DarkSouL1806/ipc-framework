#include <iostream>             // For standard I/O
#include <sys/ipc.h>            // For IPC (Inter-Process Communication) mechanisms
#include <sys/msg.h>            // For message queue functions
#include <cstring>              // For string manipulation (strcpy)
#include <unistd.h>             // For getpid() and getuid()

// Define a structure for message buffer
struct message_buffer {
    long msg_type;              // Message type (must be > 0)
    char msg_text[100];         // Message data
};

int main() {

    // Display process ID and user ID
    std::cout << "Process ID: " << getpid() << ", User ID: " << getuid() << std::endl;

    // Generate a unique key for the message queue using ftok
    key_t key = ftok("progfile", 65);

    // Create or access a message queue with read & write permissions for the owner
    int msgid = msgget(key, 0666 | IPC_CREAT);

    // Declare message structure
    message_buffer message;

    // Set the message type (must be > 0)
    message.msg_type = 1;

    // Copy the message text into the message buffer
    strcpy(message.msg_text, "Hello from message queue!");

    // Send the message to the queue
    msgsnd(msgid, &message, sizeof(message), 0);
    std::cout << "Sent: " << message.msg_text << std::endl;

    // Receive a message from the queue with type = 1
    msgrcv(msgid, &message, sizeof(message), 1, 0);
    std::cout << "Received: " << message.msg_text << std::endl;

    // Delete the message queue after usage
    msgctl(msgid, IPC_RMID, NULL);

    // Log the IPC usage event to the ipc_event.txt file inside the monitor directory
    FILE* logFile = fopen("monitor/ipc_event.txt", "a");
    fprintf(logFile, "[MSG_QUEUE] Used by UID %d (PID %d)\n", getuid(), getpid());
    fclose(logFile);

    return 0;
}
