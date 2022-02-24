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

class _717_1bitand2bitCharacters {
    /**
    * 717. 1-bit and 2-bit Characters
    * We have two special characters. The first character can be represented by one bit 0. The second character can be 
    * represented by two bits (10 or 11).

    Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. 
    The given string will always end with a zero.

    Example 1:
    Input: 
    bits = [1, 0, 0]
    Output: True
    Explanation: 
    The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.
    Example 2:
    Input: 
    bits = [1, 1, 1, 0]
    Output: False
    Explanation: 
    The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit character.

    time : O(n);
    space : O(1);
    */
 
 public:
  bool isOneBitCharacter(vector<int>& bits) {
    int index = bits.size() - 2;
    while (index >= 0 && bits[index] > 0) {
        index--;
    }
    return (bits.size() - index) % 2 == 0;
  }
};




