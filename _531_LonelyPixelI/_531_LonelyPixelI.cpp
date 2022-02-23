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

class _531_LonelyPixelI {
    /**
    * 531. Lonely Pixel I
    * Given a picture consisting of black and white pixels, find the number of black lonely pixels.

    The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.

    A black lonely pixel is character 'B' that located at a specific position where the same row and same column don't have any other black pixels.

    Example:
    Input: 
    [['W', 'W', 'B'],
    ['W', 'B', 'W'],
    ['B', 'W', 'W']]

    Output: 3
    Explanation: All the three 'B's are black lonely pixels.
    Note:
    The range of width and height of the input 2D array is [1,500].

    time : O(m * n);
    space : O(n);
    */
 
 public:
  int findLonelyPixel(vector<vector<char>>& picture) {
    if (picture.empty() || picture[0].size() == 0) return 0;
    vector<int> col(picture[0].size());
    for (int i = 0; i < picture.size(); i++) {
        for (int j = 0; j < picture[0].size(); j++) {
            if (picture[i][j] == 'B') {
                col[j]++;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < picture.size(); i++) {
        int count = 0;
        int pos = 0;
        for (int j = 0; j < picture[0].size(); j++) {
            if (picture[i][j] == 'B') {
                count++;
                pos = j;
            }
        }
        if (count == 1 && col[pos] == 1) {
            res++;
        }
    }
    return res;
  }
};




