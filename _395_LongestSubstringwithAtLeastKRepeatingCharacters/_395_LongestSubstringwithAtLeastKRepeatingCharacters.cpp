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

class _395_LongestSubstringwithAtLeastKRepeatingCharacters {
    /**
    * 395. Longest Substring with At Least K Repeating Characters
    * Find the length of the longest substring T of a given string (consists of lowercase letters only) such that 
    * every character in T appears no less than k times.

    Example 1:

    Input:
    s = "aaabb", k = 3

    Output:
    3

    The longest substring is "aaa", as 'a' is repeated 3 times.
    Example 2:

    Input:
    s = "ababbc", k = 2

    Output:
    5

    The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
    time : O(n);
    space : O(1);
    */
 
 public:
  int longestSubstring(string s, int k) {
    int res = 0;
    for (int num_unique_target = 1; num_unique_target <= 26; num_unique_target++) {
        res = max(res, helper(s, k, num_unique_target));
    }
    return res;
  }

  int helper(string s, int k, int num_unique_target) {
    vector<int> count(128);
    int start = 0, end = 0;
    int num_unique = 0, num_no_less_than_K = 0;
    int res = 0;
    
    while (end < s.size()) {
        if (count[s[end]]++ == 0) num_unique++;
        if (count[s[end++]] == k) num_no_less_than_K++;
        
        while (num_unique > num_unique_target) {
            if (count[s[start]]-- == k) num_no_less_than_K--;
            if (count[s[start++]] == 0) num_unique--;
        }
        if (num_unique == num_unique_target && num_unique == num_no_less_than_K) {
            res = max(end - start, res);
        }
    }
    return res;
  }
};




