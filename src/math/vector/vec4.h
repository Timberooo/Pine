#ifndef PINE_MATH_VECTOR_VEC4_H
#define PINE_MATH_VECTOR_VEC4_H

#include "../math_common.h"
#include "../point.h"

#include <cmath>

namespace Pine
{
    struct Vec4;

    typedef Vec4 Vector4;
    typedef Vec4 Vector4D;


    constexpr inline Vec4 normalize(const Vec4& v);

    constexpr inline float dot(const Vec4& v1, const Vec4& v2);

    // vvv Vec4 vvv

    struct Vec4
    {
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;
        float w = 0.0f;


        static constexpr inline Vec4 zero();


        constexpr inline Vec4();
        constexpr inline Vec4(float x, float y, float z, float w);

        constexpr inline bool operator==(const Vec4& other) const;
        constexpr inline bool operator!=(const Vec4& other) const;

        constexpr inline Vec4& operator+=(const Vec4& rhs);
        constexpr inline Vec4& operator-=(const Vec4& rhs);
        constexpr inline Vec4& operator*=(float s);
        constexpr inline Vec4& operator/=(float s);

        constexpr friend inline Vec4 operator+(const Vec4& lhs, const Vec4& rhs);
        constexpr friend inline Vec4 operator-(const Vec4& lhs, const Vec4& rhs);
        constexpr friend inline Vec4 operator*(const Vec4& v, float s);
        constexpr friend inline Vec4 operator*(float s, const Vec4& v);
        constexpr friend inline Vec4 operator/(const Vec4& v, float s);

        constexpr inline float length() const;
    };



    constexpr inline Vec4 Vec4::zero() {
        return Vec4();
    }



    constexpr inline Vec4::Vec4() {}

    constexpr inline Vec4::Vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}



    constexpr inline bool Vec4::operator==(const Vec4& other) const {
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }

    constexpr inline bool Vec4::operator!=(const Vec4& other) const {
        return !operator==(other);
    }



    constexpr inline Vec4& Vec4::operator+=(const Vec4& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        w += rhs.w;
        return *this;
    }

    constexpr inline Vec4& Vec4::operator-=(const Vec4& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        w -= rhs.w;
        return *this;
    }

    constexpr inline Vec4& Vec4::operator*=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
        return *this;
    }

    constexpr inline Vec4& Vec4::operator/=(float s)
    {
        x /= s;
        y /= s;
        z /= s;
        w /= s;
        return *this;
    }



    constexpr inline Vec4 operator+(const Vec4& lhs, const Vec4& rhs)
    {
        Vec4 result = lhs;
        result += rhs;
        return result;
    }

    constexpr inline Vec4 operator-(const Vec4& lhs, const Vec4& rhs)
    {
        Vec4 result = lhs;
        result -= rhs;
        return result;
    }

    constexpr inline Vec4 operator*(const Vec4& v, float s)
    {
        Vec4 result = v;
        result *= s;
        return result;
    }

    constexpr inline Vec4 operator*(float s, const Vec4& v) {
        return v * s;
    }

    constexpr inline Vec4 operator/(const Vec4& v, float s)
    {
        Vec4 result = v;
        result /= s;
        return result;
    }



    constexpr inline float Vec4::length() const {
        return std::sqrt(square(x) + square(y) + square(z) + square(w));
    }

    // vvv Free Functions vvv // ^^^ Vec4 ^^^

    constexpr inline Vec4 normalize(const Vec4& v) {
        return v / v.length();
    }



    constexpr inline float dot(const Vec4& v1, const Vec4& v2) {
        return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z) + (v1.w * v2.w);
    }
}

#endif // PINE_MATH_VECTOR_VEC4_H