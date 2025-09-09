#ifndef PINE_MATH_MATRIX_MATRIX3X3_H
#define PINE_MATH_MATRIX_MATRIX3X3_H

#include "../vector/vector3d.h"

namespace Pine
{
    struct Matrix3x3;


    constexpr inline Vector3D operator*(const Matrix3x3& m, const Vector3D& v); // A * v // TODO

    // vvv Matrix3x3 vvv

    struct Matrix3x3
    {
        Vector3D col1 = Vector3D();
        Vector3D col2 = Vector3D();
        Vector3D col3 = Vector3D();


        static constexpr inline Matrix3x3 identity(); // TODO
        static constexpr inline Matrix3x3 zero(); // TODO


        constexpr inline Matrix3x3(); // TODO
        constexpr inline Matrix3x3(const Vector3D& col1, const Vector3D& col2, const Vector3D& col3); // TODO

        constexpr inline bool operator==(const Matrix3x3& other) const; // TODO
        constexpr inline bool operator!=(const Matrix3x3& other) const; // TODO

        constexpr inline Matrix3x3& operator+=(const Matrix3x3& other); // A += B // TODO
        constexpr inline Matrix3x3& operator-=(const Matrix3x3& other); // A -= B // TODO
        constexpr inline Matrix3x3& operator*=(const Matrix3x3& other); // A *= B // TODO
        constexpr inline Matrix3x3& operator*=(float s); // A *= s // TODO
        constexpr inline Matrix3x3& operator/=(float s); // A /= s // TODO

        constexpr friend inline Matrix3x3 operator+(const Matrix3x3& lhs, const Matrix3x3& rhs); // A + B // TODO
        constexpr friend inline Matrix3x3 operator-(const Matrix3x3& lhs, const Matrix3x3& rhs); // A - B // TODO
        constexpr friend inline Matrix3x3 operator*(const Matrix3x3& lhs, const Matrix3x3& rhs); // A * B // TODO
        constexpr friend inline Matrix3x3 operator*(const Matrix3x3& m, float s); // A * s // TODO
        constexpr friend inline Matrix3x3 operator*(float s, const Matrix3x3& m); // s * A // TODO
        constexpr friend inline Matrix3x3 operator/(const Matrix3x3& m, float s); // A / s // TODO

        constexpr inline Vector3D row1() const; // TODO
        constexpr inline Vector3D row2() const; // TODO
        constexpr inline Vector3D row3() const; // TODO
    };
}

#endif // PINE_MATH_MATRIX_MATRIX3X3_H