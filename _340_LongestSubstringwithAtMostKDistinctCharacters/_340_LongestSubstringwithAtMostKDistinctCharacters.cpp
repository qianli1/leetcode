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

class _340_LongestSubstringwithAtMostKDistinctCharacters {
    /**
    * 340. Longest Substring with At Most K Distinct Characters
    * Given a string, find the length of the longest substring T that contains at most k distinct characters.

    Example 1:

    Input: s = "eceba", k = 2
    Output: 3
    Explanation: T is "ece" which its length is 3.
    Example 2:

    Input: s = "aa", k = 1
    Output: 2
    Explanation: T is "aa" which its length is 2.

    time : O(n);
    space : O(1);
    */
 
 public:
  int lengthOfLongestSubstringKDistinct(string s, int k) { 
    vector<int> count(256, 0);
    int res = 0, num = 0, j = 0;
    for (int i = 0; i < s.size(); i++) {
        if (count[s[i]]++ == 0) num++;
        if (num > k) {
            while (--count[s[j++]] > 0);
            num--;
        }
        res = max(res, i - j + 1);
    }
    return res;
  }
};




