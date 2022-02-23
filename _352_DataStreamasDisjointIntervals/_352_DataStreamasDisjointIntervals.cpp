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

class _352_DataStreamasDisjointIntervals {
    /**
    * 352. Data Stream as Disjoint Intervals
    * Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.

    For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:

    [1, 1]
    [1, 1], [3, 3]
    [1, 1], [3, 3], [7, 7]
    [1, 3], [7, 7]
    [1, 3], [6, 7]

    Follow up:

    What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?

    */
 
 private:
  map<int, vector<int>> mp;

 public:
  /** Initialize your data structure here. */
  SummaryRanges() {
    
  }

  //O(logn)
  void addNum(int val) {
    if (mp.count(val)) return;
    auto higher = mp.lower_bound(val);
    auto lower = (higher == mp.begin()) ? mp.end() : prev(higher);
    if (lower != mp.end() && higher != mp.end() && lower->second[1] + 1 == val 
        && higher->first == val + 1) {
        // merge two intervals. [1, 2] [4, 5] with val 3;
        lower->second[1] = higher->second[1];
        mp.erase(higher);
    } else if (lower != mp.end() && lower->second[1] + 1 >= val) {
        // [1, 5] with val 6
        lower->second[1] = max(lower->second[1], val);
    } else if (higher != mp.end() && higher->first == val + 1) {
        // [4, 5] with 3
        mp[val] = {val, higher->second[1]};
        mp.erase(higher);
    } else {
        mp[val] = {val, val};
    }
  }

  vector<vector<int>> getIntervals() {
    vector<vector<int>> res;
    for (const auto& p : mp) {
        res.push_back(p.second);
    }
    return res;
  }
};




