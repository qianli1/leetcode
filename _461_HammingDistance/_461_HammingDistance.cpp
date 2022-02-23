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

class _461_HammingDistance {
    /**
    * 461. Hamming Distance
    * The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

    Given two integers x and y, calculate the Hamming distance.

    Note:
    0 ≤ x, y < 2^31.

    Example:

    Input: x = 1, y = 4

    Output: 2

    Explanation:
    1   (0 0 0 1)
    4   (0 1 0 0)
           ↑   ↑

    The above arrows point to positions where the corresponding bits are different.
    
    time : O(logn);
    space : O(1);
    * @param x
    * @param y
    * @return
    */
 
 public:
  int hammingDistance(int x, int y) {
    int num = x ^ y;
    int res = 0;
    while (num != 0) {
        num &= (num - 1);
        res++;
    }
    return res;
 }
};




