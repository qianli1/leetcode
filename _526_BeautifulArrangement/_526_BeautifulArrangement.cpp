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

class _526_BeautifulArrangement {
    /**
    * 526. Beautiful Arrangement
    * Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these 
    * N numbers successfully if one of the following is true for the ith position (1 <= i <= N) in this array:

    The number at the ith position is divisible by i.
    i is divisible by the number at the ith position.

    Now given N, how many beautiful arrangements can you construct?

    Example 1:

    Input: 2
    Output: 2
    Explanation: 

    The first beautiful arrangement is [1, 2]:

    Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).

    Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

    The second beautiful arrangement is [2, 1]:

    Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).

    Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.

    time : O(n!);
    space : O(1);
    */
 
 private:
  int res;

 public:
  int countArrangement(int N) {
    res = 0;
    vector<bool> visited(N + 1, false);
    helper(visited, N, 1);
    return res;
  }

  void helper(vector<bool>& visited, int N, int pos) {
    if (pos > N) {
        res++;
        return;
    }
    for (int i = 1; i <= N; i++) {
        if (!visited[i] && (pos % i == 0 || i % pos == 0)) {
            visited[i] = true;
            helper(visited, N, pos + 1);
            visited[i] = false;
        }
    }
  }
};




