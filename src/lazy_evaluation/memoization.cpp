#include <iostream>
#include <map>
#include <tuple>

template<typename Result, typename... Args>
auto make_memoized(Result (*f)(Args...)) {
    auto cache = std::map<std::tuple<Args...>, Result>{};

    return [f, cache] (Args... args) mutable -> Result
    {
        const auto args_tuple = std::make_tuple(args...);
        const auto cached = cache.find(args_tuple);
        if (cached == cache.end()) {
            auto result = f(args...);
            cache[args_tuple] = result;
            return result;
        } else {
            return cached->second;
        }
    };
}

unsigned fib_naive(unsigned n)
{
    return n == 0 ? 0 :
           n == 1 ? 1 :
                    fib_naive(n - 1) + fib_naive(n - 2);
}

int main()
{
    auto fibmemo = make_memoized(fib_naive);

    std::cout << "fib(42) = " << fibmemo(42) << '\n';
}
