#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class EngineSchematic {
public:
    EngineSchematic(const std::string& filename);
    void display();

private:
    static const int SIZE = 9;
    static const int SUBEngineSchematic_SIZE = 3;

    std::vector< std::vector<char> > data;
};

EngineSchematic::EngineSchematic(const std::string& filename) {
    std::ifstream inputFile(filename);

    if (!inputFile) {
        std::cerr << "Error opening file." << std::endl;
        std::exit(1);
    }

    std::vector< std::vector<char> > temp;
    std::string line;
    while (std::getline(inputFile, line)) {
        std::vector<char> row(line.begin(), line.end());
        temp.push_back(row);
    }

    // Determine the size of the matrix
    size_t numRows = temp.size();
    size_t numCols = (numRows > 0) ? temp[0].size() : 0;

    // Resize the matrix and copy the data
    data.resize(numRows, std::vector<char>(numCols));
    for (size_t i = 0; i < numRows; ++i) {
        for (size_t j = 0; j < numCols; ++j) {
            data[i][j] = temp[i][j];
        }
    }

}

void EngineSchematic::display() {
    // std::string str = "................................................965..583........389.................307.................512......................395.....387";
    std::cout << "Original EngineSchematic:\n";
    std::cout << data.size() << "\n";
    std::cout << data[0].size() << "\n";
    // for (int i = 0; i < data.size(); ++i) {
    //     for (int j = 0; j < data[0].size(); ++j) {
    //         std::cout << data[i][j] << ' ';
    //     }
    //     std::cout << '\n';
    // }
}

int main() {
    EngineSchematic myEngineSchematic("input.txt");
    myEngineSchematic.display();
    return 0;
}
