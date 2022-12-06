#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <sstream>

#include <stack>

std::string getInput() {
  std::ifstream ifs("5.in");
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
  // std::cout << input.substr(input.find("\n\n")+2, input.length() - (input.find("\n\n") + 2)) << std::endl;
  std::vector<std::string> commands = split(input.substr(input.find("\n\n")+2, input.length() - (input.find("\n\n") + 2)), '\n');

  // Examble input
  // std::vector<std::vector<std::string>> stacks = {
    // { "Z", "N" },
    // { "M", "C", "D" },
    // { "P" }
  // };

  // My Actual Input
  std::vector<std::vector<std::string>> stacks = {
    { "J", "H", "G", "M", "Z", "N", "T", "F" },
    { "V", "W", "J" },
    { "G", "V", "K", "J", "B", "T", "H" },
    { "B", "P", "J", "N", "C", "D", "V", "L" },
    { "F", "W", "S", "M", "P", "R", "G" },
    { "G", "H", "C", "F", "B", "N", "V", "M" },
    { "D", "H", "G", "M", "R" },
    { "H", "N", "M", "V", "Z", "D" },
    { "G", "N", "F", "H" }
  };

  // Part 1
  // for (auto &command : commands) {
    // auto tokens = split(command, ' ');
    // int qty = stoi(tokens.at(1));
    // int from = stoi(tokens.at(3)) - 1;
    // int to = stoi(tokens.at(5)) - 1;

    // for (int i = 0; i < qty; ++i) {
      // auto v = stacks.at(from).at(stacks.at(from).size()-1);
      // stacks.at(from).pop_back();
      // stacks.at(to).push_back(v);
    // }
  // }

  // for (auto &v : stacks) {
    // std::cout << v.at(v.size()-1);
  // }

  // Part 2
  for (auto &command : commands) {
    auto tokens = split(command, ' ');
    int qty = stoi(tokens.at(1));
    int from = stoi(tokens.at(3)) - 1;
    int to = stoi(tokens.at(5)) - 1;

    std::vector<std::string> *tmp = new std::vector<std::string>;
    for (int i = 0; i < qty; ++i) {
      auto v = stacks.at(from).at(stacks.at(from).size()-1);
      stacks.at(from).pop_back();
      tmp->push_back(v);
    }
    for (int i = tmp->size()-1; i >= 0; --i) {
      stacks.at(to).push_back(tmp->at(i));
    }
    delete tmp;
  }
  for (auto &v : stacks) {
    std::cout << v.at(v.size()-1);
  }
}
