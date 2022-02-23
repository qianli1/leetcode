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

class _416_PartitionEqualSubsetSum {
    /**
    * 416. Partition Equal Subset Sum
    * Given a non-empty array containing only positive integers, find if the array can be partitioned into 
    * two subsets such that the sum of elements in both subsets is equal.

    Note:

    Each of the array element will not exceed 100.
    The array size will not exceed 200.
    
    Example 1:

    Input: [1, 5, 11, 5]

    Output: true

    Explanation: The array can be partitioned as [1, 5, 5] and [11].
    
    Example 2:

    Input: [1, 2, 3, 5]

    Output: false

    Explanation: The array cannot be partitioned into equal sum subsets.

    time : O(n * sum / 2);
    space : O(sum);
    */
 
 public:
  bool canPartition(vector<int>& nums) {
    if (nums.empty() || nums.size() == 0) return true;
    int sum = 0;
    for (int num : nums) {
        sum += num;
    }
    if (sum % 2 != 0) {
        return false;
    }
    sum /= 2;
    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for (int num : nums) {
        for (int i = sum; i >= num; i--) {
            dp[i] = dp[i] || dp[i - num];
        }
    }
    return dp[sum];
  }
};




