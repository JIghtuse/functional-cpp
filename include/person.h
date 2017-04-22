#pragma once
#include <string>
#include <ostream>

class Person {
public:
    enum OutputFormat {
        NameOnly,
        FullName,
    };
    Person(const std::string& name, bool isFemale, unsigned age=0)
        : _name{name}
        , _surname{"Doe"}
        , _age{age}
        , female{isFemale}
    {}
    Person(const std::string& name, const std::string& surname, bool isFemale, unsigned age=0)
        : _name{name}
        , _surname{surname}
        , _age{age}
        , female{isFemale}
    {}
    bool isFemale() const { return female; }
    bool isNotFemale() const { return !female; }
    std::string name() const { return _name; }
    std::string surname() const { return _surname; }
    unsigned age() const { return _age; }
    void print(std::ostream& out, Person::OutputFormat fmt) const
    {
        if (fmt == Person::NameOnly) {
            out << name() << '\n';
        } else if (fmt == Person::FullName) {
            out << name() << ' ' << surname() << '\n';
        }
    }
private:
    std::string _name;
    std::string _surname = "";
    unsigned _age;
    bool female;
};
