#ifndef PINE_MATH_POINT_H
#define PINE_MATH_POINT_H

#include "math_common.h"

#include <cmath>

namespace Pine
{
    template <typename T>
    struct Point2D;
    template <typename T>
    struct Point3D;

    // These are functionally equivalent to getting the length of the vector
    // from p1 to p2, but these functions defer the float conversion to the end
    // of the calculation and are more obvious/intuitive
    template <typename T>
    inline float distance(const Point2D<T>& p1, const Point2D<T>& p2);
    template <typename T>
    inline float distance(const Point3D<T>& p1, const Point3D<T>& p2);

    // vvv Point2D vvv

    template <typename T>
    struct Point2D
    {
        T x;
        T y;


        inline Point2D() {}
        inline Point2D(T x, T y) : x(x), y(y) {}

        inline bool operator==(const Point2D<T>& other) const;
        inline bool operator!=(const Point2D<T>& other) const;

        // Using template types so all supported conversions from T to TReturn
        // can be used instead of only explicity supported conversions
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

    // vvv Point3D vvv // ^^^ Point2D ^^^

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

        // Using template types so all supported conversions from T to TReturn
        // can be used instead of only explicity supported conversions
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

    // vvv Free Functions vvv // ^^^ Point3D ^^^

    template <typename T>
    inline float distance(const Point2D<T>& p1, const Point2D<T>& p2) {
        return std::sqrt(static_cast<float>(square(p2.x - p1.x) + square(p2.y - p1.y)));
    }

    template <typename T>
    inline float distance(const Point3D<T>& p1, const Point3D<T>& p2) {
        return std::sqrt(static_cast<float>(square(p2.x - p1.x) + square(p2.y - p1.y) + square(p2.z - p1.z)));
    }
}

#endif // PINE_MATH_POINT_H