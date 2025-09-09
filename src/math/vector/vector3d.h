#ifndef PINE_MATH_VECTOR_VECTOR3D_H
#define PINE_MATH_VECTOR_VECTOR3D_H

#include "../math_common.h"
#include "../point.h"

#include <cmath>

namespace Pine
{
    struct Vector3D;

    typedef Vector3D Vector3;
    typedef Vector3D Vec3;


    constexpr inline Vector3D normalize(const Vector3D& v);

    constexpr inline float dot(const Vector3D& v1, const Vector3D& v2);

    constexpr inline Vector3D cross(const Vector3D& v1, const Vector3D& v2);

    template <typename T1, typename T2>
    constexpr inline Vector3D operator-(const Point3D<T1>& lhs, const Point3D<T2>& rhs);

    template <typename T>
    constexpr inline Point3D<float> operator+(const Point3D<T>& lhs, const Vector3D& rhs);
    template <typename T>
    constexpr inline Point3D<float> operator+(const Vector3D& lhs, const Point3D<T>& rhs);

    // vvv Vector3D vvv

    struct Vector3D
    {
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;


        static constexpr inline Vector3D zero();


        constexpr inline Vector3D();
        constexpr inline Vector3D(float x, float y, float z);

        constexpr inline bool operator==(const Vector3D& other) const;
        constexpr inline bool operator!=(const Vector3D& other) const;

        constexpr inline Vector3D& operator+=(const Vector3D& rhs);
        constexpr inline Vector3D& operator-=(const Vector3D& rhs);
        constexpr inline Vector3D& operator*=(float s);
        constexpr inline Vector3D& operator/=(float s);

        constexpr friend inline Vector3D operator+(const Vector3D& lhs, const Vector3D& rhs);
        constexpr friend inline Vector3D operator-(const Vector3D& lhs, const Vector3D& rhs);
        constexpr friend inline Vector3D operator*(const Vector3D& v, float s);
        constexpr friend inline Vector3D operator*(float s, const Vector3D& v);
        constexpr friend inline Vector3D operator/(const Vector3D& v, float s);

        constexpr inline float length() const;
    };



    constexpr inline Vector3D Vector3D::zero() {
        return Vector3D();
    }



    constexpr inline Vector3D::Vector3D() {}

    constexpr inline Vector3D::Vector3D(float x, float y, float z) : x(x), y(y), z(z) {}



    constexpr inline bool Vector3D::operator==(const Vector3D& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    constexpr inline bool Vector3D::operator!=(const Vector3D& other) const {
        return !operator==(other);
    }



    constexpr inline Vector3D& Vector3D::operator+=(const Vector3D& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }

    constexpr inline Vector3D& Vector3D::operator-=(const Vector3D& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }

    constexpr inline Vector3D& Vector3D::operator*=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }

    constexpr inline Vector3D& Vector3D::operator/=(float s)
    {
        x /= s;
        y /= s;
        z /= s;
        return *this;
    }



    constexpr inline Vector3D operator+(const Vector3D& lhs, const Vector3D& rhs)
    {
        Vector3D result = lhs;
        result += rhs;
        return result;
    }

    constexpr inline Vector3D operator-(const Vector3D& lhs, const Vector3D& rhs)
    {
        Vector3D result = lhs;
        result -= rhs;
        return result;
    }

    constexpr inline Vector3D operator*(const Vector3D& v, float s)
    {
        Vector3D result = v;
        result *= s;
        return result;
    }

    constexpr inline Vector3D operator*(float s, const Vector3D& v) {
        return v * s;
    }

    constexpr inline Vector3D operator/(const Vector3D& v, float s)
    {
        Vector3D result = v;
        result /= s;
        return result;
    }



    constexpr inline float Vector3D::length() const {
        return std::sqrt(square(x) + square(y) + square(z));
    }

    // vvv Free Functions vvv // ^^^ Vector3D ^^^

    constexpr inline Vector3D normalize(const Vector3D& v) {
        return v / v.length();
    }



    constexpr inline float dot(const Vector3D& v1, const Vector3D& v2) {
        return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
    }



    constexpr inline Vector3D cross(const Vector3D& v1, const Vector3D& v2)
    {
        Vector3D result;
        result.x = (v1.y * v2.z) - (v1.z * v2.y);
        result.y = (v1.z * v2.x) - (v1.x * v2.z);
        result.z = (v1.x * v2.y) - (v1.y * v2.x);
        return result;
    }



    template <typename T1, typename T2>
    constexpr inline Vector3D operator-(const Point3D<T1>& lhs, const Point3D<T2>& rhs)
    {
        Vector3D result;
        result.x = lhs.x - rhs.x;
        result.y = lhs.y - rhs.y;
        result.z = lhs.z - rhs.z;
        return result;
    }

    template <typename T>
    constexpr inline Point3D<float> operator+(const Point3D<T>& lhs, const Vector3D& rhs)
    {
        Point3D<float> result;
        result.x = lhs.x + rhs.x;
        result.y = lhs.y + rhs.y;
        result.z = lhs.z + rhs.z;
        return result;
    }

    template <typename T>
    constexpr inline Point3D<float> operator+(const Vector3D& lhs, const Point3D<T>& rhs) {
        return rhs + lhs;
    }
}

#endif // PINE_MATH_VECTOR_VECTOR3D_H