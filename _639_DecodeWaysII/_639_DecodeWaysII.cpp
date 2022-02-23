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

class _639_DecodeWaysII {
    /**
    * 639. Decode Ways II
    * A message containing letters from A-Z is being encoded to numbers using the following mapping way:

    'A' -> 1
    'B' -> 2
    ...
    'Z' -> 26
    Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.

    Given the encoded message containing digits and the character '*', return the total number of ways to decode it.

    Also, since the answer may be very large, you should return the output mod 109 + 7.

    Example 1:
    Input: "*"
    Output: 9
    Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".
    Example 2:
    Input: "1*"
    Output: 9 + 9 = 18
    
    */
 
 public:
  //Time: O(n), space: O(n) 
  int numDecodings(string s) {
    int M = 1000000007;
    vector<long> dp(s.size() + 1);
    dp[0] = 1;
    dp[1] = s[0] == '*' ? 9 : s[0] == '0' ? 0 : 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '*') {
            dp[i + 1] = 9 * dp[i]; 
            if (s[i - 1] == '1') {
                dp[i + 1] = (dp[i + 1] + 9 * dp[i - 1]) % M;
            } else if (s[i - 1] == '2') {
                dp[i + 1] = (dp[i + 1] + 6 * dp[i - 1]) % M;
            } else if (s[i - 1] == '*') {
                dp[i + 1] = (dp[i + 1] + 15 * dp[i - 1]) % M;
            }
        } else {
            dp[i + 1] = s[i] != '0' ? dp[i] : 0;
            if (s[i - 1] == '1') {
                dp[i + 1] = (dp[i + 1] + dp[i - 1]) % M;
            } else if (s[i - 1] == '2' && s[i] <= '6') {
                dp[i + 1] = (dp[i + 1] + dp[i - 1]) % M;
            } else if (s[i - 1] == '*') {
                dp[i + 1] = (dp[i + 1] + (s[i] <= '6' ? 2 : 1) * dp[i - 1]) % M;
            }
        }
    }
    return (int) dp[s.size()];
  }

//DP: Time: O(n), space: O(1)
  int numDecodings2(string s) {
    int M = 1000000007;
    long first = 1, second = s[0] == '*' ? 9 : s[0] == '0' ? 0 : 1;
    for (int i = 1; i < s.size(); i++) {
        long temp = second;
        if (s[i] == '*') {
            second = 9 * second; 
            if (s[i - 1] == '1') {
                second = (second + 9 * first) % M;
            } else if (s[i - 1] == '2') {
                second = (second + 6 * first) % M;
            } else if (s[i - 1] == '*') {
                second = (second + 15 * first) % M;
            }
        } else {
            second = s[i] != '0' ? second : 0;
            if (s[i - 1] == '1') {
                second = (second + first) % M;
            } else if (s[i - 1] == '2' && s[i] <= '6') {
                second = (second + first) % M;
            } else if (s[i - 1] == '*') {
                second = (second + (s[i] <= '6' ? 2 : 1) * first) % M;
            }
        }
        first = temp;
    }
    return (int) second;
  }
};




