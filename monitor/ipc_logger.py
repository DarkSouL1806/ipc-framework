"""
ipc_logger.py - Logs IPC events written by C++ modules to ipc_log.txt
Author: Gaurav Singh Tanwar
Date: April 2025

This Python script continuously monitors 'ipc_event.txt', 
reads new IPC activity written by the C++ programs, 
and appends timestamped logs to 'ipc_log.txt' for centralized tracking.
"""

import os
import time

# Define the path to the main log file where all events are stored
log_path = "../ipc_log.txt"

# Define the path to the temporary event file written by C++ modules
event_path = "ipc_event.txt"

print("✅ IPC Monitor Started. Watching for events...")

def log_to_file(message):
    """Append a timestamped message to ipc_log.txt"""
    with open(log_path, "a") as f:
        f.write(f"[{time.ctime()}] {message}\n")

# Continuous loop to monitor the event file in real-time
while True:
    # If the event file exists, read its contents
    if os.path.exists(event_path):
        # Open and read all lines from the event file
        with open(event_path, "r") as f:
            lines = f.readlines()

        # Delete the event file after reading to avoid repeated logs
        os.remove(event_path)

        # Log each event line to the main log file with a timestamp
        for line in lines:
            log_to_file(line.strip())

    # Wait for 2 seconds before checking again
    time.sleep(2)
