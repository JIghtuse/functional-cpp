// lambdas call operator is const by default,
// so we should use "mutable" to change value of the captured variables

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


int main()
{
    int count = 0;
    auto words = std::vector<std::string>{"An", "anicent", "pond"};
    std::for_each(words.cbegin(), words.cend(),
                  [&count]
                  (const std::string& word)
                  mutable
                  {
                      if (isupper(word[0])) {
                          std::cout << word << '\n';
                          ++count;
                      }
                  });
}
