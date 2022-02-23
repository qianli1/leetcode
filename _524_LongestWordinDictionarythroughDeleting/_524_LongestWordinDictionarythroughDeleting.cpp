#include <string>
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

class _524_LongestWordinDictionarythroughDeleting {
    /**
    * 524. Longest Word in Dictionary through Deleting
    * Given a string s and a string t, check if s is subsequence of t.

    A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) 
    of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence 
    of "abcde" while "aec" is not).

    Follow up:
    If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has 
    its subsequence. In this scenario, how would you change your code?

    Credits:
    Special thanks to @pbrother for adding this problem and creating all test cases.

    Example 1:

    Input: s = "abc", t = "ahbgdc"
    Output: true
    Example 2:

    Input: s = "axc", t = "ahbgdc"
    Output: false

    time : O(m * n);
    space : O(1);
    */
 
 public:
  bool isSubsequence(string s, string t) {
    if (s.size() == 0) return true;
    int i = 0;
    int j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) i++;
        j++;
    }
    return i == s.size();
  }

  string findLongestWord(string s, vector<string>& d) {
    string res = "";
    for (string str : d) {
        if (isSubsequence(str, s)) {
            if (str.length() > res.length() || (str.length() == res.length() && (str < res))) {
                res = str;
            }
        } 
    }
    return res;
  }
};




