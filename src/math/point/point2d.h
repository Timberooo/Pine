#ifndef PINE_MATH_POINT_POINT2D_H
#define PINE_MATH_POINT_POINT2D_H

#include "../math_common.h"

#include <cmath>

namespace Pine
{
    template <typename T>
    struct Point2D;

    template <typename T>
    constexpr inline float distance(const Point2D<T>& p1, const Point2D<T>& p2);

    // vvv Point2D vvv

    template <typename T>
    struct Point2D
    {
        T x {};
        T y {};


        constexpr inline Point2D();
        constexpr inline Point2D(T x, T y);

        constexpr inline bool operator==(const Point2D<T>& other) const;
        constexpr inline bool operator!=(const Point2D<T>& other) const;

        // Using template types so all supported conversions from T to TReturn
        // can be used instead of only explicitly supported conversions
        template <typename TReturn>
        explicit constexpr inline operator Point2D<TReturn>() const { return Point2D<TReturn>(static_cast<TReturn>(x), static_cast<TReturn>(y)); }
    };



    template <typename T>
    constexpr inline Point2D<T>::Point2D() {}

    template <typename T>
    constexpr inline Point2D<T>::Point2D(T x, T y) : x(x), y(y) {}



    template <typename T>
    constexpr inline bool Point2D<T>::operator==(const Point2D<T>& other) const {
        return x == other.x && y == other.y;
    }

    template <typename T>
    constexpr inline bool Point2D<T>::operator!=(const Point2D<T>& other) const {
        return !operator==(other);
    }

    // vvv Free Functions vvv // ^^^ Point2D ^^^

    template <typename T>
    constexpr inline float distance(const Point2D<T>& p1, const Point2D<T>& p2) {
        return std::sqrt(static_cast<float>(square(p2.x - p1.x) + square(p2.y - p1.y)));
    }
}

#endif // PINE_MATH_POINT_POINT2D_H