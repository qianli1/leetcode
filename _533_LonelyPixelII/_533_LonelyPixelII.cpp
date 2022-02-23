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

class _533_LonelyPixelII {
    /**
    * 533. Lonely Pixel II
    * Given a picture consisting of black and white pixels, and a positive integer N, find the number of black pixels located 
    * at some specific row R and column C that align with all the following rules:

    Row R and column C both contain exactly N black pixels.
    For all rows that have a black pixel at column C, they should be exactly the same as row R
    The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.

    Example:
    Input:                                            
    [['W', 'B', 'W', 'B', 'B', 'W'],    
    ['W', 'B', 'W', 'B', 'B', 'W'],    
    ['W', 'B', 'W', 'B', 'B', 'W'],    
    ['W', 'W', 'B', 'W', 'B', 'W']] 

    N = 3
    Output: 6
    Explanation: All the bold 'B' are the black pixels we need (all 'B's at column 1 and 3).
            0    1    2    3    4    5         column index                                            
    0    [['W', 'B', 'W', 'B', 'B', 'W'],    
    1     ['W', 'B', 'W', 'B', 'B', 'W'],    
    2     ['W', 'B', 'W', 'B', 'B', 'W'],    
    3     ['W', 'W', 'B', 'W', 'B', 'W']]    
    row index

    Take 'B' at row R = 0 and column C = 1 as an example:
    Rule 1, row R = 0 and column C = 1 both have exactly N = 3 black pixels. 
    Rule 2, the rows have black pixel at column C = 1 are row 0, row 1 and row 2. They are exactly the same as row R = 0.

    Note:
    The range of width and height of the input 2D array is [1,200].

    time : O(m * n);
    space : O(max(m, n));
    */
 
 public:
  int findBlackPixel(vector<vector<char>>& picture, int N) {
    if (picture.empty() || picture[0].size() == 0) return 0;
    unordered_map<string, int> map;
    vector<int> col(picture[0].size());
    for (int i = 0; i < picture.size(); i++) {
        int row = 0;
        for (int j = 0; j < picture[0].size(); j++) {
            if (picture[i][j] == 'B') {
                col[j]++;
                row++;
            }
        }
        if (row == N) {
            string s(picture[i].begin(), picture[i].end());
            map[s]++;
        }
    }
    int res = 0;
    for (auto& s : map) {
        if (s.second != N) continue;
        for (int i = 0; i < col.size(); i++) {
            if (s.first[i] == 'B' && col[i] == N) {
                res += N;
            }
        }
    }
    return res;
  }
};




