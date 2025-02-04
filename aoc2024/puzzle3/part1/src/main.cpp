#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ifstream inFile;
  std::string line;
  std::vector<std::string> File;
  int lineCount = -1;
  inFile.open("d:/projects/advent/aoc2024/puzzle3/part1/src/input.txt");
  while (inFile) {
    std::getline(inFile, line);
    File.push_back(line);
    lineCount++;
  }

  std::cout << File[0] << '\n' << lineCount << '\n';

  return 0;
}
