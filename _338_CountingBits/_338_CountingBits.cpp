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

class _338_CountingBits {
    /**
    * 338. Counting Bits
    * Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's 
    * in their binary representation and return them as an array.

    Example 1:

    Input: 2
    Output: [0,1,1]
    Example 2:

    Input: 5
    Output: [0,1,1,2,1,2]
    Follow up:

    It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
    Space complexity should be O(n).
    Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

    time : O(n);
    space : O(n);
    */
 
 public:
  vector<int> countBits(int num) {
    vector<int> res(num + 1, 0);
    for (int i = 1; i <= num; i++) {
        res[i] = res[i & (i - 1)] + 1;
    }
    return res;
  }
};




