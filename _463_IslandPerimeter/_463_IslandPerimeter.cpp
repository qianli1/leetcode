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

class _463_IslandPerimeter {
    /**
    * 463. Island Perimeter
    * You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

    Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, 
    and there is exactly one island (i.e., one or more connected land cells).

    The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a 
    square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

    Example:

    Input:
    [[0,1,0,0],
     [1,1,1,0],
     [0,1,0,0],
     [1,1,0,0]]

    Output: 16

    time : O(m * n);
    space : O(1);
    * @param grid
    * @return
    */
 
 public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int islands = 0;
    int neighbours = 0;
    
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == 1) {
          islands++;
          if (i < grid.size() - 1 && grid[i + 1][j] == 1) {
            neighbours++;
          }
          if (j < grid[i].size() - 1 && grid[i][j + 1] == 1) {
            neighbours++;
          }
        }
      }
    }
    return islands * 4 - neighbours * 2;  
  }
};




