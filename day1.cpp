#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>

std::string getInput() {
  std::ifstream ifs("1.in");
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
  std::vector<std::string> elves = split(input, '\n');

  std::vector<int> *values = new std::vector<int>();
  int value = 0;
  for (auto &s: elves) {
    try {
      value += std::stoi(s);
    } catch(std::exception e) {
      values->push_back(value);
      value = 0;
    }
  }
  values->push_back(value);

  // std::cout<<*std::max_element(values->begin(), values->end())<<std::endl;
  sort(values->begin(), values->end());
  std::cout<<values->at(values->size()-1)<<std::endl;
  std::cout<<values->at(values->size()-2)<<std::endl;
  std::cout<<values->at(values->size()-3)<<std::endl;
  int f = values->at(values->size()-1)
    + values->at(values->size()-2)
    + values->at(values->size()-3);
  std::cout<<f<<std::endl;
}
