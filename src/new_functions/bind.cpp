// std::bind usage examples

#include <common.h>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <vector>

int main()
{
    using namespace std::placeholders;

    // binding all the arguments
    auto bound = std::bind(std::greater<double>(), 6, 42);

    bool is_6_greater_than_42 = bound();
    std::cout << std::boolalpha;

    std::cout << "is 6 > 42 ? " << is_6_greater_than_42 << '\n';


    // binding only one argument
    auto is_greater_than_42 = std::bind(std::greater<double>(), _1, 42);
    auto is_less_than_42 = std::bind(std::greater<double>(), 42, _1);

    std::cout << "is 4 > 42 ? " << is_greater_than_42(4) << '\n';
    std::cout << "is 8 < 42 ? " << is_less_than_42(8) << '\n';


    // binding no arguments
    // reversing the arguments of a binary function
    auto v = std::vector<int>{3, 1, 4, 5, 2};
    print(v, "Before sorting: ");
    auto less_than = std::bind(std::greater<int>(), _2, _1);
    std::sort(v.begin(), v.end(), less_than);
    print(v, "After sorting: ");
}
