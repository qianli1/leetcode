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

class _351_AndroidUnlockPatterns {
    /**
    * 351. Android Unlock Patterns
    * Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.

    Rules for a valid pattern:

    Each pattern must connect at least m keys and at most n keys.
    All the keys must be distinct.
    If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
    The order of keys used matters.
    */
 
 public:
  int numberOfPatterns(int m, int n) {
    // Skip vector represents number to skip between two pairs
    vector<vector<int>> skip(10, vector<int>(10, 0));
    skip[1][3] = skip[3][1] = 2;
    skip[1][7] = skip[7][1] = 4;
    skip[3][9] = skip[9][3] = 6;
    skip[7][9] = skip[9][7] = 8;
    skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] = skip[3][7] = skip[7][3] = skip[4][6] = skip[6][4] = 5;
    
    vector<bool> visited(10, false);
    int res = 0; 
    for (int i = m; i <= n; i++) {
        res += DFS(visited, skip, 1, i - 1) * 4; //1,3,7,9
        res += DFS(visited, skip, 2, i - 1) * 4; //2,4,6,8
        res += DFS(visited, skip, 5, i - 1); //5
        
    }
    return res;
  }

  int DFS(vector<bool>& visited, vector<vector<int>>& skip, int cur, int remain) {
    if (remain < 0) return 0;
    if (remain == 0) return 1;
    visited[cur] = true;
    int res = 0;
    for (int i = 1; i <= 9; i++) {
        if (!visited[i] && (skip[cur][i] == 0 || visited[skip[cur][i]])) {
            res += DFS(visited, skip, i, remain - 1);
        }
    }
    visited[cur] = false;
    return res;
  }
};




