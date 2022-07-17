#include "buffer.hpp"

using namespace bancho::packets;

char*& LockedBuffer::begin_write() {
    mutex.lock();
    return buffer_ptr;
}

void LockedBuffer::end_write() {
    mutex.unlock();
}

LockedBuffer::LockedBuffer()
    : buffer_start(new char[BUFFER_SIZE])
    , buffer_ptr(buffer_start) {}

LockedBuffer::~LockedBuffer() {
    delete[] buffer_start;
}

void LockedBuffer::clear() {
    buffer_ptr = buffer_start;
}
