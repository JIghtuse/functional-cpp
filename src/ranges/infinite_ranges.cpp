#include <range/v3/all.hpp>
#include <algorithm>
#include <iostream>
#include <vector>

template<typename Range>
void write_top_10(const Range& xs)
{
    using namespace ranges;

    auto items =
        view::zip(xs, view::ints(1))
            | view::transform([] (const auto& pair) {
                return std::to_string(pair.second) + " " + std::to_string(pair.first);
            })
            | view::take(10);

    for (const auto& item: items) {
        std::cout << item << '\n';
    }
}

int main()
{
    auto range = std::vector<int>{12,2,9,3,1,1423,31,34,1,1,23,1,32};
    write_top_10(range);
}
