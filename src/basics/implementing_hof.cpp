// example of higher-order function implementation
#include <person.h>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

template<typename FilterFunction>
std::vector<std::string> namesForLoop(
    const std::vector<Person>& people,
    FilterFunction filter)
{
    std::vector<std::string> names;
    for (const Person& person: people) {
        if (filter(person)) {
            names.push_back(person.name());
        }
    }
    return names;
}

template<typename FilterFunction, typename Iterator>
std::vector<std::string> namesForRecHelper(
    Iterator people_begin,
    Iterator people_end,
    FilterFunction filter,
    std::vector<std::string> previouslyCollected)
{
    if (people_begin == people_end) {
        return previouslyCollected;
    } else {
        const auto head = *people_begin;
        if (filter(head)) {
            previouslyCollected.push_back(head.name());
        }
    }

    return namesForRecHelper(people_begin + 1, people_end,
                             filter,
                             previouslyCollected);
}

template<typename FilterFunction, typename Iterator>
std::vector<std::string> namesForRec(
    Iterator people_begin,
    Iterator people_end,
    FilterFunction filter)
{
    return namesForRecHelper(people_begin, people_end, filter, {});
}

template<typename FilterFunction>
std::vector<std::string> namesForFold(
    const std::vector<Person>& people,
    FilterFunction filter)
{
    auto appendNameIf = [&filter](std::vector<std::string>& names, const Person& p) {
        if (filter(p)) {
            names.push_back(p.name());
        }
        return names;
    };

    return std::accumulate(people.cbegin(), people.cend(),
                           std::vector<std::string>{}, appendNameIf);
}

int main()
{
    auto people = std::vector<Person>{
        {"Peter", false},
        {"Martha", true},
        {"Jane", true},
        {"David", false},
        {"Tom", false},
        {"Rose", true}
    };

    auto isFemale = [](const Person& p) { return p.isFemale(); };

    auto names = namesForLoop(people, isFemale);

    std::cout << "Female person names: \n";
    for (auto name: names) {
        std::cout << name << '\n';
    }

    names = namesForRec(people.cbegin(), people.cend(), isFemale);

    std::cout << "Female person names: \n";
    for (auto name: names) {
        std::cout << name << '\n';
    }

    names = namesForFold(people, isFemale);

    std::cout << "Female person names: \n";
    for (auto name: names) {
        std::cout << name << '\n';
    }
}
