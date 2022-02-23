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

class _540_SingleElementinaSortedArray {
    /**
    * 540. Single Element in a Sorted Array
    * You are given a sorted array consisting of only integers where every element appears exactly twice, except for one 
    * element which appears exactly once. Find this single element that appears only once.

    Follow up: Your solution should run in O(log n) time and O(1) space.

    Example 1:

    Input: nums = [1,1,2,3,3,4,4,8,8]
    Output: 2
    Example 2:

    Input: nums = [3,3,7,7,10,11,11]
    Output: 10

    time : O(logn);
    space : O(1);
    */
 
 public:
  int singleNonDuplicate(vector<int>& nums) {
    int start = 0;
    int end = nums.size() / 2;
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (nums[2 * mid] != nums[2 * mid + 1]) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    return nums[2 * start];
  }
};




