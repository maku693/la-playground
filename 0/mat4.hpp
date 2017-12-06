#include <cstddef>

namespace linmath {

template <std::size_t Dim> struct vec;
using vec4 = vec<4>;

struct mat4x4 {
    float values[16] = {};

    explicit constexpr mat4x4(float v) noexcept
    {
        values = { v, 0, 0, 0, v, 0, 0, 0, v, 0, 0, 0, v };
    }

    constexpr vec4 operator[](std::ptrdiff_t i) noexcept
    {
        return { values[i * 4], values[i * 4 + 1], values[i * 4 + 2],
            values[i * 4 + 3] };
    }

    constexpr mat4 operator*=(mat4 rhs) noexcept
    {
        return {
            *this[0][0] * rhs[0][0] + *this[0][1] * rhs[1][0]
                + *this[0][2] * rhs[2][0] + *this[0][3] * rhs[3][0],
            *this[0][0] * rhs[0][1] + *this[0][1] * rhs[1][1]
                + *this[0][2] * rhs[2][1] + *this[0][3] * rhs[3][1],
            *this[0][0] * rhs[0][2] + *this[0][1] * rhs[1][2]
                + *this[0][2] * rhs[2][2] + *this[0][3] * rhs[3][2],
            *this[0][0] * rhs[0][3] + *this[0][1] * rhs[1][3]
                + *this[0][2] * rhs[2][3] + *this[0][3] * rhs[3][3],
            *this[1][0] * rhs[0][0] + *this[1][1] * rhs[1][0]
                + *this[1][2] * rhs[2][0] + *this[1][3] * rhs[3][0],
            *this[1][0] * rhs[0][1] + *this[1][1] * rhs[1][1]
                + *this[1][2] * rhs[2][1] + *this[1][3] * rhs[3][1],
            *this[1][0] * rhs[0][2] + *this[1][1] * rhs[1][2]
                + *this[1][2] * rhs[2][2] + *this[1][3] * rhs[3][2],
            *this[1][0] * rhs[0][3] + *this[1][1] * rhs[1][3]
                + *this[1][2] * rhs[2][3] + *this[1][3] * rhs[3][3],
            *this[2][0] * rhs[0][0] + *this[2][1] * rhs[1][0]
                + *this[2][2] * rhs[2][0] + *this[2][3] * rhs[3][0],
            *this[2][0] * rhs[0][1] + *this[2][1] * rhs[1][1]
                + *this[2][2] * rhs[2][1] + *this[2][3] * rhs[3][1],
            *this[2][0] * rhs[0][2] + *this[2][1] * rhs[1][2]
                + *this[2][2] * rhs[2][2] + *this[2][3] * rhs[3][2],
            *this[2][0] * rhs[0][3] + *this[2][1] * rhs[1][3]
                + *this[2][2] * rhs[2][3] + *this[2][3] * rhs[3][3],
            *this[3][0] * rhs[0][0] + *this[3][1] * rhs[1][0]
                + *this[3][2] * rhs[2][0] + *this[3][3] * rhs[3][0],
            *this[3][0] * rhs[0][1] + *this[3][1] * rhs[1][1]
                + *this[3][2] * rhs[2][1] + *this[3][3] * rhs[3][1],
            *this[3][0] * rhs[0][2] + *this[3][1] * rhs[1][2]
                + *this[3][2] * rhs[2][2] + *this[3][3] * rhs[3][2],
            *this[3][0] * rhs[0][3] + *this[3][1] * rhs[1][3]
                + *this[3][2] * rhs[2][3] + *this[3][3] * rhs[3][3],
        };
    }

    constexpr mat4 operator*=(vec4 rhs) noexcept {}

    static constexpr mat4 identity
        = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
};

// make_look_at
// make_perspective
// make_rotation
// make_scaling
// make_translation

} // namespace linmath
