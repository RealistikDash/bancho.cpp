#include "writer.hpp"
#include <cstring>

void write_uleb128(uint16_t value, char*& buffer) {
    
    do {
        uint8_t byte = value & 0x7f;
        value >>= 7;
        if (value != 0) {
            byte |= 0x80;
        }
        PWRITE_BYTE(buffer, byte);
    } while (value != 0);
}

void write_string(char* value, char*& buffer) {
    uint16_t length = strlen(value);
    write_uleb128(length, buffer);
    memcpy(buffer, value, length);
    buffer += length;
}
