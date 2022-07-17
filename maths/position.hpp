#pragma once

namespace bancho::maths {
    template <typename T>
    class Vector2 {
    public:
        T x, y;

        Vector2();
        Vector2(T x, T y);
    };
}
