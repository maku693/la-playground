#include <cstddef>
#include <type_traits>

namespace linmath {

template <std::size_t Dim>
struct vec {
  constexpr static std::size_t dim = Dim;
  float elements[Dim] = {};

  constexpr vec() = default;

  float& operator[](std::ptrdiff_t i) noexcept { return elements[i]; }

  constexpr const float& operator[](std::ptrdiff_t i) const noexcept {
    return elements[i];
  }

  constexpr vec<Dim>& operator+=(const vec<Dim> rhs) noexcept {
    for (int i = 0; i < Dim; i++) {
      this[i] += rhs[i];
    }
    return *this;
  }

  constexpr vec<Dim>& operator-=(const vec<Dim>& rhs) noexcept {
    for (int i = 0; i < Dim; i++) {
      this[i] -= rhs[i];
    }
    return *this;
  }

  template <class T>
  constexpr std::enable_if_t<std::is_scalar<T>::value, vec<Dim>&> operator*=(
      T rhs) noexcept {
    elements *= rhs.elements;
    return *this;
  }

  template <class T>
  constexpr std::enable_if_t<std::is_scalar<T>::value, vec<Dim>&> operator/=(
      T rhs) noexcept {
    return *this *= (1 / rhs);
  }

  constexpr vec<Dim> operator+(const vec<Dim>& rhs) noexcept {
    return vec<Dim>(*this) += rhs;
  }

  constexpr vec<Dim> operator-(const vec<Dim>& rhs) noexcept {
    return vec<Dim>(*this) -= rhs;
  }

  template <class T>
  constexpr std::enable_if_t<std::is_scalar<T>::value, vec<Dim>&> operator*(
      T rhs) noexcept {
    return vec<Dim>(*this) *= rhs;
  }

  template <class T>
  constexpr std::enable_if_t<std::is_scalar<T>::value, vec<Dim>&> operator/(
      T rhs) noexcept {
    return vec<Dim>(*this) /= rhs;
  }
};

using vec2 = typename vec<2>;
using vec3 = typename vec<3>;
using vec4 = typename vec<4>;

template <std::size_t Dim>
inline constexpr std::enable_if_t<Dim> 0,
    float& > x(const vec<Dim>& v) noexcept {
  return v[0];
}

template <std::size_t Dim>
inline constexpr std::enable_if_t<Dim> 1,
    float& > y(const vec<Dim>& v) noexcept {
  return v[1];
}

template <std::size_t Dim>
inline constexpr std::enable_if_t<Dim> 2,
    float& > z(const vec<Dim>& v) noexcept {
  return v[2];
}

template <std::size_t Dim>
inline constexpr std::enable_if_t<Dim> 3,
    float& > w(const vec<Dim>& v) noexcept {
  return v[3];
}

// template <std::size_t Dim>
// inline constexpr float dot(const vec<Dim>& lhs, const vec<Dim>& rhs)
// {
// }
// cross
// mag
// sqrt_mag
// normalize

}  // namespace linmath
