#pragma once
#include <cstdint>
#include <mutex>

#define BUFFER_SIZE 5192

namespace bancho::packets {
    // A mutex protected thread safe, heap allocated buffer.
    class LockedBuffer {
        char* buffer_start;
        char* buffer_ptr;
        std::mutex mutex;
    public:
        // Acquires the mutex and returns a pointer reference to the buffer.
        char*& begin_write();
        // Releases the mutex.
        void end_write();

        // Empties the buffer.
        void clear();

        LockedBuffer();
        ~LockedBuffer();
    };
}
