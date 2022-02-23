#include <vector>
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

class _633_SumofSquareNumbers {
    /**
    * 633. Sum of Square Numbers
    * Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

    Example 1:

    Input: 5
    Output: True
    Explanation: 1 * 1 + 2 * 2 = 5
    

    Example 2:

    Input: 3
    Output: False

    time : O(sqrt(n) * logn);
    space : O(1);
    */
 
 public:
  bool judgeSquareSum(int c) {
    for (long i = 0; i <= c; i++) {
        double num = sqrt(c - i * i);
        if (num == (int)num) {
            return true;
        }
    }
    return false;
  }

  bool judgeSquareSum2(int c) {
    for (long i = 0; i * i <= c; i++) {
        int num = c - (int)(i * i);
        if (binarySearch(0, num, num)) {
            return true;
        }
    }
    return false;
  }

  bool binarySearch(long left, long right, int num) {
    if (left > right) {
        return false;
    }
    long mid = left + (right - left) / 2;
    if (mid * mid == num) {
        return true;
    } else if (mid * mid > num) {
        return binarySearch(left, mid - 1, num);
    } else {
        return binarySearch(mid + 1, right, num);
    }
  }

  bool judgeSquareSum3(int c) {
    if (c < 0) return false;
    int left = 0, right = (int)sqrt(c);
    while (left <= right) {
        int cur = left * left + right * right;
        if (cur < c) {
            left++;
        } else if (cur > c) {
            right--;
        } else {
            return true;
        }
    }
    return false;
  }
};




