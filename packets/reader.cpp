#include "reader.hpp"
#include <cstring>

using namespace bancho::packets;

uint16_t reader::read_uleb128(char*& buffer) {
    uint16_t result = 0;
    uint8_t shift = 0;
    uint8_t byte;

    do {
        byte = *buffer++;
        result |= (byte & 0x7f) << shift;
        shift += 7;
    } while (byte & 0x80);

    return result;
}

char* reader::read_string(char*& buffer) {
    uint16_t length = read_uleb128(buffer);
    char* result = new char[length + 1];
    memcpy(result, buffer, length);
    result[length] = '\0';
    buffer += length;
    return result;
}
