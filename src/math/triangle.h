#ifndef PINE_MATH_TRIANGLE_H
#define PINE_MATH_TRIANGLE_H

#include "point.h"

namespace Pine
{
    struct Triangle;
    


    struct Triangle
    {
        Point2D<float> a;
        Point2D<float> b;
        Point2D<float> c;


        inline Triangle() {}
        inline Triangle(Point2D<float> a, Point2D<float> b, Point2D<float> c) : a(a), b(b), c(c) {}
        inline Triangle(float aX, float aY, float bX, float bY, float cX, float cY) : a(aX, aY), b(bX, bY), c(cX, cY) {}

        inline bool operator==(const Triangle& other) const;
        inline bool operator!=(const Triangle& other) const;
    };



    inline bool Triangle::operator==(const Triangle& other) const {
        return a == other.a && b == other.b && c == other.c;
    }

    inline bool Triangle::operator!=(const Triangle& other) const {
        return !operator==(other);
    }
}

#endif // PINE_MATH_TRIANGLE_H