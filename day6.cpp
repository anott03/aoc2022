#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

std::string getInput() {
  std::ifstream ifs("6.in");
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
  std::string input = getInput();
  // Part 1
  for (int i = 3; i < input.length(); ++i) {
    std::string s = input.substr(i-3, 4);
    std::sort(s.begin(), s.end());
    if (std::unique(s.begin(), s.end()) == s.end()) {
      std::cout << s << " " << i+1 << std::endl;
      break;
    }
  }
  // Part 2
  for (int i = 13; i < input.length(); ++i) {
    std::string s = input.substr(i-13, 14);
    std::sort(s.begin(), s.end());
    if (std::unique(s.begin(), s.end()) == s.end()) {
      std::cout << s << " " << i+1 << std::endl;
      break;
    }
  }

  for (int i = 13; i < input.length(); ++i) {
    std::string s = input.substr(i-13, 14);
    std::sort(s.begin(), s.end());
    if (std::unique(s.begin(), s.end()) == s.end()) {
      std::cout << s << " " << i+1 << std::endl;
      break;
    }
  }
}
