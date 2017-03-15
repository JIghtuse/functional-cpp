#pragma once
#include <string>

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
