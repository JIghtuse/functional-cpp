#include <iostream>
#include <vector>

unsigned fib_naive(unsigned n)
{
    return n == 0 ? 0 :
           n == 1 ? 1 :
                    fib_naive(n - 1) + fib_naive(n - 2);
}

std::vector<unsigned> vcache{0, 1};

unsigned fib_vcache(unsigned n)
{
    if (vcache.size() > n) {
        return vcache[n];
    } else {
        const auto result = fib_vcache(n - 1) + fib_vcache(n - 2);
        vcache.push_back(result);
        return result;
    }
}

class fib_cache {
public:
    fib_cache()
        : m_previous{0}
        , m_last{1}
        , m_size{2}
    {
    }

    size_t size() const
    {
        return m_size;
    }

    unsigned operator[] (unsigned n) const
    {
        return n == m_size - 1 ? m_last :
               n == m_size - 2 ? m_previous :
                                 0;
    }

    void push_back(unsigned value)
    {
        ++m_size;
        m_previous = m_last;
        m_last = value;
    }
private:
    unsigned m_previous;
    unsigned m_last;
    size_t m_size;
};

fib_cache fcache;

unsigned fib_fcache(unsigned n)
{
    if (fcache.size() > n) {
        return fcache[n];
    } else {
        const auto result = fib_fcache(n - 1) + fib_fcache(n - 2);
        fcache.push_back(result);
        return result;
    }
}


int main()
{
    std::cout << fib_naive(42) << '\n';
    std::cout << fib_vcache(42) << '\n';
    std::cout << fib_fcache(42) << '\n';
}
