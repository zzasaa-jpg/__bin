#ifndef WRITE_MEMORY_HPP
#define WRITE_MEMORY_HPP

#include <cstdint>
using namespace std;

void __write_memory(uint16_t address, uint8_t value, vector<uint8_t> &memory){
	memory[address] = value;
}

#endif //WRITE_MEMORY_HPP
