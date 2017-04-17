#include <common.h>
#include <boost/phoenix.hpp>
#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    using namespace boost::phoenix::arg_names;

    auto numbers = std::vector<int>{21, 5, 62, 42, 53};
    std::partition(numbers.begin(), numbers.end(), arg1 <= 42);

    print(numbers, "Partitioned numbers around 42: ");

    auto sum = std::accumulate(numbers.cbegin(), numbers.cend(), 0,
                               arg1 + arg2 * arg2 / 2);
    std::cout << "Sum of half-squares: " << sum << '\n';
}
