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

class _376_WiggleSubsequence {
    /**
    * 376. Wiggle Subsequence
    * A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly 
    * alternate between positive and negative. The first difference (if one exists) may be either positive or negative. 
    * A sequence with fewer than two elements is trivially a wiggle sequence.

    For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and 
    negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences 
    are positive and the second because its last difference is zero.

    Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is 
    obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining 
    elements in their original order.

    Example 1:

    Input: [1,7,4,9,2,5]
    Output: 6
    Explanation: The entire sequence is a wiggle sequence.
    Example 2:

    Input: [1,17,5,10,13,15,10,5,16,8]
    Output: 7
    Explanation: There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].
    Example 3:

    Input: [1,2,3,4,5,6,7,8,9]
    Output: 2
    Follow up:
    Can you do it in O(n) time?

    time : O(n);
    space : O(n) / O(1);
    */
 
 public:
  int wiggleMaxLength(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    vector<int> up(nums.size());
    vector<int> down(nums.size());
    
    up[0] = 1;
    down[0] = 1;
    
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i - 1]) {
            up[i] = down[i - 1] + 1;
            down[i] = down[i - 1];
        } else if (nums[i] < nums[i - 1]) {
            down[i] = up[i - 1] + 1;
            up[i] = up[i - 1];
        } else {
            down[i] = down[i - 1];
            up[i] = up[i - 1];
        }
    }
    return max(down[nums.size() - 1], up[nums.size() - 1]);
  }

  int wiggleMaxLength2(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int up = 1, down = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i - 1]) {
            up = down + 1;
        } else if (nums[i] < nums[i - 1]) {
            down = up + 1;
        }
    }
    return max(up, down);
  }
};




