#ifndef PINE_MATH_VECTOR_VEC2_H
#define PINE_MATH_VECTOR_VEC2_H

#include "../math_common.h"
#include "../point.h"

#include <cmath>

namespace Pine
{
    struct Vec2;

    typedef Vec2 Vector2;
    typedef Vec2 Vector2D;


    constexpr inline Vec2 normalize(const Vec2& v);

    constexpr inline float dot(const Vec2& v1, const Vec2& v2);

    template <typename T1, typename T2>
    constexpr inline Vec2 operator-(const Point2D<T1>& lhs, const Point2D<T2>& rhs);

    template <typename T>
    constexpr inline Point2D<float> operator+(const Point2D<T>& lhs, const Vec2& rhs);
    template <typename T>
    constexpr inline Point2D<float> operator+(const Vec2& lhs, const Point2D<T>& rhs);

    // vvv Vec2 vvv

    struct Vec2
    {
        float x = 0.0f;
        float y = 0.0f;


        static constexpr inline Vec2 zero();


        constexpr inline Vec2();
        constexpr inline Vec2(float x, float y);

        constexpr inline bool operator==(const Vec2& other) const;
        constexpr inline bool operator!=(const Vec2& other) const;

        constexpr inline Vec2& operator+=(const Vec2& rhs);
        constexpr inline Vec2& operator-=(const Vec2& rhs);
        constexpr inline Vec2& operator*=(float s);
        constexpr inline Vec2& operator/=(float s);

        constexpr friend inline Vec2 operator+(const Vec2& lhs, const Vec2& rhs);
        constexpr friend inline Vec2 operator-(const Vec2& lhs, const Vec2& rhs);
        constexpr friend inline Vec2 operator*(const Vec2& v, float s);
        constexpr friend inline Vec2 operator*(float s, const Vec2& v);
        constexpr friend inline Vec2 operator/(const Vec2& v, float s);

        constexpr inline float length() const;
    };



    constexpr inline Vec2 Vec2::zero() {
        return Vec2();
    }



    constexpr inline Vec2::Vec2() {}

    constexpr inline Vec2::Vec2(float x, float y) : x(x), y(y) {}



    constexpr inline bool Vec2::operator==(const Vec2& other) const {
        return x == other.x && y == other.y;
    }

    constexpr inline bool Vec2::operator!=(const Vec2& other) const {
        return !operator==(other);
    }



    constexpr inline Vec2& Vec2::operator+=(const Vec2& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    constexpr inline Vec2& Vec2::operator-=(const Vec2& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    constexpr inline Vec2& Vec2::operator*=(float s)
    {
        x *= s;
        y *= s;
        return *this;
    }

    constexpr inline Vec2& Vec2::operator/=(float s)
    {
        x /= s;
        y /= s;
        return *this;
    }



    constexpr inline Vec2 operator+(const Vec2& lhs, const Vec2& rhs)
    {
        Vec2 result = lhs;
        result += rhs;
        return result;
    }

    constexpr inline Vec2 operator-(const Vec2& lhs, const Vec2& rhs)
    {
        Vec2 result = lhs;
        result -= rhs;
        return result;
    }

    constexpr inline Vec2 operator*(const Vec2& v, float s)
    {
        Vec2 result = v;
        result *= s;
        return result;
    }

    constexpr inline Vec2 operator*(float s, const Vec2& v) {
        return v * s;
    }

    constexpr inline Vec2 operator/(const Vec2& v, float s)
    {
        Vec2 result = v;
        result /= s;
        return result;
    }



    constexpr inline float Vec2::length() const {
        return std::sqrt(square(x) + square(y));
    }

    // vvv Free Functions vvv // ^^^ Vec2 ^^^

    constexpr inline Vec2 normalize(const Vec2& v) {
        return v / v.length();
    }



    constexpr inline float dot(const Vec2& v1, const Vec2& v2) {
        return (v1.x * v2.x) + (v1.y * v2.y);
    }



    template <typename T1, typename T2>
    constexpr inline Vec2 operator-(const Point2D<T1>& lhs, const Point2D<T2>& rhs)
    {
        Vec2 result;
        result.x = lhs.x - rhs.x;
        result.y = lhs.y - rhs.y;
        return result;
    }

    template <typename T>
    constexpr inline Point2D<float> operator+(const Point2D<T>& lhs, const Vec2& rhs)
    {
        Point2D<float> result;
        result.x = lhs.x + rhs.x;
        result.y = lhs.y + rhs.y;
        return result;
    }

    template <typename T>
    constexpr inline Point2D<float> operator+(const Vec2& lhs, const Point2D<T>& rhs) {
        return rhs + lhs;
    }
}

#endif // PINE_MATH_VECTOR_VEC2_H