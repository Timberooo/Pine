#ifndef PINE_MATH_MATH_COMMON_H
#define PINE_MATH_MATH_COMMON_H

namespace Pine
{
    // Clearer intent that using std::pow() or std::exp() and avoids the
    // headaches of the float requirements of those functions
    template <typename T>
    inline T square(const T& val);



    template <typename T>
    inline T square(const T& val) {
        return val * val;
    }
}

#endif // PINE_MATH_MATH_COMMON_H