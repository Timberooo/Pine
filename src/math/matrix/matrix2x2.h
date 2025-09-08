#ifndef PINE_MATH_MATRIX_MATRIX2X2_H
#define PINE_MATH_MATRIX_MATRIX2X2_H

#include "../vector/vector2d.h"

namespace Pine
{
    struct Matrix2x2;


    constexpr inline Vector2D& operator*=(Vector2D& v, const Matrix2x2& m); // v *= A

    constexpr inline Vector2D operator*(const Vector2D& v, const Matrix2x2& m); // v * A
    constexpr inline Vector2D operator*(const Matrix2x2& m, const Vector2D& v); // A * v

    // vvv Matrix2x2 vvv

    struct Matrix2x2
    {
        Vector2D col1 = Vector2D();
        Vector2D col2 = Vector2D();


        static constexpr inline Matrix2x2 identity();
        static constexpr inline Matrix2x2 zero();


        constexpr inline Matrix2x2();
        constexpr inline Matrix2x2(const Vector2D& col1, const Vector2D& col2);

        constexpr inline bool operator==(const Matrix2x2& other) const;
        constexpr inline bool operator!=(const Matrix2x2& other) const;

        constexpr inline Matrix2x2& operator+=(const Matrix2x2& other); // A += B
        constexpr inline Matrix2x2& operator-=(const Matrix2x2& other); // A -= B
        constexpr inline Matrix2x2& operator*=(const Matrix2x2& other); // A *= B
        constexpr inline Matrix2x2& operator*=(float s); // A *= s
        constexpr inline Matrix2x2& operator/=(float s); // A /= s

        constexpr friend inline Matrix2x2 operator+(const Matrix2x2& lhs, const Matrix2x2& rhs); // A + B
        constexpr friend inline Matrix2x2 operator-(const Matrix2x2& lhs, const Matrix2x2& rhs); // A - B
        constexpr friend inline Matrix2x2 operator*(const Matrix2x2& lhs, const Matrix2x2& rhs); // A * B
        constexpr friend inline Matrix2x2 operator*(const Matrix2x2& m, float s); // A * s
        constexpr friend inline Matrix2x2 operator*(float s, const Matrix2x2& m); // s * A
        constexpr friend inline Matrix2x2 operator/(const Matrix2x2& m, float s); // A / s


        constexpr inline Vector2D row1() const;
        constexpr inline Vector2D row2() const;
    };



    // [ 1 0 ]
    // [ 0 1 ]
    constexpr inline Matrix2x2 Matrix2x2::identity() {
        return Matrix2x2({1, 0}, {0, 1});
    }

    // [ 0 0 ]
    // [ 0 0 ]
    constexpr inline Matrix2x2 Matrix2x2::zero() {
        return Matrix2x2();
    }



    constexpr inline Matrix2x2::Matrix2x2() {}

    constexpr inline Matrix2x2::Matrix2x2(const Vector2D& col1, const Vector2D& col2) : col1(col1), col2(col2) {}



    constexpr inline bool Matrix2x2::operator==(const Matrix2x2& other) const {
        return col1 == other.col1 && col2 == other.col2;
    }

    constexpr inline bool Matrix2x2::operator!=(const Matrix2x2& other) const {
        return !operator==(other);
    }



    constexpr inline Matrix2x2& Matrix2x2::operator+=(const Matrix2x2& other)
    {
        col1 += other.col1;
        col2 += other.col2;
        return *this;
    }

    constexpr inline Matrix2x2& Matrix2x2::operator-=(const Matrix2x2& other)
    {
        col1 -= other.col1;
        col2 -= other.col2;
        return *this;
    }

    constexpr inline Matrix2x2& Matrix2x2::operator*=(const Matrix2x2& other)
    {
        // Impelmented in terms of operator* because a
        // copy is required to perform this operation
        *this = *this * other;
        return *this;
    }

    constexpr inline Matrix2x2& Matrix2x2::operator*=(float s)
    {
        col1 *= s;
        col2 *= s;
        return *this;
    }

    constexpr inline Matrix2x2& Matrix2x2::operator/=(float s)
    {
        col1 /= s;
        col2 /= s;
        return *this;
    }



    constexpr inline Matrix2x2 operator+(const Matrix2x2& lhs, const Matrix2x2& rhs)
    {
        Matrix2x2 result = lhs;
        result += rhs;
        return result;
    }

    constexpr inline Matrix2x2 operator-(const Matrix2x2& lhs, const Matrix2x2& rhs)
    {
        Matrix2x2 result = lhs;
        result -= rhs;
        return result;
    }

    constexpr inline Matrix2x2 operator*(const Matrix2x2& lhs, const Matrix2x2& rhs)
    {
        Matrix2x2 result = lhs;
        result.col1.x = dot(lhs.row1(), rhs.col1);
        result.col1.y = dot(lhs.row2(), rhs.col1);
        result.col2.x = dot(lhs.row1(), rhs.col2);
        result.col2.y = dot(lhs.row2(), rhs.col2);
        return result;
    }

    constexpr inline Matrix2x2 operator*(const Matrix2x2& m, float s)
    {
        Matrix2x2 result = m;
        result *= s;
        return result;
    }

    constexpr inline Matrix2x2 operator*(float s, const Matrix2x2& m) {
        return m * s;
    }

    constexpr inline Matrix2x2 operator/(const Matrix2x2& m, float s)
    {
        Matrix2x2 result = m;
        result /= s;
        return result;
    }



    constexpr inline Vector2D Matrix2x2::row1() const {
        return Vector2D(col1.x, col2.x);
    }

    constexpr inline Vector2D Matrix2x2::row2() const {
        return Vector2D(col1.y, col2.y);
    }

    // vvv Free Functions vvv // ^^^ Matrix2x2 ^^^

    constexpr inline Vector2D& operator*=(Vector2D& v, const Matrix2x2& m)
    {
        // Impelmented in terms of operator* because a
        // copy is required to perform this operation
        v = v * m;
        return v;
    }



    constexpr inline Vector2D operator*(const Vector2D& v, const Matrix2x2& m)
    {
        Vector2D result;
        result.x = dot(v, m.row1());
        result.y = dot(v, m.row2());
        return result;
    }

    constexpr inline Vector2D operator*(const Matrix2x2& m, const Vector2D& v) {
        return v * m;
    }
}

#endif // PINE_MATH_MATRIX_MATRIX2X2_H