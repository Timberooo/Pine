#ifndef PINE_CALLBACK_H
#define PINE_CALLBACK_H

#include <stdexcept>
#include <type_traits>

namespace Pine
{
    template <typename TFunction>
    class Callback;



    template <typename TReturn, typename... TArgs>
    class Callback<TReturn (*)(TArgs...)>
    {
    public:

        typedef TReturn (*Function)(TArgs...);

        static constexpr bool returnsVoid = std::is_same_v<TReturn, void>;

        inline Callback() {}
        inline Callback(Function function) : m_function(function) {}

        inline operator Function() const { return m_function; }

        inline bool canCall() const;
        TReturn call(TArgs... args);
        template <typename T = TReturn, typename = typename std::enable_if<returnsVoid, T>::type>
        bool tryCall(TArgs... args);
        template <typename T = TReturn, typename = typename std::enable_if<!returnsVoid, T>::type>
        bool tryCall(T& returnVal, TArgs... args);

    private:

        Function m_function = nullptr;
    };



    template <typename TReturn, typename... TArgs>
    inline bool Callback<TReturn (*)(TArgs...)>::canCall() const {
        return m_function != nullptr;
    }



    template <typename TReturn, typename... TArgs>
    TReturn Callback<TReturn (*)(TArgs...)>::call(TArgs... args)
    {
        if (canCall())
            return m_function(args...);
        else
            throw std::logic_error("Callback function is null");
    }



    template <typename TReturn, typename... TArgs>
    template <typename T, typename>
    bool Callback<TReturn (*)(TArgs...)>::tryCall(TArgs... args)
    {
        bool callable = canCall();

        if (callable)
            m_function(args...);

        return callable;
    }

    template <typename TReturn, typename... TArgs>
    template <typename T, typename>
    bool Callback<TReturn (*)(TArgs...)>::tryCall(T& returnVal, TArgs... args)
    {
        bool callable = canCall();

        if (callable)
            returnVal = m_function(args...);

        return callable;
    }
}

#endif // PINE_CALLBACK_H