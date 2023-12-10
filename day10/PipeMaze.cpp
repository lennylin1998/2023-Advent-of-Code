#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_map>

std::vector<std::string> pipeMaze;
std::unordered_map< char, std::vector<char> > toDirection;
std::unordered_map< char, std::vector<char> > fromDirection;

toDirection['N'] = std::vector<char> {'J', 'L', '|'};
toDirection['S'] = std::vector<char> {'F', '7', '|'};
toDirection['W'] = std::vector<char> {'J', '7', '-'};
toDirection['E'] = std::vector<char> {'F', '-', 'L'};

fromDirection['N'] = std::vector<char> {'J', 'L', '|'};
fromDirection['S'] = std::vector<char> {'F', '7', '|'};
fromDirection['W'] = std::vector<char> {'J', '7', '-'};
fromDirection['E'] = std::vector<char> {'F', '-', 'L'};



int EscapeMaze(int col, int row, char next, int steps) {
    switch (next) {
        case 'N':
            if (pipeMaze[col])
            break;
        default:
    }
    return 0;
}

int main() {
    std::string line;
    std::ifstream inputFile("input.txt");
    while (std::getline(inputFile, line)) {
        pipeMaze.push_back(line);
    }

    return 0;
}