#include <fstream>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


int OasisAnalyzer(std::vector<int> history) {
    for (const int& num: history) {
        std::cout << num << ' ';
    }
    bool needToDigDeeper = false;
    std::vector<int> nextVector;
    for (size_t i=1; i<history.size(); i++) {
        if (history[i] != 0) {
            needToDigDeeper = true;
        }
        nextVector.push_back(history[i] - history[i-1]);
    }
    std::cout << "\n";
    if (!needToDigDeeper) {
        return 0;
    }
    int result = nextVector.front() - OasisAnalyzer(nextVector);
    std::cout << "subTraction: " << result << "\n";
    return result;
}

int main() {
    std::string line;
    int sum = 0;
    int num;
    
    std::ifstream inputFile("input.txt");

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::vector<int> history;
        while (iss >> num) {
            history.push_back(num);
        }
        int predict;
        predict = history.front() - OasisAnalyzer(history);
        sum += predict;
    }

    std::cout << "SUM:" << sum << "\n";
    return 0;
}