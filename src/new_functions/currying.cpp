// currying examples

#include <iomanip>
#include <iostream>

// greater : (double, double) -> bool
bool greater(double first, double second)
{
    return first > second;
}

// greater_curried : double -> (double -> bool)
auto greater_curried(double first)
{
    return [first] (double second) {
        return first > second;
    };
}

int main()
{
    auto a = 2;
    auto b = 3;

    std::cout << std::boolalpha;

    std::cout << "Is " << a << " > " << b << " ? "
              << greater(a, b) << '\n';
    std::cout << "Is " << a << " > " << b << " ? "
              << greater_curried(a)(b) << '\n';
}
