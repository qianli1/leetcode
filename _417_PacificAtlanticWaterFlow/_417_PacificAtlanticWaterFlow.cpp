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

class _417_PacificAtlanticWaterFlow {
    /**
    * 417. Pacific Atlantic Water Flow
    * Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific 
    * ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

    Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

    Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

    Note:

    The order of returned grid coordinates does not matter.
    Both m and n are less than 150.

    Example:

    Given the following 5x5 matrix:

    Pacific ~   ~   ~   ~   ~ 
        ~  1   2   2   3  (5) *
        ~  3   2   3  (4) (4) *
        ~  2   4  (5)  3   1  *
        ~ (6) (7)  1   4   5  *
        ~ (5)  1   1   2   4  *
            *   *   *   *   * Atlantic

    Return:

    [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).

    time : O(m * n);
    space : O(m * n);
    */
 
 private:
  int m;
  int n;
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  
 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    vector<vector<int>> res;
    m = matrix.size();
    if (m == 0) return res;
    n = matrix[0].size();   
    vector<vector<bool>> pac(m, vector<bool>(n, false));
    vector<vector<bool>> atl(m, vector<bool>(n, false));
    
    for (int i = 0; i < m; i++) {
        helper(matrix, pac, i, 0);
        helper(matrix, atl, i, n - 1);
    }        
    for (int i = 0; i < n; i++) {
        helper(matrix, pac, 0, i);
        helper(matrix, atl, m - 1, i);
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (pac[i][j] && atl[i][j]) {
                res.push_back({i, j});
            }
        }
    }
    return res;
}

  void helper(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int i, int j) {
    visited[i][j] = true;
    for (auto d : dir) {
        int x = i + d[0];
        int y = j + d[1];
        if (x < 0 || y < 0 || x >= m || y >= n || visited[x][y] || matrix[i][j] > matrix[x][y]) {
            continue;
        }
        helper(matrix, visited, x, y);
    }
  }
};




