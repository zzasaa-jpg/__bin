#include <iostream>
#include "./ALU.hpp"

//Arithmetic & Bitwise Logic ALU, flags auto updated inside ALU
void ALU::plus(){
	uint16_t full = (uint16_t)A + (uint16_t)B;
	A = full & 0xFF;
	flags.update(full, A);
}

void ALU::minus(){
	uint16_t full = (uint16_t)A - (uint16_t)B;
	A = full & 0xFF;
	flags.update(full, A);
}

void ALU::mult(){
	uint16_t full = (uint16_t)A * (uint16_t)B;
	A = full & 0xFF;
	flags.update(full, A);
}

uint8_t ALU::DIV(){
	if(B == 0){
		flags.Carry = 1;
		A = 0;
		flags.Zero = 1;
		flags.Negative = 0;
		return A;
	}
	uint8_t result = A / B;
	A = result;

	flags.Carry = 0;
	flags.Zero = (result == 0);
	flags.Negative = (result & 0x80) != 0;
	return result;
}

uint8_t ALU::MOD(){
	if (B == 0){
		A = 0;
		flags.Zero = 1;
		flags.Carry = 1;
		flags.Negative = 0;
		return 0;
	}
	uint8_t result = A % B;
	A = result;

	flags.Carry = 0;
	flags.Zero = (result == 0);
	flags.Negative = 0;
	return result;
}

uint8_t ALU::INC(){
	uint8_t old_A = A;
	uint8_t result = A + 1;

	A = result;

	flags.Carry = (old_A == 0xFF);
	flags.Zero = (result == 0);
	flags.Negative = (result & 0x80) != 0;
	
	return result;
}
		
uint8_t ALU::DEC(){
	uint8_t old_A = A;
	uint8_t result = A - 1;
	
	A = result;

	flags.Carry = (old_A == 0x00);
	flags.Zero = (result == 0);
	flags.Negative = (result & 0x80) != 0;

	return result;
}

//Logical ALU,
uint8_t ALU::AND(){
	uint8_t result = A & B;
	A = result;
	flags.update(result, result);
	return result;
}

uint8_t ALU::OR(){
	uint8_t result = A | B;
	A = result;
	flags.update(result, result);
	return result;
}

uint8_t ALU::XOR(){
	uint8_t result = A ^ B;
	A = result;
	flags.update(result, result);
	return result;
}

uint8_t ALU::NOT(){
	uint8_t result = ~A;
	A = result;
	flags.update(result, result);
	return result;
}

//Shift, flags handled manually because shift rules are unique
uint8_t ALU::SHL(){
	uint8_t carry = (A & 0x80) >> 7;
	uint8_t result = (A << 1);

	A = result;

	flags.Carry = carry;
	flags.Zero = (result == 0);
	flags.Negative = (result & 0x80) != 0;
	return result;
}
		
uint8_t ALU::SHR(){
	uint8_t carry = (A & 0x01);
	uint8_t result = (A >> 1);

	A = result;

	flags.Carry = carry;
	flags.Zero = (result == 0);
	flags.Negative = (result & 0x80) != 0;
	return result;
}

//Comparison
uint8_t ALU::CMP(){
	uint8_t temp = A - B;
	flags.Carry = (A < B);
	flags.Zero = (temp == 0);
	flags.Negative = (temp & 0x80) != 0;
	return temp;
}

