#pragma once
#include <string>

class Person {
public:
    Person(const std::string& name, bool isFemale, unsigned age=0)
        : _name{name}
        , _age{age}
        , female{isFemale}
    {}
    bool isFemale() const { return female; }
    bool isNotFemale() const { return !female; }
    std::string name() const { return _name; }
    unsigned age() const { return _age; }
private:
    std::string _name;
    unsigned _age;
    bool female;
};
