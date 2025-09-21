#ifndef PINE_CORE_H
#define PINE_CORE_H

#define PINE_FALSE 0
#define PINE_TRUE  1

#define PINE_STRINGIFY_MACRO(macro) PINE_STRINGIFY(macro)
#define PINE_STRINGIFY(x)           #x

// OS
#if defined(__linux__)
    #define PINE_OS_LINUX
#elif defined(_WIN64)
    #define PINE_OS_WINDOWS
#else
    #error Unknown or unsupported OS
#endif

// Debug
#if !defined(PINE_DEBUG) && (defined(_DEBUG) || defined(DEBUG))
    #define PINE_DEBUG
#endif

// Compiler
#if defined(_MSC_VER)
    #define PINE_COMPILER_MSVC _MSC_VER
#endif

// Force inline
#if defined(PINE_COMPILER_MSVC)
    #define PINE_FORCE_INLINE __forceinline
    #define PINE_FORCE_INLINE_SUPPORTED PINE_TRUE
#else
    // If compiler doesn't support forced inlining, fallback to regular inlining
    #define PINE_FORCE_INLINE inline
    #define PINE_FORCE_INLINE_SUPPORTED PINE_FALSE
#endif

namespace Pine
{
    typedef unsigned char Byte;
}

#endif // PINE_CORE_H