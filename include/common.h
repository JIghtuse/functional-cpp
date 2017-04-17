#pragma once

#include <iterator>
#include <iostream>

template<typename Container>
std::ostream& print(const Container& c,
                    const char* header = "",
                    const char* footer = "\n",
                    const char* delimiter = " ",
                    std::ostream& out = std::cout)
{
    out << header;
    for (auto it = std::begin(c); it != std::end(c); ++it) {
        out << *it << delimiter;
    }
    out << footer;
    return out;
}

