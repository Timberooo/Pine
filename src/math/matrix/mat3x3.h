#ifndef PINE_MATH_MATRIX_MAT3X3_H
#define PINE_MATH_MATRIX_MAT3X3_H

#include "../vector/vec3.h"

namespace Pine
{
    struct Mat3;

    typedef Mat3 Mat3x3;
    typedef Mat3 Matrix3;
    typedef Mat3 Matrix3x3;


    constexpr inline Vec3 operator*(const Mat3& m, const Vec3& v); // A * v

    // vvv Mat3 vvv

    struct Mat3
    {
        Vec3 col1 = Vec3();
        Vec3 col2 = Vec3();
        Vec3 col3 = Vec3();


        static constexpr inline Mat3 identity();
        static constexpr inline Mat3 zero();


        constexpr inline Mat3();
        constexpr inline Mat3(const Vec3& col1, const Vec3& col2, const Vec3& col3);

        constexpr inline bool operator==(const Mat3& other) const;
        constexpr inline bool operator!=(const Mat3& other) const;

        constexpr inline Mat3& operator+=(const Mat3& other); // A += B
        constexpr inline Mat3& operator-=(const Mat3& other); // A -= B
        constexpr inline Mat3& operator*=(const Mat3& other); // A *= B
        constexpr inline Mat3& operator*=(float s); // A *= s
        constexpr inline Mat3& operator/=(float s); // A /= s

        constexpr friend inline Mat3 operator+(const Mat3& lhs, const Mat3& rhs); // A + B
        constexpr friend inline Mat3 operator-(const Mat3& lhs, const Mat3& rhs); // A - B
        constexpr friend inline Mat3 operator*(const Mat3& lhs, const Mat3& rhs); // A * B
        constexpr friend inline Mat3 operator*(const Mat3& m, float s); // A * s
        constexpr friend inline Mat3 operator*(float s, const Mat3& m); // s * A
        constexpr friend inline Mat3 operator/(const Mat3& m, float s); // A / s

        constexpr inline Vec3 row1() const;
        constexpr inline Vec3 row2() const;
        constexpr inline Vec3 row3() const;
    };

    
    // [ 1 0 0 ]
    // [ 0 1 0 ]
    // [ 0 0 1 ]
    constexpr inline Mat3 Mat3::identity() {
        return Mat3({1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f});
    }

    // [ 0 0 0 ]
    // [ 0 0 0 ]
    // [ 0 0 0 ]
    constexpr inline Mat3 Mat3::zero() {
        return Mat3();
    }



    constexpr inline Mat3::Mat3() {}

    constexpr inline Mat3::Mat3(const Vec3& col1, const Vec3& col2, const Vec3& col3) : col1(col1), col2(col2), col3(col3) {}



    constexpr inline bool Mat3::operator==(const Mat3& other) const {
        return col1 == other.col1 && col2 == other.col2 && col3 == other.col3;
    }

    constexpr inline bool Mat3::operator!=(const Mat3& other) const {
        return !operator==(other);
    }



    constexpr inline Mat3& Mat3::operator+=(const Mat3& other)
    {
        col1 += other.col1;
        col2 += other.col2;
        col3 += other.col3;
        return *this;
    }

    constexpr inline Mat3& Mat3::operator-=(const Mat3& other)
    {
        col1 -= other.col1;
        col2 -= other.col2;
        col3 -= other.col3;
        return *this;
    }

    constexpr inline Mat3& Mat3::operator*=(const Mat3& other)
    {
        // Implemented in terms of operator* because a
        // copy is required to perform this operation
        *this = *this * other;
        return *this;
    }

    constexpr inline Mat3& Mat3::operator*=(float s)
    {
        col1 *= s;
        col2 *= s;
        col3 *= s;
        return *this;
    }

    constexpr inline Mat3& Mat3::operator/=(float s)
    {
        col1 /= s;
        col2 /= s;
        col3 /= s;
        return *this;
    }



    constexpr inline Mat3 operator+(const Mat3& lhs, const Mat3& rhs)
    {
        Mat3 result = lhs;
        result += rhs;
        return result;
    }

    constexpr inline Mat3 operator-(const Mat3& lhs, const Mat3& rhs)
    {
        Mat3 result = lhs;
        result += rhs;
        return result;
    }

    constexpr inline Mat3 operator*(const Mat3& lhs, const Mat3& rhs)
    {
        Mat3 result = lhs;
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

    constexpr inline Mat3 operator*(const Mat3& m, float s)
    {
        Mat3 result = m;
        result *= s;
        return result;
    }

    constexpr inline Mat3 operator*(float s, const Mat3& m) {
        return m * s;
    }

    constexpr inline Mat3 operator/(const Mat3& m, float s)
    {
        Mat3 result = m;
        result /= s;
        return result;
    }



    constexpr inline Vec3 Mat3::row1() const {
        return Vec3(col1.x, col2.x, col3.x);
    }

    constexpr inline Vec3 Mat3::row2() const {
        return Vec3(col1.y, col2.y, col3.y);
    }

    constexpr inline Vec3 Mat3::row3() const {
        return Vec3(col1.z, col2.z, col3.z);
    }

    // vvv Free Functions vvv // ^^^ Mat3 ^^^

    constexpr inline Vec3 operator*(const Mat3& m, const Vec3& v)
    {
        // - n of A and m of B must match for multiplication to work.
        // - m of A and n of B dictate the order of A * B.
        //     A         B            A * B
        //  mA x nA   mB x nB        mA x nB
        //    3x3       3x1            3x1
        // [ a b c ]   [ x ]   [ a*x + b*y + c*z ]
        // [ d e f ] * [ y ] = [ d*x + e*y + f*z ]
        // [ g h i ]   [ z ]   [ g*x + h*y + i*z ]
        return Vec3(dot(v, m.row1()),
                    dot(v, m.row2()),
                    dot(v, m.row3()));
    }
}

#endif // PINE_MATH_MATRIX_MAT3X3_H