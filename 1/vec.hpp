#include <cmath>
#include <type_traits>

template <class Vec>
struct vec_operators {
    friend constexpr Vec operator+(const Vec& v) noexcept
    {
        return v;
    }

    friend constexpr Vec operator-(const Vec& v) noexcept
    {
        return v * -1.0f;
    }

    friend constexpr Vec& operator-=(Vec& lhs, const Vec& rhs) noexcept
    {
        return lhs += -rhs;
    }

    friend constexpr Vec& operator/=(Vec& lhs, const float& rhs) noexcept
    {
        return lhs * (1.0f / rhs);
    }

    friend constexpr Vec operator+(const Vec& lhs, const Vec& rhs) noexcept
    {
        Vec lhs_copy{lhs};
        return lhs_copy += rhs;
    }

    friend constexpr Vec operator-(const Vec& lhs, const Vec& rhs) noexcept
    {
        Vec lhs_copy{lhs};
        return lhs_copy -= rhs;
    }

    friend constexpr Vec operator*(const Vec& lhs, const float& rhs) noexcept
    {
        Vec lhs_copy{lhs};
        return lhs_copy *= rhs;
    }

    friend constexpr Vec operator*(const float lhs, const Vec& rhs) noexcept
    {
        return rhs * lhs;
    }

    friend constexpr Vec operator/(const Vec& lhs, const float& rhs) noexcept
    {
        Vec lhs_copy{lhs};
        return lhs_copy /= rhs;
    }

    friend constexpr bool operator!=(const Vec& lhs, const Vec& rhs) noexcept
    {
        return !(lhs == rhs);
    }

    friend constexpr Vec lerp(const Vec& a, const Vec& b, const float& t)
    {
        return a + t * (b - a);
    }
};

template <class Vec>
struct vec_base : private vec_operators<Vec> {
    constexpr float squared_length() const noexcept
    {
        const Vec& v = *static_cast<const Vec*>(this);
        return dot(v, v);
    }

    float length() const noexcept
    {
        return std::sqrt(static_cast<const Vec*>(this)->squared_length());
    }

    Vec normalized() const noexcept
    {
        return *static_cast<const Vec*>(this) / length();
    }
};

template <class T>
float distance(const T& lhs, const T& rhs)
{
    return (lhs - rhs).length();
}

struct vec2 : public vec_base<vec2> {
    float x = 0.0f;
    float y = 0.0f;

    constexpr vec2() noexcept = default;

    constexpr explicit vec2(float v) noexcept : x(v), y(v) {}

    constexpr vec2(float x, float y) noexcept : x(x), y(y) {}

    constexpr const float& operator[](std::ptrdiff_t i) const
    {
        return (&x)[i];
    }

    constexpr float& operator[](std::ptrdiff_t i)
    {
        return (&x)[i];
    }

    constexpr vec2& operator+=(const vec2& rhs) noexcept
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    constexpr vec2& operator*=(const float rhs) noexcept
    {
        x *= rhs;
        y *= rhs;
        return *this;
    }

    constexpr bool operator==(const vec2& rhs) const noexcept
    {
        return x == rhs.x && y == rhs.y;
    }
};

constexpr float dot(const vec2& lhs, const vec2& rhs) noexcept
{
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

struct vec3 : public vec_base<vec3> {
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    constexpr vec3() noexcept = default;

    constexpr explicit vec3(float v) noexcept : x(v), y(v), z(v) {}

    constexpr vec3(float x, float y, float z) noexcept : x(x), y(y), z(z) {}

    constexpr const float& operator[](std::ptrdiff_t i) const
    {
        return (&x)[i];
    }

    constexpr float& operator[](std::ptrdiff_t i)
    {
        return (&x)[i];
    }

    constexpr vec3& operator+=(const vec3& rhs) noexcept
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }

    constexpr vec3& operator*=(const float rhs) noexcept
    {
        x *= rhs;
        y *= rhs;
        z *= rhs;
        return *this;
    }

    constexpr bool operator==(const vec3& rhs) const noexcept
    {
        return x == rhs.x && y == rhs.y && z == rhs.z;
    }
};

constexpr vec3 cross(const vec3& lhs, const vec3& rhs) noexcept
{
    return vec3{
        lhs.y * rhs.z - lhs.z * rhs.y,
        lhs.z * rhs.x - lhs.x * rhs.z,
        lhs.x * rhs.y - lhs.y * rhs.x
    };
}

constexpr float dot(const vec3& lhs, const vec3& rhs) noexcept
{
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

float angle(const vec3& lhs, const vec3& rhs) noexcept
{
    return std::acos(dot(lhs.normalized(), rhs.normalized()));
}

vec3 reflect(const vec3& incident, const vec3& normal) noexcept
{
    return incident - 2.0f * dot(incident, normal) * normal;
}

struct vec4 : public vec_base<vec4> {
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    float w = 0.0f;

    constexpr vec4() noexcept = default;

    constexpr explicit vec4(float v) noexcept : x(v), y(v), z(v), w(v) {}

    constexpr vec4(float x, float y, float z, float w) noexcept
        : x(x), y(y), z(z), w(w) {}

    constexpr const float& operator[](std::ptrdiff_t i) const
    {
        return (&x)[i];
    }

    constexpr float& operator[](std::ptrdiff_t i)
    {
        return (&x)[i];
    }

    constexpr vec4& operator+=(const vec4& rhs) noexcept
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        w += rhs.w;
        return *this;
    }

    constexpr vec4& operator*=(const float rhs) noexcept
    {
        x *= rhs;
        y *= rhs;
        z *= rhs;
        w *= rhs;
        return *this;
    }

    constexpr bool operator==(const vec4& rhs) const noexcept
    {
        return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w;
    }
};

constexpr float dot(const vec4& lhs, const vec4& rhs) noexcept
{
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
}
