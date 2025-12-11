#ifndef ALU_HPP
#define ALU_HPP

#include <cstdint>
#include "../FLAGS_REGISTER/Flags_register.h"

class ALU {
	public:
		uint8_t &A;
		uint8_t &B;
		FLAGS_REGISTER &flags;

		ALU(uint8_t &regA, uint8_t &regB, FLAGS_REGISTER &f): A(regA), B(regB), flags(f) {}

		//Arithmetic
		void plus();
		void minus();
		void mult();
		uint8_t DIV();
		uint8_t MOD();
		uint8_t INC();
		uint8_t DEC();

		//Logic
		uint8_t AND();
		uint8_t OR();
		uint8_t XOR();
		uint8_t NOT();

		//Shift
		uint8_t SHL();
		uint8_t SHR();

		//Comparison
		uint8_t CMP();

};

#endif //ALU_HPP
