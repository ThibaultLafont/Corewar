# Corewar Tournament Virtual Machine

## Overview

This project involves developing a virtual machine in C for the Corewar tournament, where pre-written programs, called champions, compete in a shared memory environment. The last champion to execute a survival instruction wins the game.

## Project Structure

- **Champions**: Pre-written programs in a specific assembly language that compete in the virtual machine.
- **Assembler**: Translates the champions' assembly code (.s files) into machine language understood by the virtual machine.
- **Virtual Machine**: Executes the translated instructions, manages memory, and determines the winner.

## Instructions

1. **Compile the Project**
    ```sh
    make
    ```

2. **Run the Virtual Machine**
    ```sh
    ./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address] prog_name] ...
    ```
    - `-dump nbr_cycle`: Dumps the memory after the specified number of cycles.
    - `-n prog_number`: Sets the program number.
    - `-a load_address`: Sets the program's loading address.

## Features

- **Memory Management**: Handles multiple programs competing in a shared memory space.
- **Instruction Execution**: Supports various instructions like live, ld, st, add, sub, etc.
- **Program Counters and Registers**: Manages program counters and registers for each champion.
- **Carry Flag**: Maintains the carry flag to determine the outcome of certain operations.
- **Output Messages**: Displays messages indicating the status of players and the winner.

## Optional Bonus

- Develop a graphical interface to visualize the movements and memory acquisition of champions in the arena. See the example below where Champion n°2 beat Champion n°1:

![Bonus](https://i.imgur.com/0hKqWZL.png)

## Acknowledgements

This project is a part of the curriculum at Epitech, designed to test and enhance programming, algorithm, and strategic skills.

