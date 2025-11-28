#ifndef FLAGS_REGISTER_H
#define FLAGS_REGISTER_H

#include <cstdint>
#include <iostream>
#include <bitset>
using namespace std;

class FLAGS_REGISTER{
	public:
		bool Zero, Carry, Negative;
		FLAGS_REGISTER() : flags(0), Zero(false), Carry(false), Negative(false) {}

		void update(uint16_t full, uint8_t result){
			//Z flag
			Zero = (result == 0);
			updateBit(ZERO_BIT, Zero);

			//Carry flag
			Carry = (full > 0xFF);
			updateBit(CARRY_BIT, Carry);

			//Negative flag
			Negative = (result & 0x80) != 0;
			updateBit(NEGATIVE_BIT, Negative);
		}

		void displayFlags() {
			cout << "Flags Register: " << bitset<8>(flags) << " " 
				<< "Z:" << Zero << " " << "C:" << Carry << " "
				<< "N:" << Negative << endl;
		}
		uint8_t get() const { return flags; }
	private:
		uint8_t flags;
		static const uint8_t ZERO_BIT     = 2;
		static const uint8_t CARRY_BIT    = 3;
		static const uint8_t NEGATIVE_BIT = 2;

		void updateBit(uint8_t bit, bool condition){
			if (condition) flags |= (1 << bit);
			else flags &= ~(1 << bit);
		}

};

#endif // FLAGS_REGISTER_H
