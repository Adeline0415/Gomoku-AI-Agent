# Gomoku AI Agent

This project implements an **AI agent for the board game Gomoku (Five in a Row)** using the **Minimax algorithm with Alpha–Beta pruning**.
The agent evaluates game states through a **pattern-based heuristic function** and prunes unpromising branches to make decisions efficiently within limited time.

---

## Overview

The AI simulates human-like decision-making in Gomoku by recursively evaluating possible moves and predicting the opponent’s best responses.
It aims to select the optimal move by minimizing the opponent’s advantage and maximizing its own winning probability.

---

## Features
- Minimax algorithm with Alpha-Beta pruning for efficient game tree exploration
- Advanced evaluation function considering various patterns and dynamically adjusting search depth
- Optimized search by focusing on the neighborhood of existing pieces
- Implemented in C++ for performance and robustness

---
## Key Techniques

### **1. Minimax with Alpha–Beta Pruning**

* Uses recursive tree search to simulate future moves for both the player and opponent.
* Incorporates Alpha–Beta pruning to skip branches that cannot affect the final outcome, improving efficiency dramatically.

### **2. Heuristic Evaluation Function**

* Evaluates each board configuration by detecting patterns such as **“alive 4”, “dead 4”, “alive 3”, “dead 3”**, etc.
* Each pattern contributes a weighted score to represent the strategic advantage.
* Scanning is performed across all directions (horizontal, vertical, and diagonal).

### **3. Search Space Optimization**

* Limits the move search to cells **near existing stones** to avoid exploring irrelevant positions.
* Dynamically adjusts search depth based on game progress (e.g., fewer pieces → deeper search).

### **4. Implementation Highlights**

* Written entirely in **C++** for high performance.
* Designed with a **modular structure** including separate evaluation and search modules.
* Supports cross-platform compilation (Windows, macOS, Linux).

---

## Getting Started

### For Windows Users

1. Install mingw-w64
   - Download the MinGW-W64 Online Installer from the official website
   - Run the installer and select the appropriate options as shown in the tutorial
   - Add the path to the "mingw64/bin" directory to your system's PATH environment variable

2. Compile your code
   - Open the command prompt or PowerShell
   - Change the directory to the "src" folder of your project using `cd [project_path]/src`
   - Type `make` to compile your code

### For Mac Users

1. Install Homebrew
   - Visit the Homebrew homepage and copy the installation command
   - Paste the command into the terminal and press enter
   - Enter your password when prompted and press enter to install

2. Install Coreutils
   - Type `brew install coreutils` in the terminal
   - Verify the installation by typing `gtimeout --version`

3. Modify file permissions
   - Change the directory to the "baseline/mac" folder of your project using `cd [project_path]/baseline/mac` in the terminal
   - Type `chmod u+x *` to enable execution permissions for the baseline files
   - Right-click on each baseline file in the Finder and select "Open" to grant permission to run them

4. Compile your code
   - Change the directory to the "src" folder of your project using `cd [project_path]/src` in the terminal
   - Type `make` to compile your code

### For Windows Users (WSL)

1. Install WSL
   - Follow the WSL Installation Guide to install WSL on your Windows system
   - Restart your computer after the installation

2. Setup WSL
   - Search for Ubuntu and start it
   - Enter a new username and password for your Ubuntu environment

3. Install build-essential
   - In the Ubuntu terminal, enter `sudo apt update` and provide your password when prompted
   - Enter `sudo apt install build-essential` to install the necessary build tools
   - Validate the installation by typing `g++ --version` and `make --version`

4. Compile your code
   - In the Ubuntu terminal, change the directory to the "src" folder of your project using `cd [project_path]/src`
   - Note that the project path in WSL is different from Windows, e.g., `/mnt/c/[project_path]` instead of `C:\[project_path]`
   - Type `make` to compile your code

## Usage

### For Windows Users

- If you use cmd, type `main.exe [AI1].exe [AI2].exe` while in the "src" folder of your project
- If you use PowerShell, type `.\main.exe [AI1].exe [AI2].exe` while in the "src" folder of your project

### For Mac and WSL Users

- Type `./main ./[AI1] ./[AI2]` in the terminal while in the "src" folder of your project

Note: Replace `[AI1]` and `[AI2]` with the names of the AI executables you want to run.

## References

* [Minimax Algorithm (Wikipedia)](https://en.wikipedia.org/wiki/Minimax)
* [Alpha–Beta Pruning (Wikipedia)](https://en.wikipedia.org/wiki/Alpha%E2%80%93beta_pruning)

---

## Summary

This project demonstrates how **AI search algorithms** and **heuristic evaluation** can be combined to build an intelligent game-playing agent.
By leveraging **Alpha–Beta pruning** and **pattern-based scoring**, the agent achieves strong decision-making performance while maintaining computational efficiency.
