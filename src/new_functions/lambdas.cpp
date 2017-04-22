// using lambdas as an alternative for std::bind

#include <common.h>
#include <person.h>
#include <algorithm>
#include <functional>
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
    // binding all the arguments
    auto is_6_greater_than_42 = [] {
        return 6 > 42;
    };

    std::cout << std::boolalpha;

    std::cout << "is 6 > 42 ? " << is_6_greater_than_42() << '\n';

    // binding only one argument
    auto is_greater_than_42 = [](double value) {
        return value > 42;
    };
    auto is_less_than_42 = [](double value) {
        return value < 42;
    };
    std::cout << "is 4 > 42 ? " << is_greater_than_42(4) << '\n';
    std::cout << "is 8 < 42 ? " << is_less_than_42(8) << '\n';


    // binding no arguments
    // reversing the arguments of a binary function
    auto v = std::vector<int>{3, 1, 4, 5, 2};
    print(v, "Before sorting: ");
    std::sort(v.begin(), v.end(),
        [](double a, double b) {
            // or much more verbosely
            // return std::greater<double>()(b, a);
            return b > a;
        });
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
                  [](const Person& person) {
                      printPerson(person, std::cout, Person::FullName);
                  });

    std::cout << "Some people again:\n";
    std::for_each(people.cbegin(), people.cend(),
                  [](const Person& person) {
                      person.print(std::cout, Person::NameOnly);
                  });
}
