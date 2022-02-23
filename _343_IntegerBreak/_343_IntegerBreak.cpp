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

class _343_IntegerBreak {
    /**
    * 343. Integer Break
    * Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. 
    * Return the maximum product you can get.

    Example 1:

    Input: 2
    Output: 1
    Explanation: 2 = 1 + 1, 1 × 1 = 1.
    Example 2:

    Input: 10
    Output: 36
    Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
    Note: You may assume that n is not less than 2 and not larger than 58.

    time : < O(n);
    space : O(1);
    */
 
 public:
  int integerBreak(int n) {
    if (n == 2 || n == 3) return n - 1;
    int res = 1;
    while (n > 4) {
        res *= 3;
        n -= 3;
    }
    return res * n;
    
  }
};




