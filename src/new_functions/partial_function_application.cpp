#include <common.h>
#include <partial_application.h>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

// we take
// operator > : (int, int) -> bool
// and create a new unary function object that fixes
// second argument to a specific value (partial function application)

class greaterThan {
public:
    greaterThan(int value)
        : m_value{value}
    {
    }

    bool operator() (int arg) const
    {
        return arg > m_value;
    }
private:
    int m_value;
};

int main()
{
    auto greaterThan42 = greaterThan{42};
    std::cout << std::boolalpha;
    std::cout << 1 << " > 42 ? " << greaterThan42(1) << '\n';
    std::cout << 50 << " > 42 ? " << greaterThan42(50) << '\n';

    auto xs = std::vector<int>{1, 3, 923, 12, 8, 10, 2, 42};
    std::partition(xs.begin(), xs.end(), greaterThan{6});
    print(xs, "Partitioned around 6: ");

    auto greaterThan42_generic = bind2nd(std::greater<int>(), 42);
    std::cout << 1 << " > 42 ? " << greaterThan42_generic(1) << '\n';
    std::cout << 50 << " > 42 ? " << greaterThan42_generic(50) << '\n';

    std::partition(xs.begin(), xs.end(), bind2nd(std::greater<int>(), 11));
    print(xs, "Partitioned around 11: ");
}
