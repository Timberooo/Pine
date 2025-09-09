#ifndef PINE_MATH_VECTOR_VEC3_H
#define PINE_MATH_VECTOR_VEC3_H

#include "../math_common.h"
#include "../point.h"

#include <cmath>

namespace Pine
{
    struct Vec3;

    typedef Vec3 Vector3;
    typedef Vec3 Vector3D;


    constexpr inline Vec3 normalize(const Vec3& v);

    constexpr inline float dot(const Vec3& v1, const Vec3& v2);

    constexpr inline Vec3 cross(const Vec3& v1, const Vec3& v2);

    template <typename T1, typename T2>
    constexpr inline Vec3 operator-(const Point3D<T1>& lhs, const Point3D<T2>& rhs);

    template <typename T>
    constexpr inline Point3D<float> operator+(const Point3D<T>& lhs, const Vec3& rhs);
    template <typename T>
    constexpr inline Point3D<float> operator+(const Vec3& lhs, const Point3D<T>& rhs);

    // vvv Vec3 vvv

    struct Vec3
    {
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;


        static constexpr inline Vec3 zero();


        constexpr inline Vec3();
        constexpr inline Vec3(float x, float y, float z);

        constexpr inline bool operator==(const Vec3& other) const;
        constexpr inline bool operator!=(const Vec3& other) const;

        constexpr inline Vec3& operator+=(const Vec3& rhs);
        constexpr inline Vec3& operator-=(const Vec3& rhs);
        constexpr inline Vec3& operator*=(float s);
        constexpr inline Vec3& operator/=(float s);

        constexpr friend inline Vec3 operator+(const Vec3& lhs, const Vec3& rhs);
        constexpr friend inline Vec3 operator-(const Vec3& lhs, const Vec3& rhs);
        constexpr friend inline Vec3 operator*(const Vec3& v, float s);
        constexpr friend inline Vec3 operator*(float s, const Vec3& v);
        constexpr friend inline Vec3 operator/(const Vec3& v, float s);

        constexpr inline float length() const;
    };



    constexpr inline Vec3 Vec3::zero() {
        return Vec3();
    }



    constexpr inline Vec3::Vec3() {}

    constexpr inline Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}



    constexpr inline bool Vec3::operator==(const Vec3& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    constexpr inline bool Vec3::operator!=(const Vec3& other) const {
        return !operator==(other);
    }



    constexpr inline Vec3& Vec3::operator+=(const Vec3& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }

    constexpr inline Vec3& Vec3::operator-=(const Vec3& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }

    constexpr inline Vec3& Vec3::operator*=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }

    constexpr inline Vec3& Vec3::operator/=(float s)
    {
        x /= s;
        y /= s;
        z /= s;
        return *this;
    }



    constexpr inline Vec3 operator+(const Vec3& lhs, const Vec3& rhs)
    {
        Vec3 result = lhs;
        result += rhs;
        return result;
    }

    constexpr inline Vec3 operator-(const Vec3& lhs, const Vec3& rhs)
    {
        Vec3 result = lhs;
        result -= rhs;
        return result;
    }

    constexpr inline Vec3 operator*(const Vec3& v, float s)
    {
        Vec3 result = v;
        result *= s;
        return result;
    }

    constexpr inline Vec3 operator*(float s, const Vec3& v) {
        return v * s;
    }

    constexpr inline Vec3 operator/(const Vec3& v, float s)
    {
        Vec3 result = v;
        result /= s;
        return result;
    }



    constexpr inline float Vec3::length() const {
        return std::sqrt(square(x) + square(y) + square(z));
    }

    // vvv Free Functions vvv // ^^^ Vec3 ^^^

    constexpr inline Vec3 normalize(const Vec3& v) {
        return v / v.length();
    }



    constexpr inline float dot(const Vec3& v1, const Vec3& v2) {
        return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
    }



    constexpr inline Vec3 cross(const Vec3& v1, const Vec3& v2)
    {
        Vec3 result;
        result.x = (v1.y * v2.z) - (v1.z * v2.y);
        result.y = (v1.z * v2.x) - (v1.x * v2.z);
        result.z = (v1.x * v2.y) - (v1.y * v2.x);
        return result;
    }



    template <typename T1, typename T2>
    constexpr inline Vec3 operator-(const Point3D<T1>& lhs, const Point3D<T2>& rhs)
    {
        Vec3 result;
        result.x = lhs.x - rhs.x;
        result.y = lhs.y - rhs.y;
        result.z = lhs.z - rhs.z;
        return result;
    }

    template <typename T>
    constexpr inline Point3D<float> operator+(const Point3D<T>& lhs, const Vec3& rhs)
    {
        Point3D<float> result;
        result.x = lhs.x + rhs.x;
        result.y = lhs.y + rhs.y;
        result.z = lhs.z + rhs.z;
        return result;
    }

    template <typename T>
    constexpr inline Point3D<float> operator+(const Vec3& lhs, const Point3D<T>& rhs) {
        return rhs + lhs;
    }
}

#endif // PINE_MATH_VECTOR_VEC3_H