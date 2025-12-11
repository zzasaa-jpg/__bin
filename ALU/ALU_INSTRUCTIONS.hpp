#ifndef ALU_INSTRUCTIONS_HPP
#define ALU_INSTRUCTIONS_HPP

#include <cstdint>

enum ALU_INSTRUCTION : uint8_t {
	ALU_PLUS  = 0x06,
	ALU_MINUS = 0x09,
	ALU_MULT  = 0x10,
	ALU_AND   = 0x26,
	ALU_OR    = 0x27,
	ALU_XOR   = 0x28,
	ALU_NOT   = 0x29,
	ALU_SHL   = 0x30,
	ALU_SHR   = 0x31,
	ALU_INC   = 0x32,
	ALU_DEC   = 0x33,
	ALU_DIV   = 0x34,
	ALU_MOD   = 0x35,
	ALU_CMP   = 0x36
};

#endif //ALU_INSTRUCTIONS_HPP
