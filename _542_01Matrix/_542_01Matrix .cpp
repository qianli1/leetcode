#include <vector>
#include <queue>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class _542_01Matrix {
    /**
    * 542. 01 Matrix
    * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

    The distance between two adjacent cells is 1.

    Example 1:

    Input:
    [[0,0,0],
    [0,1,0],
    [0,0,0]]

    Output:
    [[0,0,0],
    [0,1,0],
    [0,0,0]]
    Example 2:

    Input:
    [[0,0,0],
    [0,1,0],
    [1,1,1]]

    Output:
    [[0,0,0],
    [0,1,0],
    [1,2,1]]

    time : O(m * n);
    space : O(m * n);
    */
 
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].size() == 0) return matrix;
    int m = matrix.size();
    int n = matrix[0].size();
    
    queue<vector<int>> q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                q.push({i, j});
            } else {
                matrix[i][j] = INT_MAX;
            }
        }
    }
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (!q.empty()) {
        vector<int> point = q.front();
        q.pop();
        for (auto dir : dirs) {
            int r = point[0] + dir[0];
            int c = point[1] + dir[1];
            if (r < 0 || r >= m || c < 0 || c >= n || 
                matrix[r][c] <= matrix[point[0]][point[1]] + 1) {
                continue;
            }
            q.push({r, c});
            matrix[r][c] = matrix[point[0]][point[1]] + 1;
        }
    }
    return matrix;
  }
};




