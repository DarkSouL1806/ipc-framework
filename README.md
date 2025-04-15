![Language](https://img.shields.io/badge/language-C++%20%7C%20Python-blue)
![Status](https://img.shields.io/badge/status-Completed-brightgreen)
![GitHub Commits](https://img.shields.io/github/commit-activity/m/DarkSouL1806/ipc-framework)


# IPC Framework – Inter-Process Communication System

This project is a **C++ and Python-based IPC framework** that facilitates secure and efficient inter-process communication using:

- 🔹 **Unnamed Pipes**
- 🔹 **Message Queues**
- 🔹 **Shared Memory Segments**
- 🛡️ **Security Logging**
- 🐍 **Real-time Monitoring using Python**

---

## 📁 Project Structure

```
ipc_framework/
├── src/                  # C++ source files for IPC
│   ├── pipe.cpp
│   ├── msg_queue.cpp
│   ├── shared_memory.cpp
├── monitor/              # Python logger and event monitor
│   ├── ipc_logger.py
│   └── ipc_event.txt
├── ipc_log.txt           # Final log output after monitoring
├── Makefile              # Build system for C++ code
└── README.md
```

---

## ⚙️ Features

| IPC Type        | Language | Description                                      |
|-----------------|----------|--------------------------------------------------|
| Unnamed Pipe    | C++      | One-way communication between parent-child       |
| Message Queue   | C++      | POSIX queue with structured message passing      |
| Shared Memory   | C++      | Fast memory sharing between processes            |
| Logger          | Python   | Monitors and logs all IPC usage to `ipc_log.txt` |
| Security        | C++/Py   | User ID and process ID tracking for every IPC    |

---

## 🚀 How to Run the Project

### 🛠 Step 1: Build the C++ Programs

```
make
```

### 🖥️ Step 2: Start the Python Monitor

```
cd monitor
python3 ipc_logger.py
```

Leave this terminal running.

### 🚦 Step 3: Run the IPC Programs

In another terminal:

```
./pipe
./msg_queue
./shared_memory
```

### 📜 Step 4: Check Logs

```
cat ipc_log.txt
```

---

## 🔐 Security Features

- Each IPC execution logs:
  - `Process ID`
  - `User ID`
  - IPC type used
- Python monitor watches `ipc_event.txt` and writes to `ipc_log.txt` with timestamps.

---

## 👨‍💻 Technologies Used

- **C++**
- **Python 3**
- **Makefile**
- **Linux System Calls**: `fork()`, `pipe()`, `msgget()`, `shmget()`, etc.

---

## 📈 GitHub Workflow Followed

- ✅ Multiple commits with meaningful messages
- ✅ Feature branches used for testing modules
- ✅ Merged stable features into `main` after testing
- ✅ Public repo for easy evaluation

---

---

## 🙌 Acknowledgements

- Project developed as part of the Operating Systems course at Lovely Professional University.
- Thanks to faculty for guidance and evaluation.

## 📬 Contact

If you have any questions or suggestions:
- GitHub: [DarkSouL1806](https://github.com/DarkSouL1806)