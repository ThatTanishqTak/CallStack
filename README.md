<h1 align="center">🧠 CallStack</h1>
<p align="center">
  <em>A modern reimagining of the Windows Command Prompt — built in C++23 with performance, modularity, and extensibility in mind.</em>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-23-blue?logo=c%2B%2B" alt="C++23">
  <img src="https://img.shields.io/badge/Build-CMake-informational?logo=cmake" alt="CMake">
  <img src="https://img.shields.io/badge/Compiler-MSVC-orange?logo=visualstudio" alt="MSVC">
  <img src="https://img.shields.io/badge/Editor-VS%20Code-007ACC?logo=visualstudiocode" alt="VSCode">
  <img src="https://img.shields.io/badge/Status-Pre--Alpha-lightgrey" alt="Status">
  <img src="https://img.shields.io/badge/License-Apache-green" alt="License">
</p>

---

## 🚀 Overview

**CallStack** is a custom terminal and shell that recreates the core functionality of **Windows CMD**, implemented with modern C++ architecture for **speed, maintainability, and scalability**.  
Short-term, the goal is feature parity with classic CMD. Long-term, CallStack evolves into a modular, extensible developer console with first-class scripting, plugins, and cross-platform support.

---

## ✨ Project Goals

- **MVP parity with CMD**: robust internal commands, external process execution, history, and a configurable prompt  
- **Modern architecture**: C++23, clean layering, and OS abstraction to future-proof the design  
- **Developer focus**: predictable behavior, readable code, and a clear contribution workflow

---

## 🧩 Current Scope (MVP)

The first milestone targets the essentials: parsing, built-ins, process handling, and a solid foundation for growth.

### ✅ Core Features
- Command parser and tokenizer
- Built-in internal commands:
  - `dir` / `ls`
  - `cd`
  - `cls`
  - `exit`
  - `echo`
  - `help`
- Execution of external programs
- Command history buffer
- Configurable prompt (username, path, etc.)
- OS abstraction layer (Windows first)

---

## 🧠 Architecture Overview

CallStack/
│
├── src/
│   ├── BuiltinCommands.cpp
│   ├── BuiltinCommands.h
│   ├── CommandParser.cpp
│   ├── CommandParser.h
│   ├── Main.cpp
│   ├── Shell.cpp
│   └── Shell.h
│
├── CMakeLists.txt # Build configuration
└── README.md

Current modules:
- **Shell** (`Shell.cpp` / `Shell.h`): orchestrates the main loop, routing parsed commands to the appropriate handlers.
- **CommandParser** (`CommandParser.cpp` / `CommandParser.h`): tokenizes user input and produces command structures the shell can execute.
- **BuiltinCommands** (`BuiltinCommands.cpp` / `BuiltinCommands.h`): implements the built-in commands available in the MVP.

_Future structure:_ as functionality expands, expect dedicated `Core`, `Commands`, and `System` directories alongside a public `include/` tree to keep headers organized.


### Tech Stack
| Component | Technology |
|------------|-------------|
| **Language** | C++23 |
| **Build System** | CMake |
| **Compiler** | MSVC (Windows) |
| **Editor** | Visual Studio Code |
| **Testing (Planned)** | GoogleTest / Catch2 |

---

## 🧱 Development Roadmap

### **Phase 1: Core System (MVP)**
- [ ] Command parsing engine  
- [ ] Built-in commands (`dir`, `cd`, `cls`, etc.)  
- [ ] Process creation for external commands  
- [ ] Command history support  
- [ ] Customizable prompt  

### **Phase 2: Usability & Configuration**
- [ ] Colored output and syntax highlights  
- [ ] Config file support (`callstack.cfg`)  
- [ ] Environment variables and aliases  
- [ ] Enhanced error handling  

### **Phase 3: Advanced Features**
- [ ] Tab completion for commands and paths  
- [ ] Piping and redirection (`|`, `>`, `<`)  
- [ ] Background processes and multitasking  
- [ ] Batch/shell scripting support (`.csb` files)  

### **Phase 4: Future Expansion**
- [ ] Plugin system with runtime DLL/SO loading  
- [ ] Optional scripting engine (Lua or Python)  
- [ ] Cross-platform support (Linux, macOS)  
- [ ] GUI hybrid terminal with live console widgets  
- [ ] Networking tools (remote command execution, SSH integration)  

---

## 🌌 Long-Term Vision

CallStack is designed to evolve beyond a command line into a **developer console ecosystem**.  
Future versions may include:
- Integrated **extension and package manager**  
- **AI-assisted command suggestions** and natural-language execution  
- System stats overlay (CPU, RAM, network)  
- Scriptable automation workflows  
- Plugin API for third-party tools  

---

## 🛠️ Build & Run

### Prerequisites
- **CMake 3.28+**
- **Visual Studio Build Tools 2022**
- **VS Code with CMake Tools Extension**

### Build Instructions
```bash
# Clone the repository
git clone https://github.com/yourusername/CallStack.git
cd CallStack

# Configure project
cmake -B build -G "Ninja" -DCMAKE_BUILD_TYPE=Debug

# Build executable
cmake --build build

# Run (Windows)
./build/CallStack.exe
```