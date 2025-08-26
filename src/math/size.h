#ifndef PINE_MATH_SIZE_H
#define PINE_MATH_SIZE_H

namespace Pine
{
    template <typename T>
    struct Size2D;
    template <typename T>
    struct Size3D;

    // vvv Size2D vvv

    template <typename T>
    struct Size2D
    {
        T width {};
        T height {};


        constexpr inline Size2D() {}
        constexpr inline Size2D(T width, T height) : width(width), height(height) {}

        constexpr inline bool operator==(const Size2D<T>& other) const;
        constexpr inline bool operator!=(const Size2D<T>& other) const;

        // Using template types so all supported conversions from T to TReturn
        // can be used instead of only explicity supported conversions
        template <typename TReturn>
        explicit constexpr inline operator Size2D<TReturn>() const { return Size2D<TReturn>(static_cast<TReturn>(width), static_cast<TReturn>(height)); }
    };



    template <typename T>
    constexpr inline bool Size2D<T>::operator==(const Size2D<T>& other) const {
        return width == other.width && height == other.height;
    }

    template <typename T>
    constexpr inline bool Size2D<T>::operator!=(const Size2D<T>& other) const {
        return !operator==(other);
    }

    // vvv Size3D vvv // ^^^ Size2D ^^^

    template <typename T>
    struct Size3D
    {
        T width {};
        T height {};
        T length {};


        constexpr inline Size3D() {}
        constexpr inline Size3D(T width, T height, T length) : width(width), height(height), length(length) {}

        constexpr inline bool operator==(const Size3D<T>& other) const;
        constexpr inline bool operator!=(const Size3D<T>& other) const;

        // Using template types so all supported conversions from T to TReturn
        // can be used instead of only explicity supported conversions
        template <typename TReturn>
        explicit constexpr inline operator Size3D<TReturn>() const { return Size3D<TReturn>(static_cast<TReturn>(width), static_cast<TReturn>(height), static_cast<TReturn>(length)); }
    };



    template <typename T>
    constexpr inline bool Size3D<T>::operator==(const Size3D<T>& other) const {
        return width == other.width && height == other.height && length == other.length;
    }

    template <typename T>
    constexpr inline bool Size3D<T>::operator!=(const Size3D<T>& other) const {
        return !operator==(other);
    }
}

#endif // PINE_MATH_SIZE_H