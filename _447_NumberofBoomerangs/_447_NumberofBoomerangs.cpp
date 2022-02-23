#include <vector>
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

class _447_NumberofBoomerangs {
    /**
    * 447. Number of Boomerangs
    * Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) 
    * such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

    Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of 
    points are all in the range [-10000, 10000] (inclusive).

    Example:
    Input:
    [[0,0],[1,0],[2,0]]

    Output:
    2

    Explanation:
    The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]

    time : O(n^2);
    space : O(n);
    * @param points
    * @return
    */
 
 public:
  int numberOfBoomerangs(vector<vector<int>>& points) {
    int res = 0;
    unordered_map<int, int> map;
    for (int i = 0; i < points.size(); i++) {
        for (int j = 0; j < points.size(); j++) {
            if (i == j) continue;
            int distance = getDistance(points[i], points[j]);
            map[distance]++;
        }
        for (auto& val : map) {
            res += val.second * (val.second - 1);
        }
        map.clear();
    }
    return res;
  }

  int getDistance(vector<int>& a, vector<int>& b) {
    int dx = a[0] - b[0];
    int dy = a[1] - b[1];
    return dx * dx + dy * dy;
  }
};
