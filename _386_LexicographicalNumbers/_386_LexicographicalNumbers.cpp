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

class _386_LexicographicalNumbers {
    /**
    * 386. Lexicographical Numbers
    * Given an integer n, return 1 - n in lexicographical order.

    For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

    Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
    time : O(n);
    space : O(n);
    */
 
 public:
  vector<int> lexicalOrder(int n) {
    vector<int> res;
    int cur = 1;
    for (int i = 1; i <= n; i++) {
        res.push_back(cur);
        if (cur * 10 <= n) {
            cur *= 10;
        } else if (cur % 10 != 9 && cur + 1 <= n) {
            cur++;
        } else {
            while ((cur / 10) % 10 == 9) {
                cur /= 10;
            }
            cur = cur / 10 + 1;
        }
    }
    return res;
  }
};




