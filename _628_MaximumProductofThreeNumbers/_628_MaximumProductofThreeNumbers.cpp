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

class _628_MaximumProductofThreeNumbers {
    /**
    * 628. Maximum Product of Three Numbers
    * Given an integer array, find three numbers whose product is maximum and output the maximum product.

    Example 1:

    Input: [1,2,3]
    Output: 6
    

    Example 2:

    Input: [1,2,3,4]
    Output: 24
    */
 
 public:
  // Time:O(nlogn), Space:O(nlogn)
  int maximumProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return max(nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3], 
                nums[0] * nums[1] * nums[nums.size() - 1]); 
  }

  //Time: O(n), Space: O(1)
  int maximumProduct2(vector<int>& nums) {
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int max3 = INT_MIN;
    for (int n : nums) {
        if (n <= min1) {
            min2 = min1;
            min1 = n;
        } else if (n < min2) {
            min2 = n;
        }
        if (n >= max1) {
            max3 = max2;
            max2 = max1;
            max1 = n;
        } else if (n >= max2) {
            max3 = max2;
            max2 = n;
        } else if (n >= max3) {
            max3 = n;
        }
    }
    return max(min1 * min2 * max1, max1 * max2 * max3);
  }
};




