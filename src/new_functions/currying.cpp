// currying examples

#include <person.h>
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

// converting printPerson to its curried version
auto printPersonCd(const Person& person)
{
    return [&] (std::ostream& out) {
        return [&] (Person::OutputFormat fmt) {
            printPerson(person, out, fmt);
        };
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
