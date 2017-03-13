// counts number of lines in given input files
// functional style

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>

int countLines(std::ifstream& in)
{
    in.unsetf(std::ios_base::skipws);

    return std::count(
        std::istream_iterator<char>{in},
        std::istream_iterator<char>{},
        '\n');
}

std::ifstream openFile(const std::string& filename)
{
    return std::ifstream{filename};
}

std::vector<int> countLinesInFiles(const std::vector<std::string>& files)
{
    auto inStreams = std::vector<std::ifstream>(files.size());
    std::transform(files.cbegin(), files.cend(),
                   inStreams.begin(),
                   openFile);

    auto results = std::vector<int>(inStreams.size());
    std::transform(inStreams.begin(), inStreams.end(),
                   results.begin(),
                   countLines);
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
