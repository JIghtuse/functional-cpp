#include <person.h>
#include <range/v3/all.hpp>
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    using namespace ranges;

    auto people = std::vector<Person>{
        {"Peter", false},
        {"Martha", true},
        {"Jane", true},
        {"David", false},
        {"Tom", false},
        {"Rose", true}
    };

    auto isFemale = [](const Person& p) { return p.isFemale(); };
    auto name = [](const Person& p) { return p.name(); };

    auto names = people | view::filter(isFemale)
                        | view::transform(name);

    std::cout << "Female person names: \n";
    for (auto name: names) {
        std::cout << name << '\n';
    }
}

