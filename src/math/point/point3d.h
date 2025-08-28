#ifndef PINE_MATH_POINT_POINT3D_H
#define PINE_MATH_POINT_POINT3D_H

#include "../math_common.h"

#include <cmath>

namespace Pine
{
    template <typename T>
    struct Point3D;

    template <typename T>
    constexpr inline float distance(const Point3D<T>& p1, const Point3D<T>& p2);

    // vvv Point3D vvv

    template <typename T>
    struct Point3D
    {
        T x {};
        T y {};
        T z {};


        constexpr inline Point3D();
        constexpr inline Point3D(T x, T y, T z);

        constexpr inline bool operator==(const Point3D<T>& other) const;
        constexpr inline bool operator!=(const Point3D<T>& other) const;

        // Using template types so all supported conversions from T to TReturn
        // can be used instead of only explicitly supported conversions
        template <typename TReturn>
        explicit constexpr inline operator Point3D<TReturn>() const { return Point3D<TReturn>(static_cast<TReturn>(x), static_cast<TReturn>(y), static_cast<TReturn>(z)); }
    };



    template <typename T>
    constexpr inline Point3D<T>::Point3D() {}

    template <typename T>
    constexpr inline Point3D<T>::Point3D(T x, T y, T z) : x(x), y(y), z(z) {}



    template <typename T>
    constexpr inline bool Point3D<T>::operator==(const Point3D<T>& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    template <typename T>
    constexpr inline bool Point3D<T>::operator!=(const Point3D<T>& other) const {
        return !operator==(other);
    }

    // vvv Free Functions vvv // ^^^ Point3D ^^^

    template <typename T>
    constexpr inline float distance(const Point3D<T>& p1, const Point3D<T>& p2) {
        return std::sqrt(static_cast<float>(square(p2.x - p1.x) + square(p2.y - p1.y) + square(p2.z - p1.z)));
    }
}

#endif // PINE_MATH_POINT_POINT3D_H