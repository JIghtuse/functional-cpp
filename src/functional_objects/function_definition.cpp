// Two ways to define a function

#include <iostream>

// 'old' C-like syntax
int max1(int arg1, int arg2)
{
    return arg1 > arg2 ? arg1 : arg2;
}

// with a trailing return type, available since C++11
auto max2(int arg1, int arg2) -> int
{
    return arg1 > arg2 ? arg1 : arg2;
}

int main()
{
    std::cout << max1(2, 4) << '\n';
    std::cout << max2(3, 8) << '\n';
}
