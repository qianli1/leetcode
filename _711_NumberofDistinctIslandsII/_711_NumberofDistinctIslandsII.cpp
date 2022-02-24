#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class _711_NumberofDistinctIslandsII {
    /**
    * 711. Number of Distinct Islands II
    * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally 
    * (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

    Count the number of distinct islands. An island is considered to be the same as another if they have the same shape, or have 
    the same shape after rotation (90, 180, or 270 degrees only) or reflection (left/right direction or up/down direction).

    Example 1:
    11000
    10000
    00001
    00011
    Given the above grid map, return 1.

    Notice that:
    11
    1
    and
    1
    11
    are considered same island shapes. Because if we make a 180 degrees clockwise rotation on the first island, then two islands 
    will have the same shapes.
    Example 2:
    11100
    10001
    01001
    01110
    Given the above grid map, return 2.

    Here are the two distinct islands:
    111
    1
    and
    1
    1

    Notice that:
    111
    1
    and
    1
    111
    are considered same island shapes. Because if we flip the first array in the up/down direction, then they have the same shapes.

    time : O(m * n);
    space : O(m * n);
    */
 
 private:
  vector<vector<int>> trans = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

 public:
  int numDistinctIslands2(vector<vector<int>>& grid) {
    if (grid.empty() || grid.size() == 0 || grid[0].size() == 0) {
        return 0;
    }
    unordered_set<string> s;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) {
                vector<vector<int>> cells;
                dfs(grid, i, j, cells);
                string shape = normalizeIsland(cells);
                s.insert(shape);
            }
        }
    }
    return s.size();
  }

  void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& cells) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1) {
        return;
    }
    cells.push_back({i, j});
    grid[i][j] = 0;
    dfs(grid, i + 1, j, cells);
    dfs(grid, i - 1, j, cells);
    dfs(grid, i, j + 1, cells);
    dfs(grid, i, j - 1, cells);
  }

  string normalizeIsland(vector<vector<int>>& cells) {
    vector<string> forms;
    
    for (auto ts : trans) {
        vector<vector<int>> list1;
        vector<vector<int>> list2;
        
        for (auto cell : cells) {
            list1.push_back({cell[0] * ts[0], cell[1] * ts[1]});
            list2.push_back({cell[1] * ts[1], cell[0] * ts[0]});
        }
        forms.push_back(getSort(list1));
        forms.push_back(getSort(list2));
    }
    
    sort(forms.begin(), forms.end());
    return forms[0];
  }

  string getSort(vector<vector<int>>& cells) {
    sort(cells.begin(), cells.end());   
    string sb;
    int x = cells[0][0];
    int y = cells[0][1];
    for (auto cell : cells) {
        sb += to_string(cell[0] - x) + ":" + to_string(cell[1] - y) + ":";
    }
    return sb;
  }
};




