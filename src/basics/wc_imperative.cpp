// counts number of lines in given input files
// imperative style

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<int> countLinesInFiles(const std::vector<std::string>& files)
{
    auto results = std::vector<int>{};
    char c = 0;

    for (const auto& file: files) {
        auto lineCount = 0;

        auto in = std::ifstream{file};
        while (in.get(c)) {
            if (c == '\n') {
                ++lineCount;
            }
        }

        results.push_back(lineCount);
    }

    return results;
}

std::vector<std::string> getFilenames(int argc, char** argv)
{
    --argc;
    ++argv;

    auto files = std::vector<std::string>{};
    for (int i = 0; i < argc; ++i) {
        auto arg = argv[i];
        if (arg[0] == '-') {
            std::cerr << "unsupported argument: " << arg << '\n';
            continue;
        }
        files.push_back(arg);
    }
    return files;
}

int main(int argc, char** argv)
{
    auto files = getFilenames(argc, argv);
    auto lineCounts = countLinesInFiles(files);

    auto totalCount = size_t{0};
    for (size_t i = 0; i < files.size(); ++i) {
        std::cout << std::setw(11) << lineCounts[i] << ' ' << files[i] << '\n';
        totalCount += lineCounts[i];
    }
    std::cout << std::setw(11) << totalCount << " total\n";
}
