#ifndef READ_MEMORY_HPP
#define READ_MEMORY_HPP

#include <cstdint>
using namespace std;

int __read_memory(uint16_t address, vector<uint8_t> &memory){
	return memory[address];
}

#endif //READ_MEMORY_HPP 
