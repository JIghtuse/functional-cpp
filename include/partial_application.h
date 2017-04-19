#pragma once

#include <utility>

// attempt to make generic function object to wrap any binary
// function that the user passes and bind one of its arguments

template<typename Function, typename SecondArgType>
class partial_application_bind2nd_impl {
public:
    partial_application_bind2nd_impl(Function function,
                                     SecondArgType secondArg)
        : m_function{function}
        , m_second_arg{secondArg}
    {
    }

    template<typename FirstArgType>
    decltype(auto) operator() (FirstArgType&& first_arg) const
    {
        return m_function(
            std::forward<FirstArgType>(first_arg),
            m_second_arg);
    }
private:
    Function m_function;
    SecondArgType m_second_arg;
};

template<typename Function, typename SecondArgType>
partial_application_bind2nd_impl<Function, SecondArgType>
bind2nd(Function&& function, SecondArgType&& second_arg)
{
    return partial_application_bind2nd_impl<Function, SecondArgType>(
        std::forward<Function>(function),
        std::forward<SecondArgType>(second_arg));
}
