// folding examples
#include <iostream>
#include <string>
#include <numeric>

int incrementOnNewline(int previousCount, char c)
{
    return (c == '\n') ? previousCount + 1
                       : previousCount;
}

// counts newlines in string
int countLines(const std::string& s)
{
    return std::accumulate(s.cbegin(), s.cend(), 0, incrementOnNewline);
}

int main()
{
    using namespace std::string_literals;

    auto heroes = "Indiana Jones\nJohn Reese\nJames Bond"s;
    std::cout << "Number of newlines in\n"
              << "'" << heroes << "': "
              << countLines(heroes) << '\n';
}
