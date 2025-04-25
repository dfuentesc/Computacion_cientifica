#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <set>
#include <vector>
#include <cctype>


void analyze_document(const std::string & fname);

int main(int argc, char **argv)
{
    const std::string FNAME = argv[1];

    analyze_document(FNAME);

    return 0;
}

void analyze_document(const std::string & fname) 
{
    std::ifstream file(fname);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << fname << std::endl;
        return;
    }

    std::map<std::string, int> word_count;
    std::string word;

    while (file >> word) {

        
        while (!word.empty() && std::ispunct(static_cast<unsigned char>(word.back()))) {
            word.pop_back();
        }

        if (!word.empty()) {
            word_count[word]++;
        }
    }

    // Transfer to vector and sort by frequency
    std::vector<std::pair<std::string, int>> vec(word_count.begin(), word_count.end());
    std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    // Output top 20 words
    int count = 0;
    for (const auto &entry : vec) {
        std::cout << entry.first << " " << entry.second << std::endl;
        if (++count >= 20) {
            break;
        }
    }
}