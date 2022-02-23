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

class _390_EliminationGame {
    /**
    * 390. Elimination Game
    * There is a list of sorted integers from 1 to n. Starting from left to right, remove the first number and 
    * every other number afterward until you reach the end of the list.

    Repeat the previous step again, but this time from right to left, remove the right most number and every other number from the remaining numbers.

    We keep repeating the steps again, alternating left to right and right to left, until a single number remains.

    Find the last number that remains starting with a list of length n.

    Example:

    Input:
    n = 9,
    1 2 3 4 5 6 7 8 9
    2 4 6 8
    2 6
    6

    Output:
    6

    time : O(logn);
    space : O(1);
    */
 
 public:
  int lastRemaining(int n) {
    bool left = true;
    int remaining = n;
    int step = 1;
    int res = 1; //head
    while (remaining > 1) {
        if (left || remaining % 2 == 1) {
            res = res + step;
        }
        remaining = remaining / 2;
        step = step * 2;
        left = !left;
    }
    return res;
  }
};




