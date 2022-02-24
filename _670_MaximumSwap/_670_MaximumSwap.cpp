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

class _670_MaximumSwap {
    /**
    * 670. Maximum Swap
    * Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum 
    * valued number you could get.

    Example 1:
    Input: 2736
    Output: 7236
    Explanation: Swap the number 2 and the number 7.
    Example 2:
    Input: 9973
    Output: 9973
    Explanation: No swap.

    Time: O(n)位数
    Space: O(n)
    */
 
 public:
  int maximumSwap(int num) {
    string digits = to_string(num);
    vector<int> buckets(10);
    for (int i = 0; i < digits.size(); i++) {
        buckets[digits[i] - '0'] = i;
    }
    
    for (int i = 0; i < digits.size(); i++) {
        for (int j = 9; j > digits[i] - '0'; j--) {
            if (buckets[j] > i) {
                char tmp = digits[i];
                digits[i] = digits[buckets[j]];
                digits[buckets[j]] = tmp;
                return stoi(digits);
            }
        }
    }
    return num;
  }
};




