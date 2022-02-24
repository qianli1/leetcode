#include <vector>
#include <string>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class _747_LargestNumberAtLeastTwiceofOthers {
    /**
    * 747. Largest Number At Least Twice of Others
    * In a given integer array nums, there is always exactly one largest element.

    Find whether the largest element in the array is at least twice as much as every other number in the array.

    If it is, return the index of the largest element, otherwise return -1.

    Example 1:

    Input: nums = [3, 6, 1, 0]
    Output: 1
    Explanation: 6 is the largest integer, and for every other number in the array x,
    6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.

    Example 2:

    Input: nums = [1, 2, 3, 4]
    Output: -1
    Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.

    time : O(n);
    space : O(1);
    */
 
 public:
  int dominantIndex(vector<int>& nums) {
    long max = INT_MIN;
    long second = INT_MIN;
    int res = -1;
    
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > max) {
            second = max;
            max = nums[i];
            res = i;
        } else if (nums[i] > second) {
            second = nums[i];
        }
    }
    return second * 2 <= max ? res : -1;
  }
};




