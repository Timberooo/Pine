#ifndef PINE_MATH_MATRIX_MAT2X2_H
#define PINE_MATH_MATRIX_MAT2X2_H

#include "../vector/vec2.h"

namespace Pine
{
    struct Mat2;

    typedef Mat2 Mat2x2;
    typedef Mat2 Matrix2;
    typedef Mat2 Matrix2x2;


    constexpr inline Vec2 operator*(const Mat2& m, const Vec2& v); // A * v

    // vvv Mat2 vvv

    struct Mat2
    {
        Vec2 col1 = Vec2();
        Vec2 col2 = Vec2();


        static constexpr inline Mat2 identity();
        static constexpr inline Mat2 zero();


        constexpr inline Mat2();
        constexpr inline Mat2(const Vec2& col1, const Vec2& col2);

        constexpr inline bool operator==(const Mat2& other) const;
        constexpr inline bool operator!=(const Mat2& other) const;

        constexpr inline Mat2& operator+=(const Mat2& other); // A += B
        constexpr inline Mat2& operator-=(const Mat2& other); // A -= B
        constexpr inline Mat2& operator*=(const Mat2& other); // A *= B
        constexpr inline Mat2& operator*=(float s); // A *= s
        constexpr inline Mat2& operator/=(float s); // A /= s

        constexpr friend inline Mat2 operator+(const Mat2& lhs, const Mat2& rhs); // A + B
        constexpr friend inline Mat2 operator-(const Mat2& lhs, const Mat2& rhs); // A - B
        constexpr friend inline Mat2 operator*(const Mat2& lhs, const Mat2& rhs); // A * B
        constexpr friend inline Mat2 operator*(const Mat2& m, float s); // A * s
        constexpr friend inline Mat2 operator*(float s, const Mat2& m); // s * A
        constexpr friend inline Mat2 operator/(const Mat2& m, float s); // A / s

        constexpr inline Vec2 row1() const;
        constexpr inline Vec2 row2() const;
    };



    // [ 1 0 ]
    // [ 0 1 ]
    constexpr inline Mat2 Mat2::identity() {
        return Mat2({1.0f, 0.0f}, {0.0f, 1.0f});
    }

    // [ 0 0 ]
    // [ 0 0 ]
    constexpr inline Mat2 Mat2::zero() {
        return Mat2();
    }



    constexpr inline Mat2::Mat2() {}

    constexpr inline Mat2::Mat2(const Vec2& col1, const Vec2& col2) : col1(col1), col2(col2) {}



    constexpr inline bool Mat2::operator==(const Mat2& other) const {
        return col1 == other.col1 && col2 == other.col2;
    }

    constexpr inline bool Mat2::operator!=(const Mat2& other) const {
        return !operator==(other);
    }



    constexpr inline Mat2& Mat2::operator+=(const Mat2& other)
    {
        col1 += other.col1;
        col2 += other.col2;
        return *this;
    }

    constexpr inline Mat2& Mat2::operator-=(const Mat2& other)
    {
        col1 -= other.col1;
        col2 -= other.col2;
        return *this;
    }

    constexpr inline Mat2& Mat2::operator*=(const Mat2& other)
    {
        // Impelmented in terms of operator* because a
        // copy is required to perform this operation
        *this = *this * other;
        return *this;
    }

    constexpr inline Mat2& Mat2::operator*=(float s)
    {
        col1 *= s;
        col2 *= s;
        return *this;
    }

    constexpr inline Mat2& Mat2::operator/=(float s)
    {
        col1 /= s;
        col2 /= s;
        return *this;
    }



    constexpr inline Mat2 operator+(const Mat2& lhs, const Mat2& rhs)
    {
        Mat2 result = lhs;
        result += rhs;
        return result;
    }

    constexpr inline Mat2 operator-(const Mat2& lhs, const Mat2& rhs)
    {
        Mat2 result = lhs;
        result -= rhs;
        return result;
    }

    constexpr inline Mat2 operator*(const Mat2& lhs, const Mat2& rhs)
    {
        Mat2 result = lhs;
        result.col1.x = dot(lhs.row1(), rhs.col1);
        result.col1.y = dot(lhs.row2(), rhs.col1);
        result.col2.x = dot(lhs.row1(), rhs.col2);
        result.col2.y = dot(lhs.row2(), rhs.col2);
        return result;
    }

    constexpr inline Mat2 operator*(const Mat2& m, float s)
    {
        Mat2 result = m;
        result *= s;
        return result;
    }

    constexpr inline Mat2 operator*(float s, const Mat2& m) {
        return m * s;
    }

    constexpr inline Mat2 operator/(const Mat2& m, float s)
    {
        Mat2 result = m;
        result /= s;
        return result;
    }



    constexpr inline Vec2 Mat2::row1() const {
        return Vec2(col1.x, col2.x);
    }

    constexpr inline Vec2 Mat2::row2() const {
        return Vec2(col1.y, col2.y);
    }

    // vvv Free Functions vvv // ^^^ Mat2 ^^^

    constexpr inline Vec2 operator*(const Mat2& m, const Vec2& v)
    {
        // - n of A and m of B must match for multiplication to work.
        // - m of A and n of B dictate the order of A * B.
        //    A        B         A * B
        // mA x nA  mB x nB     mA x nB
        //   2x2      2x1         2x1
        // [ a b ] * [ x ] = [ a*x + b*y ]
        // [ c d ]   [ y ]   [ c*x + d*y ]
        return Vec2(dot(v, m.row1()),
                    dot(v, m.row2()));
    }
}

#endif // PINE_MATH_MATRIX_MAT2X2_H