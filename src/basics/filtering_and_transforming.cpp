// filtering and transforming example
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Person {
public:
    Person(const std::string& name, bool isFemale)
        : _name{name}
        , female{isFemale}
    {}
    bool isFemale() const { return female; }
    bool isNotFemale() const { return !female; }
    std::string name() const { return _name; }
private:
    std::string _name;
    bool female;
};

void removeNonFemales(std::vector<Person>& people)
{
    people.erase(
        std::remove_if(people.begin(), people.end(), [](const Person& p) {
            return p.isNotFemale();
        }),
        people.end());
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

    auto females = std::vector<Person>{};
    std::copy_if(people.cbegin(), people.cend(),
                 std::back_inserter(females),
                 [](const Person& p) { return p.isFemale(); });

    auto names = std::vector<std::string>(females.size());
    std::transform(females.cbegin(), females.cend(),
                   names.begin(),
                   [](const Person& p) { return p.name(); });

    std::cout << "Female person names: \n";
    for (auto name: names) {
        std::cout << name << '\n';
    }
}
