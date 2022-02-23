#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class _554_BrickWall {
    /**
    * 554. Brick Wall
    * There is a brick wall in front of you. The wall is rectangular and has several rows of bricks. The bricks have the same 
    * height but different width. You want to draw a vertical line from the top to the bottom and cross the least bricks.

    The brick wall is represented by a list of rows. Each row is a list of integers representing the width of each brick in this 
    row from left to right.

    If your line go through the edge of a brick, then the brick is not considered as crossed. You need to find out how to draw the 
    line to cross the least bricks and return the number of crossed bricks.

    You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.

    Example:

    Input: [[1,2,2,1],
            [3,1,2],
            [1,3,2],
            [2,4],
            [3,1,2],
            [1,3,1,1]]

    Output: 2

    time : O(n);
    space : O(n);
    */
 
 public:
  int leastBricks(vector<vector<int>>& wall) {
    unordered_map<int, int> mp;
    for (auto& list : wall) {
        int sum = 0;
        for (int i = 0; i < list.size() - 1; i++) {
            sum += list[i];
            mp[sum]++;
        } 
    }
    auto res = wall.size();
    for (auto& v : mp) {
        res = min(res, wall.size() - v.second);
    }
    return res;  
  }
};




