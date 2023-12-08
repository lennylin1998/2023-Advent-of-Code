#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <utility> // for std::pair

void HauntedWasteLand(const std::string& filename) {
    std::ifstream inputFile(filename);

    if (!inputFile) {
        std::cerr << "Error opening file." << std::endl;
        std::exit(1);
    }
    std::unordered_map< std::string, std::pair<std::string, std::string> > myHashTable;
    std::string instruction;
    std::getline(inputFile, instruction);

    std::string curr;

    int counter = 0;
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        // std::cout << line << "\n";

        // Parse the input
        std::string key;
        char equalSign;
        std::string left;
        std::string right;

        // Read the input into variables
        if (iss >> key >> std::ws >> equalSign >> std::ws >> left >> std::ws >> right) {
            left  = left.substr(1, left.length() - 2);
            right  = right.substr(0, right.length() - 1);
            myHashTable[key] = std::make_pair(left, right);
            if (counter < 1) {
                ++counter;
                curr = key;
            }
            // std::cout << "Key: " << key << "\n";
            // std::cout << "Left: " << left << "\n";
            // std::cout << "Right: " << right << "\n";
        }
    }
    inputFile.close();

    int steps = 0;
    int index = 0;
    while (curr != "ZZZ") {
        std::cout << curr << "\n";
        if (index > instruction.length()) {
            index = 0;
        } else {
            ++steps;
            ++index;
        }
        if (instruction[index] == 'L') {
            curr = myHashTable[curr].first;
        } else {
            curr = myHashTable[curr].second;
        }
    }
    std::cout << "FINAL" << steps << "\n";
}

int main() {
    HauntedWasteLand("input.txt");
    return 0;
}
