#include <iostream>
#include <vector>
#include <cstdint>
#include "./FLAGS_REGISTER/Flags_register.h"
#include "./JUMP_INSTRUCTIONS/Jump_Instructions.h"
#include "./MEMORY_MODULE/READ_MEMORY.hpp"
#include "./MEMORY_MODULE/WRITE_MEMORY.hpp"

using namespace std;

class CPU {
	public:
		uint8_t A, B, OUT, FlagsRegister;
		uint16_t PC;
		vector<uint8_t> memory;

		FLAGS_REGISTER flags;
		JUMP_INSTRUCTIONS jump_instruction;

		CPU(): A(0), B(0), PC(0), memory(65536, 0), FlagsRegister(0) {};

		//MEMORY
		void loadA(uint16_t address){ A = __read_memory(address, memory); }
		void loadB(uint16_t address){ B = __read_memory(address, memory); }
		void storeA(uint16_t address){ __write_memory(address, A, memory); }
		void storeB(uint16_t address){ __write_memory(address, B, memory); }

		//ALU
		void add(uint8_t value){
			uint16_t full = (uint16_t)A + (uint16_t)value;
			A = full & 0xFF;
			flags.update(full, A);
		}

		void plus(){
			uint16_t full = (uint16_t)A + (uint16_t)B;
			A = full & 0xFF;
			flags.update(full, A);
		}

		void minus(){
			uint16_t full = (uint16_t)A - (uint16_t)B;
			A = full & 0xFF;
			flags.update(full, A);

		}

		void mult(){
			uint16_t full = (uint16_t)A * (uint16_t)B;
			A = full & 0xFF;
			flags.update(full, A);

		}

		void execute(uint8_t instruction, uint16_t operand = 0){
		switch(instruction){
		
			case 0x01: loadA(operand); PC += 2; break;
			case 0x08: loadB(operand); PC += 2; break;
			case 0x02: storeA(operand); PC += 2; break;
			case 0x05: storeB(operand); PC += 2; break;

			case 0x03: add( __read_memory(operand, memory) ); PC += 1; break;
			case 0x06: plus(); PC += 1; break;
			case 0x09: minus(); PC += 1; break;
			case 0x10: mult(); PC += 1; break;

			case 0x04:
				OUT = A;
				cout << "OUTPUT: " << (int)OUT << endl;
				PC += 1;
				break;
			
			case 0x20: jump_instruction.JMP(operand, PC); break;
			case 0x21: jump_instruction.JZ(flags.Zero, operand, PC); PC += 2; break;
			case 0x22: jump_instruction.JNZ(flags.Zero, operand, PC); PC += 2; break;
			case 0x23: jump_instruction.JC(flags.Carry, operand, PC); PC += 2; break;
			case 0x24: jump_instruction.JNC(flags.Carry, operand, PC); PC += 2; break;

			default:
				cout << "Unknown Instruction.\n";
				PC += 1;
		}
	}
};

int main() {
	CPU cpu;
	__write_memory(0x00, 0x01, cpu.memory);
	__write_memory(0x01, 0x10, cpu.memory);
	__write_memory(0x10, 0, cpu.memory);

	__write_memory(0x02, 0x08, cpu.memory);
	__write_memory(0x03, 0x20, cpu.memory);
	__write_memory(0x20, 200, cpu.memory);

	__write_memory(0x04, 0x06, cpu.memory);
	__write_memory(0x05, 0x04, cpu.memory);

	while(cpu.PC < 6){
		uint8_t opcode = __read_memory(cpu.PC, cpu.memory);
		uint8_t operand = __read_memory(cpu.PC + 1, cpu.memory);
		cpu.execute(opcode, operand);
	}

	cpu.flags.displayFlags();
	return 0;
}
