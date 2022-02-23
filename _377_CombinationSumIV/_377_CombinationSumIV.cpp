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

class _377_CombinationSumIV {
    /**
    * 377. Combination Sum IV
    * Given an integer array with all positive numbers and no duplicates, find the number of possible combinations 
    * that add up to a positive integer target.

    Example:

    nums = [1, 2, 3]
    target = 4

    The possible combination ways are:
    (1, 1, 1, 1)
    (1, 1, 2)
    (1, 2, 1)
    (1, 3)
    (2, 1, 1)
    (2, 2)
    (3, 1)

    Note that different sequences are counted as different combinations.

    Therefore the output is 7.
    */
 
 public:
  // Method 1: DP. time: O(n * k), space: O(k)
  int combinationSum4(vector<int>& nums, int target) {
    vector<unsigned int> res(target + 1, 0);
    res[0] = 1;
    for (int i = 1; i < res.size(); i++) {
        for (int num : nums) {
            if (i - num >= 0) {
                res[i] += res[i - num];
            }
        }
    }
    return res[target];
  }

  //Method 2: DFS + memorization. time: < O(2^n), space: O(n)
  int combinationSum42(vector<int>& nums, int target) {
    if (nums.size() == 0) return 0;
    unordered_map<int, int> mp;
    return helper(nums, target, mp);
  }

  int helper(vector<int>& nums, int target, unordered_map<int, int>& mp) {
    if (target == 0) return 1;
    if (target < 0) return 0;
    if (mp.count(target)) {
        return mp[target];
    }
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        res += helper(nums, target - nums[i], mp);
    }
    mp[target] = res;
    return res;
  }
};




