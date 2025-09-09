#ifndef PINE_MATH_MATRIX_MAT4X4_H
#define PINE_MATH_MATRIX_MAT4X4_H

#include "../vector/vec4.h"

namespace Pine
{
    struct Mat4;

    typedef Mat4 Mat4x4;
    typedef Mat4 Matrix4;
    typedef Mat4 Matrix4x4;


    constexpr inline Vec4 operator*(const Mat4& m, const Vec4& v); // A * v

    // vvv Mat4 vvv

    struct Mat4
    {
        Vec4 col1 = Vec4();
        Vec4 col2 = Vec4();
        Vec4 col3 = Vec4();
        Vec4 col4 = Vec4();


        static constexpr inline Mat4 identity();
        static constexpr inline Mat4 zero();


        constexpr inline Mat4();
        constexpr inline Mat4(const Vec4& col1, const Vec4& col2, const Vec4& col3, const Vec4& col4);

        constexpr inline bool operator==(const Mat4& other) const;
        constexpr inline bool operator!=(const Mat4& other) const;

        constexpr inline Mat4& operator+=(const Mat4& other); // A += B
        constexpr inline Mat4& operator-=(const Mat4& other); // A -= B
        constexpr inline Mat4& operator*=(const Mat4& other); // A *= B
        constexpr inline Mat4& operator*=(float s); // A *= s
        constexpr inline Mat4& operator/=(float s); // A /= s

        constexpr friend inline Mat4 operator+(const Mat4& lhs, const Mat4& rhs); // A + B
        constexpr friend inline Mat4 operator-(const Mat4& lhs, const Mat4& rhs); // A - B
        constexpr friend inline Mat4 operator*(const Mat4& lhs, const Mat4& rhs); // A * B
        constexpr friend inline Mat4 operator*(const Mat4& m, float s); // A * s
        constexpr friend inline Mat4 operator*(float s, const Mat4& m); // s * A
        constexpr friend inline Mat4 operator/(const Mat4& m, float s); // A / s

        constexpr inline Vec4 row1() const;
        constexpr inline Vec4 row2() const;
        constexpr inline Vec4 row3() const;
        constexpr inline Vec4 row4() const;
    };

    
    // [ 1 0 0 0 ]
    // [ 0 1 0 0 ]
    // [ 0 0 1 0 ]
    // [ 0 0 0 1 ]
    constexpr inline Mat4 Mat4::identity() {
        return Mat4({1.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 1.0f});
    }

    // [ 0 0 0 0 ]
    // [ 0 0 0 0 ]
    // [ 0 0 0 0 ]
    // [ 0 0 0 0 ]
    constexpr inline Mat4 Mat4::zero() {
        return Mat4();
    }



    constexpr inline Mat4::Mat4() {}

    constexpr inline Mat4::Mat4(const Vec4& col1, const Vec4& col2, const Vec4& col3, const Vec4& col4) : col1(col1), col2(col2), col3(col3), col4(col4) {}



    constexpr inline bool Mat4::operator==(const Mat4& other) const {
        return col1 == other.col1 && col2 == other.col2 && col3 == other.col3 && col4 == other.col4;
    }

    constexpr inline bool Mat4::operator!=(const Mat4& other) const {
        return !operator==(other);
    }



    constexpr inline Mat4& Mat4::operator+=(const Mat4& other)
    {
        col1 += other.col1;
        col2 += other.col2;
        col3 += other.col3;
        col4 += other.col4;
        return *this;
    }

    constexpr inline Mat4& Mat4::operator-=(const Mat4& other)
    {
        col1 -= other.col1;
        col2 -= other.col2;
        col3 -= other.col3;
        col4 -= other.col4;
        return *this;
    }

    constexpr inline Mat4& Mat4::operator*=(const Mat4& other)
    {
        // Implemented in terms of operator* because a
        // copy is required to perform this operation
        *this = *this * other;
        return *this;
    }

    constexpr inline Mat4& Mat4::operator*=(float s)
    {
        col1 *= s;
        col2 *= s;
        col3 *= s;
        col4 *= s;
        return *this;
    }

    constexpr inline Mat4& Mat4::operator/=(float s)
    {
        col1 /= s;
        col2 /= s;
        col3 /= s;
        col4 /= s;
        return *this;
    }



    constexpr inline Mat4 operator+(const Mat4& lhs, const Mat4& rhs)
    {
        Mat4 result = lhs;
        result += rhs;
        return result;
    }

    constexpr inline Mat4 operator-(const Mat4& lhs, const Mat4& rhs)
    {
        Mat4 result = lhs;
        result += rhs;
        return result;
    }

    constexpr inline Mat4 operator*(const Mat4& lhs, const Mat4& rhs)
    {
        // NOTE: Is there not a way to do this with a for-loop and offsets?
        Mat4 result = lhs;
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

    constexpr inline Mat4 operator*(const Mat4& m, float s)
    {
        Mat4 result = m;
        result *= s;
        return result;
    }

    constexpr inline Mat4 operator*(float s, const Mat4& m) {
        return m * s;
    }

    constexpr inline Mat4 operator/(const Mat4& m, float s)
    {
        Mat4 result = m;
        result /= s;
        return result;
    }



    constexpr inline Vec4 Mat4::row1() const {
        return Vec4(col1.x, col2.x, col3.x, col4.x);
    }

    constexpr inline Vec4 Mat4::row2() const {
        return Vec4(col1.y, col2.y, col3.y, col4.y);
    }

    constexpr inline Vec4 Mat4::row3() const {
        return Vec4(col1.z, col2.z, col3.z, col4.z);
    }

    constexpr inline Vec4 Mat4::row4() const {
        return Vec4(col1.w, col2.w, col3.w, col4.w);
    }

    // vvv Free Functions vvv // ^^^ Mat4 ^^^

    constexpr inline Vec4 operator*(const Mat4& m, const Vec4& v)
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
        return Vec4(dot(v, m.row1()),
                    dot(v, m.row2()),
                    dot(v, m.row3()),
                    dot(v, m.row4()));
    }
}

#endif // PINE_MATH_MATRIX_MAT4X4_H