#include <company.h>
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

    auto company = Company(people);
    std::cout << company.countTeamMembers("some") << '\n';
}
