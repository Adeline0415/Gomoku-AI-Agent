# Gomoku AI Agent
### This project implements an AI agent for the game of Gomoku (also known as Five in a Row) using the Minimax algorithm with Alpha-Beta pruning. The agent is designed to efficiently explore the game tree and make optimal moves based on a sophisticated evaluation function.

## Features
- Minimax algorithm with Alpha-Beta pruning for efficient game tree exploration
- Advanced evaluation function considering various patterns and dynamically adjusting search depth
- Optimized search by focusing on the neighborhood of existing pieces
- Implemented in C++ for performance and robustness
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
