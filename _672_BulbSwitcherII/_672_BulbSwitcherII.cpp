#include <vector>
#include <string>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class _672_BulbSwitcherII {
    /**
    * 672. Bulb Switcher II
    * There is a room with n lights which are turned on initially and 4 buttons on the wall. After performing exactly m 
    * unknown operations towards buttons, you need to return how many different kinds of status of the n lights could be.

    Suppose n lights are labeled as number [1, 2, 3 ..., n], function of these 4 buttons are given below:

    Flip all the lights.
    Flip lights with even numbers.
    Flip lights with odd numbers.
    Flip lights with (3k + 1) numbers, k = 0, 1, 2, ...

    Example 1:

    Input: n = 1, m = 1.
    Output: 2
    Explanation: Status can be: [on], [off]
    
    Example 2:

    Input: n = 2, m = 1.
    Output: 3
    Explanation: Status can be: [on, off], [off, on], [off, off]
    
    Example 3:

    Input: n = 3, m = 1.
    Output: 4
    Explanation: Status can be: [off, on, off], [on, off, on], [off, off, off], [off, on, on].

    Time: O(1)
    Space: O(1)
    */
 
 public:
  int flipLights(int n, int m) {
    if (n == 0 || m == 0) return 1;
    if (n == 1) return 2;
    if (n == 2) return  m == 1 ? 3 : 4;
    if (m == 1) return 4;
    return m == 2 ? 7 : 8;
  }
};




