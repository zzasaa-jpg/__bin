# **8-bit VR_CPU in C++ (v0.3.0)**

A completed virtual CPU, instruction set, memory system fully written in C++.

## Project Overview
The VR CPU is a fully programmable 8bit/16bit hybrid virtual CPU with:

- 8-bit registers (A, B, OUT, FLAGS, PC)
- 64 KB RAM
- ALU with arithmetic & flags
- Jump instructions
- Core memory module

## Features
#### CPU Core
- A, B, OUT registers
- Flags register (Zero, Carry, Sign)
- Program Counter (PC)
- 64 KB RAM

#### ALU
- PLUS
- MINUS
- MULTIPLY
- Auto flag update

#### Jump system
- JMP
- JZ
- JNZ
- JC
- JNC

#### Core Memory Module
- __write_memory(address, value, memory)
- __read_memory(address, memory)
- CPU Load/Store:
    - LOAD A
    - LOAD B
    - STORE A
    - STORE B
- Program loading from memory

## How the CPU works
**1.Program is loaded into memory**

Example: 

    C++
    ------------------------------------------------------
    __write_memory(0x00, 0x01, cpu.memory); // LOAD A
    __write_memory(0x01, 0x10, cpu.memory); // operand = 0x10
    __write_memory(0x10, 100, cpu.memory); //data

**2.Fetch**

CPU reads:

- opcode = memory[PC]
- operand = memory[PC + 1]

**3.Decode**

Switch(opcode)

**4.Execute**

Perform action <br>
Increment PC <br>
Repeat...

## Example Program (Load & Print)

    C++
    -------------------------------------------------------
    __write_memory(0x00, 0x01, cpu.memory); // LOAD A
    __write_memory(0x01, 0x10, cpu.memory); // address 0x10
    __write_memory(0x10, 100, cpu.memory); // value
    __write_memory(0x02, 0x04, cpu.memory); // OUT

Output:

    OUTPUT: 100
    Flags Register: 00000000 Z:0 C:0 N:0
