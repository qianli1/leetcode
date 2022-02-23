#include <vector>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class _529_Minesweeper {
    /**
    * 529. Minesweeper
    * Let's play the minesweeper game (Wikipedia, online game)!

    You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents 
    an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent (above, below, left, right, 
    and all 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent to this revealed square, and 
    finally 'X' represents a revealed mine.

    Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'), return the 
    board after revealing this position according to the following rules:

    If a mine ('M') is revealed, then the game is over - change it to 'X'.
    If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its 
    adjacent unrevealed squares should be revealed recursively.
    If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') 
    representing the number of adjacent mines.
    Return the board when no more squares will be revealed.
    
    Example 1:

    Input: 

    [['E', 'E', 'E', 'E', 'E'],
    ['E', 'E', 'M', 'E', 'E'],
    ['E', 'E', 'E', 'E', 'E'],
    ['E', 'E', 'E', 'E', 'E']]

    Click : [3,0]

    Output: 

    [['B', '1', 'E', '1', 'B'],
    ['B', '1', 'M', '1', 'B'],
    ['B', '1', '1', '1', 'B'],
    ['B', 'B', 'B', 'B', 'B']]

    Example 2:

    Input: 

    [['B', '1', 'E', '1', 'B'],
    ['B', '1', 'M', '1', 'B'],
    ['B', '1', '1', '1', 'B'],
    ['B', 'B', 'B', 'B', 'B']]

    Click : [1,2]

    Output: 

    [['B', '1', 'E', '1', 'B'],
    ['B', '1', 'X', '1', 'B'],
    ['B', '1', '1', '1', 'B'],
    ['B', 'B', 'B', 'B', 'B']]


    time : O(m * n);
    space : O(1);
    */

 public:
  vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    int x = click[0];
    int y = click[1];
    if (board[x][y] == 'M') {
        board[x][y] = 'X';
        return board;
    }
    dfs(board, x, y);
    return board;
  }

  void dfs(vector<vector<char>>& board, int x, int y) {
    if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] != 'E') {
        return;
    }
    int mines = findMines(board, x, y);
    if (mines == 0) {
        board[x][y] = 'B';
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                dfs(board, x + i, y + j);
            }
        }
    } else {
            board[x][y] = (char)('0' + mines);
    }
  }

  int findMines(vector<vector<char>>& board, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int x1 = x + i;
            int y1 = y + j;
            if (x1 < 0 || y1 < 0 || x1 >= board.size() || y1 >= board[0].size()) {
                continue;
            }
            if (board[x1][y1] == 'M') {
                count++;
            }
        }
    }
    return count;
  }
};




