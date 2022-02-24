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

class _667_BeautifulArrangementII {
    /**
    * 667. Beautiful Arrangement II
    * Given two integers n and k, you need to construct a list which contains n different positive integers ranging from 1 to n 
    * and obeys the following requirement:
    Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly 
    k distinct integers.

    If there are multiple answers, print any of them.

    Example 1:
    Input: n = 3, k = 1
    Output: [1, 2, 3]
    Explanation: The [1, 2, 3] has three different positive integers ranging from 1 to 3, and the [1, 1] has exactly 1 distinct 
    integer: 1.
    Example 2:
    Input: n = 3, k = 2
    Output: [1, 3, 2]
    Explanation: The [1, 3, 2] has three different positive integers ranging from 1 to 3, and the [2, 1] has exactly 2 distinct 
    integers: 1 and 2.

    */
 
 public:
  vector<int> constructArray(int n, int k) {
    vector<int> res(n);
    
    int left = 1;
    int right = n;
    
    for (int i = 0; i < res.size(); i++) {
        res[i] = k % 2 != 0 ? left++ : right--;
        if (k > 1) {
            k--;
        }
    }
    return res;
  }
};




