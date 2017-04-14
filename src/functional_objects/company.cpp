#include <company.h>
#include <algorithm>

// possible implementation for lambda in countTeamMembers
class lambda_implementation {
public:
    lambda_implementation(const Company* _this,
                          const std::string& teamName)
        : m_this{_this}
        , m_teamName{teamName}
    {
    }

    bool operator() (const Person& employee) const
    {
        return m_this->teamNameFor(employee) == m_teamName;
    }
private:
    const Company* m_this;
    const std::string& m_teamName;
};

int Company::countTeamMembers(const std::string& teamName) const
{
    return std::count_if(
            m_employees.cbegin(), m_employees.cend(),
            [this, &teamName](const Person& p) {
                return teamNameFor(p) == teamName;
            });
}

std::string Company::teamNameFor(const Person&) const
{
    return "some";
}
