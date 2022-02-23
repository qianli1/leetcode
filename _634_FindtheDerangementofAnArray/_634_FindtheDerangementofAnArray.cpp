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

class _634_FindtheDerangementofAnArray {
    /**
    * 634. Find the Derangement of An Array
    * In combinatorial mathematics, a derangement is a permutation of the elements of a set, such that no element appears in its original position.

    There's originally an array consisting of n integers from 1 to n in ascending order, you need to find the number of derangement it can generate.

    Also, since the answer may be very large, you should return the output mod 109 + 7.

    Example 1:
    Input: 3
    Output: 2
    Explanation: The original array is [1,2,3]. The two derangements are [2,3,1] and [3,1,2].
    */
 
 public:
  //Time: O(n), space: O(n)
  int findDerangement(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = (int) (((i - (long)1) * (dp[i - 1] + dp[i - 2])) % 1000000007);
    }
    return dp[n];
  }

  //Time: O(n), space: O(1)
  int findDerangement2(int n) {
    int first = 1, second = 0;
    for (int i = 2; i <= n; i++) {
        int temp = second;
        second = (int) (((i - (long)1) * (first + second)) % 1000000007);
        first = temp;
    }
    return second;
  }
};




