#ifndef PINE_MATH_VECTOR_H
#define PINE_MATH_VECTOR_H

namespace Pine
{
    template <typename T>
    struct Vector2D;

    template <typename T>
    struct Vector3D;



    template <typename T>
    struct Vector2D
    {
        T x;
        T y;

        inline bool operator==(const Vector2D<T>& other) const {
            return x == other.x && y == other.y;
        }

        inline bool operator!=(const Vector2D<T>& other) const {
            return !operator==(other);
        }
    };



    template <typename T>
    struct Vector3D
    {
        T x;
        T y;
        T z;

        inline bool operator==(const Vector3D<T>& other) const {
            return x == other.x && y == other.y && z == other.z;
        }

        inline bool operator!=(const Vector3D<T>& other) const {
            return !operator==(other);
        }
    };
}

#endif // PINE_MATH_VECTOR_H