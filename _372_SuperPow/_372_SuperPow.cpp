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

class _372_SuperPow {
    /**
    * 372. Super Pow
    * Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

    Example 1:

    Input: a = 2, b = [3]
    Output: 8
    Example 2:

    Input: a = 2, b = [1,0]
    Output: 1024

    (a*a)%c = (a%c)*(a%c)
    time : O(1) 不确定;
    space : O(n);
    */
 
 public:
  int superPow(int a, vector<int>& b) {
    return superPow(a, b, b.size(), 1337);
  }

  int superPow(int a, vector<int>& b, int length, int k) {
    if (length == 1) {
        return powMod(a, b[0], k);
    }
    return powMod(superPow(a, b, length - 1, k), 10, k) * powMod(a, b[length - 1], k) % k;
  }

  int powMod(int x, int y, int k) {
    x %= k;
    int pow = 1;
    for (int i = 0; i < y; i++) {
        pow = pow * x % k;
    }
    return pow;
  }
};




