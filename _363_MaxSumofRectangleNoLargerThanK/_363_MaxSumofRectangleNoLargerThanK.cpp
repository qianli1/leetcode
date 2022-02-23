#include <vector>
#include <set>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class _363_MaxSumofRectangleNoLargerThanK {
    /**
    * 363. Max Sum of Rectangle No Larger Than K
    * Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.

    Example:

    Input: matrix = [[1,0,1],[0,-2,3]], k = 2
    Output: 2 
    Explanation: Because the sum of rectangle [[0, 1], [-2, 3]] is 2,
                and 2 is the max number no larger than k (k = 2).
    Note:

    The rectangle inside the matrix must have an area > 0.
    What if the number of rows is much larger than the number of columns?

    time : O(min(m, n)^2 * max(m, n) * log(max(m, n)));
    space : O(max(m, n));
    */
 
 public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    if (matrix.empty() || matrix.size() == 0) return 0;
    int m = matrix.size();
    int n = matrix[0].size();
    int res = INT_MIN;
    
    for (int left = 0; left < n; left++) {
        vector<int> sums(m, 0);
        for (int right = left; right < n; right++) {
            for (int i = 0; i < m; i++) {
                sums[i] += matrix[i][right];
            }
            set<int> s;
            s.insert(0);
            int cur = 0;
            for (int sum : sums) {
                cur += sum;
                auto num = s.lower_bound(cur - k);
                if (num != s.end()) {
                    res = max(res, cur - *num);
                }
                s.insert(cur);
            }
        }
    }
    return res;
  }
};




