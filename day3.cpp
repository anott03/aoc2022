#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <sstream>

std::string getInput() {
  std::ifstream ifs("3.in");
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

int letterScore(char c) {
 auto i = (int) c;
  if ( i >= 65 && i <= 90 ) return i - 38; 
  return i - 96;
}

int main() {
  std::vector<std::string> input = split(getInput(), '\n');
  int part1 = 0;
  int part2 = 0;
  // for (auto &line : input) {
    // std::string c1 = line.substr(0, line.length() / 2);
    // std::string c2 = line.substr(line.length() / 2, line.length() / 2);
    // // std::cout << c1 << "\n" << c2 << "\n" << std::endl;
    // // const char* c1 = _c1.c_str();
    // // const char* c2 = _c2.c_str();

    // for (auto &c : c1) {
      // if (c == c2.c_str()[c2.find(c)]) {
        // // std::cout<<c<<" "<<letterScore(c)<<std::endl;
        // part1 += letterScore(c);
        // break;
      // }
    // }
  // }

  for (int i = 0; i < input.size()-2; i += 3) {
    std::string line = input.at(i);

    auto c2 = input.at(i + 1);
    auto c3 = input.at(i + 2);

    for (auto &c : line) {
      if (c == c2.c_str()[c2.find(c)] && c == c3.c_str()[c3.find(c)]) {
        part2 += letterScore(c);
        break;
      }
    }
  }

  std::cout<<"Part 1: "<<part1<<std::endl;
  std::cout<<"Part 2: "<<part2<<std::endl;
}
