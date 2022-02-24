#include <vector>
#include <string>
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

class _715_RangeModule {
    /**
    * 715. Range Module
    * A Range Module is a module that tracks ranges of numbers. Your task is to design and implement the following interfaces in an 
    * efficient manner.

    addRange(int left, int right) Adds the half-open interval [left, right), tracking every real number in that interval. Adding an 
    interval that partially overlaps with currently tracked numbers should add any numbers in the interval [left, right) that are 
    not already tracked.
    queryRange(int left, int right) Returns true if and only if every real number in the interval [left, right) is currently being 
    tracked.
    removeRange(int left, int right) Stops tracking every real number currently being tracked in the interval [left, right).
    Example 1:
    addRange(10, 20): null
    removeRange(14, 16): null
    queryRange(10, 14): true (Every number in [10, 14) is being tracked)
    queryRange(13, 15): false (Numbers like 14, 14.03, 14.17 in [13, 15) are not being tracked)
    queryRange(16, 17): true (The number 16 in [16, 17) is still being tracked, despite the remove operation)
    Note:

    A half open interval [left, right) denotes all real numbers left <= x < right.
    0 < left < right < 10^9 in all calls to addRange, queryRange, removeRange.
    The total number of calls to addRange in a single test case is at most 1000.
    The total number of calls to queryRange in a single test case is at most 5000.
    The total number of calls to removeRange in a single test case is at most 1000.

    Time: O(nlogn)
    Space: O(n)
    */
 
 private:
  map<int, int> mp;

 public:
  RangeModule() {

  }

  void addRange(int left, int right) {
    if (left >= right) {
        return;
    }
    auto start = mp.upper_bound(left), end = mp.upper_bound(right); 
    if (start != mp.begin()) {
        start--;
        if (start->second < left) start++;
    }
    if (start != end) {
        left = min(left, start->first);
        right = max(right, (--end)->second);
        mp.erase(start, ++end);
    }
    mp[left] = right;
  }

  bool queryRange(int left, int right) {
    auto floor = mp.upper_bound(left);        
    return floor != mp.begin() && (--floor)->second >= right;
  }
    
  void removeRange(int left, int right) {
    if (left >= right) {
        return;
    }
    auto start = mp.upper_bound(left), end = mp.upper_bound(right); 
    if (start != mp.begin()) {
        start--;
        if (start->second < left) start++;
    }
    if (start == end) return;
    int l1 = min(left, start->first), r1 = max(right, (--end)->second);
    mp.erase(start, ++end);
    if (l1 < left) mp[l1] = left;
    if (r1 > right) mp[right] = r1;
  }
};




