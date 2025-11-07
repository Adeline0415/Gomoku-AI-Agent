# Gomoku AI Agent

This project implements an **AI agent for the board game Gomoku (Five in a Row)** using the **Minimax algorithm with Alpha–Beta pruning**.
The agent evaluates game states through a **pattern-based heuristic function** and prunes unpromising branches to make decisions efficiently within limited time.

---

## Overview

The AI simulates human-like decision-making in Gomoku by recursively evaluating possible moves and predicting the opponent’s best responses.
It aims to select the optimal move by minimizing the opponent’s advantage and maximizing its own winning probability.

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

## ⚙️ Build & Run

```bash
# Compile
g++ -O2 -std=c++17 -o gomoku_ai project.cpp

# Execute
./gomoku_ai input.txt output.txt
```

The program reads the current game state from `input.txt` and writes the next move to `output.txt`.

---

## Example

**Input (`state`):**

```
1
0 0 0 ...
0 0 0 ...
...
```

**Output (`action`):**

```
7 8
```

---

## References

* [Minimax Algorithm (Wikipedia)](https://en.wikipedia.org/wiki/Minimax)
* [Alpha–Beta Pruning (Wikipedia)](https://en.wikipedia.org/wiki/Alpha%E2%80%93beta_pruning)

---

## Summary

This project demonstrates how **AI search algorithms** and **heuristic evaluation** can be combined to build an intelligent game-playing agent.
By leveraging **Alpha–Beta pruning** and **pattern-based scoring**, the agent achieves strong decision-making performance while maintaining computational efficiency.
