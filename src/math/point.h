#ifndef PINE_MATH_POINT_H
#define PINE_MATH_POINT_H

namespace Pine
{
    template <typename T>
    struct Point2D;

    template <typename T>
    struct Point3D;



    template <typename T>
    struct Point2D
    {
        T x;
        T y;

        inline bool operator==(const Point2D<T>& other) const {
            return x == other.x && y == other.y;
        }

        inline bool operator!=(const Point2D<T>& other) const {
            return !operator==(other);
        }
    };



    template <typename T>
    struct Point3D
    {
        T x;
        T y;
        T z;

        inline bool operator==(const Point3D<T>& other) const {
            return x == other.x && y == other.y && z == other.z;
        }

        inline bool operator!=(const Point3D<T>& other) const {
            return !operator==(other);
        }
    };
}

#endif // PINE_MATH_POINT_H