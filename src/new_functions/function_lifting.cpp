// Function lifting examples
#include <common.h>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

// if we have a function that operates on a string:
void toUpper(std::string& s)
{
    std::transform(s.cbegin(), s.cend(),
                   s.begin(),
                   ::toupper);
}

// we could easily create functions to operate on a:
// - pointer to string,
// - vector of strings,
// - map with value strings

void pointerToUpper(std::string* s)
{
    if (s != nullptr) {
        toUpper(*s);
    }
}

void vectorToUpper(std::vector<std::string>& vs)
{
    for (auto& s: vs) {
        toUpper(s);
    }
}

void mapToUpper(std::map<int, std::string>& ms)
{
    for (auto& pair: ms) {
        toUpper(pair.second);
    }
}


// Note: these functions would be implemented in the exact same way
// if the function toUpper was to be replaced with something else

// We could have created a HOF that takes any function that operates
// on a single string, and creates a function that operates on a pointer (vector, map) to a string
// These functions are called lifting functions

template<typename Function>
auto pointerLift(Function f)
{
    return [f](auto* item) {
        if (item) {
            return f(*item);
        }
    };
}

template<typename Function>
auto collectionLift(Function f)
{
    return [f](auto& items) {
        for (auto& item: items) {
            f(item);
        }
    };
}

template<typename Function>
auto mapLift(Function f)
{
    return collectionLift([f](auto& pair) {
        return f(pair.second);
    });
}

template<
    typename C,
    typename P1 = typename std::remove_cv_t<typename C::value_type::first_type>,
    typename P2 = typename C::value_type::second_type
    >
std::vector<std::pair<P2, P1>> reversePairs(const C& items)
{
    std::vector<std::pair<P2, P1>> result(items.size());
    std::transform(std::begin(items), std::end(items),
                   std::begin(result),
                   [] (const std::pair<const P1, P2>& p)
                   {
                       return std::make_pair(p.second, p.first);
                   });
    return result;
}


int main()
{
    const auto vsOriginal = std::vector<std::string>{
        "Abc",
        "dEF",
        "ghi",
        "jkL"
    };

    const auto msOriginal = std::map<int, std::string>{
        {0, "dog"},
        {1, "Cat"},
        {2, "parrot"},
        {3, "worm"}
    };

    auto vs = vsOriginal;
    print(vs, "before call toUpper: ");
    vectorToUpper(vs);
    print(vs, "after call toUpper : ");

    vs = vsOriginal;
    print(vs, "before call toUpper: ");
    collectionLift(toUpper)(vs);
    print(vs, "after call toUpper : ");

    auto ms = msOriginal;
    std::cout << "Some animals before call toUpper:\n";
    for (const auto& pair: ms) {
        std::cout << pair.first << ": " << pair.second << '\n';
    }
    mapLift(toUpper)(ms);
    std::cout << "Some animals after call toUpper:\n";
    for (const auto& pair: ms) {
        std::cout << pair.first << ": " << pair.second << '\n';
    }

    auto v = reversePairs(ms);
    std::cout << "Some animals after reversing pairs: \n";
    for (const auto& pair: v) {
        std::cout << pair.first << ": " << pair.second << '\n';
    }
}
