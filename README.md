# Project_c

# C-- Interpreter Project

This project involves creating an interpreter for the C-- programming language. The interpreter is designed to handle variable assignments, arithmetic operations, conditionals, and printing. This README provides a comprehensive guide to understanding, setting up, and running the C-- interpreter.

## Table of Contents

1. [Introduction](#introduction)
2. [Project Structure](#project-structure)
3. [Requirements](#requirements)
4. [Installation](#installation)
5. [Usage](#usage)
6. [Components](#components)
    - [Interpreter](#interpreter)
    - [Arithmetic](#arithmetic)
    - [Condition](#condition)
    - [Print](#print)
    - [Variable](#variable)
7. [Testing](#testing)
8. [Contribution](#contribution)
9. [License](#license)

## Introduction

The C-- Interpreter Project is an educational project designed to demonstrate how an interpreter works. It executes a simplified version of the C programming language, called C--. The interpreter processes the code, executes operations, evaluates conditions, and manages variables.

## Project Structure

The project consists of the following files:

- `main.c` - Entry point for the program.
- `interpreter.h` / `interpreter.c` - Handles the overall interpretation process.
- `arithmetic.h` / `arithmetic.c` - Manages arithmetic operations.
- `condition.h` / `condition.c` - Manages conditional operations.
- `print.h` / `print.c` - Handles the print functionality.
- `variable.h` / `variable.c` - Manages variable assignments and retrieval.

## Requirements

To build and run the C-- interpreter, you will need:

- A C compiler (e.g., GCC)
- Make (optional, for easy building)

## Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/yourusername/c--interpreter.git
   cd c--interpreter
