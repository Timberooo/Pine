#ifndef PINE_MATH_VECTOR_VECTOR2D_H
#define PINE_MATH_VECTOR_VECTOR2D_H

#include "../math_common.h"
#include "../point.h"

#include <cmath>

namespace Pine
{
    struct Vector2D;

    typedef Vector2D Vector2;
    typedef Vector2D Vec2;


    constexpr inline Vector2D normalize(const Vector2D& v);

    constexpr inline float dot(const Vector2D& v1, const Vector2D& v2);

    template <typename T1, typename T2>
    constexpr inline Vector2D operator-(const Point2D<T1>& lhs, const Point2D<T2>& rhs);

    template <typename T>
    constexpr inline Point2D<float> operator+(const Point2D<T>& lhs, const Vector2D& rhs);
    template <typename T>
    constexpr inline Point2D<float> operator+(const Vector2D& lhs, const Point2D<T>& rhs);

    // vvv Vector2D vvv

    struct Vector2D
    {
        float x = 0.0f;
        float y = 0.0f;


        static constexpr inline Vector2D zero();


        constexpr inline Vector2D();
        constexpr inline Vector2D(float x, float y);

        constexpr inline bool operator==(const Vector2D& other) const;
        constexpr inline bool operator!=(const Vector2D& other) const;

        constexpr inline Vector2D& operator+=(const Vector2D& rhs);
        constexpr inline Vector2D& operator-=(const Vector2D& rhs);
        constexpr inline Vector2D& operator*=(float s);
        constexpr inline Vector2D& operator/=(float s);

        constexpr friend inline Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs);
        constexpr friend inline Vector2D operator-(const Vector2D& lhs, const Vector2D& rhs);
        constexpr friend inline Vector2D operator*(const Vector2D& v, float s);
        constexpr friend inline Vector2D operator*(float s, const Vector2D& v);
        constexpr friend inline Vector2D operator/(const Vector2D& v, float s);

        constexpr inline float length() const;
    };



    constexpr inline Vector2D Vector2D::zero() {
        return Vector2D();
    }



    constexpr inline Vector2D::Vector2D() {}

    constexpr inline Vector2D::Vector2D(float x, float y) : x(x), y(y) {}



    constexpr inline bool Vector2D::operator==(const Vector2D& other) const {
        return x == other.x && y == other.y;
    }

    constexpr inline bool Vector2D::operator!=(const Vector2D& other) const {
        return !operator==(other);
    }



    constexpr inline Vector2D& Vector2D::operator+=(const Vector2D& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    constexpr inline Vector2D& Vector2D::operator-=(const Vector2D& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    constexpr inline Vector2D& Vector2D::operator*=(float s)
    {
        x *= s;
        y *= s;
        return *this;
    }

    constexpr inline Vector2D& Vector2D::operator/=(float s)
    {
        x /= s;
        y /= s;
        return *this;
    }



    constexpr inline Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs)
    {
        Vector2D result = lhs;
        result += rhs;
        return result;
    }

    constexpr inline Vector2D operator-(const Vector2D& lhs, const Vector2D& rhs)
    {
        Vector2D result = lhs;
        result -= rhs;
        return result;
    }

    constexpr inline Vector2D operator*(const Vector2D& v, float s)
    {
        Vector2D result = v;
        result *= s;
        return result;
    }

    constexpr inline Vector2D operator*(float s, const Vector2D& v) {
        return v * s;
    }

    constexpr inline Vector2D operator/(const Vector2D& v, float s)
    {
        Vector2D result = v;
        result /= s;
        return result;
    }



    constexpr inline float Vector2D::length() const {
        return std::sqrt(square(x) + square(y));
    }

    // vvv Free Functions vvv // ^^^ Vector2D ^^^

    constexpr inline Vector2D normalize(const Vector2D& v) {
        return v / v.length();
    }



    constexpr inline float dot(const Vector2D& v1, const Vector2D& v2) {
        return (v1.x * v2.x) + (v1.y * v2.y);
    }



    template <typename T1, typename T2>
    constexpr inline Vector2D operator-(const Point2D<T1>& lhs, const Point2D<T2>& rhs)
    {
        Vector2D result;
        result.x = lhs.x - rhs.x;
        result.y = lhs.y - rhs.y;
        return result;
    }

    template <typename T>
    constexpr inline Point2D<float> operator+(const Point2D<T>& lhs, const Vector2D& rhs)
    {
        Point2D<float> result;
        result.x = lhs.x + rhs.x;
        result.y = lhs.y + rhs.y;
        return result;
    }

    template <typename T>
    constexpr inline Point2D<float> operator+(const Vector2D& lhs, const Point2D<T>& rhs) {
        return rhs + lhs;
    }
}

#endif // PINE_MATH_VECTOR_VECTOR2D_H