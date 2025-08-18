#ifndef PINE_MATH_VECTOR_H
#define PINE_MATH_VECTOR_H

#include <cmath>



namespace Pine
{
    struct Vector2D;
    struct Vector3D;


    inline Vector2D normalize(Vector2D vector);
    inline Vector3D normalize(Vector3D vector);



    // vvv Vector2D vvv



    struct Vector2D
    {
        float x;
        float y;


        inline bool operator==(const Vector2D& other) const;
        inline bool operator!=(const Vector2D& other) const;

        inline Vector2D& operator+=(const Vector2D& rhs);
        inline Vector2D& operator-=(const Vector2D& rhs);
        inline Vector2D& operator*=(float scalar);
        inline Vector2D& operator/=(float scalar);

        friend inline Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs);
        friend inline Vector2D operator-(const Vector2D& lhs, const Vector2D& rhs);
        friend inline Vector2D operator*(const Vector2D& vector, float scalar);
        friend inline Vector2D operator*(float scalar, const Vector2D& vector);
        friend inline Vector2D operator/(const Vector2D& vector, float scalar);
        friend inline Vector2D operator/(float scalar, const Vector2D& vector);


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

    inline Vector2D operator*(const Vector2D& vector, float scalar)
    {
        Vector2D result = vector;
        result *= scalar;
        return result;
    }

    inline Vector2D operator*(float scalar, const Vector2D& vector) {
        return operator*(vector, scalar);
    }

    inline Vector2D operator/(const Vector2D& vector, float scalar)
    {
        Vector2D result = vector;
        result /= scalar;
        return result;
    }

    inline Vector2D operator/(float scalar, const Vector2D& vector) {
        return operator/(vector, scalar);
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


        inline bool operator==(const Vector3D& other) const;
        inline bool operator!=(const Vector3D& other) const;

        inline Vector3D& operator+=(const Vector3D& rhs);
        inline Vector3D& operator-=(const Vector3D& rhs);
        inline Vector3D& operator*=(float scalar);
        inline Vector3D& operator/=(float scalar);

        friend inline Vector3D operator+(const Vector3D& lhs, const Vector3D& rhs);
        friend inline Vector3D operator-(const Vector3D& lhs, const Vector3D& rhs);
        friend inline Vector3D operator*(const Vector3D& vector, float scalar);
        friend inline Vector3D operator*(float scalar, const Vector3D& vector);
        friend inline Vector3D operator/(const Vector3D& vector, float scalar);
        friend inline Vector3D operator/(float scalar, const Vector3D& vector);


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

    inline Vector3D operator*(const Vector3D& vector, float scalar)
    {
        Vector3D result = vector;
        result *= scalar;
        return result;
    }

    inline Vector3D operator*(float scalar, const Vector3D& vector) {
        return operator*(vector, scalar);
    }

    inline Vector3D operator/(const Vector3D& vector, float scalar)
    {
        Vector3D result = vector;
        result /= scalar;
        return result;
    }

    inline Vector3D operator/(float scalar, const Vector3D& vector) {
        return operator/(vector, scalar);
    }



    inline float Vector3D::length() const {
        return std::sqrt((x * x) + (y * y) + (z * z));
    }



    // vvv Free Functions vvv // ^^^ Vector3D ^^^



    inline Vector2D normalize(Vector2D vector)
    {
        float length = vector.length();

        vector.x /= length;
        vector.y /= length;

        return vector;
    }

    inline Vector3D normalize(Vector3D vector)
    {
        float length = vector.length();

        vector.x /= length;
        vector.y /= length;
        vector.z /= length;

        return vector;
    }



    // ^^^ Free Functions ^^^
}

#endif // PINE_MATH_VECTOR_H