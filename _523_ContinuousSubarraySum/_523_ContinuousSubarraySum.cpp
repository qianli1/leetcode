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

class _523_ContinuousSubarraySum {
    /**
    * 523. Continuous Subarray Sum
    * Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous 
    * subarray of size at least 2 that sums up to a multiple of k, that is, sums up to n*k where n is also an integer.

    Example 1:

    Input: [23, 2, 4, 6, 7],  k=6
    Output: True
    Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
    Example 2:

    Input: [23, 2, 6, 4, 7],  k=6
    Output: True
    Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.
    
    time : O(n);
    space : O(n);
    */
 
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    int sum = 0;
    unordered_map<int, int> map;
    map[0] = -1;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (k != 0) {
            sum = sum % k;
        }
        if (map.count(sum)) {
            if (i - map[sum] > 1) {
                return true;
            }
        } else {
            map[sum] = i;
        }
    }
    return false;
  }
};




