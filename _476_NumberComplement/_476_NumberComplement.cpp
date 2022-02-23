/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class _476_NumberComplement {
    /**
    * 476. Number Complement
    * Given a positive integer num, output its complement number. The complement strategy is to flip the bits of its binary representation.

    Example 1:

    Input: num = 5
    Output: 2
    Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
    Example 2:

    Input: num = 1
    Output: 0
    Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.

    time : O(1);
    space : O(1);
    * @param num
    * @return
    */
 
 public:
  int findComplement(int num) {
    int sum = 0;
    while (sum < num) {
      sum = (sum << 1) | 1;
    }
    return sum - num;
  }
};




