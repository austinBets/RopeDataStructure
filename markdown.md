# Rope Data Structure Program

This program demonstrates the use of a rope data structure for efficient string manipulation. The `Rope` class provides functionalities to create, concatenate, delete, insert, and report strings using a rope data structure.

## Overview

The program consists of the following main components:
1. **Rope Class**: Defines the structure and methods to manipulate rope nodes.
2. **main.cpp**: Demonstrates the usage of the `Rope` class methods with various string operations.

### Rope Class

The `Rope` class includes:
- **CreateRope**: Constructs a rope from a given string.
- **Concatenate**: Combines two ropes into one.
- **Delete**: Removes a specified substring from the rope.
- **Insert**: Inserts a given string at a specified position in the rope.
- **Report**: Outputs the complete string stored in the rope.
- **FullText**: Helper function to get the full string from the rope.
- **StringLength**: Helper function to get the length of the string in the rope.

### main.cpp

This file demonstrates the usage of the `Rope` class:
1. Creates an initial rope with the string "HelloRopeStructure".
2. Concatenates another rope with the string "Example".
3. Deletes a portion of the concatenated rope.
4. Inserts a new string "Insertion" into the modified rope.
5. Outputs the result after each operation.

## How to Run the Program

### Prerequisites

- C++ compiler (e.g., g++)
- C++11 or later standard

### Instructions

1. **Compile the program**:
    ```
    g++ -g main.cpp Rope/Rope.cpp -o main
    ```

2. **Run the program**:
    ```
    ./main.exe
    ```

3. **Expected Output**:
    ```
    Initial rope structure: HelloRopeStructure
    After concatenation: HelloRopeStructureExample
    After deletion: HelloStructureExample
    After insertion: HelloInsertStructureExample
    ```

## Files

- `Rope.h`: Header file containing the definition of the `Rope` class and `ropeNode` struct.
- `Rope.cpp`: Implementation file for the `Rope` class methods.
- `main.cpp`: Main file demonstrating the usage of the `Rope` class.

## Summary

This program provides a basic implementation and demonstration of a rope data structure, useful for efficient string manipulation. By following the provided instructions, you can compile and run the program to see the rope operations in action.
