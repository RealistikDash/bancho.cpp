#include <iostream>

namespace bancho {
    int32_t main() {
        std::cout << "Hello, World!" << std::endl;
        return 0;
    }
}

// TODO: Look into making bancho::main the entry point.
int32_t main() {
    return bancho::main();
}
