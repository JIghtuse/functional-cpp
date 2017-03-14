
// string trimming example
#include <algorithm>
#include <iostream>
#include <string>

bool is_not_space(char c)
{
    return c != ' ' && c != '\t' && c != '\n';
}

// trims whitespace from the left of given string
std::string trimLeft(std::string s)
{
    s.erase(s.begin(),
            std::find_if(s.begin(), s.end(), is_not_space));
    return s;
}

// trims whitespace from the right of given string
std::string trimRight(std::string s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), is_not_space).base(),
            s.end());
    return s;
}

// trims whitespace from both ends of given string
std::string trim(const std::string& s)
{
    return trimLeft(trimRight(s));
}

int main()
{
    using namespace std::string_literals;

    auto s = "   abc     "s;
    std::cout << "Trimmed '" << s << "': '" << trim(s) << "'\n";
}

