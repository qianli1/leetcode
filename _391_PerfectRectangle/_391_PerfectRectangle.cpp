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

class _391_PerfectRectangle {
    /**
    * 391. Perfect Rectangle
    * Given N axis-aligned rectangles where N > 0, determine if they all together form an exact cover of a 
    * rectangular region.

    Each rectangle is represented as a bottom-left point and a top-right point. For example, a unit square is 
    represented as [1,1,2,2]. (coordinate of bottom-left point is (1, 1) and top-right point is (2, 2)).

    Example 1:

    rectangles = [
    [1,1,3,3],
    [3,1,4,2],
    [3,2,4,4],
    [1,3,2,4],
    [2,3,3,4]
    ]

    Return true. All 5 rectangles together form an exact cover of a rectangular region.

    time : O(n);
    space : O(n);
    */
 
 public:
  bool isRectangleCover(vector<vector<int>>& rectangles) {
    if (rectangles.size() == 0 || rectangles[0].size() == 0) return false;
    
    int x1 = INT_MAX;
    int x2 = INT_MIN;
    int y1 = INT_MAX;
    int y2 = INT_MIN;
    
    unordered_set<string> s;
    int area = 0;
    
    for (vector<int>& rect : rectangles) {
        x1 = min(rect[0], x1);
        y1 = min(rect[1], y1);
        x2 = max(rect[2], x2);
        y2 = max(rect[3], y2);
        
        area += (rect[2] - rect[0]) * (rect[3] - rect[1]);
        
        string s1 = to_string(rect[0]) + " " + to_string(rect[1]);
        string s2 = to_string(rect[0]) + " " + to_string(rect[3]);
        string s3 = to_string(rect[2]) + " " + to_string(rect[3]);
        string s4 = to_string(rect[2]) + " " + to_string(rect[1]);
        
        if (!s.erase(s1)) s.insert(s1);
        if (!s.erase(s2)) s.insert(s2);
        if (!s.erase(s3)) s.insert(s3);
        if (!s.erase(s4)) s.insert(s4);

    }
    if (!s.count(to_string(x1) + " " + to_string(y1)) || !s.count(to_string(x1) + " " + to_string(y2)) 
        || !s.count(to_string(x2) + " " + to_string(y1)) || !s.count(to_string(x2) + " " + to_string(y2))
        || s.size() != 4) {
        return false;
    }
    return area == (x2 - x1) * (y2 - y1);
  }
};




