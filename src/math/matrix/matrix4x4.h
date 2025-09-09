#ifndef PINE_MATH_MATRIX_MATRIX4X4_H
#define PINE_MATH_MATRIX_MATRIX4X4_H

#include "../vector/vector4d.h"

namespace Pine
{
    struct Matrix4x4;


    constexpr inline Vector4D operator*(const Matrix4x4& m, const Vector4D& v); // A * v

    // vvv Matrix4x4 vvv

    struct Matrix4x4
    {
        Vector4D col1 = Vector4D();
        Vector4D col2 = Vector4D();
        Vector4D col3 = Vector4D();
        Vector4D col4 = Vector4D();


        static constexpr inline Matrix4x4 identity();
        static constexpr inline Matrix4x4 zero();


        constexpr inline Matrix4x4();
        constexpr inline Matrix4x4(const Vector4D& col1, const Vector4D& col2, const Vector4D& col3, const Vector4D& col4);

        constexpr inline bool operator==(const Matrix4x4& other) const;
        constexpr inline bool operator!=(const Matrix4x4& other) const;

        constexpr inline Matrix4x4& operator+=(const Matrix4x4& other); // A += B
        constexpr inline Matrix4x4& operator-=(const Matrix4x4& other); // A -= B
        constexpr inline Matrix4x4& operator*=(const Matrix4x4& other); // A *= B
        constexpr inline Matrix4x4& operator*=(float s); // A *= s
        constexpr inline Matrix4x4& operator/=(float s); // A /= s

        constexpr friend inline Matrix4x4 operator+(const Matrix4x4& lhs, const Matrix4x4& rhs); // A + B
        constexpr friend inline Matrix4x4 operator-(const Matrix4x4& lhs, const Matrix4x4& rhs); // A - B
        constexpr friend inline Matrix4x4 operator*(const Matrix4x4& lhs, const Matrix4x4& rhs); // A * B
        constexpr friend inline Matrix4x4 operator*(const Matrix4x4& m, float s); // A * s
        constexpr friend inline Matrix4x4 operator*(float s, const Matrix4x4& m); // s * A
        constexpr friend inline Matrix4x4 operator/(const Matrix4x4& m, float s); // A / s

        constexpr inline Vector4D row1() const;
        constexpr inline Vector4D row2() const;
        constexpr inline Vector4D row3() const;
        constexpr inline Vector4D row4() const;
    };

    
    // [ 1 0 0 0 ]
    // [ 0 1 0 0 ]
    // [ 0 0 1 0 ]
    // [ 0 0 0 1 ]
    constexpr inline Matrix4x4 Matrix4x4::identity() {
        return Matrix4x4({1.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 1.0f});
    }

    // [ 0 0 0 0 ]
    // [ 0 0 0 0 ]
    // [ 0 0 0 0 ]
    // [ 0 0 0 0 ]
    constexpr inline Matrix4x4 Matrix4x4::zero() {
        return Matrix4x4();
    }



    constexpr inline Matrix4x4::Matrix4x4() {}

    constexpr inline Matrix4x4::Matrix4x4(const Vector4D& col1, const Vector4D& col2, const Vector4D& col3, const Vector4D& col4) : col1(col1), col2(col2), col3(col3), col4(col4) {}



    constexpr inline bool Matrix4x4::operator==(const Matrix4x4& other) const {
        return col1 == other.col1 && col2 == other.col2 && col3 == other.col3 && col4 == other.col4;
    }

    constexpr inline bool Matrix4x4::operator!=(const Matrix4x4& other) const {
        return !operator==(other);
    }



    constexpr inline Matrix4x4& Matrix4x4::operator+=(const Matrix4x4& other)
    {
        col1 += other.col1;
        col2 += other.col2;
        col3 += other.col3;
        col4 += other.col4;
        return *this;
    }

    constexpr inline Matrix4x4& Matrix4x4::operator-=(const Matrix4x4& other)
    {
        col1 -= other.col1;
        col2 -= other.col2;
        col3 -= other.col3;
        col4 -= other.col4;
        return *this;
    }

    constexpr inline Matrix4x4& Matrix4x4::operator*=(const Matrix4x4& other)
    {
        // Implemented in terms of operator* because a
        // copy is required to perform this operation
        *this = *this * other;
        return *this;
    }

    constexpr inline Matrix4x4& Matrix4x4::operator*=(float s)
    {
        col1 *= s;
        col2 *= s;
        col3 *= s;
        col4 *= s;
        return *this;
    }

    constexpr inline Matrix4x4& Matrix4x4::operator/=(float s)
    {
        col1 /= s;
        col2 /= s;
        col3 /= s;
        col4 /= s;
        return *this;
    }



    constexpr inline Matrix4x4 operator+(const Matrix4x4& lhs, const Matrix4x4& rhs)
    {
        Matrix4x4 result = lhs;
        result += rhs;
        return result;
    }

    constexpr inline Matrix4x4 operator-(const Matrix4x4& lhs, const Matrix4x4& rhs)
    {
        Matrix4x4 result = lhs;
        result += rhs;
        return result;
    }

    constexpr inline Matrix4x4 operator*(const Matrix4x4& lhs, const Matrix4x4& rhs)
    {
        // NOTE: Is there not a way to do this with a for-loop and offsets?
        Matrix4x4 result = lhs;
        result.col1.x = dot(lhs.row1(), rhs.col1);
        result.col1.y = dot(lhs.row2(), rhs.col1);
        result.col1.z = dot(lhs.row3(), rhs.col1);
        result.col1.w = dot(lhs.row4(), rhs.col1);
        result.col2.x = dot(lhs.row1(), rhs.col2);
        result.col2.y = dot(lhs.row2(), rhs.col2);
        result.col2.z = dot(lhs.row3(), rhs.col2);
        result.col2.w = dot(lhs.row4(), rhs.col2);
        result.col3.x = dot(lhs.row1(), rhs.col3);
        result.col3.y = dot(lhs.row2(), rhs.col3);
        result.col3.z = dot(lhs.row3(), rhs.col3);
        result.col3.w = dot(lhs.row4(), rhs.col3);
        result.col4.x = dot(lhs.row1(), rhs.col4);
        result.col4.y = dot(lhs.row2(), rhs.col4);
        result.col4.z = dot(lhs.row3(), rhs.col4);
        result.col4.w = dot(lhs.row4(), rhs.col4);
        return result;
    }

    constexpr inline Matrix4x4 operator*(const Matrix4x4& m, float s)
    {
        Matrix4x4 result = m;
        result *= s;
        return result;
    }

    constexpr inline Matrix4x4 operator*(float s, const Matrix4x4& m) {
        return m * s;
    }

    constexpr inline Matrix4x4 operator/(const Matrix4x4& m, float s)
    {
        Matrix4x4 result = m;
        result /= s;
        return result;
    }



    constexpr inline Vector4D Matrix4x4::row1() const {
        return Vector4D(col1.x, col2.x, col3.x, col4.x);
    }

    constexpr inline Vector4D Matrix4x4::row2() const {
        return Vector4D(col1.y, col2.y, col3.y, col4.y);
    }

    constexpr inline Vector4D Matrix4x4::row3() const {
        return Vector4D(col1.z, col2.z, col3.z, col4.z);
    }

    constexpr inline Vector4D Matrix4x4::row4() const {
        return Vector4D(col1.w, col2.w, col3.w, col4.w);
    }

    // vvv Free Functions vvv // ^^^ Matrix4x4 ^^^

    constexpr inline Vector4D operator*(const Matrix4x4& m, const Vector4D& v)
    {
        // - n of A and m of B must match for multiplication to work.
        // - m of A and n of B dictate the order of A * B.
        //      A          B               A * B
        //   mA x nA    mB x nB           mA x nB
        //     4x4        4x1               4x1
        // [ a b c d ]   [ x ]   [ a*x + b*y + c*z + d*w ]
        // [ e f g h ] * [ y ] = [ e*x + f*y + g*z + h*w ]
        // [ i j k l ]   [ z ]   [ i*x + j*y + k*z + l*w ]
        // [ m n o p ]   [ w ]   [ m*x + n*y + o*z + p*w ]
        return Vector4D(dot(v, m.row1()),
                        dot(v, m.row2()),
                        dot(v, m.row3()),
                        dot(v, m.row4()));
    }
}

#endif // PINE_MATH_MATRIX_MATRIX4X4_H