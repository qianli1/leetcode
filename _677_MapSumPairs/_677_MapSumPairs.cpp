#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class _677_MapSumPairs {
    /**
    * 677. Map Sum Pairs
    * Implement a MapSum class with insert, and sum methods.

    For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents 
    the value. If the key already existed, then the original key-value pair will be overridden to the new one.

    For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value 
    whose key starts with the prefix.

    Example 1:
    Input: insert("apple", 3), Output: Null
    Input: sum("ap"), Output: 3
    Input: insert("app", 2), Output: Null
    Input: sum("ap"), Output: 5

    Time: O(K)长度
    Space: O(K)
    */
 
 private:
  unordered_map<string, int> mp;
  unordered_map<string, int> words;

 public:
  /** Initialize your data structure here. */
  MapSum() {
    
  }

  void insert(string key, int val) {
    int diff = val - mp[key];
    mp[key] = val;
    string prefix = "";
    for (char c : key) {
        prefix += c;
        words[prefix] += diff;
    }
  }

  int sum(string prefix) {
    return words[prefix]; 
  }
};




