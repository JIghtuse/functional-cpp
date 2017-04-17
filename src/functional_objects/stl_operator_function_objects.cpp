#include <common.h>
#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    auto numbers = std::vector<int>{1, 2, 3, 4};
    auto product = std::accumulate(numbers.cbegin(), numbers.cend(), 1,
                                   std::multiplies<>());

    print(numbers, "product of ", ": ");
    std::cout << product << '\n';

    numbers = std::vector<int>{5, 21, 13, 44};
    print(numbers, "before sorting: ");

    std::sort(numbers.begin(), numbers.end(), std::greater<>());
    print(numbers, "after sorting: ");
}
