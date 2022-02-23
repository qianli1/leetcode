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

class _398_RandomPickIndex {
    /**
    * 398. Random Pick Index
    * Given an array of integers with possible duplicates, randomly output the index of a given target number. 
    * You can assume that the given target number must exist in the array.
    Note:
    The array size can be very large. Solution that uses too much extra space will not pass the judge.

    Example:

    int[] nums = new int[] {1,2,3,3,3};
    Solution solution = new Solution(nums);

    // pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
    solution.pick(3);

    // pick(1) should return 0. Since in the array only nums[0] is equal to 1.
    solution.pick(1);
    
    time : O(n);
    */
 
 private:
  vector<int> nums;
 public:
  RandomPickIndex(vector<int>& nums) {
    this->nums = nums;
  }

  int pick(int target) {
    int res = -1;
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != target) continue;
        if (rand() % (++count) == 0) {
            res = i;
        }
    }
    return res;
  }
};




