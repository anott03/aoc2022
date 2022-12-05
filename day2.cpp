#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <sstream>

std::string getInput() {
  std::ifstream ifs("2.in");
  std::string content((std::istreambuf_iterator<char>(ifs)),
                      (std::istreambuf_iterator<char>()));
  return content;
}

std::vector<std::string> split(std::string str, char delim) {
  std::vector<std::string> tokens;
  std::string token;
  std::stringstream ss(str);
  while (getline(ss, token, delim)){
      tokens.push_back(token);
  }
  return tokens;
}

int getChoiceValue(char c) {
  if (c == 'X' || c == 'A') {
    return 1;
  } else if (c == 'Y' || c =='B') {
    return 2;
  }
  return 3;
}

// A, X -> Rock
// B, Y -> Paper
// C, Z -> Scissors

int getWinValue(char c1, char c2) {
  if ((c1 == 'A' && c2 == 'Y') ||
      (c1 == 'B' && c2 == 'Z') ||
      (c1 == 'C' && c2 == 'X')) {
    return 6;
  }

  if (getChoiceValue(c1) == getChoiceValue(c2)) return 3;

  return 0;
}

int getLosingValue(char c) {
  if (c == 'A') {
    return 3;
  } else if (c == 'B') {
    return 1;
  }
  return 2;
}

int getWinningValue(char c) {
  if (c == 'A') {
    return 2;
  } else if (c == 'B') {
    return 3;
  }
  return 1;
}

int main() {
  std::string input = getInput();
  std::vector<std::string> rounds = split(input, '\n');

  int part1 = 0;
  int part2 = 0;

  for (auto &round : rounds) {
    auto s = round.c_str();

    int score1 = getChoiceValue(s[2]) + getWinValue(s[0], s[2]);
    part1 += score1;

    char c1 = s[0];
    char c2 = s[2];

    std::cout<<c1<<" "<<c2<<std::endl;

    int score2 = 0;
    if (c2 == 'X') score2 += getLosingValue(c1);
    else if (c2 == 'Y') score2 += 3 + getChoiceValue(c1);
    else if (c2 == 'Z') score2 += 6 + getWinningValue(c1);

    part2 += score2;
  }

  std::cout<<"part 1: "<<part1<<std::endl;
  std::cout<<"part 2: "<<part2<<std::endl;
}
