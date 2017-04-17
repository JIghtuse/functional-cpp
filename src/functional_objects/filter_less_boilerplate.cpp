#include <common.h>
#include <error_test.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Response {
public:
    Response(const std::string& data, bool failed)
        : m_data{data}
        , m_failed{failed}
    {
    }

    bool error() const { return m_failed; }
    std::string data() const { return m_data; }
private:
    std::string m_data;
    bool m_failed;
};

std::ostream& operator<<(std::ostream& out, const Response& r)
{
    return out << r.data();
}

template<typename Container, typename Predicate>
Container filter(const Container& c, Predicate p)
{
    Container result;
    std::copy_if(c.cbegin(), c.cend(),
                 std::back_inserter(result),
                 [&p](auto&& item) {
                     return p(item);
                 });
    return result;
}


int main()
{
    auto responses = std::vector<Response>{
        {"ok", true},
        {"<html></html>", true},
        {"Timed out", false},
        {"", true},
        {"DNS resolve error", false},
        {"", true},
    };

    auto ok_responses = filter(responses, not_error);
    // or             = filter(responses, !error);
    // or             = filter(responses, error == false);
    print(ok_responses, "Successful responses:\n", "", "\n");

    auto failed_responses = filter(responses, error);
    // or                 = filter(responses, error == true);
    // or                 = filter(responses, not_error == false);

    print(failed_responses, "Failed responses:\n", "", "\n");
}
