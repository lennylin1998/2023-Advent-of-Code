#include <fstream>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <utility> // for std::pair
#include <string>

int mirrorSpotter(const std::vector<std::string> segment) {
    int numCol = segment[0].length();
    int left = 0;
    int right = numCol - 1;
    bool mirrorIndex = 0;
    
    std::vector<std::string> shiftSegment(segment.begin() + 1, segment.end());
    std::vector<std::string> popSegment(segment.begin(), segment.end() - 1);
    while (left < right) {
        // if (segment[left] != segment[right]) {
        //     int popAndCheck = mirrorSpotter(popSegment);
        //     if (popAndCheck == 0) {
        //         mirrorIndex = 
        //     } else {
        //         mirrorIndex = checkFromLeft;
        //     }
        //     break;
        // }

    }
    return mirrorIndex;
}


int main() {
    std::string line;
    std::ifstream inputFile("input.txt");
    std::vector< std::vector<std::string> > signals;
    std::vector< std::vector<std::string> > signalsT;

    std::vector<std::string> tempRow;
    std::vector<std::string> tempCol;
    while (std::getline(inputFile, line)) {
        if (line.empty()) {
            signals.push_back(tempRow);
            tempRow.clear();
            signalsT.push_back(tempCol);
            tempCol.clear();
        } else {
            tempRow.push_back(line);
            int colNum = line.length();
            for (int i=0; i<colNum; i++) {
                if (tempCol.size() < colNum) {
                    tempCol.push_back(line.substr(i,1));
                } else {
                    tempCol[i] += line[i];
                }
            }
        }
    }

    // for (const auto& segment: signalsT[2]) {
    //     std::cout << segment << "\n";
    // }

    return 0;
}