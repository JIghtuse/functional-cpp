// read a file of text, determine the n most frequently used words,
// and print out a sorted list of those words along with their frequencies

#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

template<typename T>
using CountAndValue = std::pair<unsigned int, T>;

using CountString = std::pair<unsigned int, std::string>;

std::vector<std::string> readWords(const std::string& filename)
{
    auto words = std::vector<std::string>{};

    std::ifstream in{filename};
    for (std::string s; in >> s;)  {
        words.emplace_back(s);
    }
    return words;
}

template<typename C, typename T = typename C::value_type>
std::unordered_map<T, unsigned int> countOccurences(const C& items)
{
    auto counts = std::unordered_map<T, unsigned int>{};
    for (const auto& item: items) {
        counts[item]++;
    }
    return counts;
}

template<typename C,
         typename P1 = typename C::key_type,
         typename P2 = typename C::mapped_type>
auto reversePairs(const C& collection)
{
    auto reversed = std::vector<std::pair<P2, P1>>(collection.size());
    for (const auto& item: collection) {
        reversed.push_back({item.second, item.first});
    }
    return reversed;
}

std::vector<CountString> sorted(std::vector<CountString> v)
{
    std::sort(v.begin(), v.end(), std::greater<>());
    return v;
}

void printPairs(const std::vector<CountString>& pairs)
{
    for (const auto& pair: pairs) {
        std::cout << pair.first << '\t' << pair.second << '\n';
    }
}

void printCommonWords(const std::string& filename)
{
    printPairs(
        sorted(
            reversePairs(
                countOccurences(
                    readWords(filename)
                )
            )
        )
    );
}

int main()
{
    printCommonWords(__FILE__);
}
