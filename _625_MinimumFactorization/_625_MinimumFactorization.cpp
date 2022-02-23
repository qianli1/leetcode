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

class _625_MinimumFactorization {
    /**
    * 625. Minimum Factorization
    * Given a positive integer a, find the smallest positive integer b whose multiplication of each digit equals to a.

    If there is no answer or the answer is not fit in 32-bit signed integer, then return 0.

    Example 1
    Input:

    48 
    Output:
    68
    Example 2
    Input:

    15
    Output:
    35

    time : O(logn);
    space : O(1);
    */
 
 public:
  int smallestFactorization(int a) {
    if (a < 10) {
        return a;
    }
    long res = 0;
    for (long i = 9, f = 1; i > 1; i--) {
        while (a % i == 0) {
            res += i * f;
            if (res > INT_MAX) {
                return 0;
            }
            a /= i;
            f *= 10;
        }
    }
    return a == 1 ? (int)res : 0;
  }
};




