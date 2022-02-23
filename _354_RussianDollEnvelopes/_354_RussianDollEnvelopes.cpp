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
  bool cmp(const vector<int>& x, const vector<int>& y) {
        return x[0] != y[0] ? x[0] < y[0] : x[1] > y[1];  
  }
  
class _354_RussianDollEnvelopes {
    /**
    * 354. Russian Doll Envelopes
    * You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can 
    * fit into another if and only if both the width and height of one envelope is greater than the width and 
    * height of the other envelope.

    What is the maximum number of envelopes can you Russian doll? (put one inside other)

    Note:
    Rotation is not allowed.

    Example:

    Input: [[5,4],[6,4],[6,7],[2,3]]
    Output: 3 
    Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

    time : O(nlogn);
    space : O(n);
    */
 
 public:
  int maxEnvelopes(vector<vector<int>>& envelopes) { 
    if (envelopes.empty() || envelopes.size() == 0) return 0;
    sort(envelopes.begin(), envelopes.end(), cmp);
    vector<int> dp(envelopes.size());
    int res = 0;
    for (auto envelope : envelopes) {
        int i = binarySearch(dp, 0, res, envelope[1]);
        dp[i] = envelope[1];
        if (i == res) {
            res++;
        }
    }
    return res;
  }

  int binarySearch(vector<int>& dp, int start, int end, int target) {
    while (start + 1 < end) {
        int mid = start + (end - start) / 2;
        if (dp[mid] == target) {
            return mid;
        } else if (dp[mid] < target) {
            start = mid;
        } else {
            end = mid;
        }
    }
    if (dp[start] >= target) return start;
    return end;
  }
};




