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

class _724_FindPivotIndex {
    /**
    * 724. Find Pivot Index
    * Given an array of integers nums, write a method that returns the "pivot" index of this array.

    We define the pivot index as the index where the sum of all the numbers to the left of the index is equal to the sum 
    of all the numbers to the right of the index.

    If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot 
    index.

    Example 1:

    Input: nums = [1,7,3,6,5,6]
    Output: 3
    Explanation:
    The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
    Also, 3 is the first index where this occurs.
    Example 2:

    Input: nums = [1,2,3]
    Output: -1
    Explanation:
    There is no index that satisfies the conditions in the problem statement.

    time : O(n);
    space : O(1);
    */
 
 public:
  int pivotIndex(vector<int>& nums) {
    int total = 0;
    for (int num : nums) {
        total += num;
    }
    
    int sum = 0; 
    for (int i = 0; i < nums.size(); i++) {
        if (sum == total - sum - nums[i]) {
            return i;
        }
        sum += nums[i];
    }
    return -1;
  }
};




