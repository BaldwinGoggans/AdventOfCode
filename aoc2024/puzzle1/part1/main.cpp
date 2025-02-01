#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>

void bubbleSort(std::vector<int> &v) {
  int n = v.size();

  for (int i = 0; i < n - 1; i++) {

    for (int j = 0; j < n - i - 1; j++) {

      if (v[j] > v[j + 1])

        std::swap(v[j], v[j + 1]);
    }
  }
}

int splitToInts(std::string &s, char c, int choice) {
  int pos = s.find(c);
  std::string set2 = s.substr(pos + 1);
  int startOfLine = s.size() - set2.size() - 1;
  std::string set1 = s.substr(pos - startOfLine);
  int s1 = stoi(set1);
  int s2 = stoi(set2);

  if (choice == 1) {
    return s1;
  } else {
    return s2;
  }
}

int main() {

  std::ifstream infile;
  std::string line;
  std::vector<int> list1;
  std::vector<int> list2;
  std::vector<std::string> allLines;
  int lineCount = -1;
  infile.open("D:/advent/aoc2024/puzzle1/entry.txt");
  while (infile) {
    std::getline(infile, line);
    allLines.push_back(line);
    lineCount++;
  }
  infile.close();
  std::cout << lineCount << '\n';
  int s1;
  int s2;

  for (int i = 0; i < lineCount; ++i) {
    s1 = splitToInts(allLines[i], ' ', 1);
    s2 = splitToInts(allLines[i], ' ', 2);

    list1.push_back(s1);
    list2.push_back(s2);
  }

  bubbleSort(list1);
  bubbleSort(list2);
  int sum = 0;
  for (int i = 0; i < lineCount; ++i) {
    if (list1[i] > list2[i]) {
      sum = list1[i] - list2[i] + sum;
    } else if (list1[i] < list2[i]) {
      sum = list2[i] - list1[i] + sum;
    } else {
      sum = sum + 0;
    }
  }

  std::cout << sum << '\n';

  return 0;
}
