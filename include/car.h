#pragma once

#include <string>

class Car {
public:
    Car(const std::string manufacturer, unsigned age)
        : m_manufacturer{manufacturer}
        , m_age{age}
    {
    }
    unsigned age() const { return m_age; }
private:
    std::string m_manufacturer;
    unsigned m_age;
};
