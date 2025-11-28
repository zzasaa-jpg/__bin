#ifndef JUMP_INSTRUCTIONS_H
#define JUMP_INSTRUCTIONS_H

#include <cstdint>
using namespace std;
class CPU;

class JUMP_INSTRUCTIONS{
	private:
		//JUMP (JMP) --Unconditional--
		void JMP(uint16_t address, uint16_t &PC){
			PC = address;	
			cout << "address: " << address << " "<< "PC: " << PC << endl;
		}
		
		//ZERO JUMP (JZ)
		void JZ(bool Zero_flag, uint16_t address, uint16_t &PC){
			cout <<"before: " << "address: " << address << " "<< "PC: " << PC << endl;
			cout << Zero_flag << endl;
			if (Zero_flag){
				PC = address;
				cout<< "consdition inside: "<< "address: " << address << " " << "PC: " << PC << endl;
			} else {
				PC += 2;
			}
			cout<< "Final: "<< "address: " << address << " " << "PC: " << PC << endl;

		}

		//NON-ZERO JUMP (JNZ)
		void JNZ(bool Zero_flag, uint16_t address, uint16_t &PC){
			cout << "before: " << "address: " << address << " "<< "PC: " << PC << endl;
			if (!Zero_flag){
				PC = address;
				cout << "condition inside: " << "address: " << address << " " << "PC: " << PC << endl;
			}else {
				PC += 2;
			}
			cout<< "Final: "<< "address: " << address << " " << "PC: " << PC << endl;

		}

		//CARRY JUMP (JC)
		void JC(bool Carry_flag, uint16_t address, uint16_t &PC){
			cout<< "before: " << "address: " << address << " "<< "PC: " << PC << endl;
			if (Carry_flag){
				PC = address;
				cout << "condition inside: " << "address: " << address << " " << "PC: " << PC << endl;
			}else {
				PC += 2;
			}
			cout<< "Final: "<< "address: " << address << " " << "PC: " << PC << endl;
		}

		//NO CARRY JUMP (JNC)
		void JNC(bool Carry_flag, uint16_t address, uint16_t &PC){
			cout<< "before: " << "address: " << address << " "<< "PC: " << PC << endl;
			if (!Carry_flag){
				cout << "ccaleed";
				PC = address;
				cout << "condition inside: " << "address: " << address << " " << "PC: " << PC << endl;
			}else {
				PC += 2;
			}
			cout<< "Final: "<< "address: " << address << " " << "PC: " << PC << endl;
		}
		
		friend class CPU;

	public:
		JUMP_INSTRUCTIONS() {}
};

#endif // JUMP_INSTRUCTIONS_H
