#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <sstream>

std::string getInput() {
  std::ifstream ifs("4.in");
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

int main() {
  std::vector<std::string> input = split(getInput(), '\n');
  int part1 = 0;
  int part2 = 0;
  for (auto &pair : input) {
    // auto s = pair.c_str();
    int s1 = stoi(pair.substr(0, pair.find('-')));
    int e1 = stoi(pair.substr(pair.find('-')+1, pair.find(',')-(pair.find('-')+1)));

    auto secondSection = pair.substr(pair.find(',') + 1, pair.length());
    int s2 = stoi(secondSection.substr(0, secondSection.find('-')));
    int e2 = stoi(secondSection.substr(secondSection.find('-') + 1, secondSection.length()));
    if ((s2 >= s1 && s2 <= e1 && e2 >= s1 && e2 <= e1) ||
        (s1 >= s2 && s1 <= e2 && e1 >= s2 && e1 <= e2)){
      part1 += 1;
    }

    if ((s2 >= s1 && s2 <= e1) || (e2 >= s1 && e2 <= e1) ||
        (s1 >= s2 && s1 <= e2) || (e1 >= s2 && e1 <= e2)) {
      part2 += 1;
    }
  }

  std::cout<<part1<<std::endl;
  std::cout<<part2<<std::endl;
}
