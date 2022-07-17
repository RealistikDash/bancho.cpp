#pragma once
#include <cstdint>

#define PWRITE_BYTE(buffer, value) \
    *buffer++ = value;

#define PWRITE_VALUE(type, value, buffer) \
    *(type*)buffer = value; \
    buffer += sizeof(type);

#define PWRITE_PTR(type, ptr, buffer) \
    *(type*)buffer = *ptr; \
    buffer += sizeof(type);

namespace bancho::packets::writer {
    void write_uleb128(uint16_t value, char*& buffer);
    void write_string(char* value, char*& buffer);
}
