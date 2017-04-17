// std::function allows us to save a function object as a member of any class
// and to use a function between separate compilation units
#include <boost/phoenix.hpp>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <string>

int main()
{
    using namespace std::string_literals;
    using namespace boost::phoenix::arg_names;

    auto testFunction = std::function<float(float, float)>{};

    float a = 3;
    float b = -4.2;
    float x = 2;

    // TODO: explore why it fails
    // ordinary function
    // testFunction = std::fmax;
    // std::cout << "max of " << a << " and " << b
    //           << ": " << testFunction(a, b) << '\n';

    // class with a call operator
    testFunction = std::multiplies<float>();
    std::cout << "multiplication of " << a << " and " << b
              << ": " << testFunction(a, b) << '\n';

    // class with a generic call operator
    testFunction = std::multiplies<>();
    std::cout << "multiplication of " << a << " and " << b
              << ": " << testFunction(a, b) << '\n';

    // lambda
    testFunction = [x](float a, float b) { return a * x + b; };
    std::cout << "lambda result: " << testFunction(a, b) << '\n';

    // generic lambda
    testFunction = [x](auto a, auto b) { return a * x + b; };
    std::cout << "generic lambda result: " << testFunction(a, b) << '\n';

    // boost.phoenix expression
    testFunction = (arg1 + arg2) / 2;
    std::cout << "boost.phoenix expression result: "
              << testFunction(a, b) << '\n';



    // use member function as a function object
    auto s = "A small pond"s;
    std::function<bool(std::string)> f = &std::string::empty;

    std::cout << std::boolalpha;
    std::cout << "'" << s  << "'" << " is empty: " << f(s) << '\n';
}
