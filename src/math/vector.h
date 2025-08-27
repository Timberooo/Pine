#ifndef PINE_MATH_VECTOR_H
#define PINE_MATH_VECTOR_H

#include "point.h"

#include <cmath>

namespace Pine
{
    struct Vector2D;
    struct Vector3D;
    struct Vector4D;


    constexpr inline Vector2D normalize(const Vector2D& v);
    constexpr inline Vector3D normalize(const Vector3D& v);
    constexpr inline Vector4D normalize(const Vector4D& v);

    constexpr inline float dot(const Vector2D& v1, const Vector2D& v2);
    constexpr inline float dot(const Vector3D& v1, const Vector3D& v2);
    constexpr inline float dot(const Vector4D& v1, const Vector4D& v2);

    constexpr inline Vector3D cross(const Vector3D& v1, const Vector3D& v2);

    // Operators for getting the vector from p1 (rhs) to p2 (lhs)
    template <typename T1, typename T2>
    constexpr inline Vector2D operator-(const Point2D<T1>& lhs, const Point2D<T2>& rhs);
    template <typename T1, typename T2>
    constexpr inline Vector3D operator-(const Point3D<T1>& lhs, const Point3D<T2>& rhs);

    // Operators for getting the point a vector is pointing to from another point
    template <typename T>
    constexpr inline Point2D<float> operator+(const Point2D<T>& lhs, const Vector2D& rhs);
    template <typename T>
    constexpr inline Point2D<float> operator+(const Vector2D& lhs, const Point2D<T>& rhs);
    template <typename T>
    constexpr inline Point3D<float> operator+(const Point3D<T>& lhs, const Vector3D& rhs);
    template <typename T>
    constexpr inline Point3D<float> operator+(const Vector3D& lhs, const Point3D<T>& rhs);

    // vvv Vector2D vvv

    struct Vector2D
    {
        float x {};
        float y {};


        constexpr inline Vector2D() {}
        constexpr inline Vector2D(float x, float y) : x(x), y(y) {}

        constexpr inline bool operator==(const Vector2D& other) const;
        constexpr inline bool operator!=(const Vector2D& other) const;

        constexpr inline Vector2D& operator+=(const Vector2D& rhs);
        constexpr inline Vector2D& operator-=(const Vector2D& rhs);
        constexpr inline Vector2D& operator*=(float scalar);
        constexpr inline Vector2D& operator/=(float scalar);

        constexpr friend inline Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs);
        constexpr friend inline Vector2D operator-(const Vector2D& lhs, const Vector2D& rhs);
        constexpr friend inline Vector2D operator*(const Vector2D& v, float scalar);
        constexpr friend inline Vector2D operator*(float scalar, const Vector2D& v);
        constexpr friend inline Vector2D operator/(const Vector2D& v, float scalar);

        constexpr inline float length() const;
    };



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

    constexpr inline Vector2D& Vector2D::operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    constexpr inline Vector2D& Vector2D::operator/=(float scalar)
    {
        x /= scalar;
        y /= scalar;
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

    constexpr inline Vector2D operator*(const Vector2D& v, float scalar)
    {
        Vector2D result = v;
        result *= scalar;
        return result;
    }

    constexpr inline Vector2D operator*(float scalar, const Vector2D& v) {
        return v * scalar;
    }

    constexpr inline Vector2D operator/(const Vector2D& v, float scalar)
    {
        Vector2D result = v;
        result /= scalar;
        return result;
    }



    constexpr inline float Vector2D::length() const {
        return std::sqrt((x * x) + (y * y));
    }

    // vvv Vector3D vvv // ^^^ Vector2D ^^^

    struct Vector3D
    {
        float x {};
        float y {};
        float z {};


        constexpr inline Vector3D() {}
        constexpr inline Vector3D(float x, float y, float z) : x(x), y(y), z(z) {}

        constexpr inline bool operator==(const Vector3D& other) const;
        constexpr inline bool operator!=(const Vector3D& other) const;

        constexpr inline Vector3D& operator+=(const Vector3D& rhs);
        constexpr inline Vector3D& operator-=(const Vector3D& rhs);
        constexpr inline Vector3D& operator*=(float scalar);
        constexpr inline Vector3D& operator/=(float scalar);

        constexpr friend inline Vector3D operator+(const Vector3D& lhs, const Vector3D& rhs);
        constexpr friend inline Vector3D operator-(const Vector3D& lhs, const Vector3D& rhs);
        constexpr friend inline Vector3D operator*(const Vector3D& v, float scalar);
        constexpr friend inline Vector3D operator*(float scalar, const Vector3D& v);
        constexpr friend inline Vector3D operator/(const Vector3D& v, float scalar);

        constexpr inline float length() const;
    };



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

    constexpr inline Vector3D& Vector3D::operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    constexpr inline Vector3D& Vector3D::operator/=(float scalar)
    {
        x /= scalar;
        y /= scalar;
        z /= scalar;
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

    constexpr inline Vector3D operator*(const Vector3D& v, float scalar)
    {
        Vector3D result = v;
        result *= scalar;
        return result;
    }

    constexpr inline Vector3D operator*(float scalar, const Vector3D& v) {
        return v * scalar;
    }

    constexpr inline Vector3D operator/(const Vector3D& v, float scalar)
    {
        Vector3D result = v;
        result /= scalar;
        return result;
    }



    constexpr inline float Vector3D::length() const {
        return std::sqrt((x * x) + (y * y) + (z * z));
    }

    // vvv Vector4D vvv // ^^^ Vector3D ^^^

    struct Vector4D
    {
        float x {};
        float y {};
        float z {};
        float w {};


        constexpr inline Vector4D() {}
        constexpr inline Vector4D(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

        constexpr inline bool operator==(const Vector4D& other) const;
        constexpr inline bool operator!=(const Vector4D& other) const;

        constexpr inline Vector4D& operator+=(const Vector4D& rhs);
        constexpr inline Vector4D& operator-=(const Vector4D& rhs);
        constexpr inline Vector4D& operator*=(float scalar);
        constexpr inline Vector4D& operator/=(float scalar);

        constexpr friend inline Vector4D operator+(const Vector4D& lhs, const Vector4D& rhs);
        constexpr friend inline Vector4D operator-(const Vector4D& lhs, const Vector4D& rhs);
        constexpr friend inline Vector4D operator*(const Vector4D& v, float scalar);
        constexpr friend inline Vector4D operator*(float scalar, const Vector4D& v);
        constexpr friend inline Vector4D operator/(const Vector4D& v, float scalar);

        constexpr inline float length() const;
    };



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

    constexpr inline Vector4D& Vector4D::operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        w *= scalar;
        return *this;
    }

    constexpr inline Vector4D& Vector4D::operator/=(float scalar)
    {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        w /= scalar;
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

    constexpr inline Vector4D operator*(const Vector4D& v, float scalar)
    {
        Vector4D result = v;
        result *= scalar;
        return result;
    }

    constexpr inline Vector4D operator*(float scalar, const Vector4D& v) {
        return v * scalar;
    }

    constexpr inline Vector4D operator/(const Vector4D& v, float scalar)
    {
        Vector4D result = v;
        result /= scalar;
        return result;
    }



    constexpr inline float Vector4D::length() const {
        return std::sqrt((x * x) + (y * y) + (z * z) + (w * w));
    }

    // vvv Free Functions vvv // ^^^ Vector4D ^^^

    constexpr inline Vector2D normalize(const Vector2D& v) {
        return v / v.length();
    }

    constexpr inline Vector3D normalize(const Vector3D& v) {
        return v / v.length();
    }

    constexpr inline Vector4D normalize(const Vector4D& v) {
        return v / v.length();
    }



    constexpr inline float dot(const Vector2D& v1, const Vector2D& v2) {
        return (v1.x * v2.x) + (v1.y * v2.y);
    }

    constexpr inline float dot(const Vector3D& v1, const Vector3D& v2) {
        return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
    }

    constexpr inline float dot(const Vector4D& v1, const Vector4D& v2) {
        return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z) + (v1.w * v2.w);
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
    constexpr inline Vector2D operator-(const Point2D<T1>& lhs, const Point2D<T2>& rhs)
    {
        Vector2D result;
        result.x = lhs.x - rhs.x;
        result.y = lhs.y - rhs.y;
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

#endif // PINE_MATH_VECTOR_H