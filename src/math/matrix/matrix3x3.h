#ifndef PINE_MATH_MATRIX_MATRIX3X3_H
#define PINE_MATH_MATRIX_MATRIX3X3_H

#include "../vector/vec3.h"

namespace Pine
{
    struct Matrix3x3;

    typedef Matrix3x3 Matrix3;
    typedef Matrix3x3 Mat3;


    constexpr inline Vector3D operator*(const Matrix3x3& m, const Vector3D& v); // A * v

    // vvv Matrix3x3 vvv

    struct Matrix3x3
    {
        Vector3D col1 = Vector3D();
        Vector3D col2 = Vector3D();
        Vector3D col3 = Vector3D();


        static constexpr inline Matrix3x3 identity();
        static constexpr inline Matrix3x3 zero();


        constexpr inline Matrix3x3();
        constexpr inline Matrix3x3(const Vector3D& col1, const Vector3D& col2, const Vector3D& col3);

        constexpr inline bool operator==(const Matrix3x3& other) const;
        constexpr inline bool operator!=(const Matrix3x3& other) const;

        constexpr inline Matrix3x3& operator+=(const Matrix3x3& other); // A += B
        constexpr inline Matrix3x3& operator-=(const Matrix3x3& other); // A -= B
        constexpr inline Matrix3x3& operator*=(const Matrix3x3& other); // A *= B
        constexpr inline Matrix3x3& operator*=(float s); // A *= s
        constexpr inline Matrix3x3& operator/=(float s); // A /= s

        constexpr friend inline Matrix3x3 operator+(const Matrix3x3& lhs, const Matrix3x3& rhs); // A + B
        constexpr friend inline Matrix3x3 operator-(const Matrix3x3& lhs, const Matrix3x3& rhs); // A - B
        constexpr friend inline Matrix3x3 operator*(const Matrix3x3& lhs, const Matrix3x3& rhs); // A * B
        constexpr friend inline Matrix3x3 operator*(const Matrix3x3& m, float s); // A * s
        constexpr friend inline Matrix3x3 operator*(float s, const Matrix3x3& m); // s * A
        constexpr friend inline Matrix3x3 operator/(const Matrix3x3& m, float s); // A / s

        constexpr inline Vector3D row1() const;
        constexpr inline Vector3D row2() const;
        constexpr inline Vector3D row3() const;
    };

    
    // [ 1 0 0 ]
    // [ 0 1 0 ]
    // [ 0 0 1 ]
    constexpr inline Matrix3x3 Matrix3x3::identity() {
        return Matrix3x3({1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f});
    }

    // [ 0 0 0 ]
    // [ 0 0 0 ]
    // [ 0 0 0 ]
    constexpr inline Matrix3x3 Matrix3x3::zero() {
        return Matrix3x3();
    }



    constexpr inline Matrix3x3::Matrix3x3() {}

    constexpr inline Matrix3x3::Matrix3x3(const Vector3D& col1, const Vector3D& col2, const Vector3D& col3) : col1(col1), col2(col2), col3(col3) {}



    constexpr inline bool Matrix3x3::operator==(const Matrix3x3& other) const {
        return col1 == other.col1 && col2 == other.col2 && col3 == other.col3;
    }

    constexpr inline bool Matrix3x3::operator!=(const Matrix3x3& other) const {
        return !operator==(other);
    }



    constexpr inline Matrix3x3& Matrix3x3::operator+=(const Matrix3x3& other)
    {
        col1 += other.col1;
        col2 += other.col2;
        col3 += other.col3;
        return *this;
    }

    constexpr inline Matrix3x3& Matrix3x3::operator-=(const Matrix3x3& other)
    {
        col1 -= other.col1;
        col2 -= other.col2;
        col3 -= other.col3;
        return *this;
    }

    constexpr inline Matrix3x3& Matrix3x3::operator*=(const Matrix3x3& other)
    {
        // Implemented in terms of operator* because a
        // copy is required to perform this operation
        *this = *this * other;
        return *this;
    }

    constexpr inline Matrix3x3& Matrix3x3::operator*=(float s)
    {
        col1 *= s;
        col2 *= s;
        col3 *= s;
        return *this;
    }

    constexpr inline Matrix3x3& Matrix3x3::operator/=(float s)
    {
        col1 /= s;
        col2 /= s;
        col3 /= s;
        return *this;
    }



    constexpr inline Matrix3x3 operator+(const Matrix3x3& lhs, const Matrix3x3& rhs)
    {
        Matrix3x3 result = lhs;
        result += rhs;
        return result;
    }

    constexpr inline Matrix3x3 operator-(const Matrix3x3& lhs, const Matrix3x3& rhs)
    {
        Matrix3x3 result = lhs;
        result += rhs;
        return result;
    }

    constexpr inline Matrix3x3 operator*(const Matrix3x3& lhs, const Matrix3x3& rhs)
    {
        Matrix3x3 result = lhs;
        result.col1.x = dot(lhs.row1(), rhs.col1);
        result.col1.y = dot(lhs.row2(), rhs.col1);
        result.col1.z = dot(lhs.row3(), rhs.col1);
        result.col2.x = dot(lhs.row1(), rhs.col2);
        result.col2.y = dot(lhs.row2(), rhs.col2);
        result.col2.z = dot(lhs.row3(), rhs.col2);
        result.col3.x = dot(lhs.row1(), rhs.col3);
        result.col3.y = dot(lhs.row2(), rhs.col3);
        result.col3.z = dot(lhs.row3(), rhs.col3);
        return result;
    }

    constexpr inline Matrix3x3 operator*(const Matrix3x3& m, float s)
    {
        Matrix3x3 result = m;
        result *= s;
        return result;
    }

    constexpr inline Matrix3x3 operator*(float s, const Matrix3x3& m) {
        return m * s;
    }

    constexpr inline Matrix3x3 operator/(const Matrix3x3& m, float s)
    {
        Matrix3x3 result = m;
        result /= s;
        return result;
    }



    constexpr inline Vector3D Matrix3x3::row1() const {
        return Vector3D(col1.x, col2.x, col3.x);
    }

    constexpr inline Vector3D Matrix3x3::row2() const {
        return Vector3D(col1.y, col2.y, col3.y);
    }

    constexpr inline Vector3D Matrix3x3::row3() const {
        return Vector3D(col1.z, col2.z, col3.z);
    }

    // vvv Free Functions vvv // ^^^ Matrix3x3 ^^^

    constexpr inline Vector3D operator*(const Matrix3x3& m, const Vector3D& v)
    {
        // - n of A and m of B must match for multiplication to work.
        // - m of A and n of B dictate the order of A * B.
        //     A         B            A * B
        //  mA x nA   mB x nB        mA x nB
        //    3x3       3x1            3x1
        // [ a b c ]   [ x ]   [ a*x + b*y + c*z ]
        // [ d e f ] * [ y ] = [ d*x + e*y + f*z ]
        // [ g h i ]   [ z ]   [ g*x + h*y + i*z ]
        return Vector3D(dot(v, m.row1()),
                        dot(v, m.row2()),
                        dot(v, m.row3()));
    }
}

#endif // PINE_MATH_MATRIX_MATRIX3X3_H