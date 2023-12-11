#include <fstream>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <utility> // for std::pair
#include <cmath>

int main() {
    std::string line;
    std::ifstream inputFile("input.txt");
    std::vector< std::string > universe;
    int numRow;
    int numCol;
    std::vector<bool> rowEmpty;
    std::vector<bool> colEmpty;
    std::vector< std::pair<int, int> > unvisitGalaxies;

    // Read the file into matrix
    while (std::getline(inputFile, line)) {
        universe.push_back(line);
    }
    numRow = universe.size();
    numCol = universe[0].length();

    // Initialize array to accomodate the expansion data
    for (int i=0; i<numRow; i++) {
        rowEmpty.push_back(true);
    }
    for (int i=0; i<numCol; i++) {
        colEmpty.push_back(true);
    }
    
    // Observe the universe to keep track of the coordinates of each galaxy, also the row/col that are subject to expansion
    for (int i=0; i<numRow; i++) {
        for (int j=0; j<numCol; j++) {
            if (universe[i][j] != '.') {
                rowEmpty[i] = false;
                colEmpty[j] = false;
                unvisitGalaxies.push_back(std::make_pair(i, j));
            }
        }
    }

    // Expand: modify the recorded coordinates
    int expandedRows = 0;
    for (int i=0; i<numRow; i++) {
        if (rowEmpty[i]) {
            for (auto& pair: unvisitGalaxies) {
                if (pair.first > (i + expandedRows)) {
                    pair.first++;
                }
            }
            // Account for the expansion and add to the original recorded row/col
            expandedRows++;
        }
    }

    int expandedCols = 0;
    for (int i=0; i<numCol; i++) {
        if (colEmpty[i]) {
            for (auto& pair: unvisitGalaxies) {
                if (pair.second > (i + expandedCols)) {
                    pair.second++;
                }
            }
            expandedCols++;
        }
    }
    
    // Calculate the shortest path
    int pathSum = 0;
    std::pair<int, int> pivotGalaxy;
    do {
        pivotGalaxy = unvisitGalaxies.back();
        unvisitGalaxies.pop_back();
        for (auto& unvisitG: unvisitGalaxies) {
            pathSum += std::abs(pivotGalaxy.first - unvisitG.first) + std::abs(pivotGalaxy.second - unvisitG.second);
        }
    } while (unvisitGalaxies.size());

    std::cout << "SUM: " << pathSum << "\n";

    return 0;
}