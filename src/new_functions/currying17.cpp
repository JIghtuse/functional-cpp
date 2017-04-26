// currying examples

#include <currying17.h>
#include <person.h>
#include <iostream>

int main()
{
    std::cout << partial_add3(1, 2, 3) << '\n';
    std::cout << partial_add3(1)(2, 3) << '\n';
    std::cout << partial_add3(1, 2)(3) << '\n';
    std::cout << partial_add3(1)(2)(3) << '\n';
}
