#pragma once

#include <cstdint>

// Reads a primitive from a buffer pointer into a pointer.
#define PREAD_INTO_PTR(type, ptr, buffer) \
    ptr = (type*)buffer; \
    buffer += sizeof(type);

// Creates a new variable of type and reads it from a buffer pointer.
#define PREAD_NEW(type, name, buffer) \
    type name = *(type*)buffer; \
    buffer += sizeof(type);

namespace bancho::packets::reader {
    // Reads a string from the buffer, allocating it on the heap and returning the pointer.
    // Increments the buffer pointer.
    char* read_string(char*& buffer);

    // Reads an unsigned LEB128 from the buffer. Additionally, increments the buffer pointer.
    uint16_t read_uleb128(char*& buffer);
}

