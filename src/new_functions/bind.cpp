// std::bind usage examples

#include <common.h>
#include <person.h>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <vector>

void printPerson(const Person& person,
                 std::ostream& out,
                 Person::OutputFormat format)
{
    if (format == Person::NameOnly) {
        out << person.name() << '\n';
    } else if (format == Person::FullName) {
        out << person.name() << ' '
            << person.surname() << '\n';
    }
}

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

    auto people = std::vector<Person>{
        {"Peter", false, 56},
        {"Martha", true, 24},
        {"Jane", true, 52},
        {"David", false, 84},
        {"Tom", false, 32},
        {"Rose", true, 31}
    };
    std::cout << "Some people:\n";
    std::for_each(people.cbegin(), people.cend(),
                  std::bind(printPerson,
                            _1,
                            std::ref(std::cout),
                            Person::FullName));

    std::cout << "Some people again:\n";
    std::for_each(people.cbegin(), people.cend(),
                  std::bind(&Person::print,
                            _1,
                            std::ref(std::cout),
                            Person::NameOnly));
}
