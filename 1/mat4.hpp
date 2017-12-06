#include <array>
#include <cstddef>

#include "vec.hpp"

class mat4 {
public:
    constexpr mat4() noexcept = default;

    explicit constexpr mat4(float x) noexcept
        : m_rows{
            vec4{x,    0.0f, 0.0f, 0.0f},
            vec4{0.0f, x,    0.0f, 0.0f},
            vec4{0.0f, 0.0f, x,    0.0f},
            vec4{0.0f, 0.0f, 0.0f, x   },
        }
    {}

    constexpr mat4(float m00, float m01, float m02, float m03,
        float m10, float m11, float m12, float m13,
        float m20, float m21, float m22, float m23,
        float m30, float m31, float m32, float m33) noexcept
        : m_rows{
            vec4{m00, m01, m02, m03},
            vec4{m10, m11, m12, m13},
            vec4{m20, m21, m22, m23},
            vec4{m30, m31, m32, m33},
        }
    {}

    constexpr const vec4& operator[](std::ptrdiff_t i) const
    {
        return m_rows[i];
    }

    constexpr vec4& operator[](std::ptrdiff_t i)
    {
        return m_rows[i];
    }

    constexpr mat4 operator+() const noexcept
    {
        return *this;
    }

    constexpr mat4 operator-() const noexcept
    {
        return *this * -1.0f;
    }

    constexpr mat4& operator+=(const mat4& rhs) noexcept
    {
        // TODO
        return *this;
    }

    constexpr mat4& operator-=(const mat4& rhs) noexcept
    {
        return *this += -rhs;
    }

    constexpr mat4& operator*=(const float rhs) noexcept
    {
        // TODO
        return *this;
    }

    constexpr mat4& operator*=(const mat4& rhs) noexcept
    {
        // TODO
        return *this;
    }

    constexpr mat4 operator+(const mat4& rhs) const noexcept
    {
        return mat4(*this) += rhs;
    }

    constexpr mat4 operator-(const mat4& rhs) const noexcept
    {
        return mat4(*this) -= rhs;
    }

    constexpr mat4 operator*(const float rhs) const noexcept
    {
        return mat4(*this) *= rhs;
    }

    constexpr mat4 operator*(const mat4& rhs) const noexcept
    {
        return mat4(*this) *= rhs;
    }

private:
    std::array<vec4, 4> m_rows{};
};

// constexpr mat4 make_identity() noexcept
// {
//     return mat4{
//         1.0f, 0.0f, 0.0f, 0.0f,
//         0.0f, 1.0f, 0.0f, 0.0f,
//         0.0f, 0.0f, 1.0f, 0.0f,
//         0.0f, 0.0f, 0.0f, 1.0f
//     };
// }

// constexpr mat4 make_scale(const float x, const float y,
//     const float z) noexcept
// {
//     return mat4{
//         x,    0.0f, 0.0f, 0.0f,
//         0.0f, y,    0.0f, 0.0f,
//         0.0f, 0.0f, z,   0.0f,
//         0.0f, 0.0f, 0.0f, 1.0f
//     };
// }
