#pragma once

#include <person.h>
#include <string>
#include <vector>

class Company {
public:
    Company(const std::vector<Person>& employees)
        : m_employees{employees}
    {
    }
    std::string teamNameFor(const Person& employee) const;
    int countTeamMembers(const std::string& teamName) const;
private:
    std::vector<Person> m_employees;
};
