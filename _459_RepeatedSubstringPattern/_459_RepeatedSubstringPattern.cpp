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

class _459_RepeatedSubstringPattern {
    /**
    * 459. Repeated Substring Pattern
    * Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring 
    * together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

    Example 1:

    Input: "abab"
    Output: True
    Explanation: It's the substring "ab" twice.
    Example 2:

    Input: "aba"
    Output: False
    Example 3:

    Input: "abcabcabcabc"
    Output: True
    Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)

    time : O(m * n);
    space : O(n);
    * @param str
    * @return
    */
 
 public:
  bool repeatedSubstringPattern(string s) {
    string str = s + s;
    return str.substr(1, str.size() - 2).find(s) != string::npos;
  }


  /**
   * time : O(n^2)
   * space : O(n)
   * @param str
    * @return
    */
  bool repeatedSubstringPattern2(string s) {
    int len = s.size();
    for (int i = len / 2; i >= 1; i--) {
        if (len % i == 0) {
            int num = len / i;
            string sub = "";
            for (int j = 0; j < num; j++) {
                sub += s.substr(0, i);
            }
            if (sub == s) return true;
        }
    }
    return false;
  }
};




