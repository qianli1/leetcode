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

class _727_MinimumWindowSubsequence {
    /**
    * 727. Minimum Window Subsequence
    * Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.

    If there is no such window in S that covers all characters in T, return the empty string "". If there are multiple 
    such minimum-length windows, return the one with the left-most starting index.

    Example 1:

    Input: 
    S = "abcdebdde", T = "bde"
    Output: "bcde"
    Explanation: 
    "bcde" is the answer because it occurs before "bdde" which has the same length.
    "deb" is not a smaller window because the elements of T in the window must occur in order.

    Time: O(m * n)
    Space: O(m + n)
    */
 
 public:
  string minWindow(string S, string T) {
    int i = 0, j = 0;
    int start = -1;
    int min = S.size();
    
    while (i < S.size()) {
        if (S[i] == T[j]) {
            if (++j == T.size()) {
                int end = i + 1;
                while (--j >= 0) {
                    while (S[i--] != T[j]);
                }
                ++i;
                ++j;
                if (end - i < min) {
                    min = end - i;
                    start = i;
                }
            }
        }
        i++;
    } 
    return start == -1 ? "" : S.substr(start, min);
  }

  string minWindow(string S, string T) {
    int m = T.size();
    int n = S.size();
    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j + 1;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (T[i - 1] == S[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    int start = 0, min = n + 1;
    for (int i = 1; i <= n; i++) {
        if (dp[m][i] != 0) {
            if (i - dp[m][i] + 1 < min) {
                start = dp[m][i] - 1;
                min = i - dp[m][i] + 1;
            }
        }
    }
    return min == n + 1 ? "" : S.substr(start, min);
  }
};




