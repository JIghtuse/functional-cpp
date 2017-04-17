#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

void print(const std::vector<int>& v)
{
    for (const auto i: v) {
        std::cout << i << ' ';
    }
}

int main()
{
    auto numbers = std::vector<int>{1, 2, 3, 4};
    auto product = std::accumulate(numbers.cbegin(), numbers.cend(), 1,
                                   std::multiplies<>());
    std::cout << "product of ";
    print(numbers);
    std::cout << ": " << product << '\n';

    numbers = std::vector<int>{5, 21, 13, 44};
    std::cout << "before sorting: ";
    print(numbers);
    std::cout << '\n';

    std::sort(numbers.begin(), numbers.end(), std::greater<>());
    std::cout << "after sorting: ";
    print(numbers);
    std::cout << '\n';
}
