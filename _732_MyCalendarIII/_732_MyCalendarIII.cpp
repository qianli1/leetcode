#include <vector>
#include <map>


using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class _732_MyCalendarIII {
    /**
    * 732. My Calendar III
    * Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined 
    * as the absolute difference between A and B.

    Example 1:
    Input:
    nums = [1,3,1]
    k = 1
    Output: 0 
    Explanation:
    Here are all the pairs:
    (1,3) -> 2
    (1,1) -> 0
    (3,1) -> 2
    Then the 1st smallest distance pair is (1,1), and its distance is 0.

    Time: O(n^2)
    Space: O(n)
    */
 
 private:
  map<int, int> mp;

 public:
  MyCalendarThree() {
    
  }

  int book(int start, int end) {
    mp[start] ++;
    mp[end] --;
    
    int res = 0;
    int active = 0;
    for (auto& v : mp) {
        active += v.second;
        res = max(res, active);
    }
    return res;
  }
};




