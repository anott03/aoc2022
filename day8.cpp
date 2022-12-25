#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
const int DIM = 99;

int main() {
  int arr[DIM][DIM];
  ifstream ifs("8.in");

  if (!ifs.is_open()) {
    cout << "Error opening file" << endl;
    return -1;
  }

  std::string content((std::istreambuf_iterator<char>(ifs)),
      (std::istreambuf_iterator<char>()));

  auto input = content.c_str();

  for (int i = 0; i < DIM; ++i) {
    for (int j = 0; j < DIM; ++j) {
      arr[i][j] = input[i*(DIM+1)+j]-'0';
    }
  }

  vector<vector<int>> *points = new vector<vector<int>>();
  int count = 0;

  for (int i = 1; i < DIM-1; ++i) {
    int max = arr[i][0];
    for (int j = 1; j < DIM-1; ++j) {
      if (arr[i][j] > max) {
        max = arr[i][j];
        points->push_back({i, j});
        ++count;
      }
    }
  }

  for (int i = 1; i < DIM-1; ++i) {
    int max = arr[i][DIM-1];
    for (int j = DIM-2; j >= 1; --j) {
      if (arr[i][j] > max) {
        max = arr[i][j];
        bool ptFound = false;
        for (auto &pt : *points) {
          if (pt.at(0) == i && pt.at(1) == j) {
            ptFound = true;
            break;
          }
        }
        if (!ptFound) {
          points->push_back({i, j});
          ++count;
        }
      }
    }
  }

  for (int j = 1; j < DIM-1; ++j) {
    int max = arr[0][j];
    for (int i = 0; i < DIM-1; ++i) {
      if (arr[i][j] > max) {
        max = arr[i][j];
        bool ptFound = false;
        for (auto &pt : *points) {
          if (pt.at(0) == i && pt.at(1) == j) {
            ptFound = true;
            break;
          }
        }
        if (!ptFound) {
          points->push_back({i, j});
          ++count;
        }
      }
    }
  }

  for (int j = 1; j < DIM-1; ++j) {
    int max = arr[DIM-1][j];
    for (int i = DIM-2; i >= 1; --i) {
      if (arr[i][j] > max) {
        max = arr[i][j];
        bool ptFound = false;
        for (auto &pt : *points) {
          if (pt.at(0) == i && pt.at(1) == j) {
            ptFound = true;
            break;
          }
        }
        if (!ptFound) {
          points->push_back({i, j});
          ++count;
        }
      }
    }
  }

  count += (DIM-1)*4;
  cout << "Part 1 " << count << endl;
  cout << endl;

  // Part 2
  int maxScore = 0;
  // for (int i = 1; i < DIM-1; ++i) {
    // for (int j = 1; j < DIM-1; ++j) {
  for (auto &pt : *points) {
      int i = pt.at(0);
      int j = pt.at(1);
      // up
      int up = 1;
      for (int k = i-1; k >= 0; --k) {
        if (arr[k][j] >= arr[i][j] || k == 0) {
          up = i - k;
          break;
        }
      }
      // cout << "up   " << i << " " << j << " " << up << endl;

      // down
      int down = 1;
      for (int k = i+1; k < DIM; ++k) {
        if (arr[k][j] >= arr[i][j] || k == DIM-1) {
          down = k - i;
          break;
        }
      }
      // cout << "down " << i << " " << j << " " << down << endl;

      // left
      int left = 1;
      for (int k = j-1; k >= 0; --k) {
        if (arr[i][k] >= arr[i][j] || k == 0) {
          left = j - k;
          break;
        }
      }
      // cout << "left " << i << " " << j << " " << left << endl;

      // right
      int right = 1;
      for (int k = j+1; k < DIM; ++k) {
        if (arr[i][k] >= arr[i][j] || k == DIM-1) {
          right = k - j;
          break;
        }
      }
      // cout << "right " << i << " " << j << " " << right << endl;

      int score = up * down * left * right;
      // std::cout << "score " << i << " " << j << " " << score << endl;
      // cout << endl;
      if (score > maxScore) {
        maxScore = score;
      }
    }
  // }

  cout << "Part 2 " << maxScore << endl;

  return 0;
}
