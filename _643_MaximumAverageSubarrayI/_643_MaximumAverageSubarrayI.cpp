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

class _643_MaximumAverageSubarrayI {
    /**
    * 643. Maximum Average Subarray I
    * Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. 
    * And you need to output the maximum average value.

    Example 1:

    Input: [1,12,-5,-6,50,3], k = 4
    Output: 12.75
    Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75

    time : O(n);
    space : O(1);
    */
 
 public:
  double findMaxAverage(vector<int>& nums, int k) {
    double sum = 0;
    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }
    double res = sum;
    for (int i = k; i < nums.size(); i++) {
        sum += nums[i] - nums[i - k];
        res = max(res, sum);
    }
    return res / k;       
  }
};




