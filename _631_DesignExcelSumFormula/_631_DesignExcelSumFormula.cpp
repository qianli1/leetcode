#include <vector>
#include <unordered_map>
#include <string>


using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class Cell {
 public:
  int value;
  unordered_map<Cell*, int> mp;

  Cell(int value) {
    this->value = value;
    //mp.clear();
  }

  void add(Cell* cell) {
    mp[cell]++;
  }

  int getValue() {
    if (mp.empty()) {
        return value;
    } else {
        int sum = 0;
        for (auto& v: mp) {
            sum += v.second * v.first->getValue();
        }
        return sum;
    }
  }

  void setValue(int value) {
    this->value = value;
    this->mp.clear();
  }
};

class _631_DesignExcelSumFormula {
    /**
    * 631. Design Excel Sum Formula
    * Your task is to design the basic function of Excel and implement the function of sum formula. Specifically, you need to 
    * implement the following functions:

    Excel(int H, char W): This is the constructor. The inputs represents the height and width of the Excel form. H is a positive 
    integer, range from 1 to 26. It represents the height. W is a character range from 'A' to 'Z'. It represents that the width 
    is the number of characters from 'A' to W. The Excel form content is represented by a height * width 2D integer array C, it 
    should be initialized to zero. You should assume that the first row of C starts from 1, and the first column of C starts from 
    'A'.

    void Set(int row, char column, int val): Change the value at C(row, column) to be val.

    int Get(int row, char column): Return the value at C(row, column).

    int Sum(int row, char column, List of Strings : numbers): This function calculate and set the value at C(row, column), where the 
    value should be the sum of cells represented by numbers. This function return the sum result at C(row, column). This sum formula 
    should exist until this cell is overlapped by another value or another sum formula.

    numbers is a list of strings that each string represent a cell or a range of cells. If the string represent a single cell, then it 
    has the following format : ColRow. For example, "F7" represents the cell at (7, F).

    If the string represent a range of cells, then it has the following format : ColRow1:ColRow2. The range will always be a rectangle, 
    and ColRow1 represent the position of the top-left cell, and ColRow2 represents the position of the bottom-right cell.


    Example 1:
    Excel(3,"C"); 
    // construct a 3*3 2D array with all zero.
    //   A B C
    // 1 0 0 0
    // 2 0 0 0
    // 3 0 0 0

    Set(1, "A", 2);
    // set C(1,"A") to be 2.
    //   A B C
    // 1 2 0 0
    // 2 0 0 0
    // 3 0 0 0

    Sum(3, "C", ["A1", "A1:B2"]);
    // set C(3,"C") to be the sum of value at C(1,"A") and the values sum of the rectangle range whose top-left cell is C(1,"A") and 
    bottom-right cell is C(2,"B"). Return 4. 
    //   A B C
    // 1 2 0 0
    // 2 0 0 0
    // 3 0 0 4

    Set(2, "B", 2);
    // set C(2,"B") to be 2. Note C(3, "C") should also be changed.
    //   A B C
    // 1 2 0 0
    // 2 0 2 0
    // 3 0 0 6
        */
 
private:
  vector<vector<Cell*>> cells;

public:
  Excel(int H, char W) {
    cells = vector<vector<Cell*>> (H + 1, vector<Cell*>(W - 'A' + 1));
    for (int i = 0; i < cells.size(); i++) {
        for (int j = 0; j < cells[0].size(); j++) {
            cells[i][j] = new Cell(0);
        }
    }
  }

  void set(int r, char c, int v) {
    cells[r][c - 'A']->setValue(v);
  }

  int get(int r, char c) {
    return cells[r][c - 'A']->getValue();
  }

  int sum(int r, char c, vector<string> strs) {
    Cell* cell = cells[r][c - 'A'];
    cell->setValue(0);
    for (string str : strs) {
        size_t found = str.find(':');
        if (found != string::npos) {
            vector<int> start = position(str.substr(0, found));
            vector<int> end = position(str.substr(found + 1));
            for (int i = start[0]; i <= end[0]; i++) {
                for (int j = start[1]; j <= end[1]; j++) {
                    cell->add(cells[i][j]);
                }
            }
        } else {
            vector<int> p = position(str);
            cell->add(cells[p[0]][p[1]]);
        }
    }
    return cell->getValue();
  }

  vector<int> position(string s) {
    return {stoi(s.substr(1)), s[0] - 'A'};
  }
};




