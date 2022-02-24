#include <vector>
#include <string>
#include <cmath>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class _688_KnightProbabilityinChessboard {
    /**
    * 688. Knight Probability in Chessboard
    * On an NxN chessboard, a knight starts at the r-th row and c-th column and attempts to make exactly K moves. The rows and 
    * columns are 0 indexed, so the top-left square is (0, 0), and the bottom-right square is (N-1, N-1).

    A chess knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then 
    one square in an orthogonal direction.

    Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off 
    the chessboard) and moves there.

    The knight continues moving until it has made exactly K moves or has moved off the chessboard. Return the probability that the 
    knight remains on the board after it has stopped moving.

    Example:

    Input: 3, 2, 0, 0
    Output: 0.0625
    Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
    From each of those positions, there are also two moves that will keep the knight on the board.
    The total probability the knight stays on the board is 0.0625.

    Time: O(K * n^2)
    Space: O(n^2)
    */
 
 public:
  double knightProbability(int N, int K, int r, int c) {
    int dirs[8][2] = { {1, 2}, {2, 1}, {2, - 1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
    vector<vector<double>> dp(N, vector<double>(N));
    dp[r][c] = 1;
    for (int k = 0; k < K; k++) {
        vector<vector<double>> dp2(N, vector<double>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int l = 0; l < 8; l++) {
                    int x = i + dirs[l][0];
                    int y = j + dirs[l][1];
                    if (x < 0 || y < 0 || x >= N || y >= N) {
                        continue;
                    }
                    dp2[x][y] += dp[i][j];
                }
            }
        }
        dp = dp2;
    }
    
    double count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            count += dp[i][j];
        }
    }
    return count / pow(8, K);
  }
};




