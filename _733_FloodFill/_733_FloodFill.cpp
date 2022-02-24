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

class _733_FloodFill {
    /**
    * 733. Flood Fill
    * An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

    Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood 
    fill" the image.

    To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same 
    color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting 
    pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

    At the end, return the modified image.

    Example 1:
    Input: 
    image = [[1,1,1],[1,1,0],[1,0,1]]
    sr = 1, sc = 1, newColor = 2
    Output: [[2,2,2],[2,2,0],[2,0,1]]
    Explanation: 
    From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
    by a path of the same color as the starting pixel are colored with the new color.
    Note the bottom corner is not colored 2, because it is not 4-directionally connected
    to the starting pixel.

    time : O(R * C);
    space : O(R * C);
    */
 
 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    if (image[sr][sc] != newColor) {
        dfs(image, sr, sc, newColor, image[sr][sc]);
    }
    return image;
  }

  void dfs(vector<vector<int>>& image, int i, int j, int newColor, int replaceColor) {
    if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != replaceColor) {
        return;
    }
    
    image[i][j] = newColor;
    dfs(image, i + 1, j, newColor, replaceColor);
    dfs(image, i - 1, j, newColor, replaceColor);
    dfs(image, i, j + 1, newColor, replaceColor);
    dfs(image, i, j - 1, newColor, replaceColor);
  }  

  vector<vector<int>> floodFill2(vector<vector<int>>& image, int sr, int sc, int newColor) {
    if (image[sr][sc] == newColor) {
        return image;
    }
    
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<pair<int, int>> q;
    q.push(make_pair(sr, sc));
    int oldColor = image[sr][sc];
    
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        image[cur.first][cur.second] = newColor;
        for (auto dir : dirs) {
            int nextX = cur.first + dir[0];
            int nextY = cur.second + dir[1];
            if (isValid(nextX, nextY, image) && image[nextX][nextY] == oldColor) {
                q.push(make_pair(nextX, nextY));
            }
        }
    }
    return image;
  }

  bool isValid(int i, int j, vector<vector<int>>& image) {
    return i >= 0 && j >= 0 && i < image.size() && j < image[0].size();
  }

};




