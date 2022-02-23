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

class _397_IntegerReplacement {
    /**
    * 397. Integer Replacement
    * Given a positive integer n and you can do operations as follow:

    If n is even, replace n with n/2.
    If n is odd, you can replace n with either n + 1 or n - 1.
    What is the minimum number of replacements needed for n to become 1?

    Example 1:

    Input:
    8

    Output:
    3

    Explanation:
    8 -> 4 -> 2 -> 1
    Example 2:

    Input:
    7

    Output:
    4

    Explanation:
    7 -> 8 -> 4 -> 2 -> 1
    or
    7 -> 6 -> 3 -> 2 -> 1

    二进制
    如果倒数第二位是0，那么n-1的操作比n+1的操作能消掉更多的1
    1001 + 1 = 1010
    1001 - 1 = 1000
    如果倒数第二位是1，那么n+1的操作比n-1的操作能消掉更多的1
    1011 + 1 = 1100
    1111 + 1 = 10000
    特殊情况：3->2->1

    */
 
 public:
  //Time: O(logn), space: O(1)
  int integerReplacement(int n) {
    long N = n;
    int res = 0;
    while (N!= 1) {
        if (N % 2 == 0) {
            N >>= 1;
            res++;
        } else {
            if (N == 3) {
                res += 2;
                break;
            }
            N = (N & 2) == 2 ? N + 1 : N - 1;
            res++;
        }
    }
    return res;
  }

  //Method 2: Time: O(logn)
  int integerReplacement(int n) {
    if (n == INT_MAX) return 32;
    int res = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            if ((n + 1) % 4 == 0 && (n - 1 != 2)) {
                n++;
            } else n--;
        }
        res++;
    }
    return res;
  }
};




