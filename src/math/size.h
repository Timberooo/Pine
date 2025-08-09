#ifndef PINE_MATH_SIZE_H
#define PINE_MATH_SIZE_H

namespace Pine
{
    template <typename T>
    struct Size2D;

    template <typename T>
    struct Size3D;



    template <typename T>
    struct Size2D
    {
        T width;
        T height;

        inline bool operator==(const Size2D<T>& other) const {
            return x == other.x && y == other.y;
        }

        inline bool operator!=(const Size2D<T>& other) const {
            return !operator==(other);
        }
    };



    template <typename T>
    struct Size3D
    {
        T width;
        T height;
        T length;

        inline bool operator==(const Size3D<T>& other) const {
            return x == other.x && y == other.y && z == other.z;
        }

        inline bool operator!=(const Size3D<T>& other) const {
            return !operator==(other);
        }
    };
}

#endif // PINE_MATH_SIZE_H