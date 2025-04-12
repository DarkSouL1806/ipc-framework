import os
import time

log_path = "../ipc_log.txt"
event_path = "ipc_event.txt"

print("✅ IPC Monitor Started. Watching for events...")

def log_to_file(message):
    with open(log_path, "a") as f:
        f.write(f"[{time.ctime()}] {message}\n")

while True:
    if os.path.exists(event_path):
        with open(event_path, "r") as f:
            lines = f.readlines()

        os.remove(event_path)

        for line in lines:
            log_to_file(line.strip())

    time.sleep(2)
