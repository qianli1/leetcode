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

class _479_LargestPalindromeProduct {
    /**
    * 479. Largest Palindrome Product
    * Find the largest palindrome made from the product of two n-digit numbers.

    Since the result could be very large, you should return the largest palindrome mod 1337.

    Example:

    Input: 2

    Output: 987

    Explanation: 99 x 91 = 9009, 9009 % 1337 = 987

    Note:

    The range of n is [1,8].

    time : O(10^n);
    space : O(1);
    * @param n
    * @return
    */
 
 public:
  int largestPalindrome(int n) {
    if (n == 1) return 9;
    long maximum = (long)pow(10, n) - 1;
    long minimum = maximum / 10;
    for (long left = maximum; left > minimum; left--) {
        long right = left;
        string str = to_string(right);
        reverse(str.begin(), str.end());
        right = stol(str);
        long target = left * (maximum + 1) + right;
        for (long i = maximum; i * i >= target; i--) {
            if (target % i == 0) {
                return (int)(target % 1337);
            }
        }
    }
    return -1;
  }
};




