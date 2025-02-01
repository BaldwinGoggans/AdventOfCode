#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main() {
  std::fstream inFile;
  std::string line;
  std::vector<std::string> file;

  int lineCount = -1;
  inFile.open("D:/projects/advent/aoc2024/puzzle2/part1/src/input.txt");
  while (inFile) {
    std::getline(inFile, line);
    file.push_back(line);
    lineCount++;
  }
  inFile.close();
  std::cout << lineCount << '\n';
  int num;
  std::vector<int> numbers;
  bool order = false;
  bool difference = false;
  int safeReports = 0;
  int orderCount = 0;
  int negetiveOrderCount = 0;
  int differenceCount = 0;
  int size;
  for (int f = 0; f < lineCount; ++f) {
    std::stringstream ss(file[f]);

    while (ss >> num) {
      numbers.push_back(num);
    }
    for (int n : numbers) {
      std::cout << n << " ";
    }
    size = numbers.size();
    std::cout << '\n';
    for (int i = 0; i < size - 1; ++i) {
      if (numbers[i] > numbers[i + 1]) {
        orderCount++;
      } else if (numbers[i] < numbers[i + 1]) {
        negetiveOrderCount++;
      }
    }
    if (orderCount == size - 1 || negetiveOrderCount == size - 1) {
      order = true;
    }
    for (int i = 0; i < size - 1; i++) {
      if (numbers[i] - numbers[i + 1] > 0 && numbers[i] - numbers[i + 1] < 4) {
        differenceCount++;
      } else if (numbers[i] - numbers[i + 1] < 0 &&
                 numbers[i] - numbers[i + 1] > -4) {
        differenceCount++;
      }
    }
    if (differenceCount == size - 1) {
      difference = true;
    }
    std::cout << order << " " << difference << " " << differenceCount << " "
              << orderCount << " " << negetiveOrderCount << " " << size << '\n';
    std::cout << '\n';
    if (difference == true && order == true) {
      safeReports++;
    }
    difference = false;
    orderCount = 0;
    order = false;
    negetiveOrderCount = 0;
    numbers.clear();
    differenceCount = 0;
  }
  std::cout << safeReports << '\n';
  return 0;
}
