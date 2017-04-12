// Various things that can be used as functions in C++

#include <car.h>
#include <person.h>
#include <algorithm>
#include <iostream>
#include <vector>

int ask()
{
    return 42;
}

using function_ptr = decltype(ask)*;

class convertible_to_function_ptr {
public:
    operator function_ptr () const
    {
        return ask;
    }
};

void function_pointers_examples()
{
    auto ask_ptr = &ask;
    std::cout << ask_ptr() << '\n';

    auto& ask_ref = ask;
    std::cout << ask_ref() << '\n';

    convertible_to_function_ptr ask_wrapper;
    std::cout << ask_wrapper() << '\n';
}



bool older_than_42(const Person& person)
{
    return person.age() > 42;
}

void ordinary_function_examples(const std::vector<Person>& people)
{
    auto counter = std::count_if(people.cbegin(), people.cend(), older_than_42);
    std::cout << "Number of people older than 42: " << counter << '\n';
}


class older_than {
public:
    older_than(unsigned limit)
        : m_limit{limit}
    {
    }

    bool operator() (const Person& person) const
    {
        return person.age() > m_limit;
    }
private:
    unsigned m_limit;
};

void call_operator_overloading_examples(const std::vector<Person>& people)
{
    auto older_than_42 = older_than{42};

    auto counter_older_than_42 = std::count_if(
        people.cbegin(), people.cend(),
        older_than_42);

    auto counter_older_than_14 = std::count_if(
        people.cbegin(), people.cend(),
        older_than(14));

    std::cout << "Number of people older than 42: "
              << counter_older_than_42 << '\n';
    std::cout << "Number of people older than 14: "
              << counter_older_than_14 << '\n';
}


class g_older_than {
public:
    g_older_than(unsigned limit)
        : m_limit(limit)
    {
    }

    template<typename T>
    bool operator() (T&& object) const
    {
        return std::forward<T>(object).age() > m_limit;
    }
private:
    unsigned m_limit;
};

void generic_function_object_examples(const std::vector<Person>& people)
{
    auto cars = std::vector<Car>{
        {"Toyota", 32},
        {"Nissan", 10}
    };
    auto predicate = g_older_than(9);

    auto peopleCounter = std::count_if(people.cbegin(), people.cend(), predicate);

    std::cout << "people counter: " << peopleCounter << '\n';

    auto carCounter = std::count_if(cars.cbegin(), cars.cend(), predicate);

    std::cout << "car counter: " << carCounter << '\n';
}


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

    function_pointers_examples();
    ordinary_function_examples(people);
    call_operator_overloading_examples(people);
    generic_function_object_examples(people);
}
