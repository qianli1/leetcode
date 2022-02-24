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

class _645_SetMismatch {
    /**
    * 645. Set Mismatch
    * The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers 
    * in the set got duplicated to another number in the set, which results in repetition of one number and loss of 
    * another number.

    Given an array nums representing the data status of this set after the error. Your task is to firstly find the number 
    occurs twice and then find the number that is missing. Return them in the form of an array.

    Example 1:
    Input: nums = [1,2,2,4]
    Output: [2,3]

    time : O(n);
    space : O(1);
    */
 
 public:
  vector<int> findErrorNums(vector<int>& nums) {
    int dup = -1;
    int missing = 1;
    for (int num : nums) {
        if (nums[abs(num) - 1] < 0) {
            dup = abs(num);
        } else {
            nums[abs(num) - 1] *= -1;
        }
    }
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > 0) {
            missing = i + 1;
        }
    }
    return {dup, missing};
  }

  vector<int> findErrorNums2(vector<int>& nums) {
    int dup = 0, missing = 0;
    for (int i = 0; i < nums.size(); i++) {
        int num = abs(nums[i]);
        missing ^= (i + 1) ^ num;
        if (nums[num - 1] < 0) {
            dup = num;
        } else {
            nums[num - 1] *= -1;
        }
    }
    missing ^= dup;
    return {dup, missing};
  }
};




