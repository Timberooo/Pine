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


        inline Point2D() {}
        inline Point2D(T x, T y) : x(x), y(y) {}

        inline bool operator==(const Point2D<T>& other) const;
        inline bool operator!=(const Point2D<T>& other) const;

        template <typename TReturn>
        explicit inline operator Point2D<TReturn>() const { return Point2D<TReturn>(static_cast<TReturn>(x), static_cast<TReturn>(y)); }
    };



    template <typename T>
    inline bool Point2D<T>::operator==(const Point2D<T>& other) const {
        return x == other.x && y == other.y;
    }

    template <typename T>
    inline bool Point2D<T>::operator!=(const Point2D<T>& other) const {
        return !operator==(other);
    }



    template <typename T>
    struct Point3D
    {
        T x;
        T y;
        T z;


        inline Point3D() {}
        inline Point3D(T x, T y, T z) : x(x), y(y), z(z) {}

        inline bool operator==(const Point3D<T>& other) const;
        inline bool operator!=(const Point3D<T>& other) const;

        template <typename TReturn>
        explicit inline operator Point3D<TReturn>() const { return Point3D<TReturn>(static_cast<TReturn>(x), static_cast<TReturn>(y), static_cast<TReturn>(z)); }
    };



    template <typename T>
    inline bool Point3D<T>::operator==(const Point3D<T>& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    template <typename T>
    inline bool Point3D<T>::operator!=(const Point3D<T>& other) const {
        return !operator==(other);
    }
}

#endif // PINE_MATH_POINT_H