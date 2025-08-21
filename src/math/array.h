#ifndef PINE_MATH_ARRAY_H
#define PINE_MATH_ARRAY_H

#include "point.h"
#include "size.h"

#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include <vector>



namespace Pine
{
    template <typename T>
    class Array2D;



    template <typename T>
    class Array2D
    {
    public:

        inline Array2D();
        inline Array2D(Size2D<std::size_t> initSize);
        inline Array2D(Size2D<std::size_t> initSize, const T& value);
        inline Array2D(std::size_t width, std::size_t height);
        inline Array2D(std::size_t width, std::size_t height, const T& value);

        inline bool empty() const;
        inline Size2D<std::size_t> size() const;
        inline bool inBounds(Point2D<std::size_t> pos) const;
        inline bool inBounds(std::size_t x, std::size_t y) const;

        inline T& at(Point2D<std::size_t> pos);
        inline const T& at(Point2D<std::size_t> pos) const;
        inline T& at(std::size_t x, std::size_t y);
        inline const T& at(std::size_t x, std::size_t y) const;

        inline void resize(Size2D<std::size_t> newSize);
        inline void resize(Size2D<std::size_t> newSize, const T& value);
        inline void resize(std::size_t width, std::size_t height);
        inline void resize(std::size_t width, std::size_t height, const T& value);
        inline void clear();

        template <typename F>
        void foreach(F func);
        template <typename F>
        void foreach(F func) const;

    private:

        std::vector<T>      m_data;
        Size2D<std::size_t> m_size;


        static inline std::size_t index(Point2D<std::size_t> pos, std::size_t width);
        static inline std::size_t index(Point2D<std::size_t> pos, Size2D<std::size_t> size);
        static inline std::size_t index(std::size_t x, std::size_t y, std::size_t width);
        static inline std::size_t index(std::size_t x, std::size_t y, Size2D<std::size_t> size);

        void resizeData(Size2D<std::size_t> newSize);
        void resizeData(Size2D<std::size_t> newSize, const T& value);
        void replaceDataWithNewData(std::vector<T>& newData, Size2D<std::size_t> newSize);
    };



    template <typename T>
    inline Array2D<T>::Array2D() : Array2D(0, 0) {}
    
    template <typename T>
    inline Array2D<T>::Array2D(Size2D<std::size_t> initSize) :
        m_data(initSize.width * initSize.height), m_size(initSize) {}
    
    template <typename T>
    inline Array2D<T>::Array2D(Size2D<std::size_t> initSize, const T& value) :
        m_data(initSize.width * initSize.height, value), m_size(initSize) {}
    
    template <typename T>
    inline Array2D<T>::Array2D(std::size_t width, std::size_t height) :
        Array2D(Size2D<std::size_t>{ width, height }) {}
    
    template <typename T>
    inline Array2D<T>::Array2D(std::size_t width, std::size_t height, const T& value) :
        Array2D(Size2D<std::size_t>{ width, height }, value) {}
        


    template <typename T>
    inline bool Array2D<T>::empty() const {
        return size().width == 0; // Width and height should both be 0 if array is empty
    }



    template <typename T>
    inline Size2D<std::size_t> Array2D<T>::size() const {
        return m_size;
    }



    template <typename T>
    inline bool Array2D<T>::inBounds(Point2D<std::size_t> pos) const {
        return (pos.x < size().width && pos.y < size().height);
    }

    template <typename T>
    inline bool Array2D<T>::inBounds(std::size_t x, std::size_t y) const {
        return inBounds({ x, y });
    }



    template <typename T>
    inline T& Array2D<T>::at(Point2D<std::size_t> pos)
    {
        if (inBounds(pos))
            return m_data.at(index(pos, size()));
        else
            throw std::out_of_range("Position was outside the 2D array");
    }

    template <typename T>
    inline const T& Array2D<T>::at(Point2D<std::size_t> pos) const
    {
        if (inBounds(pos))
            return m_data.at(index(pos, size()));
        else
            throw std::out_of_range("Position was outside the 2D array");
    }

    template <typename T>
    inline T& Array2D<T>::at(std::size_t x, std::size_t y) {
        return at({ x, y });
    }

    template <typename T>
    inline const T& Array2D<T>::at(std::size_t x, std::size_t y) const {
        return at({ x, y });
    }



    template <typename T>
    inline void Array2D<T>::resize(Size2D<std::size_t> newSize) {
        resizeData(newSize);
    }

    template <typename T>
    inline void Array2D<T>::resize(Size2D<std::size_t> newSize, const T& value) {
        resizeData(newSize, value);
    }

    template <typename T>
    inline void Array2D<T>::resize(std::size_t width, std::size_t height) {
        resize({ width, height });
    }

    template <typename T>
    inline void Array2D<T>::resize(std::size_t width, std::size_t height, const T& value) {
        resize({ width, height }, value);
    }



    template <typename T>
    inline void Array2D<T>::clear()
    {
        m_size = { 0, 0 };
        m_data.clear();
    }



    template <typename T>
    template <typename F>
    void Array2D<T>::foreach(F func)
    {
        for (std::size_t i = 0; i < m_data.size(); i++)
            func(m_data.at(i));
    }

    template <typename T>
    template <typename F>
    void Array2D<T>::foreach(F func) const
    {
        for (std::size_t i = 0; i < m_data.size(); i++)
            func(m_data.at(i));
    }


    
    template <typename T>
    inline std::size_t Array2D<T>::index(Point2D<std::size_t> pos, std::size_t width) {
        return pos.x + (pos.y * width);
    }

    template <typename T>
    inline std::size_t Array2D<T>::index(Point2D<std::size_t> pos, Size2D<std::size_t> size) {
        return index(pos, size.width);
    }

    template <typename T>
    inline std::size_t Array2D<T>::index(std::size_t x, std::size_t y, std::size_t width) {
        return index({ x , y }, width);
    }

    template <typename T>
    inline std::size_t Array2D<T>::index(std::size_t x, std::size_t y, Size2D<std::size_t> size) {
        return index({ x, y }, size);
    }



    template <typename T>
    void Array2D<T>::resizeData(Size2D<std::size_t> newSize)
    {
        if (newSize == size())
            return;
        
        std::vector<T> newData(newSize.width * newSize.height);
        replaceDataWithNewData(newData, newSize);
    }

    template <typename T>
    void Array2D<T>::resizeData(Size2D<std::size_t> newSize, const T& value)
    {
        if (newSize == size())
            return;

        std::vector<T> newData(newSize.width * newSize.height, value);
        replaceDataWithNewData(newData, newSize);
    }



    template <typename T>
    void Array2D<T>::replaceDataWithNewData(std::vector<T>& newData, Size2D<std::size_t> newSize)
    {
        Size2D<std::size_t> bounds;
        bounds.width = std::min(size().width, newSize.width);
        bounds.height = std::min(size().height, newSize.height);

        for (std::size_t y = 0; y < bounds.height; y++)
            for (std::size_t x = 0; x < bounds.width; x++)
                newData.at(index(x, y, newSize)) = m_data.at(index(x, y, size()));

        m_data = newData;
    }
}

#endif // PINE_MATH_ARRAY_H