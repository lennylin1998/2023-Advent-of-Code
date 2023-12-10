#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_map>

std::vector<std::string> pipeMaze;
std::unordered_map< char, std::vector<char> > nextPipeFrom;
std::unordered_map< char, std::vector<char> > viableDirection;

nextPipeFrom['N'] = std::vector<char> {'J', 'L', '|'};
nextPipeFrom['S'] = std::vector<char> {'F', '7', '|'};
nextPipeFrom['W'] = std::vector<char> {'J', '7', '-'};
nextPipeFrom['E'] = std::vector<char> {'F', '-', 'L'};

viableDirection['|'] = std::vector<char>{'N', 'S'};
viableDirection['-'] = std::vector<char>{'E', 'W'};
viableDirection['L'] = std::vector<char>{'N', 'E'};
viableDirection['J'] = std::vector<char>{'N', 'W'};
viableDirection['7'] = std::vector<char>{'W', 'S'};
viableDirection['F'] = std::vector<char>{'S', 'E'};




int EscapeMaze(int col, int row, char from, int steps) {
    for (const char& pipe: nextPipeFrom[from]) {
        viableDirection[pipe]
    }
    return 0;
}

int main() {
    std::string line;
    std::ifstream inputFile("input.txt");
    int startCol;
    int startRow;
    while (std::getline(inputFile, line)) {
        pipeMaze.push_back(line);
    }

    return 0;
}