#ifndef PINE_MATH_VECTOR_H
#define PINE_MATH_VECTOR_H

namespace Pine
{
    struct Vector2D;
    struct Vector3D;



    struct Vector2D
    {
        float x;
        float y;


        inline bool operator==(const Vector2D& other) const;
        inline bool operator!=(const Vector2D& other) const;
    };



    inline bool Vector2D::operator==(const Vector2D& other) const {
        return x == other.x && y == other.y;
    }

    inline bool Vector2D::operator!=(const Vector2D& other) const {
        return !operator==(other);
    }



    struct Vector3D
    {
        float x;
        float y;
        float z;


        inline bool operator==(const Vector3D& other) const;
        inline bool operator!=(const Vector3D& other) const;
    };



    inline bool Vector3D::operator==(const Vector3D& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    inline bool Vector3D::operator!=(const Vector3D& other) const {
        return !operator==(other);
    }
}

#endif // PINE_MATH_VECTOR_H