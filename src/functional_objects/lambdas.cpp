#include <person.h>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    auto people = std::vector<Person>{
        {"Peter", false, 56},
        {"Martha", true, 24},
        {"Jane", true, 52},
        {"David", false, 84},
        {"Tom", false, 32},
        {"Rose", true, 31}
    };

    auto females = std::vector<Person>{};

    std::copy_if(people.cbegin(), people.cend(),
                 std::back_inserter(females),
                 [](const Person& person) {
                     return person.isFemale();
                 });

    std::cout << "Female person names: \n";
    for (auto person: females) {
        std::cout << person.name() << '\n';
    }
}
