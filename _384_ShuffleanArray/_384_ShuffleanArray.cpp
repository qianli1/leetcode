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

class _384_ShuffleanArray {
    /**
    * 384. Shuffle an Array
    * Shuffle a set of numbers without duplicates.

    Example:

    // Init an array with set 1, 2, and 3.
    int[] nums = {1,2,3};
    Solution solution = new Solution(nums);

    // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
    solution.shuffle();

    // Resets the array back to its original configuration [1,2,3].
    solution.reset();

    // Returns the random shuffling of array [1,2,3].
    solution.shuffle();

    time : O(n);
    */
 
 private:
  vector<int> nums;
    
 public:
  ShuffleanArray(vector<int>& nums) {
        this->nums = nums;
  }
    
  /** Resets the array to its original configuration and return it. */
  vector<int> reset() {
    return nums;
  }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    if (nums.empty()) return {};
    vector<int> clone(nums);
    for (int i = 1; i < clone.size(); i++) {
        int random = rand() % (i + 1);
        swap(clone, i, random);
    }
    return clone;
  }

  void swap(vector<int>& clone, int i, int j) {
    int tmp = clone[i];
    clone[i] = clone[j];
    clone[j] = tmp;
  }
};




