# Makefile for IPC Framework

all: pipe msg_queue shared_memory

pipe: src/pipe.cpp
	g++ src/pipe.cpp -o pipe

msg_queue: src/msg_queue.cpp
	g++ src/msg_queue.cpp -o msg_queue

shared_memory: src/shared_memory.cpp
	g++ src/shared_memory.cpp -o shared_memory

clean:
	rm -f pipe msg_queue shared_memory
