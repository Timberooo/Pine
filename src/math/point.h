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

        explicit inline operator Point2D<char>() const { return Point2D<char>(x, y); }
        explicit inline operator Point2D<unsigned char>() const { return Point2D<unsigned char>(x, y); }
        explicit inline operator Point2D<short>() const { return Point2D<short>(x, y); }
        explicit inline operator Point2D<unsigned short>() const { return Point2D<unsigned short>(x, y); }
        explicit inline operator Point2D<int>() const { return Point2D<int>(x, y); }
        explicit inline operator Point2D<unsigned int>() const { return Point2D<unsigned int>(x, y); }
        explicit inline operator Point2D<long>() const { return Point2D<long>(x, y); }
        explicit inline operator Point2D<unsigned long>() const { return Point2D<unsigned long>(x, y); }
        explicit inline operator Point2D<long long>() const { return Point2D<long long>(x, y); }
        explicit inline operator Point2D<unsigned long long>() const { return Point2D<unsigned long long>(x, y); }
        explicit inline operator Point2D<float>() const { return Point2D<float>(x, y); }
        explicit inline operator Point2D<double>() const { return Point2D<double>(x, y); }
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

        explicit inline operator Point3D<char>() const { return Point3D<char>(x, y, z); }
        explicit inline operator Point3D<unsigned char>() const { return Point3D<unsigned char>(x, y, z); }
        explicit inline operator Point3D<short>() const { return Point3D<short>(x, y, z); }
        explicit inline operator Point3D<unsigned short>() const { return Point3D<unsigned short>(x, y, z); }
        explicit inline operator Point3D<int>() const { return Point3D<int>(x, y, z); }
        explicit inline operator Point3D<unsigned int>() const { return Point3D<unsigned int>(x, y, z); }
        explicit inline operator Point3D<long>() const { return Point3D<long>(x, y, z); }
        explicit inline operator Point3D<unsigned long>() const { return Point3D<unsigned long>(x, y, z); }
        explicit inline operator Point3D<long long>() const { return Point3D<long long>(x, y, z); }
        explicit inline operator Point3D<unsigned long long>() const { return Point3D<unsigned long long>(x, y, z); }
        explicit inline operator Point3D<float>() const { return Point3D<float>(x, y, z); }
        explicit inline operator Point3D<double>() const { return Point3D<double>(x, y, z); }
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