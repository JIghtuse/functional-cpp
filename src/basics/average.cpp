// Calculates the average value from some list of values
#include <iostream>
#include <numeric>
#include <vector>


double averageScoreImperative(const std::vector<int>& scores)
{
    auto sum = 0;

    for (auto score: scores) {
        sum += score;
    }

    return sum / (double) scores.size();
}

double averageScoreFunctional(const std::vector<int>& scores)
{
    auto sum = std::accumulate(scores.cbegin(), scores.cend(), 0);
    return sum / (double) scores.size();
}

double scoresProduct(const std::vector<int>& scores)
{
    return std::accumulate(scores.cbegin(), scores.cend(), 1,
                           std::multiplies<int>());
}

int main()
{
    auto values = std::vector<int>{9, 7, 10, 5, 8, 8, 6};
    std::cout << averageScoreImperative(values) << '\n';
    std::cout << averageScoreFunctional(values) << '\n';
    std::cout << scoresProduct(values) << '\n';
}
