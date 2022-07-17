#include "position.hpp"

using namespace bancho::maths;

template <typename T>
Vector2<T>::Vector2() {};

template <typename T>
Vector2<T>::Vector2(T x, T y)
    : x(x)
    , y(y) {}
