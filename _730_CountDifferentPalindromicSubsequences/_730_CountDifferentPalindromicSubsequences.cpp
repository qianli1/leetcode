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

class _730_CountDifferentPalindromicSubsequences {
    /**
    * 730. Count Different Palindromic Subsequences
    * Given a string S, find the number of different non-empty palindromic subsequences in S, and return that number modulo 10^9 + 7.

    A subsequence of a string S is obtained by deleting 0 or more characters from S.

    A sequence is palindromic if it is equal to the sequence reversed.

    Two sequences A_1, A_2, ... and B_1, B_2, ... are different if there is some i for which A_i != B_i.

    Example 1:
    Input: 
    S = 'bccb'
    Output: 6
    Explanation: 
    The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
    Note that 'bcb' is counted only once, even though it occurs twice.
    Example 2:
    Input: 
    S = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
    Output: 104860361
    Explanation: 
    There are 3104860382 different non-empty palindromic subsequences, which is 104860361 modulo 10^9 + 7.

    Time: O(n^2)
    Space: O(n^2)
    */
 
 public:
  int countPalindromicSubsequences(string S) {
    int n = S.size();
    vector<vector<int>> dp(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    
    for (int k = 1; k < n; k++) {
        for (int i = 0; i < n - k; i++) {
            int j = i + k;
            if (S[i] == S[j]) {
                int left = i + 1;
                int right = j - 1;
                while (left <= right && S[left] != S[j]) {
                    left++;
                }
                while (left <= right && S[right] != S[j]) {
                    right--;
                }
                if (left > right) {
                    dp[i][j] = dp[i + 1][j - 1] * 2 + 2;
                } else if (left == right) {
                    dp[i][j] = dp[i + 1][j - 1] * 2 + 1;
                } else {
                    dp[i][j] = dp[i + 1][j - 1] * 2 - dp[left + 1][right - 1];
                }
            } else {
                dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
            }
            dp[i][j] = dp[i][j] < 0 ? dp[i][j] + 1000000007 : dp[i][j] % 1000000007;
        }
    }
    return dp[0][n - 1];
  }
};




