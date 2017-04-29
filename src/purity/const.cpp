// some const details

#include <iostream>
#include <string>

// basic idea behind const is to prevent data mutation
// the way it is done in C++ is through its type system:
// `T` and `const T` are different types

void printName(std::string nameCopy)
{
}

void printNameRef(std::string& nameRef)
{
}

void printNameConstRef(const std::string& nameConstRef)
{
}

class Person {
public:
    // std::string (Person* this)
    std::string name_nonconst()
    {
        return name;
    }

    // std::string (const Person* this)
    std::string name_const() const
    {
        return name;
    }

    // std::string (Person* this, std::ostream& out)
    void printNonconst(std::ostream& out)
    {
        out << name;
    }

    // std::string (const Person* this, std::ostream& out)
    void printConst(std::ostream& out) const
    {
        out << name;
    }
private:
    std::string name;
};

int main()
{
    const std::string name{"John Smith"};
    std::string nameCopy = name;
    // error
    // std::string& nameRef = name;
    const std::string& nameConstref = name;

    // error
    // std::string* namePtr = &name;
    const std::string* nameConstptr = &name;

    printName(name);
    // error
    // printNameRef(name);
    printNameConstRef(name);
}
