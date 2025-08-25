#ifndef PINE_MATH_VECTOR_H
#define PINE_MATH_VECTOR_H

#include "point.h"

#include <cmath>

namespace Pine
{
    struct Vector2D;
    struct Vector3D;


    inline Vector2D normalize(Vector2D v);
    inline Vector3D normalize(Vector3D v);

    inline float dot(Vector2D v1, Vector2D v2);
    inline float dot(Vector3D v1, Vector3D v2);

    inline Vector3D cross(Vector3D v1, Vector3D v2);

    // Operators for getting the vector from p1 (rhs) to p2 (lhs)
    template <typename T1, typename T2>
    inline Vector2D operator-(const Point2D<T1>& lhs, const Point2D<T2>& rhs);
    template <typename T1, typename T2>
    inline Vector3D operator-(const Point3D<T1>& lhs, const Point3D<T2>& rhs);

    // Operators for getting the point a vector is pointing to from another point
    template <typename T>
    inline Point2D<float> operator+(const Point2D<T>& lhs, const Vector2D& rhs);
    template <typename T>
    inline Point2D<float> operator+(const Vector2D& lhs, const Point2D<T>& rhs);
    template <typename T>
    inline Point3D<float> operator+(const Point3D<T>& lhs, const Vector3D& rhs);
    template <typename T>
    inline Point3D<float> operator+(const Vector3D& lhs, const Point3D<T>& rhs);

    // vvv Vector2D vvv

    struct Vector2D
    {
        float x;
        float y;


        inline Vector2D() {}
        inline Vector2D(float x, float y) : x(x), y(y) {}

        inline bool operator==(const Vector2D& other) const;
        inline bool operator!=(const Vector2D& other) const;

        inline Vector2D& operator+=(const Vector2D& rhs);
        inline Vector2D& operator-=(const Vector2D& rhs);
        inline Vector2D& operator*=(float scalar);
        inline Vector2D& operator/=(float scalar);

        friend inline Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs);
        friend inline Vector2D operator-(const Vector2D& lhs, const Vector2D& rhs);
        friend inline Vector2D operator*(const Vector2D& v, float scalar);
        friend inline Vector2D operator*(float scalar, const Vector2D& v);
        friend inline Vector2D operator/(const Vector2D& v, float scalar);

        inline float length() const;
    };



    inline bool Vector2D::operator==(const Vector2D& other) const {
        return x == other.x && y == other.y;
    }

    inline bool Vector2D::operator!=(const Vector2D& other) const {
        return !operator==(other);
    }



    inline Vector2D& Vector2D::operator+=(const Vector2D& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    inline Vector2D& Vector2D::operator-=(const Vector2D& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    inline Vector2D& Vector2D::operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    inline Vector2D& Vector2D::operator/=(float scalar)
    {
        x /= scalar;
        y /= scalar;
        return *this;
    }



    inline Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs)
    {
        Vector2D result = lhs;
        result += rhs;
        return result;
    }

    inline Vector2D operator-(const Vector2D& lhs, const Vector2D& rhs)
    {
        Vector2D result = lhs;
        result -= rhs;
        return result;
    }

    inline Vector2D operator*(const Vector2D& v, float scalar)
    {
        Vector2D result = v;
        result *= scalar;
        return result;
    }

    inline Vector2D operator*(float scalar, const Vector2D& v) {
        return v * scalar;
    }

    inline Vector2D operator/(const Vector2D& v, float scalar)
    {
        Vector2D result = v;
        result /= scalar;
        return result;
    }



    inline float Vector2D::length() const {
        return std::sqrt((x * x) + (y * y));
    }

    // vvv Vector3D vvv // ^^^ Vector2D ^^^

    struct Vector3D
    {
        float x;
        float y;
        float z;


        inline Vector3D() {}
        inline Vector3D(float x, float y, float z) : x(x), y(y), z(z) {}

        inline bool operator==(const Vector3D& other) const;
        inline bool operator!=(const Vector3D& other) const;

        inline Vector3D& operator+=(const Vector3D& rhs);
        inline Vector3D& operator-=(const Vector3D& rhs);
        inline Vector3D& operator*=(float scalar);
        inline Vector3D& operator/=(float scalar);

        friend inline Vector3D operator+(const Vector3D& lhs, const Vector3D& rhs);
        friend inline Vector3D operator-(const Vector3D& lhs, const Vector3D& rhs);
        friend inline Vector3D operator*(const Vector3D& v, float scalar);
        friend inline Vector3D operator*(float scalar, const Vector3D& v);
        friend inline Vector3D operator/(const Vector3D& v, float scalar);

        inline float length() const;
    };



    inline bool Vector3D::operator==(const Vector3D& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    inline bool Vector3D::operator!=(const Vector3D& other) const {
        return !operator==(other);
    }



    inline Vector3D& Vector3D::operator+=(const Vector3D& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }

    inline Vector3D& Vector3D::operator-=(const Vector3D& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }

    inline Vector3D& Vector3D::operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    inline Vector3D& Vector3D::operator/=(float scalar)
    {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }



    inline Vector3D operator+(const Vector3D& lhs, const Vector3D& rhs)
    {
        Vector3D result = lhs;
        result += rhs;
        return result;
    }

    inline Vector3D operator-(const Vector3D& lhs, const Vector3D& rhs)
    {
        Vector3D result = lhs;
        result -= rhs;
        return result;
    }

    inline Vector3D operator*(const Vector3D& v, float scalar)
    {
        Vector3D result = v;
        result *= scalar;
        return result;
    }

    inline Vector3D operator*(float scalar, const Vector3D& v) {
        return v * scalar;
    }

    inline Vector3D operator/(const Vector3D& v, float scalar)
    {
        Vector3D result = v;
        result /= scalar;
        return result;
    }



    inline float Vector3D::length() const {
        return std::sqrt((x * x) + (y * y) + (z * z));
    }

    // vvv Free Functions vvv // ^^^ Vector3D ^^^

    inline Vector2D normalize(Vector2D v) {
        return v / v.length();
    }

    inline Vector3D normalize(Vector3D v) {
        return v / v.length();
    }



    inline float dot(Vector2D v1, Vector2D v2) {
        return (v1.x * v2.x) + (v1.y * v2.y);
    }

    inline float dot(Vector3D v1, Vector3D v2) {
        return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
    }



    inline Vector3D cross(Vector3D v1, Vector3D v2)
    {
        Vector3D result;
        result.x = (v1.y * v2.z) - (v1.z * v2.y);
        result.y = (v1.z * v2.x) - (v1.x * v2.z);
        result.z = (v1.x * v2.y) - (v1.y * v2.x);
        return result;
    }



    template <typename T1, typename T2>
    inline Vector2D operator-(const Point2D<T1>& lhs, const Point2D<T2>& rhs)
    {
        Vector2D result;
        result.x = lhs.x - rhs.x;
        result.y = lhs.y - rhs.y;
        return result;
    }

    template <typename T1, typename T2>
    inline Vector3D operator-(const Point3D<T1>& lhs, const Point3D<T2>& rhs)
    {
        Vector3D result;
        result.x = lhs.x - rhs.x;
        result.y = lhs.y - rhs.y;
        result.z = lhs.z - rhs.z;
        return result;
    }



    template <typename T>
    inline Point2D<float> operator+(const Point2D<T>& lhs, const Vector2D& rhs)
    {
        Point2D<float> result;
        result.x = lhs.x + rhs.x;
        result.y = lhs.y + rhs.y;
        return result;
    }

    template <typename T>
    inline Point2D<float> operator+(const Vector2D& lhs, const Point2D<T>& rhs) {
        return rhs + lhs;
    }

    template <typename T>
    inline Point3D<float> operator+(const Point3D<T>& lhs, const Vector3D& rhs)
    {
        Point3D<float> result;
        result.x = lhs.x + rhs.x;
        result.y = lhs.y + rhs.y;
        result.z = lhs.z + rhs.z;
        return result;
    }

    template <typename T>
    inline Point3D<float> operator+(const Vector3D& lhs, const Point3D<T>& rhs) {
        return rhs + lhs;
    }
}

#endif // PINE_MATH_VECTOR_H