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
  
class _407_TrappingRainWaterII {
    /**
    * 354. Russian Doll Envelopes
    * Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, 
    * compute the volume of water it is able to trap after raining.

    Example:

    Given the following 3x6 height map:
    [
    [1,4,3,1,3,2],
    [3,2,1,3,2,4],
    [2,3,3,2,3,1]
    ]

    Return 4.

    time : O(m * n * log(m + n));
    space : O(m * n);
    */
 
 public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    if (heightMap.empty() || heightMap.size() <= 1 || heightMap[0].size() <= 1) {
        return 0;
    }
    int m = heightMap.size();
    int n = heightMap[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> pq;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                pq.push({heightMap[i][j], i, j});
                visited[i][j] = true;
            }
        }
    }        
    int res = 0, mx = INT_MIN;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!pq.empty()) {
        auto cell = pq.top(); 
        pq.pop();
        for (vector<int> dir : dirs) {
            int x = cell[1] + dir[0];
            int y = cell[2] + dir[1];
            if (x >= 0 && x < m && y > 0 && y < n && !visited[x][y]) {
                visited[x][y] = true;
                res += max(0, cell[0] - heightMap[x][y]);
                pq.push({max(cell[0], heightMap[x][y]), x, y});
            }
        }            
    }
    return res; 
  }
};




