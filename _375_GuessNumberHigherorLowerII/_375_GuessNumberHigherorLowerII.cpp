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

class _375_GuessNumberHigherorLowerII {
    /**
    * 375. Guess Number Higher or Lower II
    * We are playing the Guess Game. The game is as follows:

    I pick a number from 1 to n. You have to guess which number I picked.

    Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

    However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

    Example:

    n = 10, I pick 8.

    First round:  You guess 5, I tell you that it's higher. You pay $5.
    Second round: You guess 7, I tell you that it's higher. You pay $7.
    Third round:  You guess 9, I tell you that it's lower. You pay $9.

    Game over. 8 is the number I picked.

    You end up paying $5 + $7 + $9 = $21.
    Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.

    time : O(n^3);
    space : O(n^2);
    */
 
 public:
  vector<vector<int>> dp;

  int getMoneyAmount(int n) {
    dp.resize(n + 1);
    for (int i = 0; i < n + 1; ++i) {
        dp[i].resize(n + 1);
    }
    return helper(1, n);
  }

  int helper(int i, int j) {
    if (i >= j) return 0;
    if (dp[i][j] != 0) return dp[i][j];
    int res = INT_MAX;
    for (int x = i; x <= j; x++) {
        res = min(res, max(helper(i, x - 1), helper(x + 1, j)) + x);
    }
    dp[i][j] = res;
    return res;
  }

  int getMoneyAmount2(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i > 0; i--) {
        for (int j = i + 1; j <= n; j++) {
            dp[i][j] = INT_MAX;
            for (int x = i; x < j; x++) {
                dp[i][j] = min(dp[i][j], x + max(dp[i][x -1], dp[x + 1][j]));
            }
        }
    }
    return dp[1][n];        
  }
};




