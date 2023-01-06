#include <fstream>
#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

struct Point {
  int x;
  int y;
};

bool is_touching(Point p1, Point p2) {
  if (abs(p1.x - p2.x) <= 1 && abs(p1.y - p2.y) <= 1) {
    return true;
  }
  return false;
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
Point move_tail(Point head, Point tail) {
  vector<Point> points = {
    // straight line moves first
    Point{head.x-1, head.y},
    Point{head.x+1, head.y},
    Point{head.x, head.y-1},
    Point{head.x, head.y+1},
    // then consider diagonals
    Point{head.x-1, head.y-1},
    Point{head.x+1, head.y-1},
    Point{head.x+1, head.y+1},
    Point{head.x-1, head.y+1},
  };

  for (auto &point : points) {
    if (is_touching(point, tail)) {
      return point;
    }
  }

  return tail;
}

vector<Point> *visited_points = new vector<Point>();

bool point_visted(Point p) {
  for (auto &point : *visited_points) {
    if (point.x == p.x && point.y == p.y) {
      return true;
    }
  }
  return false;
}

int main() {
  ifstream ifs("9.in");
  if (!ifs.is_open()) {
      cout << "error opening file." << endl;
      return -1;
  }
  string content((istreambuf_iterator<char>(ifs)),
      (istreambuf_iterator<char>()));
  const vector<string> lines = split(content, '\n');

  Point head = Point{ .x = 0, .y = 0 };
  Point tail = Point{ .x = 0, .y = 0 };
  visited_points->push_back(tail);

  for (auto &_line : lines) {
    auto line = _line.c_str();

    for (int i = 0; i < (stoi(_line.substr(2, _line.length()-2))); ++i) {
      if (line[0] == 'R') {
        head.x += 1;
        if (is_touching(head, tail)) continue;
        tail = move_tail(head, tail);
        if (point_visted(tail)) continue;
        visited_points->push_back(tail);
      } else if (line[0] == 'L') {
        head.x -= 1;
        if (is_touching(head, tail)) continue;
        tail = move_tail(head, tail);
        if (point_visted(tail)) continue;
        visited_points->push_back(tail);
      } else if (line[0] == 'U') {
        head.y += 1;
        if (is_touching(head, tail)) continue;
        tail = move_tail(head, tail);
        if (point_visted(tail)) continue;
        visited_points->push_back(tail);
      } else if (line[0] == 'D') {
        head.y -= 1;
        if (is_touching(head, tail)) continue;
        tail = move_tail(head, tail);
        if (point_visted(tail)) continue;
        visited_points->push_back(tail);
      } else {
        cout << "something went wrong" << endl;
      }
    }
  }
  cout << head.x << " " << head.y << endl;

  // 3192; too low
  cout << "Part 1 " << visited_points->size() << endl;


  // Part 2
  head = Point { 0, 0 };
  visited_points = new vector<Point>();
  vector<Point> *tails = new vector<Point>();
  for (int i = 0; i < 10; ++i) {
    tails->push_back(Point{0, 0});
  }

  for (auto &_line : lines) {
    auto line = _line.c_str();

    for (int i = 0; i < (stoi(_line.substr(2, _line.length()-2))); ++i) {
    }
  }

  return 0;
}
