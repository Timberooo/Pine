#ifndef PINE_MATH_VECTOR_VECTOR4D_H
#define PINE_MATH_VECTOR_VECTOR4D_H

#include "../math_common.h"
#include "../point.h"

#include <cmath>

namespace Pine
{
    struct Vector4D;


    constexpr inline Vector4D normalize(const Vector4D& v);

    constexpr inline float dot(const Vector4D& v1, const Vector4D& v2);

    // vvv Vector4D vvv

    struct Vector4D
    {
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;
        float w = 0.0f;


        static constexpr inline Vector4D zero();


        constexpr inline Vector4D();
        constexpr inline Vector4D(float x, float y, float z, float w);

        constexpr inline bool operator==(const Vector4D& other) const;
        constexpr inline bool operator!=(const Vector4D& other) const;

        constexpr inline Vector4D& operator+=(const Vector4D& rhs);
        constexpr inline Vector4D& operator-=(const Vector4D& rhs);
        constexpr inline Vector4D& operator*=(float s);
        constexpr inline Vector4D& operator/=(float s);

        constexpr friend inline Vector4D operator+(const Vector4D& lhs, const Vector4D& rhs);
        constexpr friend inline Vector4D operator-(const Vector4D& lhs, const Vector4D& rhs);
        constexpr friend inline Vector4D operator*(const Vector4D& v, float s);
        constexpr friend inline Vector4D operator*(float s, const Vector4D& v);
        constexpr friend inline Vector4D operator/(const Vector4D& v, float s);

        constexpr inline float length() const;
    };



    constexpr inline Vector4D Vector4D::zero() {
        return Vector4D();
    }



    constexpr inline Vector4D::Vector4D() {}

    constexpr inline Vector4D::Vector4D(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}



    constexpr inline bool Vector4D::operator==(const Vector4D& other) const {
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }

    constexpr inline bool Vector4D::operator!=(const Vector4D& other) const {
        return !operator==(other);
    }



    constexpr inline Vector4D& Vector4D::operator+=(const Vector4D& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        w += rhs.w;
        return *this;
    }

    constexpr inline Vector4D& Vector4D::operator-=(const Vector4D& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        w -= rhs.w;
        return *this;
    }

    constexpr inline Vector4D& Vector4D::operator*=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
        return *this;
    }

    constexpr inline Vector4D& Vector4D::operator/=(float s)
    {
        x /= s;
        y /= s;
        z /= s;
        w /= s;
        return *this;
    }



    constexpr inline Vector4D operator+(const Vector4D& lhs, const Vector4D& rhs)
    {
        Vector4D result = lhs;
        result += rhs;
        return result;
    }

    constexpr inline Vector4D operator-(const Vector4D& lhs, const Vector4D& rhs)
    {
        Vector4D result = lhs;
        result -= rhs;
        return result;
    }

    constexpr inline Vector4D operator*(const Vector4D& v, float s)
    {
        Vector4D result = v;
        result *= s;
        return result;
    }

    constexpr inline Vector4D operator*(float s, const Vector4D& v) {
        return v * s;
    }

    constexpr inline Vector4D operator/(const Vector4D& v, float s)
    {
        Vector4D result = v;
        result /= s;
        return result;
    }



    constexpr inline float Vector4D::length() const {
        return std::sqrt(square(x) + square(y) + square(z) + square(w));
    }

    // vvv Free Functions vvv // ^^^ Vector4D ^^^

    constexpr inline Vector4D normalize(const Vector4D& v) {
        return v / v.length();
    }



    constexpr inline float dot(const Vector4D& v1, const Vector4D& v2) {
        return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z) + (v1.w * v2.w);
    }
}

#endif // PINE_MATH_VECTOR_VECTOR4D_H