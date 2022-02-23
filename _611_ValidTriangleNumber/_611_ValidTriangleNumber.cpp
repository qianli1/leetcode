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

class _611_ValidTriangleNumber {
    /**
    * 611. Valid Triangle Number
    * Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array 
    * that can make triangles if we take them as side lengths of a triangle.
    Example 1:
    Input: [2,2,3,4]
    Output: 3
    Explanation:
    Valid combinations are: 
    2,3,4 (using the first 2)
    2,3,4 (using the second 2)
    2,2,3

    time : O(n^2);
    space : O(1);
    */
 
 public:
  int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int res = 0;
    for (int i = nums.size() - 1; i >= 2; i--) {
        int l = 0, r = i - 1;
        while (l < r) {
            if (nums[l] + nums[r] > nums[i]) {
                res += r - l;
                r--;
            } else {
                l++;
            }
        }
    }
    return res;
  }
};




