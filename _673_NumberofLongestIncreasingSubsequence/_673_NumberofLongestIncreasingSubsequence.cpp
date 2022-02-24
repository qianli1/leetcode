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

class _673_NumberofLongestIncreasingSubsequence {
    /**
    * 673. Number of Longest Increasing Subsequence
    * Given an unsorted array of integers, find the number of longest increasing subsequence.

    Example 1:
    Input: [1,3,5,4,7]
    Output: 2
    Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
    Example 2:
    Input: [2,2,2,2,2]
    Output: 5
    Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.

    Time: O(n^2)
    Space: O(n)
    */
 
 public:
  int findNumberOfLIS(vector<int>& nums) {
    int res = 0, max = 0;
    vector<int> len(nums.size());
    vector<int> count(nums.size());
    
    for (int i = 0; i < nums.size(); i++) {
        len[i] = count[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                if (len[i] == len[j] + 1) {
                    count[i] += count[j];
                }
                if (len[i] < len[j] + 1) {
                    len[i] = len[j] + 1;
                    count[i] = count[j];
                }
            }
        }
        if (max == len[i]) {
            res += count[i];
        }
        if (max < len[i]) {
            max = len[i];
            res = count[i];
        }
    }
    return res;
  }
};




